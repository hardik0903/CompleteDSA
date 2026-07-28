"""
Auto-Commit & Push Script for DSA Repository
=============================================

This script monitors the repository directory for compiled binaries being
created or updated (i.e. a successful `g++ NinjaTraining.cpp -o NinjaTraining`).
When such a binary is detected, it finds the matching `.cpp` source
(same name, same directory) and:

  1. Stages the `.cpp` file with `git add`.
  2. Generates a meaningful commit message from the file's path
     (e.g., "Add Array/LEETCODE: 4Sum").
  3. Commits and pushes to `origin main`.

A file only counts as a "compiled binary" if it has no extension, is
executable, and has a sibling `.cpp` with the same name — this filters
out unrelated no-extension files (Makefile, LICENSE, .git internals, etc).

Usage:
    python auto_commit.py

    Press Ctrl+C to stop the watcher gracefully.

Requirements:
    - `watchdog` (pip install watchdog)  — already installed
    - Git configured with remote `origin` pointing to your GitHub repo.
"""

import os
import sys
import time
import subprocess
from datetime import datetime
from pathlib import Path

from watchdog.observers import Observer
from watchdog.events import FileSystemEventHandler

# ── ANSI Color Codes ────────────────────────────────────────────────────────

GREEN = "\033[92m"
YELLOW = "\033[93m"
RED = "\033[91m"
CYAN = "\033[96m"
BOLD = "\033[1m"
RESET = "\033[0m"

# ── Repository Root ─────────────────────────────────────────────────────────

REPO_DIR = os.path.dirname(os.path.abspath(__file__))

# ── Cooldown (seconds) ─────────────────────────────────────────────────────

COOLDOWN_SECONDS = 5


def timestamp() -> str:
    """Return a formatted timestamp string for console logging."""
    return datetime.now().strftime("%H:%M:%S")


def log_info(msg: str) -> None:
    print(f"  {CYAN}[{timestamp()}]{RESET}  {msg}")


def log_success(msg: str) -> None:
    print(f"  {GREEN}[{timestamp()}]  ✔  {msg}{RESET}")


def log_skip(msg: str) -> None:
    print(f"  {YELLOW}[{timestamp()}]  ⏭  {msg}{RESET}")


def log_error(msg: str) -> None:
    print(f"  {RED}[{timestamp()}]  ✖  {msg}{RESET}")


def run_git(*args: str) -> subprocess.CompletedProcess:
    """
    Run a git command inside the repo directory.
    Returns the CompletedProcess; the caller decides how to handle errors.
    """
    return subprocess.run(
        ["git", *args],
        cwd=REPO_DIR,
        capture_output=True,
        text=True,
    )


def is_file_tracked(rel_path: str) -> bool:
    """Return True if the file already has at least one commit in the log."""
    result = run_git("log", "--oneline", "--", rel_path)
    return bool(result.stdout.strip())


def build_commit_message(rel_path: str) -> str:
    """
    Build a human-readable commit message from the relative .cpp path.

    Examples:
        Array/LEETCODE/4Sum.cpp      →  Add Array/LEETCODE: 4Sum
        Graphs/BASICS/BFS.cpp        →  Add Graphs/BASICS: BFS
        LinkedList/BASICS/ll2.cpp    →  Add LinkedList/BASICS: ll2
        hashCode.cpp                 →  Add hashCode
    """
    # Normalise to forward slashes for consistency
    rel_path = rel_path.replace("\\", "/")
    parts = Path(rel_path).parts  # e.g. ('Array', 'LEETCODE', '4Sum.cpp')

    # Determine Add vs Update
    verb = "Update" if is_file_tracked(rel_path) else "Add"

    problem_name = Path(parts[-1]).stem  # filename without extension

    if len(parts) >= 3:
        # e.g. Array/LEETCODE/4Sum.cpp → "Array/LEETCODE: 4Sum"
        prefix = "/".join(parts[:-1])
        return f"{verb} {prefix}: {problem_name}"
    elif len(parts) == 2:
        # e.g. LinkedList/ll2.cpp → "LinkedList: ll2"
        return f"{verb} {parts[0]}: {problem_name}"
    else:
        # Root-level file
        return f"{verb} {problem_name}"


class BinaryEventHandler(FileSystemEventHandler):
    """Watches for compiled-binary creation / update and auto-commits the matching .cpp."""

    def __init__(self) -> None:
        super().__init__()
        # {absolute_cpp_path: last_commit_timestamp}
        self._cooldowns: dict[str, float] = {}

    # ── Event Callbacks ─────────────────────────────────────────────────

    def on_created(self, event):
        if not event.is_directory:
            self._handle(event.src_path)

    def on_modified(self, event):
        if not event.is_directory:
            self._handle(event.src_path)

    # ── Core Logic ──────────────────────────────────────────────────────

    def _handle(self, binary_path: str) -> None:
        abs_binary = os.path.abspath(binary_path)

        # Ignore anything inside .git
        if os.sep + ".git" + os.sep in abs_binary:
            return

        # A "compiled binary" has no extension …
        if os.path.splitext(abs_binary)[1] != "":
            return

        # … must actually exist as a regular file …
        if not os.path.isfile(abs_binary):
            return

        # … must be executable …
        if not os.access(abs_binary, os.X_OK):
            return

        # … and must have a matching .cpp source next to it.
        abs_cpp = abs_binary + ".cpp"
        if not os.path.isfile(abs_cpp):
            return

        # ── Cooldown check ──────────────────────────────────────────────
        now = time.time()
        last = self._cooldowns.get(abs_cpp, 0)
        if now - last < COOLDOWN_SECONDS:
            log_skip(f"Cooldown active — skipping {os.path.basename(abs_cpp)}")
            return
        self._cooldowns[abs_cpp] = now

        rel_cpp = os.path.relpath(abs_cpp, REPO_DIR).replace("\\", "/")
        log_info(f"Detected compiled binary → {BOLD}{rel_cpp}{RESET}")

        # ── git add ─────────────────────────────────────────────────────
        try:
            result = run_git("add", rel_cpp)
            if result.returncode != 0:
                log_error(f"git add failed: {result.stderr.strip()}")
                return
        except Exception as exc:
            log_error(f"git add error: {exc}")
            return

        # ── Check for staged changes ───────────────────────────────────
        try:
            diff = run_git("diff", "--cached", "--name-only")
            if not diff.stdout.strip():
                log_skip("No staged changes — nothing to commit")
                return
        except Exception as exc:
            log_error(f"git diff error: {exc}")
            return

        # ── Commit ──────────────────────────────────────────────────────
        message = build_commit_message(rel_cpp)

        try:
            result = run_git("commit", "-m", message)
            if result.returncode != 0:
                log_error(f"git commit failed: {result.stderr.strip()}")
                return
            log_success(f"Committed → {BOLD}{message}{RESET}")
        except Exception as exc:
            log_error(f"git commit error: {exc}")
            return

        # ── Push ────────────────────────────────────────────────────────
        try:
            result = run_git("push", "origin", "main")
            if result.returncode != 0:
                log_error(f"Push failed (committed locally): {result.stderr.strip()}")
                return
            log_success("Pushed to origin/main  🚀")
        except Exception as exc:
            log_error(f"Push error (committed locally): {exc}")


def print_banner() -> None:
    """Print a startup banner with repo info."""
    banner = f"""
{CYAN}{BOLD}╔══════════════════════════════════════════════════════╗
║          🔄  DSA Auto-Commit Watcher  🔄             ║
╚══════════════════════════════════════════════════════╝{RESET}

  {CYAN}Repo :{RESET}  {BOLD}{REPO_DIR}{RESET}
  {CYAN}Watch:{RESET}  Recursive — all subdirectories
  {CYAN}For  :{RESET}  compiled binary appears → auto-commit & push matching .cpp

  {YELLOW}Press Ctrl+C to stop.{RESET}
"""
    print(banner)


def main() -> None:
    print_banner()

    event_handler = BinaryEventHandler()
    observer = Observer()
    observer.schedule(event_handler, REPO_DIR, recursive=True)
    observer.start()

    log_info("Watcher started — waiting for compiled binaries …")
    print()

    try:
        while True:
            time.sleep(1)
    except KeyboardInterrupt:
        print()
        log_info("Shutting down watcher …")
        observer.stop()

    observer.join()
    log_success("Watcher stopped. Goodbye! 👋")


if __name__ == "__main__":
    main()
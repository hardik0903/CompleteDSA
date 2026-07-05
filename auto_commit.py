"""
Auto-Commit & Push Script for DSA Repository
=============================================

This script monitors the repository directory for `.exe` file creation or
modification events. When a new/modified `.exe` is detected, it:

  1. Finds the corresponding `.cpp` source file (same name, same directory).
  2. Stages the `.cpp` file with `git add`.
  3. Generates a meaningful commit message from the file's path
     (e.g., "Add Array/LEETCODE: 4Sum").
  4. Commits and pushes to `origin main`.

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


class ExeEventHandler(FileSystemEventHandler):
    """Watches for .exe creation / modification and auto-commits the .cpp."""

    def __init__(self) -> None:
        super().__init__()
        # {absolute_exe_path: last_commit_timestamp}
        self._cooldowns: dict[str, float] = {}

    # ── Event Callbacks ─────────────────────────────────────────────────

    def on_created(self, event):
        if not event.is_directory:
            self._handle(event.src_path)

    def on_modified(self, event):
        if not event.is_directory:
            self._handle(event.src_path)

    # ── Core Logic ──────────────────────────────────────────────────────

    def _handle(self, exe_path: str) -> None:
        # Only care about .exe files
        if not exe_path.lower().endswith(".exe"):
            return

        abs_exe = os.path.abspath(exe_path)

        # ── Cooldown check ──────────────────────────────────────────────
        now = time.time()
        last = self._cooldowns.get(abs_exe, 0)
        if now - last < COOLDOWN_SECONDS:
            log_skip(f"Cooldown active — skipping {os.path.basename(abs_exe)}")
            return
        self._cooldowns[abs_exe] = now

        # ── Find corresponding .cpp ─────────────────────────────────────
        cpp_path = os.path.splitext(abs_exe)[0] + ".cpp"
        rel_exe = os.path.relpath(abs_exe, REPO_DIR).replace("\\", "/")

        log_info(f"Detected .exe → {BOLD}{rel_exe}{RESET}")

        if not os.path.isfile(cpp_path):
            log_skip(f"No matching .cpp found — skipping")
            return

        rel_cpp = os.path.relpath(cpp_path, REPO_DIR).replace("\\", "/")
        log_info(f"Found source   → {BOLD}{rel_cpp}{RESET}")

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
  {CYAN}For  :{RESET}  .exe creation / modification → auto-commit .cpp

  {YELLOW}Press Ctrl+C to stop.{RESET}
"""
    print(banner)


def main() -> None:
    print_banner()

    event_handler = ExeEventHandler()
    observer = Observer()
    observer.schedule(event_handler, REPO_DIR, recursive=True)
    observer.start()

    log_info("Watcher started — waiting for .exe events …")
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

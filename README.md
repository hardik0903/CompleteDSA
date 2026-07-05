<div align="center">

# 🧠 Complete DSA

### Structured Data Structures & Algorithms Solutions — Built in Public

[![C++](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)](https://isocpp.org/)
[![Problems Solved](https://img.shields.io/badge/Problems%20Solved-215-brightgreen?style=for-the-badge)](https://github.com/hardik0903/CompleteDSA)
[![LeetCode](https://img.shields.io/badge/LeetCode-Solutions-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/)
[![GFG](https://img.shields.io/badge/GeeksforGeeks-Solutions-2F8D46?style=for-the-badge&logo=geeksforgeeks&logoColor=white)](https://www.geeksforgeeks.org/)

---

*I believe in learning in public. Every problem I solve, every algorithm I study, and every data structure I implement is documented here — with clean, readable C++ code and structured by topic. This repository is a living record of my DSA journey, built one commit at a time.*

</div>

---

## 📌 About This Repository

This is not a dump of solutions. It is a **disciplined, topic-wise** collection of DSA problems solved across multiple competitive programming platforms — organized for revision, reference, and accountability.

Every file is committed individually with a descriptive message. Every solution compiles and runs. The repository is updated automatically on every build via a custom watcher script.

---

## 📊 Progress Overview

| Topic | Problems | Key Concepts |
|:------|:--------:|:-------------|
| [**Arrays**](./Array) | 32 | Kadane's, Merge Sort, Two Pointers, Prefix Sum, Inversions |
| [**Binary Search**](./Binary-Search) | 33 | Search Space Reduction, Rotated Arrays, 2D Matrix, Answer on BS |
| [**Binary Search Tree**](./Binary-Search-Tree) | 12 | Insert/Delete, Validation, LCA, Iterator, Recovery |
| [**Binary Tree**](./Binary-Tree) | 13 | Traversals, Construction, Serialization, Width, Burning Tree |
| [**Graphs**](./Graphs) | 28 | BFS/DFS, Dijkstra, Bellman-Ford, Floyd-Warshall, Topo Sort |
| [**Linked List**](./LinkedList) | 26 | Reversal, Cycle Detection, Merge, Clone, DLL Operations |
| [**Sliding Window & Two Pointer**](./SlidingWindowTwoPointer) | 11 | Variable Window, Subarray Sum, K-Distinct, Subsequence |
| [**Stacks & Queues**](./StackAndQueues) | 20 | Monotonic Stack, NGE/NSE, Histogram, LRU Cache, Infix/Postfix |
| [**Strings**](./String) | 37 | KMP, Rabin-Karp, Palindromes, Anagrams, Pattern Matching |
| **Miscellaneous** | 3 | Hashing, Exponentiation |
| | **215** | |

---

## 🗂️ Repository Structure

```
CompleteDSA/
│
├── Array/
│   ├── BASICS/            # Foundational algorithms (Merge Sort)
│   ├── Coding-Ninjas/     # Platform-specific problems
│   ├── GFG/               # GeeksforGeeks solutions
│   ├── InterViewBit/      # InterviewBit solutions
│   └── LEETCODE/          # LeetCode solutions
│
├── Binary-Search/
│   ├── Coding-Ninjas/     # Aggressive Cows, Book Allocation, etc.
│   ├── GFG/               # Floor, Ceil, Lower/Upper Bound
│   └── Leetcode/          # Koko Bananas, Rotated Array, 2D Matrix
│
├── Binary-Search-Tree/
│   ├── GFG/               # Floor & Ceil of BST
│   └── Leetcode/          # Validate, LCA, Recovery, Iterator
│
├── Binary-Tree/
│   ├── Basics/            # Inorder, Preorder, All Traversals
│   ├── GeeksForGeeks/     # Burning Tree, Children Sum
│   └── Leetcode/          # Construction, Serialization, Width
│
├── Graphs/
│   ├── BASICS/            # BFS, DFS, Dijkstra, Bellman-Ford, Floyd-Warshall
│   ├── GFG/               # Shortest Paths, Word Ladder
│   ├── Leetcode/          # Provinces, Enclaves, Course Schedule
│   └── Study/             # Cycle Detection, Kahn's Algo, Alien Dict
│
├── LinkedList/
│   ├── BASICS/            # Singly & Doubly LL implementation
│   ├── CodingNinjas/      # DLL operations, Flattening
│   ├── GFG/               # Add One, Array to LL
│   └── LEETCODE/          # Reverse, Cycle, Merge, Clone, Sort
│
├── SlidingWindowTwoPointer/
│   ├── CodingNinjas/      # K-Distinct, Min Window Subsequence
│   └── Leetcode/          # Fruits, Max Ones, Binary Subarray Sum
│
├── StackAndQueues/
│   ├── BASICS/            # Stack & Queue implementation, Conversions
│   ├── CodingNinjas/      # NSE
│   ├── GFG/               # Celebrity, NGE
│   └── LeetCode/          # Histogram, LRU Cache, Trapping Water
│
├── String/
│   ├── BASICS/            # KMP, Rabin-Karp, String fundamentals
│   ├── Coding-Ninjas/     # Palindrome, Replace Spaces
│   ├── GFG/               # Anagram, Atoi, Binary Strings
│   └── LeetCode/          # Longest Palindrome, Permutations, Compression
│
├── auto_commit.py         # 🔄 Auto-commit watcher script
└── .gitignore
```

---

## ⚙️ Auto-Commit System

This repository features a custom **file watcher** that automatically commits and pushes solutions the moment they compile successfully.

```bash
python auto_commit.py
```

**How it works:**
1. Monitors the repository for `.exe` file creation (triggered by C++ compilation)
2. Identifies the corresponding `.cpp` source file
3. Commits with a structured message → `Add <Topic>/<Platform>: <ProblemName>`
4. Pushes to GitHub immediately

> No manual git commands needed. Solve → Build → It's live.

---

## 🏗️ Platforms Covered

<div align="center">

| Platform | Badge |
|:---------|:-----:|
| LeetCode | ![LeetCode](https://img.shields.io/badge/-LeetCode-FFA116?style=flat-square&logo=leetcode&logoColor=white) |
| GeeksforGeeks | ![GFG](https://img.shields.io/badge/-GeeksforGeeks-2F8D46?style=flat-square&logo=geeksforgeeks&logoColor=white) |
| Coding Ninjas | ![CN](https://img.shields.io/badge/-Coding%20Ninjas-DD6620?style=flat-square&logo=codingninjas&logoColor=white) |
| InterviewBit | ![IB](https://img.shields.io/badge/-InterviewBit-5B5EA6?style=flat-square) |

</div>

---

## 🛠️ Tech Stack

- **Language:** C++ (compiled with `g++` / `cl.exe`)
- **IDE:** Visual Studio Code
- **Automation:** Python + Watchdog
- **Version Control:** Git + GitHub

---

## 🧭 Philosophy

- **Consistency over intensity** — One problem at a time, every day.
- **Understanding over memorization** — Every solution includes the thought process.
- **Public accountability** — If it's not committed, it didn't happen.

---

<div align="center">

**Built with discipline. Updated with every build.**

⭐ Star this repo if you find it useful.

</div>

# 📄 get_next_line – 42 Wolfsburg

This project is part of the 42 Core Curriculum.  
The goal is to build a function `get_next_line()` that reads a file descriptor line by line — handling memory, buffer sizes, and multiple file descriptors manually, without using standard C library functions.

---

## 🚀 Project Overview

The function prototype:

```c
char *get_next_line(int fd);

    Returns the next line from a file, including the \n if present

    Reads until the next newline or EOF

    Works with any file descriptor (files, stdin, etc.)

    Handles multiple file descriptors at once

    Uses a static buffer to maintain state between calls

📁 File Structure

    get_next_line.c – main logic for reading from file descriptors

    get_next_line_utils.c – helper functions (e.g. string operations)

    get_next_line.h – header file with function declarations

    Makefile – build automation

🛠️ What I Learned

    File I/O in C (read)

    Manual memory management (malloc, free)

    String manipulation without standard C library

    Working with static variables for persistent function state

    Managing edge cases and multiple file descriptors

🔧 Compilation

To compile:

make

To test with a custom main.c:

gcc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c -D BUFFER_SIZE=42

Replace 42 with any buffer size you'd like to test.
✅ Project Status

    📅 Completed: July 2025

    🏫 School: 42 Wolfsburg

    🧠 Language: C

📎 Constraints

    You may only use: read, malloc, and free

    Must work with any buffer size via the -D BUFFER_SIZE flag

    No usage of standard string or file handling functions

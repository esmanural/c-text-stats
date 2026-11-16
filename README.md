# c-text-stats

A lightweight command-line utility written in **C** to analyze text files by counting lines, words, and characters.

## Features
* **File Processing:** Safely opens and reads text files using standard C file I/O (`fopen`, `fgetc`).
* **Statistical Metrics:** Calculates total character count, word count (handling whitespace parsing), and line count.
* **CLI Support:** Accepts a target filename via command-line arguments with a safe fallback to a default sample file.

## Project Structure
* `main.c`: Core source code containing file analysis and string parsing logic.
* `sample.txt`: Sample text file used for testing the tool.

## How to Compile and Run
1. Ensure you have a C compiler installed (like GCC).
2. Clone the repository and compile the program:
   ```bash
   gcc main.c -o c-text-stats

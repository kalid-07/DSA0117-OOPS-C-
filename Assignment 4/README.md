# Assignment 4 – CO4 (C++)

## Package contents
- `Assignment4_Answers.pdf`: written model answers for all six tasks.
- `Task01` through `Task06`: individual C++ source programs.
- Each task folder contains `output.txt` and `output_screenshot.png` generated from a local run.

## Compiler and commands
Tested with the system `g++` compiler using C++17 and warnings enabled:

```bash
g++ -std=c++17 -Wall -Wextra Task01/task01.cpp -o task01
./task01
```

Repeat with the matching task folder and source filename for Tasks 02–06.

For Task 04, an AddressSanitizer run can be attempted with:

```bash
g++ -std=c++17 -Wall -Wextra -fsanitize=address Task04/task04.cpp -o task04
./task04
```

## Before submission
1. Replace the blank student name, register number and GitHub URL on the PDF cover page.
2. Verify the compiler version on your own computer and update this README if needed.
3. Re-run the programs on your computer and replace/add your own screenshots if your faculty requires screenshots from your system.
4. Create a GitHub repository named `DSA01-<RegisterNumber>-Assignment4`.
5. Upload this package's contents, commit each task separately, and share the repository with the faculty.
6. Put the working GitHub link on the PDF cover page and submit the PDF plus repository link as directed by your faculty.

The assignment brief requires a GitHub repository, progressive commits, source code, input files where applicable, output screenshots and README. This ZIP does not create or publish a GitHub repository for you.

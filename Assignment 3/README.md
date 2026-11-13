# Assignment 3 – CO3

**Student:** Kalid A.  
**Register Number:** 192421010  
**Course Code:** DSA0117  
**Repository:** `kalid-07/DSA0117-OOPS-C-`

## Contents

All seven tasks are kept directly inside this single `Assignment 3` folder (no separate task folders), as requested:

- `Task01.cpp` through `Task07.cpp` – C++ source programs
- `Task01_output.txt` through `Task07_output.txt` – output captured from local compilation and execution
- `Task01_output.png` through `Task07_output.png` – terminal-style images rendered from the captured output
- `Assignment3_Report.docx` – report

## Compiler and build

Compiler used in the preparation environment: **g++ 14.2.0**.

Compile each program with:

```bash
g++ -std=c++17 -Wall -Wextra Task01.cpp -o Task01
```

Run on Windows PowerShell:

```powershell
.\Task01.exe
```

Run on Linux/macOS:

```bash
./Task01
```

Repeat with the matching task filename for Tasks 02–07.

## Task summary

1. **Task 01:** Book class with default, delegated, and parameterized constructors; rejects negative copy counts.
2. **Task 02:** Prescription class with deep-copy constructor, copy assignment, destructor, and self-assignment protection.
3. **Task 03:** Event class demonstrates construction, booking/cancellation, scope-based destruction, and dynamic allocation.
4. **Task 04:** Money class demonstrates arithmetic, comparison, compound assignment, and stream operators.
5. **Task 05:** Time and Playlist classes demonstrate prefix/postfix increment, comparison, and subscript operators.
6. **Task 06:** Text class demonstrates copy control and overloaded concatenation, assignment, comparison, and stream output.
7. **Task 07:** Complex-number class demonstrates arithmetic and stream insertion for an RLC impedance example.

## Important submission note

The `.txt` files contain outputs from compiling and running these programs in the preparation environment. The `.png` files are generated terminal-style renderings of those captured outputs; they are **not photographs of the student's laptop screen**. The assignment brief also requires the student to execute every task individually, perform the specified investigations (including sanitizer/timing/prediction activities where required), and commit progressively. Complete those required experiments and replace/add genuine local screenshots before final submission if your faculty requires them.

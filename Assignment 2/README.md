# DSA01-192421010-Assignment2

**Student name:** [Enter your name]  
**Register number:** [Enter your register number]  
**Compiler:** g++ (Debian 14.2.0-19)  
**Language standard:** C++17  
**Compile command:** `g++ -std=c++17 -Wall -Wextra qN.cpp -o qN`  
**Run command:** `./qN` (Windows MinGW: `qN.exe`)

## Tasks

| Folder | File | Purpose | Run result |
|---|---|---|---|
| Q1 | q1.cpp | Call by value/reference/pointer, reference return, default arguments and concession functions | output.txt |
| Q2 | q2.cpp | Return by reference, const reference, copy and index | output.txt |
| Q2 | dangling_warning.cpp | Intentionally unsafe dangling-reference example; compile only, do not execute | warning.txt |
| Q3 | q3.cpp | Non-ambiguous overloads and default arguments | output.txt |
| Q4 | q4.cpp | SavingsAccount class with a fixed transaction array | output.txt |
| Q5 | q5.cpp | Static members, Token prediction and array of BusTicket objects | output.txt |
| Q6 | q6.cpp | Friend functions and time comparison | output.txt |
| Q6 | inline_benchmark.cpp | 10,000,000-call inline/non-inline timing test | inline_O0.txt, inline_O2.txt |
| Q7 | q7.cpp | Shift-array versus circular-buffer redesign benchmark | output.txt, output_O2.txt |

## Compile and run each task

From the repository root:

```bash
g++ -std=c++17 -Wall -Wextra Q1/q1.cpp -o Q1/q1 && ./Q1/q1
g++ -std=c++17 -Wall -Wextra Q2/q2.cpp -o Q2/q2 && ./Q2/q2
g++ -std=c++17 -Wall -Wextra Q3/q3.cpp -o Q3/q3 && ./Q3/q3
g++ -std=c++17 -Wall -Wextra Q4/q4.cpp -o Q4/q4 && ./Q4/q4
g++ -std=c++17 -Wall -Wextra Q5/q5.cpp -o Q5/q5 && ./Q5/q5
g++ -std=c++17 -Wall -Wextra Q6/q6.cpp -o Q6/q6 && ./Q6/q6
g++ -std=c++17 -Wall -Wextra Q7/q7.cpp -o Q7/q7 && ./Q7/q7
```

## Additional experiments

```bash
# Q2 warning only; do not execute the resulting program
g++ -std=c++17 -Wall -Wextra -Wreturn-local-addr -c Q2/dangling_warning.cpp -o dangling_warning.o 2> Q2/warning.txt

# Q6 inline timing
g++ -std=c++17 -O0 Q6/inline_benchmark.cpp -o Q6/inline_O0 && ./Q6/inline_O0
g++ -std=c++17 -O2 Q6/inline_benchmark.cpp -o Q6/inline_O2 && ./Q6/inline_O2

# Q7 optimization comparison
g++ -std=c++17 -O2 -Wall -Wextra Q7/q7.cpp -o Q7/q7_O2 && ./Q7/q7_O2
```

## Notes before submission

1. Replace the repository name placeholder with your actual register number.
2. Add your own name, register number and working GitHub URL to the Word report.
3. Run all programs on your own laptop and capture terminal screenshots; text output files are included as reference evidence.
4. Timings vary by computer and system load. Repeat Q6 and Q7 timing tests and report your own measurements if required by your course submission.
5. Commit progressively, at least one commit per task, rather than uploading everything in one final commit.

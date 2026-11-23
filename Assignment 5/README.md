# C++ Assignment 5 – CO5

Student: Kalid A.  
Register Number: 192421010  
Compiler: g++ (GNU C++ compiler; C++17 mode)

## Folder contents
- `PartA/PartA_Answers.md` – Part A design answers and explanations.
- `TaskB1/main.cpp` – Runtime polymorphic hospital bills.
- `TaskB2/main.cpp` – Claim validation, custom exception, logging and rethrowing.
- `TaskB3/benchmark.cpp` – Virtual function, switch and `std::variant` comparison (1,000,000 bills in this run).
- `TaskB4/main.cpp` – Laboratory bill and corporate payer extension.
- `Outputs/` – Captured actual outputs, AddressSanitizer run outputs and prediction files.

## Compile and run
From the `Assignment5_CO5` directory:

```bash
g++ -std=c++17 -Wall -Wextra -O2 TaskB1/main.cpp -o TaskB1/program
./TaskB1/program

g++ -std=c++17 -Wall -Wextra -O2 TaskB2/main.cpp -o TaskB2/program
./TaskB2/program

g++ -std=c++17 -Wall -Wextra -O2 TaskB3/benchmark.cpp -o TaskB3/program
./TaskB3/program

g++ -std=c++17 -Wall -Wextra -O2 TaskB4/main.cpp -o TaskB4/program
./TaskB4/program
```

## AddressSanitizer

```bash
g++ -std=c++17 -Wall -Wextra -fsanitize=address -g TaskB1/main.cpp -o TaskB1/program_asan
./TaskB1/program_asan
```

Repeat for TaskB2 and TaskB4. Captured runs are in `Outputs/`.

## Results summary
- Task B1: OP bill = 1700; IP bill = 47500; combined total = 49200.
- Task B2: Valid claim approved; over-cover claim logged and rethrown; negative amount rejected.
- Task B3: Virtual, switch and variant totals agreed for 1,000,000 bills. Recorded timings are in `Outputs/TaskB3_actual_output.txt` and depend on the machine.
- Task B4: Laboratory bill total = 2500; corporate payer covers 2000 (80%).

## Submission reminder
The captured outputs are from this execution environment. Recompile and run on your own system, add your own terminal screenshots, and record your own benchmark timings before submission. The assignment also requires a GitHub repository named `DSA01-192421010-Assignment5`, with progressive commits and the repository link on the report cover page.

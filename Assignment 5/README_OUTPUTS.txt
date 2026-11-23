ACTUAL PROGRAM OUTPUTS

TaskB1_actual_output.txt: Actual output from compiling and running TaskB1/main.cpp.
TaskB2_actual_output.txt: Actual output from compiling and running TaskB2/main.cpp.
TaskB3_actual_output.txt: Actual output from compiling and running TaskB3/benchmark.cpp. Timing values are specific to the machine/container where it was run and will vary on your computer.
TaskB4_actual_output.txt: Actual output from compiling and running TaskB4/main.cpp.

The *_asan_output.txt files are captured runs compiled with -fsanitize=address. They show the program output and no sanitizer diagnostic was printed in these runs.

The TaskA2, TaskA5 and TaskB2 prediction files contain the expected/predicted outputs for the short output-prediction questions in the assignment. Write predictions before executing those programs as required by the assignment.

Compile command used for normal runs:
g++ -std=c++17 -Wall -Wextra -O2 <source.cpp> -o program

AddressSanitizer command used:
g++ -std=c++17 -Wall -Wextra -fsanitize=address -g <source.cpp> -o program_asan

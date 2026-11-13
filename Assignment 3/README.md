# Assignment 3 – CO3

**Student:** Kalid A.  
**Register Number:** 192421010  
**Course Code:** DSA0117  
**Repository name:** `DSA01-192421010-Assignment3`

## Compiler and build instructions

Compiler used for preparation: GNU g++ (C++17 compatible). Confirm your installed version with `g++ --version`.

Compile each task from the repository root:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic Task01/main.cpp -o task01
./task01
```

Repeat by replacing `Task01` and `task01` with `Task02`/`task02` through `Task07`/`task07`.

For AddressSanitizer (where supported):

```bash
g++ -std=c++17 -Wall -Wextra -fsanitize=address -fno-omit-frame-pointer Task02/main.cpp -o task02_asan
./task02_asan
```

## Task summaries

- **Task01:** Book constructors, constructor delegation, initializer lists and validation of copy count.
- **Task02:** Deep-copy constructor, copy assignment, destructor and self-assignment safety for prescription arrays.
- **Task03:** Dynamic seat map using vector-managed storage, booking/cancellation and object lifetime messages.
- **Task04:** Money arithmetic, comparisons and stream insertion/extraction using integer paise.
- **Task05:** Prefix/postfix increment, comparisons and checked const/non-const playlist indexing.
- **Task06:** Dynamically allocated Text class implementing the Rule of Three, concatenation and comparisons.
- **Task07:** Complex-number arithmetic and an AC impedance example with safe division-by-zero handling.

## Important submission note

The source files were compiled with `g++ -std=c++17 -Wall -Wextra -pedantic` during preparation. You must still execute every task on your own system, capture genuine terminal screenshots, complete your own timing/sanitizer experiments, and commit each task separately. Do not claim benchmark timings or sanitizer results that you have not personally collected.

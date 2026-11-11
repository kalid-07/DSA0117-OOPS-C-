// Intentionally unsafe example for compiler-warning demonstration only.
// Do not call this function or use its returned reference.
int& danglingReference() {
    int local = 42;
    return local; // returning a reference to a local object is invalid
}
int main() { return 0; }

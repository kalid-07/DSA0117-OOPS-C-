#include <iostream>
#include <algorithm>
using namespace std;

int& highestMark(int marks[], int size) {
    int index = 0;
    for (int i = 1; i < size; ++i)
        if (marks[i] > marks[index]) index = i;
    return marks[index];
}

const int& highestMarkReadOnly(const int marks[], int size) {
    int index = 0;
    for (int i = 1; i < size; ++i)
        if (marks[i] > marks[index]) index = i;
    return marks[index];
}

int highestMarkCopy(const int marks[], int size) {
    int highest = marks[0];
    for (int i = 1; i < size; ++i) highest = max(highest, marks[i]);
    return highest;
}

int highestMarkIndex(const int marks[], int size) {
    int index = 0;
    for (int i = 1; i < size; ++i)
        if (marks[i] > marks[index]) index = i;
    return index;
}

int main() {
    int marks[] = {78, 91, 85, 88};
    int size = sizeof(marks) / sizeof(marks[0]);
    cout << "Highest mark: " << highestMark(marks, size) << '\n';
    highestMark(marks, size) += 2;
    cout << "After moderation: " << highestMark(marks, size) << '\n';
    cout << "Read-only highest: " << highestMarkReadOnly(marks, size) << '\n';
    cout << "Copy of highest: " << highestMarkCopy(marks, size) << '\n';
    int index = highestMarkIndex(marks, size);
    cout << "Index of highest: " << index << ", value: " << marks[index] << '\n';
    // Do not return a reference to a local variable: it dangles after function exit.
}

#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

class Book {
    string title;
    string author;
    int copies;
public:
    Book() : Book("Untitled", "Unknown", 0) {}
    explicit Book(const string& t) : Book(t, "Unknown", 0) {}
    Book(const string& t, int c) : Book(t, "Unknown", c) {}
    Book(const string& t, const string& a, int c)
        : title(t), author(a), copies(c) {
        if (copies < 0) throw invalid_argument("Copies cannot be negative");
    }
    void print() const { cout << "Title: " << title << " | Author: " << author << " | Copies: " << copies << '\n'; }
};
int main() {
    Book empty;
    Book donated("The Alchemist");
    Book limited("Wings of Fire", 4);
    Book full("Clean Code", "Robert C. Martin", 3);
    empty.print(); donated.print(); limited.print(); full.print();
    try { Book invalid("Invalid Book", "Nobody", -2); invalid.print(); }
    catch (const invalid_argument& e) { cout << "Rejected: " << e.what() << '\n'; }
}

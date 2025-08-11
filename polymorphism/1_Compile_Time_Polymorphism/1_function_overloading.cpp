#include <iostream>
#include <string>
using namespace std;
class Printer {
public:
    // Overload 1: Takes an integer.
    void print(int i) {
        cout << "Printing an integer: " << i << endl;
    }

    // Overload 2: Takes a double.
    void print(double d) {
        cout << "Printing a double: " << d << endl;
    }

    // Overload 3: Takes a string.
    void print(const string& s) {
        cout << "Printing a string: \"" << s << "\"" << endl;
    }
};

int main() {
    Printer p;
    // The compiler selects the correct 'print' function at COMPILE TIME
    // based on the type of the argument passed.
    p.print(100);
    p.print(3.14159);
    p.print("Hello, C++!");
    return 0;
}
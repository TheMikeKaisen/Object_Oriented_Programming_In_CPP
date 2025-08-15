#include <iostream>
using namespace std;

class Rectangle {
public:
    int length;  // Public data member
    int breadth; // Public data member

    // Constructor to initialize variables
    Rectangle(int len, int brth) : length(len), breadth(brth) {}

    // Function to calculate area
    int getArea() {
        return length * breadth;
    }
};

int main() {
    Rectangle rect1(8, 6); // Create a Rectangle object

    // Accessing data members directly (not yet fully encapsulated/hidden)
    cout << "Initial Length: " << rect1.length << endl;
    cout << "Initial Breadth: " << rect1.breadth << endl;
    cout << "Initial Area: " << rect1.getArea() << endl;

    // Directly modifying data members from outside the class
    rect1.length = -10; // This is problematic! A length cannot be negative.
    cout << "\nAfter direct modification:" << endl;
    cout << "New Length: " << rect1.length << endl;
    cout << "New Area: " << rect1.getArea() << endl; // Area will be negative!

    return 0;
}
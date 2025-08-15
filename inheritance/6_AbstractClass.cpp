#include <iostream>
#include <string>
#include <vector>
using namespace std;

// abstract base class
class Shape {
public:
    string color;

    Shape(string c = "unknown") : color(c) {}

    // Pure virtual function: must be implemented by derived concrete classes
    virtual void draw() const = 0;

    // Non-pure virtual function (can be overridden or used as is)
    virtual void displayColor() const {
        cout << "Color: " << color << endl;
    }

    virtual ~Shape() = default; // Important for polymorphic base classes
};

// Concrete Derived Class 1
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r, string c) : Shape(c), radius(r) {}

    // Must implement the pure virtual draw() function
    void draw() const override {
        cout << "Drawing a Circle with radius " << radius << ". ";
        displayColor(); // Using inherited method
    }
};

// Concrete Derived Class 2
class Square : public Shape {
private:
    double side;
public:
    Square(double s, string c) : Shape(c), side(s) {}

    // Must implement the pure virtual draw() function
    void draw() const override {
        cout << "Drawing a Square with side " << side << ". ";
        displayColor(); // Using inherited method
    }
};

int main() {
    // Shape myShape; // ERROR: Cannot instantiate abstract class

    Circle circle1(5.0, "Red");
    Square square1(7.0, "Blue");

    // Use base class pointers for polymorphic behavior
    vector<Shape*> shapes;
    shapes.push_back(&circle1);
    shapes.push_back(&square1);

    for (const auto& s : shapes) {
        s->draw(); // Calls the appropriate derived class's draw()
    }

    // Example of a class that would still be abstract if draw() was not implemented
    // class IncompleteShape : public Shape {
    //     // No draw() implementation, so IncompleteShape is also abstract
    // };
    // IncompleteShape is; // ERROR: Cannot instantiate abstract class

    return 0;
}
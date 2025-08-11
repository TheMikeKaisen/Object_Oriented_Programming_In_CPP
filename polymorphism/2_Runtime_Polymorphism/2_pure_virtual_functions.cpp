#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Shape {
public:

    // no extra memory is allocated to this function
    // A pure virtual function defines an interface contract.
    // Any derived class MUST implement area().
    virtual double area() = 0;

    // A pure virtual function for getting the shape's name.
    virtual string getName() = 0;

    // Abstract classes can still have regular virtual functions with implementations.
    virtual void draw() {
        cout << "Drawing a " << getName() << " with area " << area() << endl;
    }
    
    // A virtual destructor is essential for any base class with virtual functions.
    virtual ~Shape() {
        cout << "Shape destructor called." << endl;
    }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    
    // Fulfilling the contract: providing an implementation for area().
    double area() override {
        cout << "drawing a circle" << endl;
        return 3.14159 * radius * radius;
    }

    // Fulfilling the contract: providing an implementation for getName().
    string getName() override {
        cout <<  "circle" << endl;
        return "Circle";
    }
};

class Rectangle : public Shape {
private:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}

    // Fulfilling the contract.
    double area() override {
        return width * height;
    }

    string getName() override {
        return "Rectangle";
    }
};

int main() {
    // Shape myShape; // ERROR! Cannot declare variable 'myShape' to be of abstract type 'Shape'. [3, 7]

    // But we can have pointers to it, which is the key to polymorphism. [5, 6]
    vector<Shape*> shapes;
    shapes.push_back(new Circle(10.0));
    shapes.push_back(new Rectangle(5.0, 8.0));
    shapes.push_back(new Circle(2.0));

    // pointer to base class can point to its derived class as well.
    for (Shape* shapePtr : shapes) {
        shapePtr->draw(); // Dynamic 

    // Clean up memory using the base class pointer.
    // The virtual destructor ensures the correct derived destructor is called first.
    for (Shape* shapePtr : shapes) {
        delete shapePtr;
    }

    return 0;
}
}
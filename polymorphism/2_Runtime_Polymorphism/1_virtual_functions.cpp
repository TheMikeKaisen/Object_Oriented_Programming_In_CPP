#include <iostream>
using namespace std;

class Shape {
public:
    // By declaring draw() as virtual, we enable dynamic dispatch (late binding).
    virtual void draw() {
        cout << "Drawing a generic shape." << endl;
    }


    // A virtual destructor is for polymorphic base classes to ensure
    // proper cleanup when objects are deleted via a base class pointer.
    virtual ~Shape() {}
};

class Circle : public Shape {
public:
    // The 'override' specifier is not mandatory but is a modern C++ best practice.
    // It makes the intent clear and asks the compiler to verify that a base
    // class virtual function is indeed being overridden.
    void draw() override {
        cout << "Drawing a circle." << endl;
    }
};

class Square : public Shape {
public:
    void draw() override {
        cout << "Drawing a square." << endl;
    }
};

// This function demonstrates the power of polymorphism. It operates on any object
// that "is-a" Shape, without needing to know its concrete type.
void render(Shape* shapePtr) {
    shapePtr->draw(); // The polymorphic call happens here!
}

int main() {
    Shape s;
    Circle c;
    Square sq;

    cout << "Calling render with a Shape pointer to a Shape object:" << endl;
    render(&s); // Statically, this is a Shape*, but it points to a Shape. Calls Shape::draw().

    cout << "\nCalling render with a Shape pointer to a Circle object:" << endl;
    render(&c); // At runtime, this resolves to Circle::draw().

    cout << "\nCalling render with a Shape pointer to a Square object:" << endl;
    render(&sq); // At runtime, this resolves to Square::draw().

    return 0;
}
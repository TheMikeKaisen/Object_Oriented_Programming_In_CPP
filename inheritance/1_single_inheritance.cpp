#include <iostream>
using namespace std;

// Base class
class Animal {
public:
    void eat() {
        cout << "I can eat!" << endl;
    }
    void sleep() {
        cout << "I can sleep!" << endl;
    }
};

// Derived class: Dog inherits publicly from Animal
class Dog : public Animal {
public:
    void bark() {
        cout << "I can bark! Woof woof!!" << endl;
    }
};

int main() {
    Dog dog1; // Create an object of the derived class

    // Calling members inherited from the base class (Animal)
    dog1.eat();
    dog1.sleep();

    // Calling a member specific to the derived class (Dog)
    dog1.bark();

    return 0;
}
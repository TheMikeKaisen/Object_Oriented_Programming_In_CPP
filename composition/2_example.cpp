#include <iostream>
#include <string>
using namespace std;

class Engine {
public:
    Engine() {
        cout << "Engine constructed." << endl;
    }
    void start() {
        cout << "Engine starting..." << endl;
    }
    void stop() {
        cout << "Engine stopping..." << endl;
    }
    ~Engine() {
        cout << "Engine destroyed." << endl;
    }
};

class Car {
private:
    Engine engine; // Composition: Car HAS-A Engine
    string model;
public:
    Car(string m) : model(m) {
        cout << "Car " << model << " created." << endl;
    }
    void drive() {
        engine.start();
        cout << "Driving " << model << endl;
    }
    ~Car() {
        engine.stop();
        cout << "Car " << model << " destroyed." << endl;
    }
};

int main() {
    Car myCar("Sedan");
    myCar.drive();
    // When myCar goes out of scope, its destructor is called,
    // which in turn calls the engine's destructor.
    return 0;
}

// output:
/*
Engine constructed.
Car Sedan created.
Engine starting...
Driving Sedan
Engine stopping...
Car Sedan destroyed.
Engine destroyed.
*/

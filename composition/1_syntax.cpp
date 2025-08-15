#include <iostream>
using namespace std;

class Engine {
public:
    void start() { 
        cout << "Engine is starting..." << endl;
     }
};

class Car {
private:
    Engine engine; // Car HAS-A Engine
    string model;
public:
    Car(string m) : model(m) {}
    void drive() {
        engine.start(); // Car uses its Engine
        cout << "Driving " << model << endl;
    }
};
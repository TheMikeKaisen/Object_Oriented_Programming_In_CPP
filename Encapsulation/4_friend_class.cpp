#include <iostream>
using namespace std;

class Engine;

class Car {
private:
    int fuel = 50;

    // Make Engine a friend class
    friend class Engine;
};

class Engine {
public:
    void checkFuel(Car &c) {
        cout << "Fuel level: " << c.fuel << endl;
    }
};

int main() {
    Car myCar;
    Engine e;
    e.checkFuel(myCar); // Output: Fuel level: 50
}

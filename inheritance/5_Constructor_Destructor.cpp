#include <iostream>
using namespace std;

// Scenario 1: Base class destructor is NOT virtual
class BaseNonVirtual {
public:
    BaseNonVirtual() { cout << "BaseNonVirtual Constructor" << endl; }
    ~BaseNonVirtual() { cout << "BaseNonVirtual Destructor" << endl; } // NOT virtual
};

class DerivedNonVirtual : public BaseNonVirtual {
public:
    int* data; // Resource that needs cleanup
    DerivedNonVirtual() {
        cout << "DerivedNonVirtual Constructor" << endl;
        data = new int(10); // Allocate memory
    }
    ~DerivedNonVirtual() {
        cout << "DerivedNonVirtual Destructor" << endl;
        delete data; // Deallocate memory
        data = nullptr;
    }
};

// Scenario 2: Base class destructor IS virtual
class BaseVirtual {
public:
    BaseVirtual() { cout << "BaseVirtual Constructor" << endl; }
    virtual ~BaseVirtual() { cout << "BaseVirtual Destructor" << endl; } // IS virtual
};

class DerivedVirtual : public BaseVirtual {
public:
    int* data; // Resource that needs cleanup
    DerivedVirtual() {
        cout << "DerivedVirtual Constructor" << endl;
        data = new int(20); // Allocate memory
    }
    ~DerivedVirtual() {
        cout << "DerivedVirtual Destructor" << endl;
        delete data; // Deallocate memory
        data = nullptr;
    }
};

int main() {
    cout << "--- Scenario 1: Non-Virtual Destructor ---" << endl;
    BaseNonVirtual* ptr1 = new DerivedNonVirtual(); // Base pointer to Derived object
    delete ptr1; // Only BaseNonVirtual destructor called, memory leak!
    cout << "Memory leak likely occurred above if DerivedNonVirtual allocated resources." << endl;

    cout << "\n--- Scenario 2: Virtual Destructor ---" << endl;
    BaseVirtual* ptr2 = new DerivedVirtual(); // Base pointer to Derived object
    delete ptr2; // Both DerivedVirtual and BaseVirtual destructors called, no leak!

    return 0;
}
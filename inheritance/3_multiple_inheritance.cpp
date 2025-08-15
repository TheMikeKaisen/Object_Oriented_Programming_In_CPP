#include <iostream>
#include <string>
using namespace std;

// Base class 1
class Father {
public:
    string fatherTrait = "Strong";
    void displayFatherTrait() {
        cout << "Father's trait: " << fatherTrait << endl;
    }
};

// Base class 2
class Mother {
public:
    string motherTrait = "Caring";
    void displayMotherTrait() {
        cout << "Mother's trait: " << motherTrait << endl;
    }
};

// Derived class inheriting from both Father and Mother
class Child : public Father, public Mother {
public:
    string childTrait = "Creative";
    void displayChildTraits() {
        cout << "Child's own trait: " << childTrait << endl;
        // Accessing inherited traits
        displayFatherTrait();
        displayMotherTrait();
    }
};

int main() {
    Child myChild;
    myChild.displayChildTraits();
    return 0;
}
#include <iostream>using namespace std;

// Base class - Level 1
class Grandfather {
public:
    void tellGrandpaStory() {
        cout << "Grandfather: I remember the old days..." << endl;
    }
};

// Derived class (Level 2): Father inherits from Grandfather
class Father : public Grandfather {
public:
    void teachLifeLesson() {
        cout << "Father: Son, let me teach you a life lesson." << endl;
    }
};

// Derived from derived class (Level 3): Child inherits from Father
class Child : public Father {
public:
    void playGames() {
        cout << "Child: Time to play games!" << endl;
    }
};

int main() {
    Child obj; // Create object of the most derived class

    // Child object can access its own methods
    obj.playGames();

    // Child object can access methods from its direct parent (Father)
    obj.teachLifeLesson();

    // Child object can access methods from its grandparent (Grandfather)
    obj.tellGrandpaStory();

    return 0;
}
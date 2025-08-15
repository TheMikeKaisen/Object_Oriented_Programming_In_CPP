#include <iostream>
#include <string>
using namespace std;

// Grandparent Class
class Person {
public:
    string name;
    Person(string n = "Unknown") : name(n) {
        cout << "Person Constructor: " << name << endl;
    }
    void greet() const {
        cout << "Hello, I am " << name << "." << endl;
    }
    virtual ~Person() { cout << "Person Destructor: " << name << endl; }
};

// Parent Class 1, virtually inheriting Person
class Student : virtual public Person {
public:
    int studentID;
    Student(string n = "", int id = 0) : Person(n), studentID(id) { // Person constructor called by most derived class
        cout << "Student Constructor: ID " << studentID << endl;
    }
    void study() const {
        cout << name << " (ID: " << studentID << ") is studying." << endl;
    }
    virtual ~Student() { cout << "Student Destructor: ID " << studentID << endl; }
};

// Parent Class 2, virtually inheriting Person
class Teacher : virtual public Person {
public:
    string subject;
    Teacher(string n = "", string s = "") : Person(n), subject(s) { // Person constructor called by most derived class
        cout << "Teacher Constructor: Subject " << subject << endl;
    }
    void teach() const {
        cout << name << " (Subject: " << subject << ") is teaching." << endl;
    }
    virtual ~Teacher() { cout << "Teacher Destructor: Subject " << subject << endl; }
};

// Child Class, inheriting from Student and Teacher
class TeachingAssistant : public Student, public Teacher {
public:
    int hoursPerWeek;
    // The Person constructor is called ONLY ONCE by the most derived class (TeachingAssistant)
    TeachingAssistant(string n, int id, string s, int h)
        : Person(n), Student(n, id), Teacher(n, s), hoursPerWeek(h) {
        cout << "TeachingAssistant Constructor: Hours " << hoursPerWeek << endl;
    }
    void assist() const {
        cout << name << " is assisting for " << hoursPerWeek << " hours/week." << endl;
    }
    virtual ~TeachingAssistant() { cout << "TeachingAssistant Destructor: Hours " << hoursPerWeek << endl; }
};

int main() {
    // Without virtual inheritance, accessing 'name' or 'greet()' would be ambiguous
    // and 'Person' constructor would be called twice.
    TeachingAssistant ta("Alice", 101, "Math", 20);

    ta.greet(); // Now unambiguous
    ta.study();
    ta.teach();
    ta.assist();

    // Observe constructor and destructor call order with virtual inheritance
    // Person constructor called once by TeachingAssistant
    // Destructors called in reverse order: TA -> Student -> Teacher -> Person
    return 0;
}
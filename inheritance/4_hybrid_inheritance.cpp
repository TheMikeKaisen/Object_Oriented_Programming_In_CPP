#include <iostream>
#include <string>
using namespace std;

// Base class (Grandparent)
class Person {
public:
    string name;
    int age;
    Person(string n = "", int a = 0) : name(n), age(a) {}
    void displayPersonInfo() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

// Derived class 1 (Parent 1) - inherits from Person
class Student : public Person {
public:
    int studentID;
    Student(string n = "", int a = 0, int id = 0) : Person(n, a), studentID(id) {}
    void displayStudentInfo() {
        displayPersonInfo(); // Inherited
        cout << "Student ID: " << studentID << endl;
    }
};

// Derived class 2 (Parent 2) - inherits from Person
class Teacher : public Person {
public:
    string subject;
    Teacher(string n = "", int a = 0, string s = "") : Person(n, a), subject(s) {}
    void displayTeacherInfo() {
        displayPersonInfo(); // Inherited
        cout << "Subject: " << subject << endl;
    }
};

// Derived class (Child) - inherits from both Student and Teacher (Multiple Inheritance)
// This setup creates a "Diamond Problem" for 'Person' members if not handled with virtual inheritance
class TeachingAssistant : public Student, public Teacher {
public:
    int hoursPerWeek;
    TeachingAssistant(string n = "", int a = 0, int id = 0, string s = "", int h = 0)
        : Student(n, a, id), Teacher(n, a, s), hoursPerWeek(h) {
        // Note: 'name' and 'age' from Person are inherited twice here,
        // once via Student and once via Teacher. This causes ambiguity
        // if not resolved with virtual inheritance (discussed later).
        // For now, we'll initialize them through both parents, but direct
        // access to 'name' or 'age' would be ambiguous.
    }

    void displayTAInfo() {
        cout << "\n--- Teaching Assistant Info ---" << endl;
        // Ambiguity for 'name' and 'age' if not using virtual inheritance.
        // Must use scope resolution to specify which path to take:
        Student::displayPersonInfo(); // Access Person info via Student path
        // Teacher::displayPersonInfo(); // Access Person info via Teacher path (would be duplicate)
        cout << "Student ID: " << studentID << endl;
        cout << "Subject: " << subject << endl;
        cout << "Hours per week: " << hoursPerWeek << endl;
    }
};

int main() {
    TeachingAssistant ta("John Doe", 25, 12345, "Computer Science", 15);
    ta.displayTAInfo();

    // To access ambiguous members, scope resolution is needed:
    cout << "TA's name (via Student path): " << ta.Student::name << endl;
    cout << "TA's age (via Teacher path): " << ta.Teacher::age << endl;

    return 0;
}
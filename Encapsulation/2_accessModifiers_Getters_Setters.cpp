#include <iostream>
#include <string>
using namespace std;
class Employee {
private:
    string name;
    int employeeID;
    double salary; // private
    
    public:
    // Constructor
    Employee(string empName, int empID, double empSalary) {
        name = empName;
        employeeID = empID;
        setSalary(empSalary); // Use setter for initial validation
    }

    // Getter for name (read-only)
    string getName() const { // 'const' indicates this method doesn't modify the object
        return name;
    }

    // Getter for employeeID (read-only)
    int getEmployeeID() const {
        return employeeID;
    }

    // Getter for salary (read-only)
    double getSalary() const {
        return salary;
    }

    // Setter for salary (controlled write access with validation)
    void setSalary(double newSalary) {
        if (newSalary >= 0) { // Validation: Salary cannot be negative
            salary = newSalary;
            cout << "Salary updated successfully to: " << salary << endl;
        } else {
            cout << "Error: Invalid salary amount. Salary must be non-negative." << endl;
        }
    }

    // Display employee information
    void displayEmployeeInfo() const {
        cout << "\n--- Employee Details ---" << endl;
        cout << "Name: " << name << endl;
        cout << "ID: " << employeeID << endl;
        cout << "Salary: $" << salary << endl;
    }
};

int main() {
    Employee emp1("Alice Smith", 1001, 60000.0);
    emp1.displayEmployeeInfo();

    // setting an invalid salary
    emp1.setSalary(-500.0);
    emp1.displayEmployeeInfo(); // Salary remains unchanged due to validation

    // Setting a valid salary
    emp1.setSalary(65000.0);
    emp1.displayEmployeeInfo();

    // Direct access attempt (will fail)
    // emp1.salary = 100000.0; // Compilation error: 'salary' is private

    return 0;
}
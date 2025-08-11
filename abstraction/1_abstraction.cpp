#include<iostream>
using namespace std;

class BankAccount {
private:
    double balance; // balance is hidden from the outside world

public:
    BankAccount(double initialBalance) {
        if (initialBalance >= 0) {
            balance = initialBalance;
        } else {
            balance = 0;
        }
    }

    // Interface: A public method to deposit money.
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposit successful." << std::endl;
        } else {
            std::cout << "Deposit amount must be positive." << std::endl;
        }
    }

    // Interface: A public method to withdraw money, with validation.
    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful." << std::endl;
            return true; // Success
        }
        cout << "Withdrawal failed. Invalid amount or insufficient funds." << std::endl;
        return false; // Failure
    }

    // view the balance.
    double getBalance() const {
        return balance;
    }
};

int main() {
    BankAccount myAccount(1000.0);

    myAccount.deposit(500.0);
    cout << "Balance after deposit: $" << myAccount.getBalance() << endl;

    myAccount.withdraw(200.0);
    cout << "Balance after withdrawal: $" << myAccount.getBalance() << endl;

    // compiler error because 'balance' is private.
    // myAccount.balance = 50000.0; // This is prevented by abstraction!

    return 0;
}
#include <iostream>
#include <string>
using namespace std;

// Base Account class
class Account {
private:
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    // Constructor to initialize account holder name & balance
    Account(int accNum, const string& name, double bal)
        : accountNumber(accNum), accountHolderName(name), balance(bal) {}

    // Method to deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    // Method to withdraw money
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        } else {
            cout << "Invalid withdraw amount or insufficient funds." << endl;
        }
    }

    // Method to display account details
    virtual void display() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder Name: " << accountHolderName << endl;
        cout << "Balance: " << balance << endl;
    }

    // Getter for balance
    double getBalance() const {
        return balance;
    }

    // Setter for balance (used in derived class)
    void setBalance(double bal) {
        balance = bal;
    }
};

// Derived SavingsAccount class
class SavingsAccount : public Account {
private:
    double interestRate;

public:
    // Constructor to initialize account number, account holder name, balance and interest rate
    SavingsAccount(int accNum, const string& name, double bal, double rate)
        : Account(accNum, name, bal), interestRate(rate) {}

    // Method to calculate and add interest to the balance
    void addInterest() {
        double interest = getBalance() * (interestRate / 100);
        deposit(interest);
        cout << "Interest added: " << interest << endl;
    }

    // Override display method to include interest rate information
    void display() const override {
        Account::display();
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};

int main() {
    // Create a SavingsAccount object
    SavingsAccount savAcc(12345, "ABC", 10000.0, 5.0);

    // Display account details
    savAcc.display();

    // Deposit money
    savAcc.deposit(5000.0);

    // Withdraw money
    savAcc.withdraw(2000.0);

    // Add interest
    savAcc.addInterest();

    // Display updated account details
    savAcc.display();

    return 0;
}

#include <iostream>
using namespace std;

class ATM
{
private:
    double balance;
    int pin;

public:
    
    ATM(double initialBalance, int userPin)
    {
        balance = initialBalance;
        pin = userPin;
    }

    bool verifyPIN(int enteredPin)
    {
        return pin == enteredPin;
    }
  
    void checkBalance()
    {
        cout << "Your current balance is: $" << balance << endl;
    }

    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "$" << amount << " has been deposited." << endl;
        }
        else
        {
            cout << "Invalid amount!" << endl;
        }
    }

    
    void withdraw(double amount)
    {
        if (amount > balance)
        {
            cout << "Insufficient balance!" << endl;
        }
        else if (amount > 0)
        {
            balance -= amount;
            cout << "$" << amount << " has been withdrawn." << endl;
        }
        else
        {
            cout << "Invalid amount!" << endl;
        }
    }
};

int main()
{
    
    ATM myATM(1000.00, 1234);
    int enteredPin, option;
    double amount;

    cout << "Welcome to the ATM!\n";

    
    cout << "Please enter your PIN: ";
    cin >> enteredPin;

    if (!myATM.verifyPIN(enteredPin))
    {
        cout << "Incorrect PIN. Exiting.\n";
        return 0;
    }

    while (true)
    {
        
        cout << "\nATM Menu:\n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Exit\n";
        cout << "Choose an option: ";
        cin >> option;

        switch (option)
        {
        case 1:
            myATM.checkBalance();
            break;
        case 2:
            cout << "Enter amount to deposit: ";
            cin >> amount;
            myATM.deposit(amount);
            break;
        case 3:
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            myATM.withdraw(amount);
            break;
        case 4:
            cout << "Thank you for using the ATM. Goodbye!\n";
            return 0;
        default:
            cout << "Invalid option. Please try again.\n";
        }
    }

    return 0;
}

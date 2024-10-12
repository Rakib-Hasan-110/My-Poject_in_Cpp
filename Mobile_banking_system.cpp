#include <iostream>
#include <string>
using namespace std;


class MobileBanking
{
private:
    string userName;
    string accountNumber;
    double balance;
    int pin;

public:
    
    MobileBanking(string name, string accNumber, double initialBalance, int userPin)
    {
        userName = name;
        accountNumber = accNumber;
        balance = initialBalance;
        pin = userPin;
    }

    
    bool verifyPIN(int enteredPin)
    {
        return pin == enteredPin;
    }

    
    void displayAccountInfo()
    {
        cout << "Account Holder: " << userName << endl;
        cout << "Account Number: " << accountNumber << endl;
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
            cout << "$" << amount << " has been deposited into your account." << endl;
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
            cout << "$" << amount << " has been withdrawn from your account." << endl;
        }
        else
        {
            cout << "Invalid amount!" << endl;
        }
    }

    
    void transferMoney(string recipientAccount, double amount)
    {
        if (amount > balance)
        {
            cout << "Insufficient balance to transfer!" << endl;
        }
        else if (amount > 0)
        {
            balance -= amount;
            cout << "$" << amount << " has been transferred to account " << recipientAccount << "." << endl;
        }
        else
        {
            cout << "Invalid amount!" << endl;
        }
    }
};

int main()
{
    
    MobileBanking myAccount("John Doe", "123456789", 5000.00, 1234);

    int enteredPin, option;
    double amount;
    string recipientAccount;

    cout << "Welcome to Mobile Banking!\n";

    
    cout << "Please enter your PIN: ";
    cin >> enteredPin;

    if (!myAccount.verifyPIN(enteredPin))
    {
        cout << "Incorrect PIN. Exiting.\n";
        return 0;
    }

    while (true)
    {
        
        cout << "\nMobile Banking Menu:\n";
        cout << "1. View Account Info\n";
        cout << "2. Check Balance\n";
        cout << "3. Deposit Money\n";
        cout << "4. Withdraw Money\n";
        cout << "5. Transfer Money\n";
        cout << "6. Exit\n";
        cout << "Choose an option: ";
        cin >> option;

        switch (option)
        {
        case 1:
            myAccount.displayAccountInfo();
            break;
        case 2:
            myAccount.checkBalance();
            break;
        case 3:
            cout << "Enter amount to deposit: ";
            cin >> amount;
            myAccount.deposit(amount);
            break;
        case 4:
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            myAccount.withdraw(amount);
            break;
        case 5:
            cout << "Enter recipient's account number: ";
            cin >> recipientAccount;
            cout << "Enter amount to transfer: ";
            cin >> amount;
            myAccount.transferMoney(recipientAccount, amount);
            break;
        case 6:
            cout << "Thank you for using Mobile Banking. Goodbye!\n";
            return 0;
        default:
            cout << "Invalid option. Please try again.\n";
        }
    }

    return 0;
}

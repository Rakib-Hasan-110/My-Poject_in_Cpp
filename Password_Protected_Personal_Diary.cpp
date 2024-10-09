#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Diary {
public:
    virtual void addEntry(const string& entry) = 0; 
    virtual void viewEntries(const string& password) = 0; 
    virtual ~Diary() {} 
};

class PasswordProtectedDiary : public Diary {
private:
    string password;
    vector<string> entries;

public:
    PasswordProtectedDiary(const string& pass) : password(pass) {}

    void addEntry(const string& entry) override {
        entries.push_back(entry);
    }

    void viewEntries(const string& pass) override {
        if (pass == password) {
            cout << "Diary Entries:" << endl;
            for (const auto& entry : entries) {
                cout << "- " << entry << endl;
            }
        } else {
            cout << "Incorrect password. Access denied!" << endl;
        }
    }
};

int main() {
    string password;
    cout << "Set a password for your diary: ";
    cin >> password;

    PasswordProtectedDiary myDiary(password);

    while (true) {
        cout << "\n1. Add Entry\n2. View Entries\n3. Exit\nChoose an option: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            string entry;
            cout << "Enter your diary entry: ";
            cin.ignore(); 
            getline(cin, entry);
            myDiary.addEntry(entry);
        } else if (choice == 2) {
            string pass;
            cout << "Enter your password to view entries: ";
            cin >> pass;
            myDiary.viewEntries(pass);
        } else if (choice == 3) {
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

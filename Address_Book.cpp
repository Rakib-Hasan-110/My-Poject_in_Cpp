#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Contact
{
private:
    string name;
    string phoneNumber;
    string email;

public:
    
    Contact(string n, string p, string e) : name(n), phoneNumber(p), email(e) {}

    
    string getName() const
    {
        return name;
    }

    string getPhoneNumber() const
    {
        return phoneNumber;
    }

    string getEmail() const
    {
        return email;
    }

    
    void displayContact() const
    {
        cout << "Name: " << name << "\nPhone Number: " << phoneNumber << "\nEmail: " << email << endl;
    }
};


class AddressBook
{
private:
    vector<Contact> contacts; 

public:
    
    void addContact(const string &name, const string &phoneNumber, const string &email)
    {
        contacts.push_back(Contact(name, phoneNumber, email));
    }

    
    void viewContacts() const
    {
        if (contacts.empty())
        {
            cout << "No contacts available!" << endl;
        }
        else
        {
            for (size_t i = 0; i < contacts.size(); i++)
            {
                cout << "\nContact " << i + 1 << ":\n";
                contacts[i].displayContact();
            }
        }
    }

    
    void searchContact(const string &name) const
    {
        bool found = false;
        for (const auto &contact : contacts)
        {
            if (contact.getName() == name)
            {
                cout << "\nContact found:\n";
                contact.displayContact();
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "Contact not found." << endl;
        }
    }
};

int main()
{
    AddressBook myAddressBook;
    int choice;

    while (true)
    {
        cout << "\n1. Add Contact\n2. View All Contacts\n3. Search Contact\n4. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        if (choice == 1)
        {
            cin.ignore(); 
            string name, phoneNumber, email;
            cout << "Enter Name: ";
            getline(cin, name);
            cout << "Enter Phone Number: ";
            getline(cin, phoneNumber);
            cout << "Enter Email: ";
            getline(cin, email);
            myAddressBook.addContact(name, phoneNumber, email);
        }
        else if (choice == 2)
        {
            myAddressBook.viewContacts();
        }
        else if (choice == 3)
        {
            cin.ignore(); 
            string name;
            cout << "Enter the name of the contact to search: ";
            getline(cin, name);
            myAddressBook.searchContact(name);
        }
        else if (choice == 4)
        {
            cout << "Exiting the address book." << endl;
            break;
        }
        else
        {
            cout << "Invalid option! Please try again." << endl;
        }
    }

    return 0;
}

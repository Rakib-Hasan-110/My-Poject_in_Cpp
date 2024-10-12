#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Medicine
{
public:
    string name;
    double price;
    int quantity;

public:
    Medicine(string n, double p, int q) : name(n), price(p), quantity(q) {}

    virtual void displayInfo() = 0;
    virtual double calculateTotalCost(int purchaseQuantity) = 0;
};

class Tablet : public Medicine
{
public:
    Tablet(string n, double p, int q) : Medicine(n, p, q) {}

    void displayInfo() override
    {
        cout << "Tablet Name: " << name << "\nPrice: " << price << "\nQuantity in Stock: " << quantity << endl;
    }

    double calculateTotalCost(int purchaseQuantity) override
    {
        if (purchaseQuantity <= quantity)
        {
            return purchaseQuantity * price;
        }
        else
        {
            cout << "Not enough stock available!" << endl;
            return 0.0;
        }
    }
};

class Syrup : public Medicine
{
public:
    Syrup(string n, double p, int q) : Medicine(n, p, q) {}

    void displayInfo() override
    {
        cout << "Syrup Name: " << name << "\nPrice: " << price << "\nQuantity in Stock: " << quantity << endl;
    }

    double calculateTotalCost(int purchaseQuantity) override
    {
        if (purchaseQuantity <= quantity)
        {
            return purchaseQuantity * price;
        }
        else
        {
            cout << "Not enough stock available!" << endl;
            return 0.0;
        }
    }
};

class PharmacyManagement
{
private:
    vector<Medicine *> inventory;

public:
    void addMedicine(Medicine *med)
    {
        inventory.push_back(med);
    }

    void showInventory()
    {
        cout << "\nAvailable Medicines:\n";
        for (Medicine *med : inventory)
        {
            med->displayInfo();
            cout << "------------------------\n";
        }
    }

    void purchaseMedicine(string medName, int quantity)
    {
        for (Medicine *med : inventory)
        {
            if (medName == med->name)
            {
                double totalCost = med->calculateTotalCost(quantity);
                if (totalCost > 0)
                {
                    cout << "Total cost: $" << totalCost << endl;
                    med->quantity -= quantity;
                }
                return;
            }
        }
        cout << "Medicine not found!" << endl;
    }
};

int main()
{
    PharmacyManagement pharmacy;

    pharmacy.addMedicine(new Tablet("Paracetamol", 0.50, 100));
    pharmacy.addMedicine(new Syrup("Cough Syrup", 5.0, 50));

    int choice;
    string medName;
    int quantity;

    while (true)
    {
        cout << "\nPharmacy Management System\n";
        cout << "1. View Inventory\n";
        cout << "2. Purchase Medicine\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            pharmacy.showInventory();
            break;
        case 2:
            cout << "Enter medicine name: ";
            cin >> medName;
            cout << "Enter quantity to purchase: ";
            cin >> quantity;
            pharmacy.purchaseMedicine(medName, quantity);
            break;
        case 3:
            cout << "Exiting system...\n";
            return 0;
        default:
            cout << "Invalid choice, please try again.\n";
        }
    }

    return 0;
}

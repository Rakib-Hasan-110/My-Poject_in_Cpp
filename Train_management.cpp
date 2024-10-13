#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Train
{
private:
    string trainName;
    string source;
    string destination;
    int trainNumber;
    int availableSeats;

public:
    Train(string name, string src, string dest, int num, int seats)
        : trainName(name), source(src), destination(dest), trainNumber(num), availableSeats(seats) {}

    string getTrainName()
    {
        return trainName;
    }

    int getTrainNumber()
    {
        return trainNumber;
    }

    string getSource()
    {
        return source;
    }

    string getDestination()
    {
        return destination;
    }

    int getAvailableSeats()
    {
        return availableSeats;
    }

    void displayDetails()
    {
        cout << "Train Name: " << trainName << "\n"
             << "Train Number: " << trainNumber << "\n"
             << "Source: " << source << "\n"
             << "Destination: " << destination << "\n"
             << "Available Seats: " << availableSeats << endl;
    }

    void bookSeats(int seats)
    {
        if (seats <= availableSeats)
        {
            availableSeats -= seats;
            cout << seats << " seat(s) successfully booked!" << endl;
        }
        else
        {
            cout << "Not enough available seats!" << endl;
        }
    }
};

class TrainManagementSystem
{
private:
    vector<Train> trains;

public:
    void addTrain(string name, string src, string dest, int number, int seats)
    {
        Train newTrain(name, src, dest, number, seats);
        trains.push_back(newTrain);
    }

    void displayAllTrains()
    {
        cout << "\nList of Trains:\n";
        for (Train &train : trains)
        {
            train.displayDetails();
            cout << "-----------------------\n";
        }
    }

    Train *searchTrainByNumber(int number)
    {
        for (Train &train : trains)
        {
            if (train.getTrainNumber() == number)
            {
                return &train;
            }
        }
        return nullptr;
    }
};

int main()
{
    TrainManagementSystem system;
    int option, trainNumber, seats;
    string name, source, destination;

    while (true)
    {

        cout << "\nTrain Management System\n";
        cout << "1. Add Train\n";
        cout << "2. View All Trains\n";
        cout << "3. Search Train by Number\n";
        cout << "4. Book Seats\n";
        cout << "5. Exit\n";
        cout << "Choose an option: ";
        cin >> option;

        switch (option)
        {
        case 1:

            cout << "Enter Train Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Source Station: ";
            getline(cin, source);
            cout << "Enter Destination Station: ";
            getline(cin, destination);
            cout << "Enter Train Number: ";
            cin >> trainNumber;
            cout << "Enter Available Seats: ";
            cin >> seats;
            system.addTrain(name, source, destination, trainNumber, seats);
            cout << "Train added successfully!\n";
            break;

        case 2:

            system.displayAllTrains();
            break;

        case 3:

            cout << "Enter Train Number: ";
            cin >> trainNumber;
            if (Train *train = system.searchTrainByNumber(trainNumber))
            {
                train->displayDetails();
            }
            else
            {
                cout << "Train not found!\n";
            }
            break;

        case 4:

            cout << "Enter Train Number: ";
            cin >> trainNumber;
            if (Train *train = system.searchTrainByNumber(trainNumber))
            {
                cout << "Enter number of seats to book: ";
                cin >> seats;
                train->bookSeats(seats);
            }
            else
            {
                cout << "Train not found!\n";
            }
            break;

        case 5:

            cout << "Exiting Train Management System. Goodbye!\n";
            return 0;

        default:
            cout << "Invalid option. Please try again.\n";
        }
    }

    return 0;
}

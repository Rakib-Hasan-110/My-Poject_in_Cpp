#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class Date
{
private:
    int day;
    int month;
    int year;

public:
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    void display() const
    {
        cout << setfill('0') << setw(2) << day << "/"
             << setfill('0') << setw(2) << month << "/"
             << year;
    }

    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }
};

class Event
{
private:
    string title;
    Date date;

public:
    Event(const string &t, const Date &d) : title(t), date(d) {}

    void display() const
    {
        cout << "Event: " << title << " on ";
        date.display();
        cout << endl;
    }

    Date getDate() const { return date; }
};

class Calendar
{
private:
    vector<Event> events;

public:
    void addEvent(const string &title, const Date &date)
    {
        events.emplace_back(title, date);
    }

    void displayEvents() const
    {
        if (events.empty())
        {
            cout << "No events scheduled." << endl;
            return;
        }
        cout << "Scheduled Events:" << endl;
        for (const auto &event : events)
        {
            event.display();
        }
    }

    void displayEventsOnDate(const Date &date) const
    {
        bool found = false;
        cout << "Events on ";
        date.display();
        cout << ":" << endl;
        for (const auto &event : events)
        {
            if (event.getDate().getDay() == date.getDay() &&
                event.getDate().getMonth() == date.getMonth() &&
                event.getDate().getYear() == date.getYear())
            {
                event.display();
                found = true;
            }
        }
        if (!found)
        {
            cout << "No events scheduled on this date." << endl;
        }
    }
};

int main()
{
    Calendar calendar;
    int choice;

    do
    {
        cout << "\n--- Calendar Menu ---\n";
        cout << "1. Add Event\n";
        cout << "2. View All Events\n";
        cout << "3. View Events on Specific Date\n";
        cout << "4. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string title;
            int day, month, year;

            cout << "Enter event title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter date (dd mm yyyy): ";
            cin >> day >> month >> year;

            Date date(day, month, year);
            calendar.addEvent(title, date);
            cout << "Event added successfully." << endl;
            break;
        }
        case 2:
            calendar.displayEvents();
            break;
        case 3:
        {
            int day, month, year;
            cout << "Enter date (dd mm yyyy): ";
            cin >> day >> month >> year;

            Date date(day, month, year);
            calendar.displayEventsOnDate(date);
            break;
        }
        case 4:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}

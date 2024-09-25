#include <iostream>
using namespace std;

class AgeCalculator
{
private:
    int birthYear, birthMonth, birthDay;
    int currentYear, currentMonth, currentDay;

    int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    bool isLeapYear(int year)
    {
        if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
            return true;
        return false;
    }

public:
    AgeCalculator(int bYear, int bMonth, int bDay,
                  int cYear, int cMonth, int cDay)
    {
        birthYear = bYear;
        birthMonth = bMonth;
        birthDay = bDay;
        currentYear = cYear;
        currentMonth = cMonth;
        currentDay = cDay;

        if (isLeapYear(birthYear))
            daysInMonth[1] = 29;
    }

    int calculateDayDifference()
    {
        int dayDiff = currentDay - birthDay;
        if (dayDiff < 0)
        {
            currentMonth--;
            dayDiff += daysInMonth[(birthMonth - 1) % 12];
        }
        return dayDiff;
    }

    int calculateMonthDifference()
    {
        int monthDiff = currentMonth - birthMonth;
        if (monthDiff < 0)
        {
            monthDiff += 12;
            currentYear--;
        }
        return monthDiff;
    }

    int calculateYearDifference()
    {
        return currentYear - birthYear;
    }

    void displayAge()
    {
        int dayDiff = calculateDayDifference();
        int monthDiff = calculateMonthDifference();
        int yearDiff = calculateYearDifference();

        cout << "Your age is: " << yearDiff << " years, "
             << monthDiff << " months, and " << dayDiff << " days." << endl;
    }
};

int main()
{
    int birthYear, birthMonth, birthDay;
    int currentYear, currentMonth, currentDay;

    cout << "Enter your birth year: ";
    cin >> birthYear;
    cout << "Enter your birth month (1-12): ";
    cin >> birthMonth;
    cout << "Enter your birth day: ";
    cin >> birthDay;

    cout << "Enter the current year: ";
    cin >> currentYear;
    cout << "Enter the current month (1-12): ";
    cin >> currentMonth;
    cout << "Enter the current day: ";
    cin >> currentDay;

    AgeCalculator ageCalculator(birthYear, birthMonth, birthDay,
                                currentYear, currentMonth, currentDay);

    ageCalculator.displayAge();

    return 0;
}

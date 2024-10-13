#include <iostream>
using namespace std;

double celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32;
}

double celsiusToKelvin(double celsius) {
    return celsius + 273.15;
}

double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0;
}

double fahrenheitToKelvin(double fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0 + 273.15;
}

double kelvinToCelsius(double kelvin) {
    return kelvin - 273.15;
}

double kelvinToFahrenheit(double kelvin) {
    return (kelvin - 273.15) * 9.0 / 5.0 + 32;
}

int main() {
    int choice;
    double temp, result;
    
    cout << "Temperature Converter:\n";
    cout << "1. Celsius to Fahrenheit\n";
    cout << "2. Celsius to Kelvin\n";
    cout << "3. Fahrenheit to Celsius\n";
    cout << "4. Fahrenheit to Kelvin\n";
    cout << "5. Kelvin to Celsius\n";
    cout << "6. Kelvin to Fahrenheit\n";
    cout << "Choose an option: ";
    cin >> choice;
    
    cout << "Enter temperature: ";
    cin >> temp;
    
    switch(choice) {
        case 1:
            result = celsiusToFahrenheit(temp);
            cout << temp << " Celsius is " << result << " Fahrenheit\n";
            break;
        case 2:
            result = celsiusToKelvin(temp);
            cout << temp << " Celsius is " << result << " Kelvin\n";
            break;
        case 3:
            result = fahrenheitToCelsius(temp);
            cout << temp << " Fahrenheit is " << result << " Celsius\n";
            break;
        case 4:
            result = fahrenheitToKelvin(temp);
            cout << temp << " Fahrenheit is " << result << " Kelvin\n";
            break;
        case 5:
            result = kelvinToCelsius(temp);
            cout << temp << " Kelvin is " << result << " Celsius\n";
            break;
        case 6:
            result = kelvinToFahrenheit(temp);
            cout << temp << " Kelvin is " << result << " Fahrenheit\n";
            break;
        default:
            cout << "Invalid option\n";
    }
    
    return 0;
}

#include <iostream>
using namespace std;

class CurrencyConverter
{
public:
    CurrencyConverter()
    {
        currencies[0] = ("USD", "usd"); //US Dollar
        exchangeRates[0] = 119.68;
        currencies[1] = ("EUR", "eur"); //Euro
        exchangeRates[1] = 133.29;
        currencies[2] = ("GBP", "gbp"); //British Pound
        exchangeRates[2] = 158.65;
        currencies[3] = ("JPY", "jpy"); //Japanese Yen
        exchangeRates[3] = 0.83;
        currencies[4] = ("AUD", "aud"); //Australian Dollar
        exchangeRates[4] = 81.56;
        currencies[5] = ("CAD", "cad"); //Canadian Dollar
        exchangeRates[5] = 88.23;
        currencies[6] = ("CHF", "chf"); //Swiss Franc
        exchangeRates[6] = 140.91;
        currencies[7] = ("CNY", "cny"); //Chinese Yuan
        exchangeRates[7] = 16.93;
        currencies[8] = ("ZAR", "zar"); //South African Rand
        exchangeRates[8] = 6.87;
        currencies[9] = ("INR", "inr"); //Indian Rupee
        exchangeRates[9] = 1.43;
        currencies[10] = ("BDT", "bdt"); //Bangladeshi Taka
        exchangeRates[10] = 1;
        currencies[11] = ("RUB", "rub"); //Russian Ruble
        exchangeRates[11] = 1.29;
    }

    double convert(const string &from, const string &to, double amount)
    {
        double fromRate = 0, toRate = 0;

        for (int i = 0; i < 12; ++i)
        {
            if (currencies[i] == from)
            {
                fromRate = exchangeRates[i];
            }
            if (currencies[i] == to)
            {
                toRate = exchangeRates[i];
            }
        }
        if (fromRate == 0 || toRate == 0)
        {
            cout << "Invalid currency code.\n";
            return 0;
        }
        return amount * (fromRate / toRate);
    }

private:
    string currencies[12];
    double exchangeRates[12];
};

int main()
{
    CurrencyConverter converter;
    string fromCurrency, toCurrency;
    double amount;

    cout << "(USD) - United States Dollar" << endl;
    cout << "(EUR) - Euro (European Union)" << endl;
    cout << "(GBP) - British Pound Sterling" << endl;
    cout << "(JPY) - Japanese Yen" << endl;
    cout << "(AUD) - Australian Dollar" << endl;
    cout << "(CAD) - Canadian Dollar" << endl;
    cout << "(CHF) - Swiss Franc" << endl;
    cout << "(CNY) - Chinese Yuan" << endl;
    cout << "(ZAR) - South African Rand" << endl;
    cout << "(INR) - Indian Rupee" << endl;
    cout << "(BDT) - Bangladeshi Taka" << endl;
    cout << "(RUB) - Russian Ruble" << endl << endl;

    cout << "Enter the currency to convert from: ";
    cin >> fromCurrency;
    cout << "Enter the currency to convert to: ";
    cin >> toCurrency;
    cout << "Enter the amount: ";
    cin >> amount;

    double convertedAmount = converter.convert(fromCurrency, toCurrency, amount);

    if (convertedAmount != 0)
    {
        cout << amount << " " << fromCurrency << " is equivalent to " << convertedAmount 
        << " " << toCurrency << endl;
    }
    else
    {
        cout << "Conversion failed. Please check the currency codes.\n";
    }
    return 0;
}

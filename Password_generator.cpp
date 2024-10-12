#include <iostream>
#include <cstdlib>   
#include <ctime>  
#include <string>

using namespace std;

class PasswordGenerator {
    int length;
    string charPool;

public:
    PasswordGenerator(int len, bool upper, bool lower, bool numbers, bool special)
        : length(len) {
        if (upper) charPool += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        if (lower) charPool += "abcdefghijklmnopqrstuvwxyz";
        if (numbers) charPool += "0123456789";
        if (special) charPool+="!@#$%^&*()_+[]{}|;:,.<>?";
    }

    string generate() const {
        if (charPool.empty()) return "No character sets selected.";
        string password;
        for (int i = 0; i < length; i++)
            password += charPool[rand() % charPool.length()];
        return password;
    }
};

int main() {
    srand(static_cast<unsigned int>(time(0))); 
    int length;
    bool upper, lower, numbers, special;

    cout << "Password Length: "; cin >> length;
    cout << "Include Uppercase (1/0): "; cin >> upper;
    cout << "Include Lowercase (1/0): "; cin >> lower;
    cout << "Include Numbers (1/0): "; cin >> numbers;
    cout << "Include Special Characters (1/0): "; cin >> special;

    PasswordGenerator generator(length, upper, lower, numbers, special);
    cout << "Generated Password: " << generator.generate() << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class NumberGuessingGame {
private:     //Encapsulation
    int num; 
    int tries;

public:
    NumberGuessingGame() {
        srand(time(0));  
        num = (rand() % 100) + 1;
        tries = 0;
    }

    void play() {
        int guess;
        cout << "******Number guessing game*****" << endl;
        do {
            cout << "Enter a guess between 1-100: ";
            cin >> guess;
            tries++;

            if (guess > num) {
                cout << "Too high" << endl;
            } else if (guess < num) {
                cout << "Too low" << endl;
            } else {
                cout << "CORRECT! Number of tries: " << tries << endl;
            }
        } while (guess != num);
    }
};

int main() {
    NumberGuessingGame game;
    game.play();
    return 0;
}

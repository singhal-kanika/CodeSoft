#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand(time(0));
    int numberToGuess = rand() % 100 + 1;
    int userGuess = 0;

    cout << "Welcome to the Guess the Number Game!" << endl;
    cout << "I have selected a random number between 1 and 100." << endl;

    while (userGuess != numberToGuess)
    {
        cout << "Enter your guess: ";

        if (!(cin >> userGuess))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Please enter a valid integer." << endl;
            continue;
        }

        if (userGuess < numberToGuess)
        {
            cout << "Too low! Try again." << endl;
        }
        else if (userGuess > numberToGuess)
        {
            cout << "Too high! Try again." << endl;
        }
        else
        {
            cout << "Congratulations! You guessed the correct number." << endl;
        }
    }

    return 0;
}

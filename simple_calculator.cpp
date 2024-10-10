#include <iostream>
using namespace std;

int main()
{
    double num1, num2;
    char operation;

    cout << "Enter first number: ";
    while (!(cin >> num1))
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Please enter a valid number: ";
    }

    cout << "Enter second number: ";
    while (!(cin >> num2))
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Please enter a valid number: ";
    }

    cout << "Choose an operation (+, -, *, /): ";
    cin >> operation;

    switch (operation)
    {
    case '+':
        cout << "Result: " << num1 + num2 << endl;
        break;
    case '-':
        cout << "Result: " << num1 - num2 << endl;
        break;
    case '*':
        cout << "Result: " << num1 * num2 << endl;
        break;
    case '/':
        if (num2 != 0)
        {
            cout << "Result: " << num1 / num2 << endl;
        }
        else
        {
            cout << "Error: Division by zero is not allowed." << endl;
        }
        break;
    default:
        cout << "Error: Invalid operation selected. Please choose from (+, -, *, /)." << endl;
        break;
    }

    return 0;
}

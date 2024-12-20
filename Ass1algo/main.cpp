#include <iostream>
#include "Fibonacci.h"
using namespace std;
int main() {
    Fibonacci fibonacci;
    int n;
    int choice;

    cout << "Enter the Fibonacci term you want to calculate: ";
    cin >> n;

    cout << "Choose a method to calculate Fibonacci:\n";
    cout << "1. Matrix Exponentiation\n";
    cout << "2. Recursive\n";
    cout << "3. Dynamic Programming\n";
    cout << "Enter your choice (1, 2, or 3): ";
    cin >> choice;

    int result;
    switch (choice) {
        case 1:
            result = fibonacci.fibMatrix(n);
            cout << "Fibonacci (Matrix): " << result << endl;
            break;
        case 2:
            result = fibonacci.fibRecursive(n);
            cout << "Fibonacci (Recursive): " << result << endl;
            break;
        case 3:
            result = fibonacci.fibDP(n);
            cout << "Fibonacci (DP): " << result << endl;
            break;
        default:
            cout << "Invalid choice. Please enter 1, 2, or 3." << endl;
            break;
    }

    return 0;
}

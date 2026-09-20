#include <iostream>
using namespace std;

// ==================================================
// FACTORIAL
// ==================================================
int factorial(int n)
{
    // Base case
    if (n == 0)
    {
        return 1;
    }

    // Recursive case
    return n * factorial(n - 1);
}

// ==================================================
// FACTORIAL WITH TRACE (SHOWS CALL STACK BEHAVIOR)
// ==================================================
int factorialTrace(int n)
{
    cout << "Entering factorial(" << n << ")" << endl;

    if (n == 0)
    {
        cout << "Base case reached: factorial(0) = 1" << endl;
        return 1;
    }

    int result = n * factorialTrace(n - 1);

    cout << "Returning from factorial(" << n
         << ") = " << result << endl;

    return result;
}

// ==================================================
// RECURSIVE ARRAY SUM
// ==================================================
int sumArray(int arr[], int size)
{
    // Base case
    if (size == 0)
    {
        return 0;
    }

    // Recursive case
    return arr[0] + sumArray(arr + 1, size - 1);
}

// ==================================================
// RECURSIVE ARRAY SUM WITH TRACE
// ==================================================
int sumArrayTrace(int arr[], int size)
{
    if (size == 0)
    {
        cout << "No elements left -> return 0" << endl;
        return 0;
    }

    cout << "Processing element: " << arr[0] << endl;

    int result = arr[0] + sumArrayTrace(arr + 1, size - 1);

    cout << "Current sum including "
         << arr[0] << " = " << result << endl;

    return result;
}

// ==================================================
// TOWER OF HANOI
// ==================================================
void hanoi(int n, char from, char to, char aux)
{
    // Base case
    if (n == 1)
    {
        cout << "Move disc 1 from "
             << from << " to "
             << to << endl;
        return;
    }

    // Move n-1 discs to helper rod
    hanoi(n - 1, from, aux, to);

    // Move largest disc
    cout << "Move disc "
         << n << " from "
         << from << " to "
         << to << endl;

    // Move n-1 discs to destination
    hanoi(n - 1, aux, to, from);
}

// ==================================================
// COUNT HANOI MOVES (2^n - 1)
// ==================================================
int countMoves(int n)
{
    if (n == 1)
    {
        return 1;
    }

    return 2 * countMoves(n - 1) + 1;
}

// ==================================================
// MAIN
// ==================================================
int main()
{
    int choice;

    do
    {
        cout << "\n=====================================";
        cout << "\n      RECURSION DEMONSTRATION";
        cout << "\n=====================================";
        cout << "\n1. Factorial";
        cout << "\n2. Factorial (Call Stack Trace)";
        cout << "\n3. Sum of Array";
        cout << "\n4. Sum of Array (Trace)";
        cout << "\n5. Tower of Hanoi";
        cout << "\n6. Exit";
        cout << "\nChoose: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int n;
            cout << "\nEnter n: ";
            cin >> n;

            cout << n << "! = "
                 << factorial(n)
                 << endl;
            break;
        }

        case 2:
        {
            int n;
            cout << "\nEnter n: ";
            cin >> n;

            cout << "\n--- Recursive Trace ---\n";
            int result = factorialTrace(n);

            cout << "\nFinal Answer = "
                 << result << endl;
            break;
        }

        case 3:
        {
            int arr[] = {10, 20, 30, 40};
            int size = 4;

            cout << "\nArray: {10, 20, 30, 40}";
            cout << "\nSum = "
                 << sumArray(arr, size)
                 << endl;
            break;
        }

        case 4:
        {
            int arr[] = {10, 20, 30, 40};
            int size = 4;

            cout << "\n--- Recursive Trace ---\n";

            int result = sumArrayTrace(arr, size);

            cout << "\nFinal Sum = "
                 << result << endl;
            break;
        }

        case 5:
        {
            int discs;

            cout << "\nEnter number of discs: ";
            cin >> discs;

            cout << "\nMoves:\n";

            hanoi(discs, 'A', 'C', 'B');

            cout << "\nMinimum moves = "
                 << countMoves(discs)
                 << endl;

            cout << "(Matches formula: 2^n - 1)"
                 << endl;

            break;
        }

        case 6:
            cout << "\nProgram ended.\n";
            break;

        default:
            cout << "\nInvalid choice.\n";
        }

    } while (choice != 6);

    return 0;
}

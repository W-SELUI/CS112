#include <iostream>
using namespace std;

// Print a 1D array
void printMarks(const int marks[], int size) {
    for (int i = 0; i < size; i++) {
        cout << marks[i] << " ";
    }
    cout << endl;
}

// Add 5 bonus marks to each score
void addBonus(int marks[], int size) {
    for (int i = 0; i < size; i++) {
        marks[i] += 5;
    }
}

// Print a 2D array
void printTable(const int table[][3], int rows) {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < 3; c++) {
            cout << table[r][c] << " ";
        }
        cout << endl;
    }
}

int main() {
    const int SIZE = 5;

    int marks[SIZE] = {70, 85, 90, 65, 78};

    cout << "Original marks: ";
    printMarks(marks, SIZE);

    // Modify one element
    marks[1] = 88;

    int sum = 0;
    int maximum = marks[0];

    for (int i = 0; i < SIZE; i++) {
        sum += marks[i];

        if (marks[i] > maximum) {
            maximum = marks[i];
        }
    }

    double average = (double)sum / SIZE;

    cout << "Sum: " << sum << endl;
    cout << "Average: " << average << endl;
    cout << "Maximum: " << maximum << endl;

    // Linear search
    int target = 90;
    int foundIndex = -1;

    for (int i = 0; i < SIZE; i++) {
        if (marks[i] == target) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1)
        cout << target << " found at index " << foundIndex << endl;
    else
        cout << target << " not found" << endl;

    // Modify the array using a function
    addBonus(marks, SIZE);

    cout << "Marks after bonus: ";
    printMarks(marks, SIZE);

    // 2D array
    int studentMarks[2][3] = {
        {80, 75, 90},
        {65, 88, 72}
    };

    cout << "\nStudent marks table:" << endl;
    printTable(studentMarks, 2);

    return 0;
}

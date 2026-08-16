#include <iostream>
using namespace std;

// Modify a variable using a pointer
void changeValue(int *p) {
    *p = 100;
}

// Swap two variables using pointers
void swapValues(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Print an array using a pointer
void printArray(const int *arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}

int main() {

    // Basic pointer
    int age = 20;
    int *p = &age;

    cout << "Age: " << age << endl;
    cout << "Address: " << p << endl;
    cout << "Value through pointer: " << *p << endl;

    // Modify value through pointer
    *p = 25;
    cout << "New age: " << age << endl;

    // Pass pointer to a function
    changeValue(&age);
    cout << "After function: " << age << endl;

    // Pointer and array
    int numbers[4] = {10, 20, 30, 40};
    int *ptr = numbers;

    cout << "\nArray using pointer: ";
    printArray(numbers, 4);

    cout << "First element: " << *ptr << endl;
    cout << "Second element: " << *(ptr + 1) << endl;

    // Swap using pointers
    int x = 5;
    int y = 10;

    cout << "\nBefore swap: " << x << " " << y << endl;

    swapValues(&x, &y);

    cout << "After swap: " << x << " " << y << endl;

    // nullptr
    int *empty = nullptr;

    if (empty == nullptr) {
        cout << "\nPointer is empty" << endl;
    }

    // Dynamic memory
    int size = 5;
    int *dynamicArray = new int[size];

    for (int i = 0; i < size; i++) {
        dynamicArray[i] = (i + 1) * 10;
    }

    cout << "Dynamic array: ";
    printArray(dynamicArray, size);

    delete[] dynamicArray;
    dynamicArray = nullptr;

    // Pointer to pointer
    int number = 50;
    int *firstPointer = &number;
    int **secondPointer = &firstPointer;

    cout << "Pointer to pointer value: " << **secondPointer << endl;

    return 0;
}

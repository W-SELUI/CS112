#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    // Attributes (Variables hidden inside the class)
    string name;
    int mark;

public:
    // 1. Default Constructor (Sets safe starting values)
    Student() {
        name = "Unknown";
        mark = 0;
        cout << "[Default Constructor Called]" << endl;
    }

    // 2. Parameterized Constructor (Sets specific values right away)
    Student(string initialName, int initialMark) {
        name = initialName;
        mark = initialMark;
        cout << "[Parameterized Constructor Called]" << endl;
    }

    // 3. Setters (Functions to change private data later)
    void setName(string newName) {
        name = newName;
    }

    void setMark(int newMark) {
        // Setters are great because you can block bad data!
        if (newMark >= 0 && newMark <= 100) {
            mark = newMark;
        } else {
            cout << "Error: Invalid mark entered!" << endl;
        }
    }

    // 4. Getters (Functions to look at private data)
    string getName() {
        return name;
    }

    int getMark() {
        return mark;
    }
};

int main() {
    // --- EXAMPLE 1: Using the Default Constructor & Setters/Getters ---
    cout << "--- Creating Student 1 ---" << endl;
    Student s1; // Uses default constructor

    // Change data using Setters
    s1.setName("Alice");
    s1.setMark(95);

    // Read data using Getters paired with cout
    cout << "Student 1 Name: " << s1.getName() << endl;
    cout << "Student 1 Mark: " << s1.getMark() << endl;
    cout << endl;

    // --- EXAMPLE 2: Using the Parameterized Constructor ---
    cout << "--- Creating Student 2 ---" << endl;
    // Uses parameterized constructor to skip the setters entirely
    Student s2("Bob", 88); 

    // Read data using Getters paired with cout
    cout << "Student 2 Name: " << s2.getName() << endl;
    cout << "Student 2 Mark: " << s2.getMark() << endl;

    return 0;
}


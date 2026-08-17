#include <iostream>
#include <string>
using namespace std;

struct Address {
    string city;
    string island;
};

struct Student {
    string name;
    int id;
    double gpa;
    Address home;
};

void printStudent(const Student &s) {
    cout << "Name: " << s.name << endl;
    cout << "ID: " << s.id << endl;
    cout << "GPA: " << s.gpa << endl;
    cout << "City: " << s.home.city << endl;
    cout << "Island: " << s.home.island << endl;
    cout << endl;
}

void giveBonus(Student &s) {
    s.gpa += 0.1;

    if (s.gpa > 4.0) {
        s.gpa = 4.0;
    }
}

void changeName(Student s) {
    s.name = "Changed Name";
}

int main() {

    Student s1 = {"Mele", 11244878, 3.7, {"Suva", "Viti Levu"}};

    cout << "Single Student" << endl;
    printStudent(s1);

    giveBonus(s1);

    cout << "After GPA Bonus" << endl;
    printStudent(s1);

    changeName(s1);

    cout << "After Passing by Value" << endl;
    cout << s1.name << endl << endl;

    Student students[3] = {
        {"Mele", 11244878, 3.8, {"Suva", "Viti Levu"}},
        {"Sione", 11244879, 3.2, {"Nuku'alofa", "Tongatapu"}},
        {"Ana", 11244880, 3.9, {"Lautoka", "Viti Levu"}}
    };

    cout << "All Students" << endl;

    for (int i = 0; i < 3; i++) {
        printStudent(students[i]);
    }

    Student *ptr = &students[0];

    cout << "Using Pointer" << endl;
    cout << "Name: " << ptr->name << endl;
    cout << "GPA: " << ptr->gpa << endl;
    cout << "City: " << ptr->home.city << endl;

    return 0;
}

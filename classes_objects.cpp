#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int id;
    int mark;

public:
    Student(string n, int i, int m) {
        name = n;
        id = i;
        mark = m;
    }

    void setMark(int m) {
        if (m >= 0 && m <= 100) {
            mark = m;
        }
    }

    int getMark() {
        return mark;
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Mark: " << mark << endl;
        cout << endl;
    }
};

int main() {

    Student s1("William", 11244878, 85);
    Student s2("Mele", 11244879, 92);

    cout << "Student 1" << endl;
    s1.display();

    cout << "Student 2" << endl;
    s2.display();

    s1.setMark(90);

    cout << "Student 1 after mark update" << endl;
    s1.display();

    cout << "Student 1 mark: " << s1.getMark() << endl;

    return 0;
}

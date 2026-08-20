#include <iostream>

using namespace std;

class Student{
    private:
    string name;
    int id;

    public:
    Student(){
        cout << "Student has been created" << endl;
    }

    public:
    void display(){
        cout << "Student has been created" << endl;
    }
};

int main(){
    Student s1;

    s1.display();

    return 0;
}


/*
#include <iostream>

using namespace std;

class Student{
    private:
        string name;
        int mark;

    public:
        void setMark(int m){
            mark = m;
        }

        int getMark(){
            return mark;
        }

};

int main(){

    Student s1;

    s1.setMark(80);

    cout << s1.getMark();



}
*/

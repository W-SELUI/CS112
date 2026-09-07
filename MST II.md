
**Section A: Trace the Output**
For each program, write down exactly what is printed to the screen

1. Trace the output

```c++
void swap(int a, int b){

    int temp = a;

    a = b;

    b = temp;

}

int main(){

    int x = 3, y = 8;

    swap(x, y);

    cout << x << " " << y;

}
```

Output: 

2. Trace the output

```c++
int nums[4] = {10, 20, 30, 40};

int *ptr = nums + 1;

cout << *ptr << " " << *(ptr + 2);
```

Output: 

3. Trace the output

```c++
class Counter{

    public:

        static int total;

        Counter(){ total++; }

};

int Counter::total = 0;

int main(){

    Counter a, b, c;

    cout << Counter::total;

}
```

Output: 

4. Trace the output

```c++
class Base{

    public:

        void greet(){ cout << "Base"; }

};

class Derived: public Base{

    public:

        void greet(){ cout << "Derived"; }

};

int main(){

    Base *b = new Derived();

    b->greet();

}
```

Output: 


---

**Section B: True or False(Justify each answer in one sentence)**

1. Passing an array to a function in C++ always makes a full copy of the array 

WHY? 

2. A class can have more than one constructor as long as their parameter lists differ

WHY?

3. Protected members of a base class can be accessed directly by objects of the derived class from the outside class.

WHY?

4.  A pure virtual function must still have a function body inside the class that declares it

WHY?

5. A struct in C++ can contain member functions, just like a class

WHY? 

---

**Section C: Program Writing**

1. Find and Fix the Bug
The following class is meant to represent a bank account, but it will not compile. Identify every line with a problem, explain why it's wrong and state your fix

```c++
class Account{                     // line 1

    int balance;

    Account(int startingBalance){

        balance = startingBalance;

    }

    void deposit(int amount){

        balance = balance + amount;

    }

};                                  // line 11

int main(){

    Account acc(100);

    acc.deposit(50);

    cout << acc.balance;

}
```

Line(s) with a problem: 
Why is it wrong ? 
Your fix : 


2. Complete your class
Shape is an abstract base class. Complete the Triangle class below so it compiles and correctly overrides the abstract method, then show how to call it through a Shape pointer.

```c++
class Shape{

    public:

        virtual float area() = 0;

        virtual void describe(){

            cout << "Area: " << area();

        }

};

class Triangle: public Shape{

    public:

        float base, height;

        Triangle(float b, float h){

            // TODO: initialise base and height

        }

        // TODO: implement area() -> 0.5 * base * height

};

int main(){

    Shape *s;

    // TODO: point s at a Triangle with base 6 and height 4,

    // then call describe() through s

}
```

a. Why must Triangle provide an implementation of area( ) before it can be instantiated?

b. Complete the Triangle constructor and the area( ) method.

c. Write the missing lines in main( ) to create the Triangle on the heap, point s at it and call describe( )


3. Structs and Pointers

Consider the following code
```c++
#include <iostream>

using namespace std;

struct Employee{

    int id;

    string name;

    float salary;

};

int main(){

    Employee e[4] = {

            {301, "Sam", 950.50},

            {302, "Ana", 1200.00},

            {303, "Ben", 875.25},

            {304, "Mia", 1100.75}

        };

        //To Do

};
```

Task : Complete main( ) using a pointer (not array indexing with [ ] to move through the Employee array and print the name and salary of every employee whose salary is above 1000.)


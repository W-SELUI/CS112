
1. The Three Pillars of OOP - Quick Review
Before diving in, here's the big picture. Each pillar solves a different problem:

●        Encapsulation — protecting an object's data, only allowing controlled access. (We already met this via private/public.)

●        Inheritance — letting one class reuse and extend another class instead of rewriting everything from scratch.

●        Polymorphism — letting the SAME function call behave differently depending on the actual object involved.

 A rough mental order: encapsulation protects data inside ONE class, inheritance connects MULTIPLE classes together, and polymorphism is what makes those connected classes flexible to work with

----

2. Encapsulation - Quick Recap

Encapsulation just means bundling data and the methods that work on it together, and hiding the data from direct outside access. You already used this last week with private and public.

```c++
class Student {

private:

    int mark;         // hidden -- encapsulated

public:

    void setMark(int m) { mark = m; }   // controlled access

    int getMark() { return mark; }

};
```

Explanation: mark is protected from being set to something invalid directly (s.mark = -50; is blocked). Outside code has to go through setMark(), which COULD include a check like 'reject marks below 0' — that's the real value of encapsulation: control, not just hiding for its own sake.

🎯 Exam hint: If a question asks 'what OOP concept does private + getters/setters demonstrate?' — the answer is encapsulation

---

3. Inheritance

Inheritance lets you create a NEW class based on an EXISTING class. The new class (called the derived class or child class) automatically gets all the attributes and methods of the existing class (called the base class or parent class), and can add its own on top.

The classic test for whether inheritance makes sense: the 'is-a' relationship. A Lecturer IS A Person. A Dog IS AN Animal. A SavingsAccount IS AN Account.

3.1 Basic Syntax

```c++
class Base {

    // shared attributes and methods

};

class Derived : public Base {

    // extra attributes and methods, PLUS everything from Base

};
```

Explanation: class Derived : public Base means 'Derived inherits publicly from Base'. Every object of type Derived automatically has everything Base has, without needing to rewrite it


3.2 Worked Example

```c++
#include <iostream>

using namespace std;

class Person {

protected:

    string name;

public:

    void setName(string n) { name = n; }

    void display() { cout << "Name: " << name << endl; }

};

class Student : public Person {

private:

    int mark;

public:

    void setMark(int m) { mark = m; }

    void showMark() { cout << "Mark: " << mark << endl; }

};

int main() {

    Student s1;

    s1.setName("William");   // inherited from Person

    s1.setMark(85);           // Student's own method

    s1.display();             // inherited from Person

    s1.showMark();            // Student's own method

    return 0;

}

```

Explanation: Student never defines setName() or display() itself — it gets them for free by inheriting from Person. s1 can call BOTH inherited methods and its own new methods, because a Student object IS a Person, with extras added on top.

3.3 Protected - "the middle ground" access specifier

You'll notice name is protected, not private. protected behaves like private (hidden from outside code) EXCEPT derived classes are still allowed to access it directly.

```
private:    accessible only inside the SAME class

protected:  accessible inside the same class AND any class that inherits from it

public:     accessible from anywhere
```

🎯 Exam hint: If a base class needs a derived class to reach a member directly (not just through a public method), that member should be protected, not private. This is a common exam distinction

3.4 Constructors and Inheritance

When a derived object is created, the BASE class's constructor runs first automatically, then the derived class's constructor runs.

```c++
class Person {

public:

    Person() { cout << "Person constructor" << endl; }

};

class Student : public Person {

public:

    Student() { cout << "Student constructor" << endl; }

};

int main() {

    Student s1;

    // Output:

    // Person constructor

    // Student constructor

}
```

Explanation: it makes sense in order — the base part of the object has to be built before the derived part can add anything on top of it. This 'base first, then derived' order always holds.

---

4. Polymorphism

Polymorphism means 'many forms' — the same function call can behave differently depending on which object it's actually working with. There are two kinds you'll typically meet at this level.

4.1 Compile-time polymorphism — function overloading

Multiple functions with the SAME name but DIFFERENT parameters. The compiler decides which one to use based on what you pass in.

```c++
#include <iostream>

using namespace std;

class Calculator {

public:

    int add(int a, int b) {

        return a + b;

    }

    double add(double a, double b) {

        return a + b;

    }

};

int main() {

    Calculator c;

    cout << c.add(2, 3) << endl;       // uses int version -> 5

    cout << c.add(2.5, 3.5) << endl;   // uses double version -> 6

    return 0;

}
```

Explanation: both methods are called add, but they have different parameter types. The compiler looks at what you passed in (two ints vs two doubles) and picks the matching version automatically — this decision happens at COMPILE time, before the program even runs.

🎯 Exam hint: Overloading = same name, different parameter list (type or number of parameters). If the parameter list is identical, it's not valid overloading — the compiler won't know which one you mean.

4.2 Run-time polymorphism - function overriding + virtual functions

This is the more powerful form. A derived class provides its OWN version of a method that already exists in the base class — this is called overriding. Combined with a base class pointer/reference, C++ decides WHICH version to run while the program is actually running

```c++
#include <iostream>

using namespace std;

class Animal {

public:

    virtual void speak() {

        cout << "The animal makes a sound" << endl;

    }

};

class Dog : public Animal {

public:

    void speak() override {          // overriding the base version

        cout << "The dog barks" << endl;

    }

};

class Cat : public Animal {

public:

    void speak() override {

        cout << "The cat meows" << endl;

    }

};

int main() {

    Animal *a1 = new Dog();

    Animal *a2 = new Cat();

    a1->speak();   // "The dog barks"

    a2->speak();   // "The cat meows"

    delete a1;

    delete a2;

    return 0;

}
```

Explanation: a1 and a2 are both DECLARED as Animal pointers, but they actually POINT TO a Dog and a Cat. Because speak() is marked virtual in the base class, C++ looks at runtime what the object ACTUALLY is, and calls that version instead of the base one. Without virtual, both calls would print the generic Animal message, no matter what they point to.

💡 virtual on the base class method is what turns this feature on. override on the derived version isn't strictly required, but it's good practice — it makes your intent clear and the compiler will warn you if you got the function signature wrong.

---

5. Common Mistakes and Exam Tips

●        Forgetting public when inheriting: class Student : public Person — leaving public out changes the inheritance type and is rarely what you want at this level.

●        Using private instead of protected when a derived class actually needs direct access to a base member.

●        Forgetting virtual on the base class method, then being confused why overriding 'isn't working' through a base pointer.

●        Confusing overloading (same name, different parameters, decided at compile time) with overriding (same name AND same parameters, redefined in a derived class, decided at run time).

●        Assuming a base class object automatically behaves like its derived version — polymorphism only kicks in through pointers/references PLUS virtual, not with plain objects

⚠ Overloading vs overriding is one of the most commonly mixed-up pairs of terms in OOP. Overloading = multiple versions in the SAME class, different parameters. Overriding = a derived class REPLACES a base class method, same name and parameters

---

6. Putting it ALL Together

```
ENCAPSULATION

  Protects data inside ONE class (private/protected + public methods)

INHERITANCE

  class Derived : public Base

  "Derived IS A Base, plus extra stuff"

  Base constructor runs first, then Derived's

POLYMORPHISM

  Overloading  -> same name, different parameters, compile-time

  Overriding   -> same name+parameters, redefined in Derived, needs 'virtual'

  Animal *a = new Dog();  a->speak();  -> runs Dog's version at run-time
```

If you can explain these three ideas in your own words with a simple example each, you've got a solid grip on OOP at this level

---

7. Quick Reference Summary

●        Encapsulation: hide data (private/protected), expose controlled access (public getters/setters).

●        Inheritance: class Derived : public Base;      Derived gets everything Base has, plus its own additions.

●        Access levels: private (class only) < protected (class + derived classes) < public (everyone).

●        Constructor order in inheritance: Base constructor runs first, then Derived's.

●        Overloading: same method name, different parameter list, resolved at compile time.

●        Overriding: derived class redefines a base method with the SAME signature; base method must be virtual.

Runtime polymorphism pattern: ``BaseType *ptr = new DerivedType(); ptr->method();`` 
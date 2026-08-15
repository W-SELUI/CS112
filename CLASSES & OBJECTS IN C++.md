_A Beginner-to-Intermediate Guide_

CS111 PASS Session Resource 

Compiled by William Selui, PASS Leader | University of the South Pacific

This document covers the basics of Classes and Objects in C++ — the building blocks of object-oriented programming (OOP). If you're comfortable with structs, this will feel very familiar: a class is basically a struct with functions attached, plus control over what the outside world can see. Each concept comes with a simple example, a plain-English explanation, and exam hints to help spot these patterns in tests.

---

 1. What Is a Class? What Is an Object?
A class is a BLUEPRINT. It describes what something looks like and what it can do, but on its own it isn't a real, usable 'thing' yet. An object is what you get when you actually build something FROM that blueprint — a real, usable instance.

```c++
class Student {

    // attributes and methods go here

};

Student s1;   // s1 is an OBJECT built from the Student blueprint

Student s2;   // s2 is a completely separate object, same blueprint
```

Explanation: class Student {...}; just defines what a Student looks like — it creates no actual data. Student s1; and Student s2; each create a real, independent object. s1 and s2 both follow the same blueprint, but changing s1's data has no effect on s2.

The blueprint picture
```
CLASS

               Student

              /        \

             /          \

         OBJECT        OBJECT

           s1             s2
```

 Exam hint: If you see "Student s1;" — is Student an object? NO. Student is the class (the type). s1 is the object. This exact distinction shows up constantly in tests, so get comfortable naming which is which

---

2. Attributes and Methods — What an Object HAS vs DOES

Every class is really just two kinds of things bundled together: data (attributes) and behavior (methods).

●        Attributes describe what the object HAS — its data, its properties.

●        Methods describe what the object DOES — its actions, its functions.


Example: breaking down a Student
```
Student

HAS (attributes):

  - name

  - id

  - mark

DOES (methods):

  - display()

  - calculateGPA()

  - updateMark()
```

Explanation: before writing any code, it helps to sort the class requirements into these two buckets. Anything that sounds like a NOUN or a piece of information (name, mark, balance) is an attribute. Anything that sounds like a VERB or an action (display, calculate, update) is a method.

 Putting it into code
```c++
#include <iostream>

using namespace std;

class Student {

private:

    string name;

    int mark;

public:

    void display() {

        cout << name << " " << mark << endl;

    }

};
```

Explanation: name and mark are the attributes — they sit above, describing what a Student HAS. display() is a method — it sits below, describing what a Student DOES. This separation of data and functions is the core shape of every class you'll write.

Exam hint: If an exam question says "create a class called X with attributes A, B and methods C, D" — immediately sketch class X { }; first, then sort the given items into a HAS list and a DOES list before writing anything else._

---

 3. private vs public

This is the big new idea that structs didn't really use. Class members can be marked private or public, which controls whether OUTSIDE code is allowed to touch them directly.

●        🔒 private — protect the data. Only code INSIDE the class can access it directly.

●        🌎 public — open to the outside world. Any code with an object can access these.

```c++
class Student {

private:

    int mark;         // protected -- can't touch this from outside

public:

    void setMark(int m) {

        mark = m;      // allowed -- this code is INSIDE the class

    }

    int getMark() {

        return mark;

    }

};
```

| Student s;<br><br>s.mark = 80;      // ❌ ERROR -- mark is private, outside code can't touch it<br><br>s.setMark(80);    // ✅ OK -- going through a public method instead |
| ------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |

Explanation: this pattern — hiding the raw data and only allowing access through methods — is called encapsulation. It stops other code from setting a Student's mark to something invalid (like -50) without going through logic that could check it first.

A class with NO access specifier written defaults to private (this is different from struct, which defaults to public — that's the one real difference between the two keywords).

---

4. Creating Objects and the Dot Operator

Once a class exists, you create objects from it just like declaring any other variable — the class name becomes the type.

```
Student s1;

Student s2;

Student s3;
```

Each of these is a separate object — same blueprint, independent data.

 Accessing members with the dot operator
```
Student s1;

s1.setMark(80);   // tell s1 to run its setMark method

s1.display();     // tell s1 to run its display method
```
Explanation: the **dot .** means **I'm accessing something that belongs to this specific object.** 
s1.setMark(80) reads naturally as 'tell s1 to set its mark to 80'. You can only reach PUBLIC members this way — private ones stay hidden.

---

5. Constructors

A constructor is a special method that runs AUTOMATICALLY the moment an object is created. It's normally used to set up an object's starting data.

 **5.1 Spotting a constructor**

```c++
class Student {

public:

    Student() {

        cout << "Student created" << endl;

    }

};
```

●        Same name as the class (Student, matching class Student).

●        No return type at all — not even void.

```
Student() { }      // ✅ this IS a constructor

void Student() { } // ❌ this is NOT a constructor (has a return type)
```

 Exam hint: Rule of thumb: constructor = same name as the class + no return type. If either of those is missing, it's just a regular method, not a constructor.

 **5.2 Parameterized constructors — initializing on creation**

If an exam question says 'initialize the object when it's created', that's a constructor with parameters.

```c++
#include <iostream>

using namespace std;

class Student {

private:

    string name;

    int mark;

public:

    Student(string n, int m) {   // parameterized constructor

        name = n;

        mark = m;

    }

    void display() {

        cout << name << " " << mark << endl;

    }

};

int main() {

    Student s1("William", 85);   // constructor runs automatically here

    s1.display();                // William 85

    return 0;

}
```

Explanation: Student s1("William", 85); creates s1 AND immediately calls the constructor with "William" and 85, which sets name and mark right away. No separate setName() / setMark() calls needed — the object is ready to use the instant it exists.

---

 6. Getters and Setters

Since private data can't be touched directly from outside, classes typically provide public methods to read (getter) and change (setter) that data in a controlled way.
```c++
class Student {

private:

    int mark;

public:

    void setMark(int m) {   // SETTER -- changes the private value

        mark = m;

    }

    int getMark() {          // GETTER -- reads the private value

        return mark;

    }

};
```


Explanation: the naming convention is consistent across almost all C++ code: setX(...) to change a value, getX() to read it. This keeps mark protected while still giving outside code a controlled, predictable way to work with it.

---

 7. Common Mistakes and Exam Tips

●        Forgetting the semicolon after the closing brace of a class definition: };

●        Trying to access a private member directly from outside the class (s.mark = 80;) instead of going through a public method.

●        Confusing the class with an object — Student is the type, s1 is the object built from it.

●        Writing a method with the class's name but giving it a return type — that makes it NOT a constructor anymore.

●        Forgetting that a class defaults to private (unlike struct, which defaults to public) if no access specifier is given.

If a test question shows code and asks 'what will this print / is this valid', check access specifiers FIRST. A huge number of class questions are really testing whether you can spot a private member being accessed from outside._

# 8. Putting It All Together — The Mental Model

```
CLASS

  |

Blueprint

  |

Contains:

  |-- Attributes (data)          e.g. name, mark

  |-- Methods (functions)        e.g. display(), setMark()

  |

Create object

  |

Student s1;

  |

Access members

  |

s1.setMark(80);

s1.display();
```

If you can follow this flow — class defines attributes and methods, an object is built from the class, and the dot operator is how you reach an object's public members — you've got the core of basic OOP down. Everything from here (constructors, encapsulation, getters/setters) is just adding detail to this same picture.

_💡 This week we're keeping it to class → attributes → methods → object → dot operator → constructor. Inheritance and polymorphism build on top of this later — no need to worry about them yet._

---

9. Quick Reference Summary

●        Define a class: class Name { ... };   (don't forget the semicolon!)

●        Attributes = HAS (data).   Methods = DOES (functions).

●        🔒 private = hidden from outside.   🌎 public = accessible from outside.

●        Create an object: Name obj;      Access a member: obj.member

●        Constructor: same name as the class, NO return type — runs automatically when an object is created.

●        Parameterized constructor lets you initialize an object in one line: Name obj(value1, value2);

●        Getter: returns a private value.   Setter: changes a private value — both are public.

●        Class vs object: the class is the type/blueprint; the object is the actual thing created from it.

_End of Classes & Objects module. Keep an eye out for private/public access questions and constructor-spotting questions — they're some of the most common ways this topic gets tested. Bring questions to the PASS session!_
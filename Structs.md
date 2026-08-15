_A Beginner-to-Intermediate Guide_

CS111 PASS Session Resource — Prepared for NotebookLM

Compiled by William Selui, PASS Leader | University of the South Pacific

---

**STRUCTS IN C++**

 1. What Is a Struct?

A struct (short for 'structure') is a way to bundle several DIFFERENT related variables together under one name. Where an array groups many values of the SAME type, a struct groups values that can be of DIFFERENT types but belong together conceptually.

Think of a struct like a student ID card. One card holds a name (text), an ID number (integer), and a GPA (decimal) — all different types of information, but all describing the ONE student. Instead of tracking these as three separate loose variables, a struct keeps them together.

_💡 If an array is a row of identical lockers, a struct is more like a single labelled folder that holds a few different kinds of documents belonging to the same person._

 Why use structs?

●        Group related data together instead of juggling separate variables (studentName, studentID, studentGPA...).

●        Makes function signatures cleaner — pass ONE struct instead of five separate parameters.

●        Foundation for object-oriented programming — a class in C++ is essentially a struct with added behaviour (functions) and access control, which you'll meet later.

---

 2. Declaring and Defining a Struct

Basic syntax — this defines a new TYPE, it doesn't create a variable yet:

```c++
struct StructName {

    dataType member1;

    dataType member2;

    // ...

};   // <-- don't forget this semicolon!
```

Example — a struct describing a student:

```c++
#include <iostream>

using namespace std;

struct Student {

    string name;

    int id;

    double gpa;

};

int main() {

    Student s1;        // create a variable of type Student

    s1.name = "Mele";  // use the dot . to access a member

    s1.id = 11244878;

    s1.gpa = 3.7;

    cout << s1.name << " (" << s1.id << ") GPA: " << s1.gpa << endl;

    return 0;

}
```

Explanation: struct Student {...}; defines a new blueprint called Student — it does not create any actual data yet. Student s1; then creates one real variable following that blueprint. The dot operator (.) is how you reach into a struct variable to get or set one of its members.

_⚠ The closing brace of a struct definition needs a semicolon after it: };  — forgetting it is one of the most common struct errors and often produces a confusing compiler error on the NEXT line of code, not the struct itself._

---

 3. Initializing Structs

Instead of setting each member on its own line, you can initialize a struct all at once using curly braces, in the same order the members were declared.

```c++
struct Student {

    string name;

    int id;

    double gpa;

};

int main() {

    Student s1 = {"Mele", 11244878, 3.7};

    // name = "Mele", id = 11244878, gpa = 3.7

    cout << s1.name << endl;

    return 0;

}
```

Explanation: the values inside {} are matched to members in DECLARATION ORDER — name first, then id, then gpa. Mixing up the order silently assigns values to the wrong members, so always double-check against the struct definition.

---

 4. **Structs and Functions**

A struct can be passed into a function just like any other variable — by value (a copy) or by reference (the original).

4.1 Passing by value (a copy)

```c++
#include <iostream>

using namespace std;

struct Student {

    string name;

    double gpa;

};

void printStudent(Student s) {

    cout << s.name << " - GPA: " << s.gpa << endl;

}

int main() {

    Student s1 = {"Mele", 3.7};

    printStudent(s1);

    return 0;

}
```

Explanation: printStudent(Student s) receives a full COPY of s1. Any changes made to s inside the function do NOT affect s1 back in main — same 'copy problem' as with normal variables.

 **4.2 Passing by reference (to actually modify it)**

```c++
void giveBonus(Student &s) {   // & means 'reference to the original'

    s.gpa += 0.1;              // this changes the REAL struct

}

int main() {

    Student s1 = {"Mele", 3.7};

    giveBonus(s1);

    cout << s1.gpa << endl;  // 3.8 -- it actually changed!

    return 0;

}
```

Explanation: Student &s means the function works directly on the original struct, not a copy. This is the cleanest way in C++ to let a function modify a struct — no need for pointer syntax like *.

_💡 Passing large structs by reference (Student &s) is also faster than by value, since it avoids copying every member every time the function is called — worth doing even when you don't need to modify anything, by using const Student &s to signal 'read-only, but don't copy'._

---

 5. **Arrays of Structs**

Structs and arrays combine naturally — you often need a LIST of structured records, e.g. a whole class of students.

```c++
#include <iostream>

using namespace std;

struct Student {

    string name;

    double gpa;

};

int main() {

    Student classList[3] = {

        {"Mele", 3.7},

        {"Sione", 3.2},

        {"Ana", 3.9}

    };

    for (int i = 0; i < 3; i++) {

        cout << classList[i].name << ": " << classList[i].gpa << endl;

    }

    return 0;

}
```

Explanation: classList[3] is an array where each SLOT is a whole Student struct, not just a single number. classList[i] gets you the i-th struct, and .name / .gpa then reaches into that specific struct's members — combining array indexing with dot-access.

---

 6. **Structs and Pointers (the -> operator)**

When you have a POINTER to a struct (rather than the struct itself), you can't use the dot . directly on the pointer — you'd first have to dereference it. C++ gives you a shortcut: the arrow operator ->.

```c++
#include <iostream>

using namespace std;

struct Student {

    string name;

    double gpa;

};

int main() {

    Student s1 = {"Mele", 3.7};

    Student *p = &s1;   // p points to s1

    cout << (*p).name << endl;  // works, but clunky: dereference, then dot

    cout << p->name << endl;    // same thing, much cleaner

    return 0;

}
```

Explanation: p->name is exactly equivalent to (*p).name — 'follow the pointer, then access the member'. The arrow operator exists purely to make this common pattern easier to read. You'll see -> constantly once structs and pointers are combined, e.g. with linked lists.

---
 7. **Nested Structs**

A struct's member can itself be another struct — useful for grouping related sub-details, like an address inside a student record.

```c++
struct Address {

    string city;

    string island;

};

struct Student {

    string name;

    Address home;   // a struct INSIDE a struct

};

int main() {

    Student s1;

    s1.name = "Mele";

    s1.home.city = "Suva";     // chain the dots to reach nested members

    s1.home.island = "Viti Levu";

    cout << s1.name << " lives in " << s1.home.city << endl;

    return 0;

}
```

Explanation: s1.home is itself a full Address struct, so to reach INTO it you chain another dot: s1.home.city. Read it left to right — 's1's home's city'.

---
 8. **Quick Note: struct vs class**

You may have heard of classes in C++ (used for object-oriented programming). A struct and a class are almost identical under the hood — the only default difference is access control:

●        struct members are public by default (accessible from anywhere, like all the examples above).

●        class members are private by default (hidden from outside code unless explicitly exposed).

_💡 For now, at beginner-to-intermediate level, structs are perfect for simple data bundles with no need to hide anything. Classes become more useful once you start adding behavior (functions) and want to protect data — a topic for later._

---
 9. Common Beginner Mistakes to Avoid

●        Forgetting the semicolon after the closing brace of a struct definition: };

●        Mixing up the order of values in brace initialization — they're matched by POSITION, not by name.

●        Trying to use . on a pointer to a struct instead of -> (or (*p).member).

●        Passing a large struct by value everywhere out of habit, causing unnecessary copying — use & (or const &) when you don't need a separate copy.

●        Forgetting that a struct passed by value in a function will NOT reflect changes back in the caller.

---

10. Quick Reference Summary

●        Define: struct Name { type member1; type member2; };

●        Create: Name var;      Initialize: Name var = {value1, value2};

●        Access a member: var.member

●        Access through a pointer: ptr->member   (same as (*ptr).member)

●        Array of structs: Name list[size];   then   list[i].member

●        Pass by value (copy): void f(Name s)      Pass by reference (original): void f(Name &s)

●        Read-only reference (no copy, no changes allowed): void f(const Name &s)

●        Nested struct access: chain the dots — outer.inner.member

_End of Structs module — this completes the Arrays / Pointers / Structs set for this week's NotebookLM notebook. Bring questions to the PASS session!_
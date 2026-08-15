_A Beginner-to-Intermediate Guide_

CS111 PASS Session Resource — Prepared for NotebookLM

Compiled by William Selui, PASS Leader | University of the South Pacific

---

**POINTERS IN C++**

 1. What Is a Pointer?

Every variable in your program lives somewhere in memory, and that location has an address — like a house number. A pointer is a variable whose JOB is to store one of these addresses, instead of storing an ordinary value like 5 or 'hello'.

Think of a normal variable as a box holding a value. A pointer is a sticky note that has the ADDRESS of that box written on it — it doesn't hold the value itself, it holds directions to where the value is.

_💡 Two symbols do all the heavy lifting with pointers: & (address-of) means 'give me the address of this variable', and * (dereference) means 'go to the address stored here and give me the value'. **Mixing these up is the #1 source of pointer confusion for beginners._**

 **Why do pointers matter?**

●        They let a function modify the caller's actual variables, not just a copy.

●        They're the mechanism behind dynamic memory (creating things at runtime, whose size you don't know in advance).

●        Arrays, strings, and many data structures (linked lists, trees) are built directly on pointer logic.

---

 2. **Declaring Pointers, & and ***

Basic syntax — the * in a declaration says 'this variable is a pointer':

`dataType *pointerName;`

```c++
#include <iostream>

using namespace std;

int main() {

    int age = 20;        // a normal variable holding 20

    int *p = &age;       // p now stores the ADDRESS of age

    cout << age << endl;   // 20              (the value)

    cout << &age << endl;  // e.g. 0x7ffee4    (age's address)

    cout << p << endl;     // e.g. 0x7ffee4    (same address, stored in p)

    cout << *p << endl;    // 20              (dereference: 'go get the value at p')

    return 0;

}
```

Explanation: &age reads as 'the address of age' — this is what gets stored inside p. Later, *p reads as 'the value at the address p is pointing to', which takes you right back to age's value, 20.

 **The two meanings of *  (this trips up everyone at first)**

●        In a DECLARATION — int *p; — the * means 'p is a pointer to an int'.

●        Anywhere ELSE — *p = 5; or cout << *p; — the * means 'dereference: go to the address and act on the value there'.

_⚠ These are two different uses of the same symbol. int *p is declaring a pointer type. *p on its own line later is dereferencing. Context tells you which one it is._

---

3. **Reading and Modifying Through a Pointer**

```c++
#include <iostream>

using namespace std;

int main() {

    int score = 50;

    int *p = &score;

    *p = 100;   // 'go to the address p points to, and set that value to 100'

    cout << score << endl;  // 100  -- score itself changed!

    return 0;

}
```

Explanation: *p = 100; does NOT change what p points to — it changes the VALUE sitting at that address. Since p points to score, score itself gets updated. This is the whole point of a pointer: it gives you a way to reach out and change a variable indirectly.

---

4. **Pointers and Arrays**

An array name, on its own, behaves like a pointer to its first element. This is why arrays and pointers are taught together — understanding one makes the other click.

```c++
#include <iostream>

using namespace std;

int main() {

    int nums[3] = {10, 20, 30};

    int *p = nums;   // no & needed -- nums already 'decays' into a pointer

    cout << *p << endl;       // 10  (first element)

    cout << *(p + 1) << endl; // 20  (second element)

    cout << *(p + 2) << endl; // 30  (third element)

    return 0;

}
```

Explanation: p + 1 doesn't mean 'add 1 to the address' in a raw byte sense — it means 'move forward by ONE int-sized step'. C++ automatically scales the math based on the pointer's data type. This is called **pointer arithmetic.**

Array indexing IS pointer arithmetic in disguise

`nums[i]     is exactly the same as     *(nums + i)`

_💡 You'll rarely need to write *(p + i) yourself — `nums[i]` is cleaner and does the same thing. But knowing they're equivalent explains WHY array indexing works the way it does._

---

5. **Pointers and Functions (Pass by Pointer)**

Normally, when you pass a variable into a function, C++ copies it — changes inside the function don't affect the original. Passing a POINTER instead lets the function reach back and modify the caller's actual variable.

**5.1 Without a pointer — the copy problem**

```c++
void tryToChange(int x) {

    x = 999;   // only changes the LOCAL copy

}

int main() {

    int num = 5;

    tryToChange(num);

    cout << num << endl;   // still 5 -- unchanged!

}
```

Explanation: x is a brand new copy of num that exists only inside the function. Changing x has zero effect on num back in main.

**5.2 With a pointer — actually changing it**

```c++
void reallyChange(int *x) {

    *x = 999;   // go to the address, change the value living there

}

int main() {

    int num = 5;

    reallyChange(&num);   // pass the ADDRESS of num

    cout << num << endl;   // 999 -- it worked!

}
```

Explanation: this time we hand the function num's address, not num itself. Inside the function, *x dereferences that address and edits the real variable directly.

**5.3 Classic example: swap two values**

```c++
#include <iostream>

using namespace std;

void swap(int *a, int *b) {

    int temp = *a;

    *a = *b;

    *b = temp;

}

int main() {

    int x = 1, y = 2;

    swap(&x, &y);

    cout << x << " " << y << endl;  // 2 1

    return 0;

}
```

Explanation: this is the go-to example for showing why pointers matter — without pointers, you cannot write a swap function that actually swaps the caller's variables. temp is a normal local variable used to hold one value while the swap happens.

---

6. **const with Pointers**

There are two different things you might want to 'lock' with a pointer: the value it points to, or the address it holds. const placement controls which one.

```c++
int x = 10;

const int *p1 = &x;   // CANNOT change *p1 (the value), CAN change p1 (re-point it)

int *const p2 = &x;   // CAN change *p2 (the value), CANNOT change p2 (re-point it)

const int *const p3 = &x; // neither can change -- fully locked
```

Explanation: read it right-to-left from the variable name. p1: 'p1 is a pointer to a const int' — the pointed-to value is protected. p2: 'p2 is a const pointer to an int' — the pointer's address is locked, but the value can still change through it.

_💡 In function parameters, const int *arr means 'this function promises not to modify the array contents' — very common for read-only functions, as shown in the Arrays guide._

---

7. **Dynamic Memory Allocation (new and delete)**

So far, every variable's size has been fixed at compile time. Sometimes you need memory whose size or existence is decided while the program is RUNNING — that's what new and delete are for.

```c++
#include <iostream>

using namespace std;

int main() {

    int *p = new int;   // ask the OS for space for one int, at runtime

    *p = 42;

    cout << *p << endl;  // 42

    delete p;   // give the memory back when you're done

    p = nullptr; // good practice: avoid leaving a 'dangling' pointer

    return 0;

}
```

Explanation: new allocates memory on the heap (as opposed to the stack, where normal variables live) and returns its address. That memory sticks around until YOU explicitly free it with delete — the compiler will not clean it up for you.

**Dynamic arrays**

```c++
int size = 5;

int *arr = new int[size];   // array size decided at runtime

for (int i = 0; i < size; i++) {

    arr[i] = i * 10;

}

delete[] arr;   // note the [] -- must match how it was created
```

_⚠ Every **new** needs exactly one matching delete (and every new[] needs delete[]). **Forgetting delete causes a memory leak** — memory that's reserved but never given back, which can slowly eat up a program's available memory.

---

8. **nullptr and Dangling Pointers**

A pointer that isn't pointing at anything valid yet should be set to nullptr, C++'s way of saying 'points to nothing'.

```c++
int *p = nullptr;

if (p == nullptr) {

    cout << "p is not pointing to anything yet" << endl;

}
```

Explanation: checking against nullptr before dereferencing a pointer is a common safety habit — dereferencing a null or uninitialized pointer is undefined behavior and a frequent source of crashes.

_⚠ A DANGLING pointer is one that still holds an address, but the memory at that address has already been freed (e.g. after delete) or gone out of scope. Using it is dangerous even though the pointer 'looks' valid. Set pointers to nullptr right after delete to avoid this trap._

---

9. **Pointer to Pointer (Intermediate)** - Not sure if this is cover in CS112

Just like a pointer stores the address of a variable, a pointer can also store the address of ANOTHER pointer. You'll see this less often as a beginner, but it's good to recognize.
```c++
int x = 5;

int *p = &x;      // p points to x

int **pp = &p;    // pp points to p

cout << **pp << endl;  // 5 -- dereference twice to reach x's value
```

Explanation: *pp gives you back p (an address). **pp dereferences twice — first to get p, then to follow p to x's actual value. This pattern shows up in things like dynamically allocated 2D arrays or when a function needs to modify a pointer itself (not just what it points to).

---

10. **Common Beginner Mistakes to Avoid**

●        Dereferencing an uninitialized pointer — always initialize a pointer (even to nullptr) before using it.

●        Confusing & (address-of) with * (dereference) — say the operation out loud: 'address of' vs 'value at'.

●        Forgetting delete after new, causing memory leaks.

●        Using a pointer after delete (dangling pointer) — set it to nullptr immediately after freeing it.

●        Mixing up int *p (pointer to const-ish… no — see Section 6) placement of const — re-read Section 6 slowly if unsure.

●        Forgetting the [ ] in delete[ ] when freeing a dynamically allocated array.

---

11. **Quick Reference Summary**

●        Declare: int *p;      Point it: p = &x;      Both at once: int *p = &x;

●        Address-of: &x  ("the address of x")      Dereference: *p  ("the value at p")

●        Pointer arithmetic: p + 1 moves forward by ONE element (size depends on the data type).

●        Array name decays to a pointer: nums[i]  is the same as  *(nums + i)

●        Pass by pointer to a function so it can modify the caller's variable: void f(int *x) { *x = ...; }

●        const int *p — value locked.   int *const p — address locked.

●        Dynamic memory: new / delete for a single value, new[] / delete[] for an array.

●        Empty/unset pointer: int *p = nullptr;   Always check before dereferencing if unsure.


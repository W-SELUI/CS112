
For Loops & 1D Arrays — The Basics

PASS Session 1 — Warm-Up Before Arrays / Pointers / Structs Begin Next Week

Led by William Selui, PASS Leader | University of the South Pacific

---
This is a quick refresher on two things we'll be leaning on hard from next week onward: for loops, and one-dimensional arrays. If everyone's solid on these basics today, the arrays / pointers / structs sessions will click a lot faster. Simple examples only — no new content, just making sure the foundation is steady.

---

 1. **Why We're Revising This Today**

Starting next week, we're covering arrays, pointers, and structs properly. Almost everything in those topics is built on TWO skills: being comfortable with for loops, and knowing how a basic (1D) array works. If those two are shaky, everything after gets harder than it needs to be.

Today's goal: make sure everyone can confidently read AND write a simple for loop, and can confidently declare, fill, and loop through a 1D array. That's it — nothing fancier.

---

2. **For Loops — The Basics**

A for loop repeats a block of code a set number of times. It's the go-to loop when you know (or can calculate) how many times you need to repeat something.


**2.1** Anatomy of a for loop

```c++
for (int i = 0; i < 5; i++) {

    // code that runs each time

}
```

**Explanation**: a **for loop** has three parts, separated by semicolons:

●        int i = 0;  →  starting point (runs ONCE, before the loop begins)

●        i < 5;  →  the condition checked BEFORE every repeat — as long as it's true, the loop keeps going

●        i++  →  what happens AFTER each repeat (usually incrementing the counter)

 **i** is just a variable name — short for 'index' or 'iterator'. You can call it anything, but i (and j for a nested loop) is the standard convention everyone uses.
 

 **2.2** A simple counting example

```c++
#include <iostream>

using namespace std;

int main() {

    for (int i = 1; i <= 5; i++) {

        cout << i << endl;

    }

    return 0;

}

// Output:

// 1

// 2

// 3

// 4

// 5
```

Explanation: **i** starts at 1. The loop keeps running as long as **i <= 5**. After printing, i++ bumps i up by 1, and the condition is checked again. Once i becomes 6, 6 <= 5 is false, so the loop stops.

 **2.3** Counting down
```c++
for (int i = 5; i >= 1; i--) {

    cout << i << endl;

}

// Output: 5 4 3 2 1
```

**Explanation:** same idea, just reversed — start high, condition checks we haven't gone below 1, and **i--** decreases by 1 each time instead of increasing.

 Ask the group: what would happen if we changed i <= 5 to i < 5 in the first example? (Answer: it would stop one number early, printing only 1 to 4 — a classic off-by-one situation.)

 **2.4** Common mistakes with for loops

●        Using = instead of == in the condition (= assigns a value, == compares — this is a compile error or silent bug depending on context).

●        Off-by-one errors: mixing up < and <=, causing the loop to run one time too many or too few.

●        Forgetting i++ (or writing it wrong), which can cause the loop to run forever (an infinite loop).

_⚠ If a program seems 'frozen' and never finishes, an infinite loop is almost always the first thing to check — look for a condition that never becomes false._

---

3. **One-Dimensional (1D) Arrays — The Basics**

An array stores multiple values of the SAME type under one name, each reachable by an index number starting at 0.

 **3.1** Declaring and initializing

```c++
int scores[5];                        // empty array, holds 5 ints

int scores[5] = {80, 75, 90, 60, 88}; // filled right away

int scores[] = {80, 75, 90, 60, 88};  // size 5 auto-counted
```

Explanation: the number in [ ] sets how many slots the array has. Indexing always starts at 0, so a 5-element array has valid positions scores[0] through scores[4] — there is no scores[5].

 **3.2** Accessing and changing elements

```c++
int scores[5] = {80, 75, 90, 60, 88};

cout << scores[0] << endl;  // 80 -- the FIRST element

scores[2] = 100;             // change the THIRD element (index 2)

cout << scores[2] << endl;  // 100
```

Explanation: square brackets [index] both READ a value (on the right of =, or inside cout) and WRITE a value (on the left of =).

 **3.3** The pairing everyone needs to be solid on: looping through an array

```c++
#include <iostream>

using namespace std;

int main() {

    int scores[5] = {80, 75, 90, 60, 88};

    for (int i = 0; i < 5; i++) {

        cout << "scores[" << i << "] = " << scores[i] << endl;

    }

    return 0;

}
```

Explanation: this is the pattern you'll use constantly. i < 5 (NOT i <= 5) is what keeps us safely inside the array — i visits 0,1,2,3,4, which are exactly the 5 valid indexes. This for-loop-plus-array combo is the single most important pattern from today's session.

 **3.4** A simple worked example: summing an array

```c++
int scores[5] = {80, 75, 90, 60, 88};

int sum = 0;

for (int i = 0; i < 5; i++) {

    sum += scores[i];   // sum = sum + scores[i]

}

cout << "Total: " << sum << endl;   // 393
```

Explanation: sum starts at 0 and collects each element as the loop runs through the array. This 'running total' pattern (loop + accumulator variable) shows up everywhere once we start doing real array work next week.

 Ask the group: could someone adapt this code to find the AVERAGE instead of just the sum? (Hint: it's the sum divided by how many elements there are.)

---

4. **Quick Recap Before We Move On**

●        for (start; condition; step) { } — start runs once, condition is checked every round, step runs after every round.

●        Watch for off-by-one bugs: < vs <=, and whether you start counting from 0 or 1.

●        Arrays hold many values of the same type; indexing always starts at 0.

●        The core combo: for (int i = 0; i < size; i++) { ...array[i]... } — this pattern will appear in almost everything from here on.

●        Next week we build on exactly this: arrays in more depth, then pointers, then structs.

---

If today felt comfortable, next week's material will build naturally on it. If anything here felt shaky, that's exactly what this session was for — flag it now so we can sort it before we move faster.
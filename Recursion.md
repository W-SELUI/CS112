
This document covers recursion from the ground up — a function that calls itself to solve a problem. We build from the simplest possible examples up to the classic Tower of Hanoi puzzle, which is the example most courses use to really test if recursion has clicked. Each concept comes with a simple example, a plain-English explanation, and exam hints.

---

1. **What Is Recursion?**

Recursion is when a function calls ITSELF to solve a smaller version of the same problem. Instead of using a loop to repeat something, the function keeps calling a smaller copy of itself until the problem becomes so small it can be answered directly.

Think of Russian nesting dolls (matryoshka). To open the whole thing, you open the outer doll, then you're faced with the EXACT same task — open a doll — just on a smaller doll. You keep doing the same action until you reach the smallest doll, which doesn't open any further. That smallest doll is where the repeating stops.

Every recursive function needs two things: a BASE CASE (the smallest doll — when to stop) and a RECURSIVE CASE (call itself again, but on a smaller/simpler version of the problem). Miss the base case and the function calls itself forever.

 Why use recursion instead of a loop?
●        Some problems are naturally defined in terms of smaller versions of themselves (factorial, Fibonacci, tree structures, Tower of Hanoi).
●        It can make certain problems much shorter and cleaner to write than an equivalent loop.
●        It's a required way of thinking for a lot of computer science topics later on (trees, divide-and-conquer algorithms, backtracking).

---

2. **Anatomy of a Recursive Function**

```c++
returnType functionName(parameters) {

    if (base case condition) {

        return baseCaseValue;      // STOP -- no further calls

    } else {

        return functionName(smaller version of the problem);  // recursive call

    }

}
```

Explanation: the base case is checked FIRST, every single time the function runs. If it's true, the function returns immediately without calling itself again. Otherwise, it calls itself with a smaller or simpler input, trusting that the smaller call will eventually hit the base case.

_🎯 Exam hint: If an exam question shows a recursive function and asks 'what happens if the base case is removed / wrong', the answer is almost always: infinite recursion, which crashes the program (stack overflow) because the function never stops calling itself._

---

3. **Simple Example: Factorial**

Factorial (written n!) means multiply every whole number from n down to 1. For example, 4! = 4 × 3 × 2 × 1 = 24.
The recursive insight: n! is just n × (n-1)!  — factorial defined in terms of a SMALLER factorial. And 0! is defined as 1 (the base case).

```c++
#include <iostream>

using namespace std;

int factorial(int n) {

    if (n == 0) {          // BASE CASE

        return 1;

    } else {

        return n * factorial(n - 1);   // RECURSIVE CASE

    }

}

int main() {

    cout << factorial(4) << endl;   // 24

    return 0;

}
```

Explanation: factorial(4) calls factorial(3), which calls factorial(2), which calls factorial(1), which calls factorial(0) — and THAT hits the base case and returns 1 without calling itself again. Then each waiting call finishes its multiplication on the way back:

```c++
factorial(4) = 4 * factorial(3)

             = 4 * (3 * factorial(2))

             = 4 * (3 * (2 * factorial(1)))

             = 4 * (3 * (2 * (1 * factorial(0))))

             = 4 * (3 * (2 * (1 * 1)))

             = 24
```

 Notice the pattern: the function keeps calling itself DEEPER (going down), then once it hits the base case, it starts actually computing and returning values back UP through each waiting call. This 'go down, then come back up' shape is the heart of how recursion works.

---

4. **How Recursion Actually Runs — The Call Stack**

Every time a function is called (recursive or not), the program remembers where to come back to and what its local variables were, by placing that information on the call stack — think of it like a stack of trays, each new call placed on top.

```
Calling factorial(4):

  factorial(0)   <- top of stack, runs first (base case, returns 1)

  factorial(1)

  factorial(2)

  factorial(3)

  factorial(4)   <- bottom, called first, finishes LAST
```

Explanation: each call waits, paused, until the call above it finishes and returns a value. Once factorial(0) returns 1, factorial(1) can finish its own multiplication and return, then factorial(2) can finish, and so on back down to factorial(4).

⚠ If there's no base case (or it's never reached), calls keep piling onto the stack forever, with nothing ever popping off. Eventually the program runs out of stack space and crashes — this is called a stack overflow, and it's the most common recursion bug.

---

 5. **Another Example: Sum of an Array**
The sum of an array can be defined recursively too: the sum of n elements is the FIRST element plus the sum of the REMAINING (n-1) elements.

```c++
#include <iostream>

using namespace std;

int sumArray(int arr[], int size) {

    if (size == 0) {              // BASE CASE -- no elements left

        return 0;

    } else {

        return arr[0] + sumArray(arr + 1, size - 1);  // RECURSIVE CASE

    }

}

int main() {

    int nums[4] = {10, 20, 30, 40};

    cout << sumArray(nums, 4) << endl;   // 100

    return 0;

}
```

Explanation: each call handles just the FIRST element and hands off the rest of the array (arr + 1, one smaller size) to the next call. This mirrors the factorial pattern exactly: peel off one piece, recurse on what's left, and stop when nothing is left.

---

6. **The Classic Example: Tower of Hanoi**

Tower of Hanoi is a puzzle with 3 rods (A, B, C) and a stack of different-sized discs on rod A, arranged largest at the bottom to smallest at the top. The goal: move the ENTIRE stack from rod A to rod C, using rod B as a helper, following two rules:

●        Only move ONE disc at a time.
●        A larger disc can NEVER be placed on top of a smaller one.


**6.1 The recursive insight**
To move n discs from A to C (using B as the helper), you can break it into 3 steps:

```
1. Move the top (n-1) discs from A to B   (using C as the helper this time)

2. Move the LAST (biggest) disc from A to C directly

3. Move the (n-1) discs from B to C       (using A as the helper this time)
```

Explanation: notice steps 1 and 3 are the SAME kind of problem as the original — 'move some discs from one rod to another using a third as helper' — just with one fewer disc. That's the recursive case. The base case is moving just 1 disc, which needs no helper steps at all — you just move it.

**6.2 The code**

```c++
#include <iostream>

using namespace std;

void hanoi(int n, char from, char to, char aux) {

    if (n == 1) {                          // BASE CASE

        cout << "Move disc 1 from " << from << " to " << to << endl;

        return;

    }

    hanoi(n - 1, from, aux, to);   // Step 1: move (n-1) discs, A -> B

    cout << "Move disc " << n << " from " << from << " to " << to << endl;

    hanoi(n - 1, aux, to, from);   // Step 3: move (n-1) discs, B -> C

}

int main() {

    hanoi(3, 'A', 'C', 'B');   // move 3 discs from A to C, using B as helper

    return 0;

}
```

Explanation of the parameters: from is the rod discs start on, to is the rod they need to end up on, and aux is the spare rod used along the way. Each call swaps these roles around for its two recursive calls — that's the trickiest part to follow, so trace it slowly with n = 2 or 3 discs on paper first.

**6.3 Tracing Hanoi(2, 'A', 'C', 'B')**

```c++
hanoi(2, A, C, B)

  -> hanoi(1, A, B, C)   "Move disc 1 from A to B"   (base case)

  -> print "Move disc 2 from A to C"

  -> hanoi(1, B, C, A)   "Move disc 1 from B to C"   (base case)

Final output:

Move disc 1 from A to B

Move disc 2 from A to C

Move disc 1 from B to C
```


Explanation: with 2 discs, the small disc moves out of the way (A to B), the big disc moves directly to its destination (A to C), then the small disc moves on top of it (B to C). That IS the solution to 2-disc Hanoi, and it falls straight out of the recursive pattern above.

🎯 Exam hint: A very common exam question: 'how many moves does it take to solve Tower of Hanoi with n discs?' The answer is 2^n - 1. For 3 discs: 2^3 - 1 = 7 moves. This comes from the fact that each level of recursion does 2 recursive calls of size n-1 plus 1 direct move.

---

# 7. Common Mistakes and Exam Tips

●        Forgetting the base case entirely, or writing a base case that can never actually be reached — both cause infinite recursion (stack overflow).

●        Not making the problem SMALLER on each recursive call (e.g. calling factorial(n) instead of factorial(n - 1) by mistake) — this also causes infinite recursion.

●        Forgetting to return the result of the recursive call (writing factorial(n - 1); instead of return n * factorial(n - 1);).

●        Trying to trace a recursive function in your head all at once — instead, trace it step by step on paper, writing down each call and what it's waiting on, especially for Tower of Hanoi.

⚠ For Tower of Hanoi specifically: the most common mix-up is swapping which rod is 'to' and which is 'aux' between the two recursive calls. Double-check: the FIRST call moves n-1 discs out of the way (to the aux rod), and the SECOND call moves them back onto the destination (using the original 'from' rod as its new helper).

---

# 8. Quick Reference Summary

●        Recursion = a function that calls itself on a smaller version of the same problem.
●        Every recursive function needs: a BASE CASE (stops the recursion) and a RECURSIVE CASE (calls itself with smaller input).
●        Missing/unreachable base case = infinite recursion = stack overflow / crash.
●        Calls 'go down' to the base case, then values are computed and passed back 'up' as each call returns.
●        Factorial pattern: n! = n * (n-1)!, with 0! = 1 as the base case.
●        Tower of Hanoi: move n discs = (move n-1 to helper) + (move 1 big disc directly) + (move n-1 from helper to destination).
●        Tower of Hanoi minimum moves for n discs: 2^n - 1.

End of Recursion module. Practice tracing factorial and Tower of Hanoi by hand with small values (n = 2, 3) before trying to read the code straight through — that's the fastest way to make the base-case / recursive-case pattern click. Bring questions to the PASS session!

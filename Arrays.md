**ARRAYS IN C++**

Compiled by William Selui, PASS Leader | University of the South Pacific

This document covers everything a beginner needs to get comfortable with arrays in C++, building up to intermediate topics like passing arrays to functions and working with 2D arrays. Each concept comes with a simple, reliable example and a plain-English explanation.

---

  
1. **What Is an Array?**

An array is a container that holds multiple values of the SAME data type, stored right next to each other in memory. Instead of creating separate variables for every value, you group them under one name and access each one using an index number.

Think of an array like a row of lockers. All the lockers are the same size (same data type), they're numbered starting from 0, and you use that number to open the one you want.

Arrays in C++ have a FIXED size once created — you decide how many elements it holds, and that cannot change at runtime for a normal array._

 Why use arrays?

●        Store many related values under one name (e.g. 5 test scores) instead of score1, score2, score3...

●        Loop through data easily using an index.

●        Foundation for more advanced structures — strings, matrices, vectors, and data structures all build on this idea.

---

2. **Declaring and Initializing Arrays**

Basic syntax:

`dataType arrayName[size]

Example — declaring an array of 5 integers:

`int scores[5];
creates an array that can hold 5 integers
values are 'garbage' (uninitialized) until you set them

You can also initialize it with values right away:

```c++
#include <iostream>

using namespace std;

int main() {

    int scores[5] = {80, 75, 90, 60, 88};

    cout << scores[0] << endl;  // prints 80 (the FIRST element)

    cout << scores[4] << endl;  // prints 88 (the LAST element)

    return 0;

}
```

Explanation: scores[5] means the array holds 5 elements. Indexing ALWAYS starts at 0, so valid positions here are scores[0] through scores[4]. There is no scores[5] — that slot doesn't exist.

 **Letting the compiler count the size for you**

`int scores[] = {80, 75, 90, 60, 88};  // size is automatically 5`

This is handy when you don't want to manually count the elements, or when the list might change slightly during development.

 Going out of bounds (e.g. scores[5] or scores[-1]) does NOT give you a clean error in C++. It reads/writes memory that doesn't belong to the array, causing undefined behavior — sometimes it 'works', sometimes it crashes, sometimes it corrupts other data. Always double-check your index range._

---

 3. **Accessing and Modifying Elements**

Use square brackets [ ] with the index to read or change a value.

```c++
#include <iostream>

using namespace std;

int main() {

    int ages[3] = {19, 20, 21};

    ages[1] = 25;   // change the SECOND element (index 1) to 25

    cout << ages[0] << " " << ages[1] << " " << ages[2] << endl;

    // prints: 19 25 21

    return 0;

}
```

Explanation: ages[1] refers to the element at index 1, which is the SECOND slot (index 0 is the first). Assigning a new value with = overwrites whatever was there before.

---

 4. **Looping Through Arrays**

Manually writing out `cout` for every element doesn't scale. Loops let you visit every element automatically.

**4.1 Classic for loop**

```c++
#include <iostream>

using namespace std;

int main() {

    int marks[5] = {70, 85, 90, 65, 78};

    for (int i = 0; i < 5; i++) {

        cout << "marks[" << i << "] = " << marks[i] << endl;

    }

    return 0;

}
```

Explanation: i starts at 0 and stops BEFORE it reaches 5 (i < 5), so it visits indices 0,1,2,3,4 — exactly the 5 valid slots. This pattern (i < size) is the standard safe way to loop through an array.

---

5. **Common Array Operations**

 **5.1 Sum and average**

```c++
#include <iostream>

using namespace std;

int main() {

    int nums[5] = {4, 8, 15, 16, 23};

    int sum = 0;

    for (int i = 0; i < 5; i++) {

        sum += nums[i];   // add each element to the running total

    }

    double average = (double)sum / 5;

    cout << "Sum: " << sum << endl;

    cout << "Average: " << average << endl;

    return 0;

}
```

Explanation: sum starts at 0 and accumulates each element as the loop runs. (double) forces the division to give a decimal answer instead of rounding down to a whole number.

 **5.2 Finding the maximum value**

```c++
int nums[5] = {4, 8, 15, 16, 23};

int max = nums[0];   // assume the first element is the biggest, for now

for (int i = 1; i < 5; i++) {

    if (nums[i] > max) {

        max = nums[i];   // found a bigger one, update max

    }

}

cout << "Max: " << max << endl;
```

Explanation: this is the classic 'assume the first, then compare' pattern. The loop starts at i = 1 (not 0) because we already used index 0 as our starting guess.

 **5.3 Linear search (finding a value)**

```c++
int nums[5] = {4, 8, 15, 16, 23};

int target = 15;

int foundIndex = -1;   // -1 means 'not found yet'

for (int i = 0; i < 5; i++) {

    if (nums[i] == target) {

        foundIndex = i;

        break;   // stop searching, we already found it

    }

}

if (foundIndex != -1)

    cout << "Found at index " << foundIndex << endl;

else

    cout << "Not found" << endl;
```

Explanation: -1 is used as a signal value because it's not a valid array index. break exits the loop immediately once a match is found, so we don't waste time checking the rest.

---

 6. **Arrays and Functions**

Arrays can be passed into functions, but there's an important detail: C++ arrays 'decay' into a pointer to their first element when passed to a function. This means the function does NOT know the array's size on its own — you must pass the size separately.

 **6.1 Passing an array to a function**

```c++
#include <iostream>

using namespace std;

// function that prints all elements

void printArray(int arr[], int size) {

    for (int i = 0; i < size; i++) {

        cout << arr[i] << " ";

    }

    cout << endl;

}

int main() {

    int data[4] = {10, 20, 30, 40};

    printArray(data, 4);   // pass the array AND its size

    return 0;

}
```

Explanation: int arr[ ] in the function parameter looks like an array, but it's really just a pointer to the first element. That's why we ALSO pass 4 (the size) — without it, printArray has no way to know how many elements to loop through.

 **6.2 Modifying an array inside a function**

```c++
void doubleValues(int arr[], int size) {

    for (int i = 0; i < size; i++) {

        arr[i] = arr[i] * 2;

    }

}

int main() {

    int data[4] = {10, 20, 30, 40};

    doubleValues(data, 4);

    for (int i = 0; i < 4; i++) cout << data[i] << " ";

    // prints: 20 40 60 80

}
```

 Unlike normal variables, arrays are passed by reference automatically (because of that pointer decay). So changes made inside the function DO affect the original array back in main — no need for & like you would with a single int.

**6.3 Keeping an array read-only in a function**
```c++
// 'const' tells the compiler this function will not modify the array

void printOnly(const int arr[], int size) {

    for (int i = 0; i < size; i++) {

        cout << arr[i] << " ";

    }

}
```

Explanation: adding const is good practice when a function only needs to read the array. It protects you from accidentally changing data you didn't mean to touch, and it documents intent for anyone reading your code.

---

 7. **Two-Dimensional (2D) Arrays**

A 2D array is basically an array of arrays — think of it as a grid or table with rows and columns. Useful for things like a tic-tac-toe board, a seating chart, or a matrix of numbers.

7.1 **Declaring and initializing a 2D array**

`dataType arrayName[rows][columns];`

```c++
#include <iostream>

using namespace std;

int main() {

    int grid[2][3] = {

        {1, 2, 3},   // row 0

        {4, 5, 6}    // row 1

    };

    cout << grid[0][2] << endl;  // prints 3 (row 0, column 2)

    cout << grid[1][0] << endl;  // prints 4 (row 1, column 0)

    return 0;

}
```


Explanation: grid[2][3] means 2 rows and 3 columns (6 elements total). The FIRST index picks the row, the SECOND index picks the column within that row — always [row][column]

**7.2 Looping through a 2D array (nested loops)**

```c++
int grid[2][3] = {

    {1, 2, 3},

    {4, 5, 6}

};

for (int row = 0; row < 2; row++) {

    for (int col = 0; col < 3; col++) {

        cout << grid[row][col] << " ";

    }

    cout << endl;   // move to a new line after each row

}

// Output:

// 1 2 3

// 4 5 6
```

Explanation: the OUTER loop walks through each row, and the INNER loop walks through each column within that row. This 'loop inside a loop' pattern is the standard way to visit every cell in a grid.

 **7.3 2D arrays and functions**

When passing a 2D array to a function, C++ requires you to specify the COLUMN size (the row count can be left flexible, but columns cannot).

```c++
#include <iostream>

using namespace std;

void printGrid(int arr[][3], int rows) {

    for (int r = 0; r < rows; r++) {

        for (int c = 0; c < 3; c++) {

            cout << arr[r][c] << " ";

        }

        cout << endl;

    }

}

int main() {

    int grid[2][3] = {

        {1, 2, 3},

        {4, 5, 6}

    };

    printGrid(grid, 2);

    return 0;

}
```


Explanation: `arr[][3]` tells the compiler each row has exactly 3 columns, which it needs to correctly calculate memory offsets. The row count (2) is passed separately as rows, just like the 1D case.

 Common beginner mistake: forgetting that `arr[row][col]`order matters. Mixing up rows and columns is one of the most frequent bugs with 2D arrays — always double-check which index means what in your specific array._

8. **Common Beginner Mistakes to Avoid**

●        Off-by-one errors: using <= instead of < in loop conditions, causing an out-of-bounds access (e.g. i <= 5 on a 5-element array reaches the invalid index 5).

●        Forgetting that indexing starts at 0, not 1.

●        Passing an array to a function without also passing its size.

●        Assuming arrays can be resized — C++ arrays are fixed size; use std::vector if you need a resizable container (a slightly more advanced topic).

●        Mixing up rows and columns when working with 2D arrays.

●        Comparing arrays with == expecting it to compare contents — it actually compares memory addresses, not values.


---

9. **Quick Reference Summary**

●        Declare:` int arr[5];`      Initialize: `int arr[5] = {1,2,3,4,5};`

●        Access: `arr[i]`      Modify: `arr[i] = value`;

●        Loop: for (int i = 0; i < size; i++)   

●        Pass to function: needs both the array AND its size — `void f(int arr[ ], int size)

●        2D declare: `int grid[rows][cols];`    Access: `grid[row][col]`

●        2D loop: nested for loops — outer for rows, inner for columns

●        2D in functions: column size must be specified — `void f(int arr[ ][cols], int rows)`


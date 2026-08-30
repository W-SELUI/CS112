**Processors, Linking & Memory Allocation**

Beginner-to-Intermediate Guide_

Processors, Linking & Memory Allocation

Compiled by William Selui, PASS Leader | University of the South Pacific 
This document covers the basics of the C++ pre-processor, linking, and dynamic memory allocation. These topics explain what happens before a program runs, how multiple files work together, and how programs can request memory while running. Each concept comes with simple examples, plain-English explanations, and exam hints to help spot common test questions.

---

 # 1. What Happens Before a Program Runs?

When you write a C++ program, several steps happen before your code actually executes.

```
Source Code
     |
Preprocessor
     |
Compiler
     |
Linker
     |
Executable Program
     |
Loader
     |
Program Runs
```

Explanation:

Think of it as an assembly line.

- The **Preprocessor** prepares the code.
- The **Compiler** translates the code.
- The **Linker** connects missing pieces.
- The **Loader** places the program into memory.
- The CPU then executes the program

**Exam Hint**
Students often mix up the compiler and linker.

- Compiler = translates code
- Linker = connects code together

---

2. What Is the Pre-processor?

The **pre-processor** is a program that runs automatically BEFORE compilation begins. It follows special instructions called **pre-processor directives**. 

These directives always begin with the # symbol.

Example:

``#include <iostream>

Explanation:
The pre-processor looks for instructions like this and performs actions before the compiler sees the code.

Common jobs include:
- Including files
- Replacing text
- Conditional compilation 

Exam Hint
If a line begins with # , it is usually a preprocessor directive and not ordinary C++ code.

---

3. The `#include` Directive

The most common preprocessor directive is:

``#include <iostream>

This tells the preprocessor:
 "Copy the contents of the iostream header file into this program."

 Standard Library Header Files

C++

```
#include <iostream>
#include <string>
```

The angle brackets `< >` tell the preprocessor to search for standard library files. 

Programmer-Defined Header Files

``#include "Student.h"

The quotation marks tell the preprocessor to search for files created by the programmer.

**Exam Hint**
Know the difference:

``#include <filename>


Standard library file

``#include "filename"

Programmer-created file

---

4. Header Files and Implementation Files

Large programs are usually split into multiple files.

Example:

```
Student.h
Student.cpp
main.cpp
```

Header File (.h)
Contains declarations.

```c++
class Student{
	public:
		void display();
}
```

Implementation File (.cpp)
Contains definitions.

```c++
void Student::display(){
	cout << "Hello";
}
```

Main File
Uses the class.

```c++
#include "Student.h"

int main(){
	Student s;
}
```

Explanation:
The header tells the compiler WHAT exists.
The implementation file contains HOW it works. 

Exam Hint
Remember:

```
.h  -> declarations
.cpp -> implementations
```

---

5. What Is Linking?

Many programs use functions and classes that are defined in separate files.
After compilation, there may be missing pieces.
The linker fills these gaps by joining the required files together. 

```
main.cpp 
	\
	 \ 
	 student.cpp 
	 / 
	/ 
Linker 
 | 
Executable Program
```

Explanation:
Without linking, different files would never be connected into one complete program.

Exam Hint
- The compiler creates object code.
- The linker combines object code into an executable program. 

---

6. The #define Directive

Another common preprocessor directive is:

``#define SIZE 100

Explanation:
Every occurrence of SIZE is replaced with 100 before compilation.

Example:

```
#define SIZE 100
int arr[SIZE]
```


Becomes:

``int arr[100];

Symbolic Constants

``#define MAX_MARK 100
This creates a symbolic constant. 

Exam Hint
Traditionally symbolic constants written with `#define` use CAPITAL LETTERS.

---

7. Static vs Dynamic Memory Allocation

Memory can be allocated in two different ways.

Static Memory Allocation
Memory is arranged before the program runs.

```c++
int x;
float money;
```

These are examples of statically allocated objects. 

 Characteristics
- Size known beforehand
- Created automatically
- Managed automatically

---

 Dynamic Memory Allocation
Memory is requested while the program is running.

``int* ptw = new int;

The amount of memory needed may not be known until the program executes.

Exam Hint
Static = memory decided before runtime
Dynamic = memory decided during runtime

---

 8. Stack vs Heap

Memory is divided into different areas.

Stack
Stores most statically allocated variables.

```c++
int age;
double balance;
```

Heap (Free Store)
Stores dynamically allocated memory.

``int* ptr = new int;

The Big Idea

```
STACK
--------
age
balance

HEAP
--------
new int
new char
new float
```

Explanation:
Static variables usually live on the stack.
Memory created using `new` comes from the heap.

---

 9. The new Operator

The `new` operator allocates memory from the heap and returns its address. 

Example:

``int* IDpt = new int;

Explanation:

- Memory is created on the heap.
- The memory has no name.
- A pointer stores its address. 

Memory picture:

```
IDpt
 |
 v
[ Heap Memory ]
```

Initializing the Value

Method 1:

```c++
int* IDpt = new int;
*IDpt = 5;
```

Method 2:

``i*t* IDpt = new int(5);

Both result in the allocated integer having the value 5. 

Exam Hint
`new` returns an address, so the result must be stored in a pointer.

---

10. The delete Operator

Memory allocated with `new` should be released when it is no longer needed.

``delete IDpt;

Explanation:

The `delete` operator returns allocated heap memory back to the system. 

The Golden Rule
```
Every new should have a delete.
```


---

11. Memory Leaks

A memory leak occurs when dynamically allocated memory is never released. 


Example:

``int* ptr = new int;

Suppose the pointer disappears before:

`delete ptr;
is called.

The memory still exists but can no longer be reached.

The Problem
```
Pointer Lost
     X

Heap Memory Still Exists
```

Explanation:
The program keeps losing available memory.
Over time this can reduce performance or even cause the program to fail.

Exam Hint
If you see:

`new`

without a later

`delete`

think:

> Potential memory leak.

---

12. Dynamically Allocating Arrays

Arrays can also be allocated dynamically.

`int* pt = new int[1024];

This creates an array of 1024 integers on the heap. 

Accessing elements:

```c++
pt[0] = 10;
pt[1] = 20;
pt[2] = 30;
```

Important Difference

`int* pt = new int[1024]`
creates an array.

But:

`int* pt = new int(1024)`
creates ONE integer initialized with the value 1024. 

Exam Hint
- Students often confuse these two examples.
- Pay attention to the square brackets!

---

13. Deleting Dynamic Arrays

Arrays use slightly different syntax when being deleted.

Allocate:

`int* pt = new int[1024`

Delete:

`delete[] pt;`

Memory Rule
Single object:

```c++
new int
delete ptr;
```

Array:

```c++
new int[10]
delete[] ptr
```

Exam Hint
One of the most common mistakes is forgetting the square brackets after delete when deleting arrays.

---

14. Dangling Pointers

A **dangling pointer** occurs when a pointer still contains an address after the memory has already been deleted. 

Example:

```c++
int* myPointer;

myPointer = new int(10);

delete myPointer;

*myPointer = 5; //Problem!
```

Explanation:
- The memory has already been released.
- The pointer is pointing to memory it no longer owns. 

Why Is It Dangerous?
- The released memory may be reused by another variable.
- Changing it could corrupt another part of the program.

---

15. Preventing Dangling Pointers

A common technique is:

```c++
delete myPo*ter;
myPointer = NULL;
```

Explanation:
Setting the pointer to NUL
This helps programmers find bugs more easily. 

Exam Hint

```c++
delete ptr;
p*r = NULL;
```

---

16. Putting It All Together - The Mental Model

```
Source Code
      |
Preprocessor
(#include, #define)
      |
Compiler
      |
Linker
      |
Executable Program
      |
Program Runs
      |
Need Memory?
      |
     new
      |
Use Memory
      |
   delete
      |
Program Ends
```

If you can follow this flow, you've got the core of this topic down. The preprocessor prepares the code, the linker connects everything together, and dynamic memory allocation allows programs to request memory while they run.

---

17. Common Mistakes and Exam Tips

● Confusing the compiler with the linker.

● Thinking `#include` is ordinary C++ code when it is actually a pre-processor directive.

● Forgetting that memory allocated with `new` comes from the heap.

● Forgetting to use `delete` after `new`.

● Using:

`delet* ptr;`

for a dynamic array allocated with:

```
new int[100];
*
```
instead of:

`delete[] p*r;

● Continuing to use a pointer after it has been deleted (dangling pointer).
● Forgetting that dynamic memory is accessed through pointers. 

---

18. Quick Reference Summary

- Preprocessor runs before compilation
- `#include ` copies a file into the program
- `#define`  creates symbolic constants
- Header files (.h) usually contain definitions
- Linker combines separate object files into one executable program
- Static memory is allocated before runtime
- Dynamic memory is allocated before runtime
- Heap stores dynamically is allocated during runtime
- new allocates memory and return its address
- delete releases allocated memory
- Dynamic arrays use `new int [size]`  and `delete[] ptr`
- Forgetting to delete memory can cause memory leaks
- Using a pointer after deleting its memory creates a dangling pointer

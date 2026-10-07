Pass sessions Notes compiled by the PASS Leader - William Selui 

---
## **Introduction**

This module introduces two important linear data structure Stacks and Queues
Both structures store data, but they differ in the order that items are inserted and removed

Before looking at stacks, the lecture briefly dynamic memory allocation in C. including the use of malloc( ) and free( ), which are commonly used when implementing dynamic data structures.

At the end of this topic, you should understand
- Dynamic memory allocation
- Stack data structures
- Queue data structures
- Push and Pop operations
- Enqueue and Dequeue operations
- LIFO and FIFO concepts
- Basic stack and queue implementations

---
## **DYNAMIC MEMORY ALLOCATION IN C**

In C++, memory is often allocated using **new**
In C, memory is allocated using **malloc( )**

Function prototype
``void* malloc(size_t nbytes);
malloc() allocates memory and returns a pointer to the allocated memory block

Example
```c++
char* cpt;

if ((cpt = (char*)malloc(25)) == NULL)

{

    printf("Error on malloc\n");

}

``
```
Explanation
- Allocate 25 bytes of memory
- If allocation fails, malloc( ) returns NULL
- Always check for NULL before using the memory

---

## **Freeing Memory**
When memory is allocated dynamically, it must eventually be released

In C++ `delete`
In C  `free()`

Example
`free(cpt)`
Failing to free unused memory can lead to memory leaks

---
## **What is a Stack?**
A Stack is a data structure that stores items in a special order

It mainly supports two operations
```
push -> insert an item
pop -> remove an item
```

A stack works like a stack of plates
- new plates are added to the top
- Plates are removed from the top

The last item is placed on the stack is always the first item removed

---
## **LIFO (Last In, First Out)**
Stacks follow the `LIFO`  -> Last In, First Out rule

Example
```
Push:

1
2
3
4
```

Stack
```
Top
 |
 4
 3
 2
 1
```

Pop sequence
```
4
3
2
1
```

The last item inserted is (4) hence why its removed first

---
## **WHY ARE STACKS USEFUL?**

Stacks are commonly used for
- Function calls
- Storing return addresses
- Tracking variables
- Expression evaluation
- Expression parsing

---
## **Stack Implementations using Linked Lists**
A Stack can be implemented using a linkedlist

Node structure
```c++
typedef struct stack_node
{
    int sData;
    stack_node* next;
} sNode;
```

Top pointer `sNode* top = NULL;` 
The top pointer always points to the top item in the stack

---
## **Push Operation**
Push adds a new item to the top of the stack

```c++
void push(int data)
{
    sNode* nNode =

        (sNode*)malloc(sizeof(sNode));

    nNode->sData = data;

    if(top == NULL)

    {
        top = nNode;

        nNode->next = NULL;
    }

    else
    {
        nNode->next = top;
        top = nNode;
    }
}
```

### **How Push Works**
Suppose we push
```
10
20
30
```

After pushing:
```
Top
 |
30
 |
20
 |
10
 |
NULL
```
Every new node becomes the new top node


---
## **POP Operation**
Pop removes the top item from the stack

```c++
bool pop(int &data)
{
    if(top == NULL)

        return false;
        
    sNode* tmp = top;
    data = top->sData;
    top = top->next;
    free(tmp);
    return true;
}
```

### **How Pop Works**
Before
```
Top
 |
30
 |
20
 |
10
```

Pop `30 removed`

After
```
Top
 |
20
 |
10
```
The top pointer moves down to the next node


---
## **Printing a Stack**
Example
```c++
void printStack()
{
    sNode* tmp = top;

    while(tmp != NULL)

    {

        cout << tmp->sData << endl;

        tmp = tmp->next;

    }
}
```
The stack is printed from top to bottom

---
## **Stack Output Example**

If we push: `1 2 3 4 5 6 7`

The stack contains
```
7
6
5
4
3
2
1
```

When popping
```
7
6
5
4
3
2
1
```
This demonstrates the LIFO behaviour of a stack

---
## **Stack Implementation Using Arrays**
Stacks can also be implemented using arrays

Example class
```c++
template <class Type>

class Stack

{
private:

    int size;

    Type* sPtr;

    int top;

public:

    ...
};
```

Key variables :
- Maximum stack size `size
- Array storing stack data `sPtr
- Index of the current top element `top`

---
## Array-Based Push

```c++
bool push(Type val)

{
    if(!isFull())

    {

        sPtr[++top] = val;

        return true;

    }

    return false;
}
```

Explanation
1. Increase top index
2. Store new value
3. Return success


---
## **Array-Based Pop**

```c++
bool pop(Type &data)
{
    if(!isEmpty())

    {

        data = sPtr[top--];

        return true;

    }

    return false;
}
```
Explanation
1. Retrieve value
2. Decrease top index
3. Returns success

---
## **WHAT IS A QUEUE?**

A Queue is another data structure that stores elements in a specific order

Think of a supermarket checkout line
- First customer enters first
- First customer leaves first

This is known as
` FIFO. First In First Out`

---
## **HOW DOES QUEUES WORK**

Insertion happens at the `Tail(Rear)`
Removal happens at the `Front`

Example
```
Front

10 -> 20 -> 30 -> 40

                Tail

```

If we dequeue `10 leaves first` because it entered first

---
## **QUEUE APPLICATIONS**

Queues are used in many-real world situations

Examples
- Processor Queue - Task execute in the order they arrive
- Keyboard Queue - Characters appear in the order typed
- Printer Queue - Documents print in the order received
- Router Queue - Network packets are sent in the order received

---
## **DEQUEUE FACTS**

When using arrays
```
Delete an item
-> Space becomes free
```
Instead of wasting those spaces, queue implementations often reuse them using circular indexing

---
## **QUEUE VARIABLES**

Typical queue implementations uses
```
front
tail
size
length
```

Meaning
- front -> Position of first item
- tail -> Position where new item is added
- length -> Current number of items
- size -> maximum capacity

---
## **ENQUEUE OPERATION**

Enqueue inserts an item at the tail

Example
```c++
bool enqueue(int val)
{
    if(length != size)

    {

        qPtr[tail] = val;

        tail = (tail + 1) % size;

        length++;

        return true;

    }

    return false;
}
```

### **How Enqueue Works**

Queue: `10 20 30`
Enqueue: `40`

Result: `10 20 30 40`
The new item is inserted at the back of the queue


---
## **DEQUEUE OPERATION**

Dequeue removes an item from the front

Example
```c++
bool dequeue(int &data)
{
    if(length != 0)

    {

        data = qPtr[front];

        front = (front + 1) % size;

        length--;

        return true;

    }

    return false;
}
```

### **How Dequeue Works**

Queue: `10 -> 20 -> 30 -> 40`
Dequeue: `removed`

Result: `20 -> 30 -> 40`
The first item inserted is the first item removed

---
## **STACK vs QUEUE**

#### **Stack**
- LIFO, Last In First Out
- Operations - Push, Pop
- Example - Stack of Plates

#### **Queue**
- FIFO, First In First Out
- Operations - Enqueue, Dequeue
- Example - Checkout line


---

## **COMMON EXAM QUESTIONS**

What is the difference between a Stack and a Queue?
- LIFO -> Last element added leaves first
- FIFO -> First element added leaves first

What operations inserts data into a Stack?
- Push

What operation removes data from a Stack?
- Pop

What operation inserts data into a Queue?
- Enqueue

What operation removes data from a Queue?
- Dequeue

Why is free( ) important?
- Because dynamically allocated memory must be released to avoid memory leaks


---
## **QUICK REFERENCE SUMARY**

Dynamic Memory
- malloc( ) allocates memory
- free( )  releases memory
- Always check for NULL after malloc( )

Stacks
- Follow LIFO
- Operations: Push and Pop
- Top pointer tracks the stack
- Can be implemented using linked lists or arrays

Queues
- Follow FIFO
- Operations: Enqueue and Dequeue
- Insert at tail
- Remove from front

Common Uses
- Stack: Function calls, expression evaluation
- Queue: Printing, processors, keyboards, routers

---
## **Final Exam Focus**

Prioritize these topics:
1. Difference between Stack and Queue.
2. LIFO vs FIFO.
3. Push and Pop operations.
4. Enqueue and Dequeue operations.
5. Dynamic memory allocation using `malloc()`.
6. Memory deallocation using `free()`.
7. Stack implementation using linked lists.
8. Stack implementation using arrays.
9. Queue implementation using arrays.
10. Real-world applications of stacks and queues.

If you can clearly explain the difference between **LIFO and FIFO**, and trace how **Push, Pop, Enqueue, and Dequeue** work step-by-step, you'll be in a very strong position for quizzes, tests, and the final exam.
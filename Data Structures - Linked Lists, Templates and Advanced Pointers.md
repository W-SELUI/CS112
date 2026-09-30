<h1>Data Structures - Linked Lists, Templates and Advanced Pointers</h1>

Pass Sessions Notes compiled by the PASS Leader - William Selui

---

# Introduction

This topic introduces one of the most important dynamic data structures in programming: the **Linked List**.

Unlike arrays, linked lists do not store elements in consecutive memory locations. Instead, each element (called a node) contains data and a reference to the next node in the sequence.

These notes cover:

- Singly Linked Lists
- Doubly Linked Lists
- Circular Linked Lists
- Linked List Operations
- Template Classes
- Pointer to Pointer (`**`)

Understanding these concepts is important because they form the foundation for many advanced data structures such as stacks, queues, trees, and graphs.

---

# 1. What Is a Linked List?

A Linked List is a dynamic collection of nodes connected using pointers.

Each node contains:

- Data
- A pointer to the next node

Example:
`10 → 20 → 30 → NULL

Each node stores a value and the memory address of the next node.
The final node points to `NULL`, indicating the end of the list.

---

## Why Use a Linked List?

Arrays have a fixed size and require contiguous memory.

Linked Lists provide:

- Dynamic growth
- Efficient insertion
- Efficient deletion
- Better memory flexibility

Because nodes are connected through pointers, they can be inserted or removed without shifting large amounts of data.

---

## Arrays vs Linked Lists

### Arrays

Advantages:

- Fast random access using indexes
- Simple implementation

Disadvantages:

- Fixed size
- Expensive insertion and deletion

### Linked Lists

Advantages:

- Dynamic size
- Easy insertion and deletion

Disadvantages:

- Sequential access only
- Extra memory required for pointers

---

# 2. Structure of a Node

The basic building block of a linked list is the node.

Example structure:

```c++
struct nodeType

{

    int info;

    nodeType* link;

};
```
Components:

- `info` stores the data
- `link` stores the address of the next node

Visual representation:

Plain Text
```
+------+------+

| 10   |  •---|---->

+------+------+
```

---

# 3. Basic Linked List Operations

Most linked list implementations support four fundamental operations.

## Traversing

Traversal means visiting every node in the list.

Example:
```
10 → 20 → 30 → NULL
```
Output:
```
10 20 30
```

Traversal continues until `NULL` is reached.

---

## Insertion
Insertion means adding new nodes into the list.

Common positions:
- Beginning
- End
- Middle

Example:

Before:
`10 → 20 → 30

Insert 15:
`10 → 15 → 20 → 30`

---

## Deletion
Deletion removes a node from the list.

Example:
Before:
`10 → 20 → 30`


Delete 20:
`10 → 30`

Pointers must be adjusted correctly to prevent losing access to remaining nodes.

---

## Searching

Searching involves moving through the list until a specific value is found.

Example:
``10 → 20 → 30 → 40

Search for 30:
```
10 ✓

20 ✓

30 Found
```

---

# 4. Singly Linked List

A Singly Linked List contains nodes that point only to the next node.

Example:
```
Head

 ↓

10 → 20 → 30 → NULL
```
Characteristics:
- One directional movement
- Less memory usage
- Simpler implementation

A pointer called `head` stores the address of the first node.

---

## The Head Pointer

The Head pointer is extremely important.

Example:
```
head

 ↓

10 → 20 → 30 → NULL
```

Without the head pointer, the entire list becomes inaccessible.
Always protect and update the head pointer carefully when inserting or deleting nodes.

---

# 5. Doubly Linked List

A Doubly Linked List stores two links.

Each node contains:
- Previous pointer
- Data
- Next pointer

Example:
```
NULL ← 10 ↔ 20 ↔ 30 → NULL
```

Advantages:
- Forward traversal
- Backward traversal
- Easier deletion in some cases

Disadvantages:
- More memory required
- More pointer management

---

## Singly vs Doubly Linked Lists

### Singly Linked List

``10 → 20 → 30
- One link
- Less memory
- Forward movement only

### Doubly Linked List
``10 ↔ 20 ↔ 30
- Two links
- More memory
- Forward and backward movement

---

# 6. Circular Linked Lists

A Circular Linked List has no NULL pointer at the end.
Instead, the last node points back to the first node.

Example:
```
10 → 20 → 30

↑         ↓

└─────────┘
```
This creates a circle.

---

## Why Use Circular Lists?

Useful for:
- Round-robin scheduling
- Multiplayer game turns
- Music playlists
- Repeating processes

Since the last node links back to the first node, traversal can continue indefinitely.

---

# 7. Circular Doubly Linked Lists

A Circular Doubly Linked List combines:

- Circular structure
- Previous links
- Next links

Example:
```
      ↔ 10 ↔

    ↗       ↘

 30           20

    ↖       ↙

       ↔
```
Benefits:
- Forward navigation
- Backward navigation
- Continuous looping

This is one of the most flexible linked-list structures.

---

# 8. Classes and Linked Lists

Linked Lists can be implemented using classes.

Benefits include:
- Encapsulation
- Reusability
- Better organization
- Data protection

Instead of storing everything in a struct, operations become class member functions.

Example operations:
```
insert()

deleteNode()

search()

print()

length()
```

Object-Oriented Programming makes linked list management easier for larger programs.

---

# 9. Linked List Construction and Destruction

When creating linked lists dynamically:
`new`
allocates memory.

When nodes are no longer needed:
`delete`
must be used.

---

## Why Is This Important?

Failing to delete unused nodes causes:
- Memory leaks
- Wasted memory
- Poor program performance

Always release dynamically allocated memory when finished.

---

# 10. Templates

Templates allow a single class or function to work with multiple data types.

Without templates:
```
int list

double list

string list
```
would all require separate implementations.

---

## Template Concept

Example:
```
template <class T>
```
or
```
template <typename T>
```
`T` represents a placeholder type.

The compiler replaces `T` with the actual data type when the program is compiled.

---

## Why Use Templates?

Advantages:
- Code reuse
- Less duplication
- Easier maintenance
- Greater flexibility

One linked list class can support:
```
LinkedList<int>

LinkedList<double>

LinkedList<string>
```
using the same code.

---

# 11. Pointer to Pointer (**)

A Pointer to Pointer stores the address of another pointer.

Example:
```
int x = 10;

int* p = &x;

int** pp = &p;
```

Visual representation:
```
x = 10

pp → p → x
```

---

## Levels of Indirection
`X`
Actual value.

`*p`
Value pointed to by p.

`**p`
Value reached through pp.

All three ultimately access the same value.

---

## Why Use Pointer to Pointer?

Common uses include:
- Dynamic memory structures
- Linked list manipulation
- Updating head pointers
- Multi-dimensional dynamic arrays

Pointer-to-pointer variables provide an additional level of control over memory addresses.

---

# 12. Common Exam Questions

## Why are linked lists considered dynamic?

Because nodes are created and removed during program execution, allowing the structure to grow or shrink as needed.

---

## What is the difference between an array and a linked list?

Array:
- Fixed size
- Direct index access

Linked List:
- Dynamic size
- Uses pointers
- Sequential access

---

## Why is a doubly linked list more flexible?

Because it allows movement in both directions through the list.

---

## What makes a circular linked list different?

The final node points back to the first node instead of NULL.

---

## Why are templates useful?

They allow one implementation to work with multiple data types.

---

## What is the purpose of a pointer to pointer?

It stores the address of another pointer and allows indirect access to data through multiple levels of referencing.

---

# Quick Reference Summary

### Linked Lists

- Dynamic collection of nodes.
- Nodes contain data and pointers.
- Support insertion, deletion, traversal, and searching.

### Singly Linked Lists

- One link per node.
- Forward traversal only.

### Doubly Linked Lists

- Previous and next links.
- Supports forward and backward traversal.

### Circular Linked Lists

- No NULL at the end.
- Last node points back to first node.

### Circular Doubly Linked Lists

- Circular structure with two-way traversal.

### Templates

- Generic programming tool.
- Works with multiple data types.
- Uses `template<class T>`.

### Pointer to Pointer
- Stores the address of another pointer.
- Written using `**`.
- Useful for advanced memory management.

---

# Final Exam Focus

Prioritize these topics:

1. Structure of a linked list node.
2. Linked list traversal, insertion, deletion, and searching.
3. Differences between singly, doubly, and circular linked lists.
4. Purpose of the head pointer.
5. Advantages and disadvantages of linked lists.
6. Dynamic memory using `new` and `delete`.
7. Template syntax and benefits.
8. How `template<class T>` works.
9. Understanding pointer-to-pointer (`**`).
10. Memory management and avoiding memory leaks.


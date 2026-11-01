
### **BINARY TREE**

##### **Pre-Order**
```c++
template <class dataType>
void preOrderTraverse (BinaryTreeNode <dataType>* bt)
{
    if ( ! (bt == NULL) )
    {
        //visit tree
        cout << bt -> getData ( ) << "\t";
        //traverse left child
        preOrderTraverse ( bt -> left ( ) );
        //traverse right child
        preOrderTraverse ( bt -> right ( ) );
    }
}
```


##### **In-Order**
```c++
template <class dataType>
void inOrderTraverse (BinaryTreeNode <dataType> * bt)
{
    if ( ! (bt == NULL) )
    {
        //traverse left child
        inOrderTraverse ( bt -> left ( ) );
        //visit tree
        cout << bt->getData ( ) << "\t";
        //traverse right child
        inOrderTraverse ( bt -> right ( ) );
    }
}
```

##### **Post-order**
```c++
template <class dataType>
void postOrderTraverse(BinaryTreeNode <dataType> * bt)
{
    if ( ! (bt == NULL) )
    {
        //traverse left child
        postOrderTraverse ( bt->left ( ) );
        //traverse right child
        postOrderTraverse ( bt -> right ( ) );
        //visit tree
        cout << bt -> getData ( ) << "\t";
    }
}
```

##### **What's the same in all three**
Every function has the same four parts:
1. The NULL checks: "Is there a box here?"
2. A recursive call on the left: `bt->left()
3. A recursive call on the right: `bt->right()`
4. The cout line, which prints the box

And the left call always comes before the right call

##### **What's different**
Only where the cout line sits

|            | Line 1 | Line 2 | Line 3 |
| ---------- | ------ | ------ | ------ |
| Pre-order  | cout   | left   | right  |
| In-order   | left   | cout   | right  |
| Post-order | left   | right  | cout   |
The `cout` line just slides down one spot each time: top, middle, bottom.

---
## **Quick Summary**

### 1. **Drawing the tree from main**
What to do: read main line by line and draws as you go
- insert("X") means put X in the box
- a->makeLeft(b) means draw b under a, on the left
- a->makeRight(b) means draw b under a, on the right

**Example**
```c++
BinaryTree * a = new BinaryTree;  a->insert(4);
BinaryTree * b = new BinaryTree;  b->insert(9);
BinaryTree * c = new BinaryTree;  c->insert(2);
c->makeRight(b);
c->makeLeft(a);
```

**Answer**
```
    2
   / \
  4   9
```

**Watch out:** the order of makeLeft and makeRight in the code doesn't matter. Only which one is left and which is right matters

---
#### 2. **Writing main to build a small tree**

What to do: build from the bottom up. Children first, then the parent, then link them.

**Example: build this tree**
```c++
    5
   / \
  3   8
```

**Answer:**
```c++
BinaryTree * left = new BinaryTree;   left->insert(3);
BinaryTree * right = new BinaryTree;  right->insert(8);

BinaryTree * root = new BinaryTree;   root->insert(5);
root->makeLeft(left);
root->makeRight(right);
```

**Why bottom up: you can't link the parent to a child that doesn't exist yet**

---
#### 3. **Writing isLeaf**
What to do: a leaf has no children, so both arrows are NULL

Answer
```c++
bool BinaryTree::isLeaf()
{
    return (leftTree == NULL && rightTree == NULL);
}
```
In plain words: "Is my left empty AND my right empty?" If both, I'm a leaf
Watch out: a box with only one child is not a leaf. Both must be NULL

---
4. **Giving the traversal output**
The three rules

| Order      | Rule            | Trick        |
| ---------- | --------------- | ------------ |
| Pre-order  | me, left, right | pre = before |
| In-order   | left, me, right | in = middle  |
| Post-order | left, right, me | post = after |
Example
```
        5
       / \
      2   7
     / \
    4   9
```

**Answers**
- Pre-order: 5 2 4 9 7
- In-order: 4 2 9 5 7
- Post-order: 4 9 2 7 5



----

# **LinkedList**

### **2023**
##### **Part A**
```c++
int main() {
    Node * n;
    Node * pHead;
    Node * pTail;          // points to the last node
    int value;
    char choice;

    pHead = NULL;          // list starts empty
    pTail = NULL;

    do {
        cout << "Enter an integer: ";
        cin >> value;

        n = new Node;      // build a new box
        n->data = value;   // put the number in it
        n->next = NULL;    // it's the last box, so nothing after it

        if (pHead == NULL) {     // list is empty?
            pHead = n;           // new box is the first box
            pTail = n;           // and also the last box
        }
        else {
            pTail->next = n;     // old last box points to new box
            pTail = n;           // new box is now the last box
        }

        cout << "Add another number? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    return 0;
}
```

##### **Part B**
```c++
cout << "The list contains: ";

n = pHead;                  // start at the first box
while (n != NULL)           // keep going while there's a box
{
    cout << n->data << " "; // print the number in this box
    n = n->next;            // move to the next box
}
cout << endl;
```


### **2024**

Part A
```
pHead
  ↓
┌────┬───┐     ┌────┬───┐     ┌────┬──────┐
│ 10 │ ●─┼───→ │ 20 │ ●─┼───→ │ 30 │ NULL │
└────┴───┘     └────┴───┘     └────┴──────┘

pHead
  ↓
┌────┬───┐     ┌────┬───┐     ┌────┬──────┐
│ 30 │ ●─┼───→ │ 20 │ ●─┼───→ │ 10 │ NULL │
└────┴───┘     └────┴───┘     └────┴──────┘
```

Part B
```c++
struct Node {
    int data;
    Node *next;
};

Node *reverseList(Node *head){
    Node *prev = NULL;     // the box behind (already flipped)
    Node *cur = head;      // the box we're on right now
    Node *next;            // the box ahead (saved before flipping)

    while (cur != NULL)
    {
        next = cur->next;  // 1. save the next box
        cur->next = prev;  // 2. flip this box's arrow backwards
        prev = cur;        // 3. move prev forward
        cur = next;        // 4. move cur forward
    }

    return prev;           // prev is the new first box
}
```

Part C
```c++
//assume pHead is given which is pointing to the head of the reversed list.

Node *temp = pHead;              // start at the first box
while (temp != NULL)             // keep going while there's a box
{
    cout << temp->data << " ";   // print this box's number
    temp = temp->next;           // move to the next box
}
```


**One note for the actual exam:** the paper already declares the three variables with its own names (`cur = NULL`, `next = head`, `prev`). Since they’re already written on the page, you’ll need to use those names in your loop. So learn it with the clear names above, but in the exam just swap them using this table:

| Our name | Exam's name |
| -------- | ----------- |
| prev     | cur         |
| cur      | next        |
| next     | prev        |

### **2025**

```c++
NODE *pHead;   // global head pointer

void promote_kth_to_head(int k)
{
    if (k <= 1 || pHead == NULL)     // already at the front, or empty list
        return;

    // 1. walk to the node BEFORE the kth node
    NODE *pPrev = pHead;
    for (int i = 1; i < k - 1; i++)
        pPrev = pPrev->pNext;

    // 2. grab the kth node
    NODE *pKth = pPrev->pNext;

    // 3. unlink it (the node before skips over it)
    pPrev->pNext = pKth->pNext;

    // 4. move it to the front
    pKth->pNext = pHead;
    pHead = pKth;
}
```


---
### **2024 Stacks**

```c++
// Function to reverse a string using the character stack
string reverseString(const string& s) {
    CharStack stack;          // GIVEN
    string reversed;          // GIVEN

    // 1. push every character of s onto the stack
    for (int i = 0; i < s.length(); i++)
    {
        stack.push(s[i]);
    }

    // 2. pop every character off and add it to reversed
    while (!stack.isEmpty())
    {
        reversed = reversed + stack.pop();
    }

    // 3. give back the reversed string
    return reversed;
}
```


---

## **OOP Concepts**

##### **Part A**
```c++
class hourlyEmp : public employee{
	private:
		int hours_worked;
		double wage;
		
	public: 
		hourlyEmp();
		~hourlyEmp();
		
		void set_hours_worked(double h );
		int get_hours_worked();
		
		void set_wage(double w);
		int get_wage();
		
		double calc_salary();

}; 
```

```c++
class commission : public employee {
public:
    commission();              // constructor
    ~commission();             // destructor

    void setSales(double c);
    float getSales();
    void setPercent(double p);
    float getPercent();

    float calc_salary();       // its own version: sales * percent

private:
    double sales;
    double percent;
};
```

##### **Part B**
```c++
void print_salary(employee * e)
{
    cout << "Name: " << e->getname() << endl;
    cout << "ID: " << e->getID() << endl;
    cout << "Salary: " << e->calc_salary() << endl;
}
```

This is the key idea of polymorphism. The function takes a pointer to **any** employee. It doesn’t know or care whether it’s hourly or commission. Because hourly and commission both **are** employees (through inheritance), a pointer to either one can go into `e`

You must use a **pointer** (or a reference), not a plain `employee e`. `employee` is abstract, so you can’t make an actual `employee` object, but a pointer to one is allowed.

##### **Part c**
```c++
int main()
{
    // create an hourly employee with dummy values
    hourly h;
    h.setname("John");
    h.setID("E001");
    h.setHours(40);
    h.setWage(10.5);

    // create a commission employee with dummy values
    commission c;
    c.setname("Mary");
    c.setID("E002");
    c.setSales(5000);
    c.setPercent(0.1);

    // call the polymorphic function for each one
    print_salary(&h);
    print_salary(&c);

    return 0;
}
```


---
### **2024**

##### **Part A**
```c++
class Shape {
public:
    virtual double area() = 0;   // pure virtual function
    virtual ~Shape() {}          // virtual destructor
};
```

##### **Part B**
```c++
class Rectangle : public Shape {
private:
    double length;
    double width;
public:
    Rectangle(double l, double w) {   // constructor
        length = l;
        width = w;
    }

    double area() {                   // its own version
        return length * width;
    }
};
```

```c++
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) {                // constructor
        radius = r;
    }

    double area() {                   // its own version
        return 3.14159 * radius * radius;
    }
};
```

##### **Part C**
```c++
int main(){
    //create Rectangle object

    Shape * rectangle;                       // GIVEN

    rectangle = new Rectangle(5, 3);         // make a Rectangle, store its address

    cout << "Area of rectangle: " << rectangle->area() << endl;

    delete rectangle;                        // free the memory
    return 0;
}
```

---
### **2025**

##### **Part A**
```c++
#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;      // attributes kept private (encapsulation)
    string author;

public:
    // parameterised constructor
    Book(string t, string a) {
        title = t;
        author = a;
    }

    // method to display the book details
    void printBook() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
    }
};

int main() {
    Book b1("Harry Potter", "J.K. Rowling");
    b1.printBook();
    return 0;
}
```


##### **Part B**
```c++
#include <iostream>
using namespace std;

// base class (abstract)
class Payment {
public:
    virtual void processPayment() = 0;   // pure virtual function
    //virtual ~Payment() {}                // virtual destructor
};

// derived class 1
class CreditCardPayment : public Payment {
public:
    void processPayment() override{
        cout << "Processing payment using Credit Card." << endl;
    }
};

// derived class 2
class PayPalPayment : public Payment {
public:
    void processPayment() {
        cout << "Processing payment using PayPal." << endl;
    }
};

int main() {
    // create objects and store them in pointers to Payment
    Payment * p1 = new CreditCardPayment();
    Payment * p2 = new PayPalPayment();

    // call processPayment through the base class pointers
    p1->processPayment();
    p2->processPayment();

    delete p1;
    delete p2;
    return 0;
}
```


## Section A: Multiple Choice

**1. Answer: d — Error, 0, or a random value**

The function is supposed to return an `int`, but it never uses `return`.

- **a. 5** — Wrong. Even though `x` starts as 5, that's not what gets returned (nothing is returned at all).
- **b. f(5)** — Wrong. This isn't a real value, it's just the function call itself. Doesn't make sense as output.
- **c. 10** — Wrong. Yes, `x` gets changed to 10 inside the function, but `x` is just a **local copy** of the parameter — changing it doesn't send 10 back out, and there's no `return` anyway.
- **d. Correct.** Since there's no `return` statement, the function doesn't properly give back a value. So whatever `cout` prints is undefined — could be 0, garbage, or your compiler might even flag it as an error.

---

**2. Answer: b — 3**

Quick heads-up: this code has a small typo — it should be `int *p = arr;` (with a `*`), otherwise it won't compile at all. Assuming that's what was meant:

- `arr` is an array, and `p` is a pointer that gets pointed at `arr`'s first element.
- `*p` means "give me the value **at** the address `p` is pointing to" → that's `arr[0]`, which is `3`.
- **a. Some address** — Wrong. This would be true if you printed `p` (without the `*`). But `*p` gives the _value_, not the address.
- **b. Correct.**
- **c. {3,4,5}** — Wrong. `*p` only ever gives ONE value, not the whole array.
- **d. an error** — Wrong (given the typo fix above). With `int *p = arr;`, this is perfectly valid code.
---

**3. Answer: c — Easy to organize the code**

- Classes let you group related data and functions together, which keeps big programs organized and manageable.
- **a. program becomes fast** — Wrong. Classes don't make code run faster — speed depends on your logic/algorithms, not whether you use classes.
- **b. Its easy to use the code** — Wrong. This is vague and not really the _main_ reason — "easy to use" isn't really specific to classes.
- **c. Correct.**
- **d. Have less bugs in the code** — Wrong. Classes don't automatically remove bugs. Good organization _can_ help you avoid some bugs, but it's not guaranteed or automatic.

---

**4. Answer: b — "private members are not inherited"** (the false statement)

This is the trickiest one. Here's the simple version:

- When a derived class inherits from a base class, **everything technically comes along for the ride** — including private members. They exist inside the derived object.
- BUT — the derived class just **can't directly access or use** those private members in its own code.
- So saying "private members are **not inherited**" is technically false — the correct way to say it is "private members are inherited but **not accessible**."
- **a. Inheritance helps in reusing code** — True (that's the whole point of inheritance), so NOT the answer.
- **c. derived class can inherit multiple base classes** — True in C++ (this is called multiple inheritance), so NOT the answer.
- **d. derived class can access protected members** — True, protected members ARE accessible to derived classes (unlike private), so NOT the answer.
- **b. Correct — this is the FALSE one**, for the reason above.

---

**5. Answer: c — n-1**

- a. n — Wrong. One index too far (off-by-one error), doesn't exist.
- b. n+1 — Wrong. Even further out of bounds.
- c. Correct. Arrays are zero-indexed, so with `n` elements, valid indexes run from 0 to n-1.
- d. 0 — Wrong. That's the index of the first element, not the last.

---

## Section B: Short Answers

**1. Three pillars of OOP**
- **Encapsulation** — keeping an object's data safe inside it, and only letting other code touch it through controlled methods (not directly messing with the data from outside).
- **Inheritance** — letting one class reuse and build on the code of another class, instead of rewriting it from scratch.
- **Polymorphism** — the same action/method name can behave differently depending on which object is using it.

Simple way to remember: **protect it, reuse it, and let it change shape.**

Encapsulation
```cpp
class Account {
	private:
		double balance;  // hidden from outside
	public:
		void deposit(double amt){ balance += amt; }
		double getBalance(){ return balance; }
};
```

Inheritance
```cpp
class Animal {
	public:
		void eat(){ cout << "eating"; }
};

class Dog : public Animal {
	public:
		void bark(){ cout << "barking"; }
};
```

Polymorphism
```cpp
class Animal {
	public:
		virtual void makeSound(){ cout << "..."; }
};

class Dog : public Animal {
	public:
		void makeSound() override { cout << "Bark!"; }
};

class Cat : public Animal {
	public:
		void makeSound() override { cout << "Meow!"; }
};
```

---

**2. Student–Course relationship — many-to-many**

Simple answer: it's a **"many-to-many" relationship**.

- One student can take many courses.
- One course can have many students.
- Neither one "owns" the other — a Student can still exist even if they're not enrolled in any Course, and a Course can still exist even with no students yet.

**Assumption to mention:** A student can be enrolled in zero, one, or many courses at once — and same for a course, it can have zero, one, or many students.

```cpp
#include <vector>
using namespace std;

class Course; // tell compiler Course exists

class Student {
	public:
		string name;
		vector<Course*> courses; // a student can have many courses
};

class Student; // tell compiler Student exists

class Course {
	public:
		string title;
		vector<Student*> students; // a course can have many students
};
```

---

**3. Constructor**

Simple answer: its job is to **set up the object when it's first created** — giving its variables starting values so the object is ready to use right away, instead of being empty or messy.

Think of it like: when you build a new car, the constructor is what fills the tank with gas and sets the seat position **before** you drive off — it preps the object for use.

```cpp
class Car {
	public:
		int fuel;
		
		Car(){          // constructor
			fuel = 100;  // sets starting value automatically
		}
};

int main(){
	Car myCar;                    // constructor runs here automatically
	cout << myCar.fuel;           // prints 100, already set up
}
```

---

**4. Method overriding**

Simple answer: it lets a **child class change how a method works**, while still keeping the same method name as the parent.

So different objects can respond differently to the _same_ instruction. For example, if you have a `makeSound()` method:

- Parent class `Animal` has a generic `makeSound()`.
- Child class `Dog` overrides it to bark.
- Child class `Cat` overrides it to meow.

Same method name, different behavior depending on which object you're calling it on. That's what makes it useful — you can treat all animals the same way in your code, and each one still "does its own thing."

```cpp
class Animal {
	public:
		virtual void makeSound(){
			cout << "Some generic animal sound";
		}
};

class Dog : public Animal {
	public:
		void makeSound() override {
			cout << "Bark!";
		}
};

int main(){
	Animal *a = new Dog();
	a->makeSound();   // prints "Bark!" — Dog's version runs, not Animal's
}
```


---

## **Section C : Program Writing**

### **Question 1**

#### **What's wrong:**
Look at `Point`'s constructor — `Point(){;}` — it's sitting under `private:`.
Then look at `Circle`'s constructor, at line 25: `:Point()`. This is `Circle` trying to call `Point`'s constructor.

#### **The problem:** 
`Point`'s constructor is private, and private things can only be used inside the `Point` class itself. `Circle` is a completely different class — even though it inherits from `Point`, it still counts as "outside" for access rules. So `Circle` is not allowed to call `Point()` here. This won't compile.

#### **Line number(s):** 7 (`private:`) — this is where the problem starts.

#### **How to correct it:**
Change `private:` to `protected:` on line 7. Protected still blocks outside classes from calling it, but it specifically allows derived classes (like `Circle`) to call it. That's exactly the access `Circle` needs.

```c++
class point{
	protected:
		point(){;}
		int x;
		int y;
}
```
**Line numbers(7)**


### **Question 2**

**a. Why is there no implementation for `area()` in `Shape`?**

Because of the `= 0` at the end of it. This is called a **pure virtual function**. It means `Shape` is not giving any actual code for `area()` — it's just saying "every class that inherits from me **must** write their own `area()`."

This also makes `Shape` an **abstract class**, meaning you can never write `Shape s;` directly — it only exists to be inherited from.

b. Complete area( ) and Circle

```c++
virtual float area(){
	return 3.14 * radius * radius;
}
```
This is just the normal circle area formula (π × r × r), using the `radius` variable that's already stored in the object.

c. Using a Shape* pointer, call area( ) for a Circle with radius 5 

```c++
Shape *s;
s = new Circle(5);
cout << s->area();
```

Step by step:

- `Shape *s;` — this just creates a pointer, it doesn't create an actual object yet.
- `s = new Circle(5);` — this creates an actual `Circle` object (with radius 5) on the heap, and `s` now points to it.
- `s->area();` — this calls `area()` through the pointer. Even though `s` is typed as `Shape*`, because `area()` is `virtual`, it runs **Circle's** version of `area()`, not `Shape`'s (which has no version anyway).


### **Question 3: Print all 5 students**

```c++
struct Student{
	int id;
	string name;
};

int main(){
	Student s[5] = {
			{101, "Ali"},
			{102, "Ravi"},
			{103, "Lina"},
			{104, "Maya"},
			{105, "John"}
		};
		
	for(int i = 0; i < 5; i++){
		cout << s[i].id << " " << s[i].name << endl;
	}
}
```

**How this works:**

- `s` is an array holding 5 `Student` structs, at index positions `0` to `4`.
- The `for` loop starts `i` at `0` and runs while `i < 5`, so it touches every index exactly once: 0, 1, 2, 3, 4.
- `s[i]` gets you the student at that index.
- `s[i].id` and `s[i].name` — the `.` lets you reach inside that struct and grab its `id` and `name` values.
- `endl` just moves to a new line after each student, so the output is neat.


---

# **Extra Notes**

### **Step 1: `Shape *s;`**

```cpp
Shape *s;
```

This line creates a **pointer** named `s`. A pointer is just a variable that stores a **memory address** — think of it as a variable that holds "the location of something," not the actual something itself.

The type `Shape *` means: "this pointer is allowed to point at a `Shape` object (or anything that inherits from `Shape`)."

Right now, `s` doesn't point at anything real yet — no actual object has been created. It's just an empty pointer variable sitting there.

### **Step 2: `s = new Circle(5);`**

```cpp
s = new Circle(5);
```

This line has two things happening:

1. **`new Circle(5)`** — this actually **creates a real `Circle` object** in memory (on what's called the "heap"). It calls `Circle`'s constructor with `radius = 5`. So now, somewhere in memory, there's a real `Circle` object sitting there with `radius` set to `5`.
2. **`s = ...`** — this takes the memory address of that new `Circle` object and stores it inside `s`.

So after this line: `s` is a `Shape*` pointer, but it's actually pointing at a `Circle` object. This is allowed because `Circle` **is a** `Shape` (it inherits from `Shape`), so a `Shape*` pointer is allowed to point at it.

Important: `s`'s **type** is `Shape*`. But what it's **pointing at** is a real `Circle` object. These are two different things — the type of the pointer, and the actual object it points to.

### **Step 3: `cout << s->area();`**

```cpp
cout << s->area();
```

`s->area()` means: "go to the object that `s` is pointing at, and call its `area()` function."

Here's the key question: since `s` is typed as `Shape*`, does it call `Shape`'s `area()` or `Circle`'s `area()`?

**Answer: it calls `Circle`'s `area()`.**

Why? Because `area()` was declared as `virtual` in `Shape`. The `virtual` keyword tells the compiler: "Don't decide which version of this function to run based on the pointer's type. Instead, at the moment the program actually runs, check what object is _really_ sitting there, and run **that object's** version."

So even though `s` is "labeled" as a `Shape*`, the program looks at what `s` is actually pointing to — a `Circle` — and runs `Circle`'s `area()` function.

This is why `Shape::area()` didn't need real code (`= 0`) — it's never actually called. It only exists so that any pointer of type `Shape*` is guaranteed to have an `area()` function available to call, and `virtual` makes sure the **correct, actual** version always runs.

**If `area()` had NOT been marked `virtual`:** then `s->area()` would have just called `Shape`'s version directly, based on `s`'s declared type — completely ignoring the fact that it's really pointing at a `Circle`. That would be the wrong, broken behavior — which is exactly why `virtual` is used here.


---

### **Why are we using a pointer at all?**

Two connected reasons:
**Reason 1: `Shape` can't be created directly.**
Remember, `Shape` has:

```cpp
virtual float area() = 0;
```

That `= 0` makes `area()` a **pure virtual function**, which makes `Shape` an **abstract class**. Abstract classes cannot be created as actual objects — this line would fail to compile:

```cpp
Shape s;  // ERROR — not allowed
```

C++ blocks this because `Shape` is incomplete on purpose — it has a function with no body. You're not supposed to make a plain `Shape`, only specific shapes like `Circle`, `Square`, etc.

**Reason 2: We want ONE variable that can hold ANY kind of shape.**
Say later you also have a `Square` class that inherits from `Shape`. If you write a function like:

```cpp
void printArea(Shape *s){
	cout << s->area();
}
```

You can now pass in a `Circle`, a `Square`, or any other shape — the **same function works for all of them**. That's the whole point of `Shape` existing: it's a common "label" so different shape types can all be handled the same way, through one pointer type.

A pointer is what makes this flexible matching possible — a `Shape*` pointer is allowed to point at any object that inherits from `Shape`, whatever type it actually is underneath.

### **Why `new Circle(5)` and not `new Shape(5)`?**

Because **`new Shape(...)` isn't even allowed.** Since `Shape` is abstract (has that pure virtual `area()`), you cannot create a `Shape` object at all — not with `new`, not any way:

```cpp
Shape *s = new Shape();  // ERROR — Shape is abstract, cannot be instantiated
```

So we must create an actual **real, concrete** object — something that has fully filled in every function `Shape` demanded. `Circle` did that: it wrote the actual code for `area()`. So `Circle` is allowed to be created with `new`, and `Shape` is not.

**Putting it together:**

- `Shape` = just a category/rule saying "anything calling itself a Shape must have an `area()` function" — but it's not a real object you can make.
- `Circle` = an actual real shape that follows that rule and can be created.
- The pointer `s` (typed `Shape*`) is just a flexible "handle" that can point at any real object that followed `Shape`'s rule — in this case, a `Circle`.

### **What is an abstract class?**

**A class that has at least one pure virtual function, and because of that, cannot be used to create objects directly.**

A pure virtual function is one written like this — with `= 0` at the end and no actual code:

```cpp
virtual float area() = 0;
```

That single function is enough to make the whole class abstract. You can try, but this won't compile:

```cpp
Shape s;           // ERROR
Shape *s = new Shape();  // ERROR
```

### **What is its main use?**

**To define a common interface (a set of functions) that all derived classes are forced to implement, without giving any implementation itself.**

In plain terms: an abstract class is used to say _"every shape must have an `area()` function"_ — without saying _how_ to calculate that area, because that depends on the specific shape. `Circle` calculates it one way, `Square` would calculate it a different way — but both are guaranteed to _have_ an `area()` function, because `Shape` demanded it.

This lets you write code that works generically with **any** derived type, through a base class pointer:

```cpp
Shape *s = new Circle(5);
cout << s->area();   // works no matter what shape it actually is
```

**If your exam wants a short one-liner answer, this works well:**

> An abstract class is a class containing at least one pure virtual function, so it cannot be instantiated. Its main use is to define a common interface that derived classes must implement, enabling polymorphism.

---

**Section A: Multiple Choice**

1. Consider the following C++ code

```c++
void f(int &x){
	x=20;
}
```

What is the outcome of the following statement used in main( )?

a. 5
b. 20
c. 0
d. Error, function must return a value

2. What is the outcome of the following C++ program?
```c++
int arr[] ={7,8,9};
int *p = arr;
cout << *(p+2);
```

a. 7
b. 8
c. 9
d. An address

3. Why is encapsulation recommended when designing large programs?

a. It makes the program runs faster
b. It protects an object's internal state from unintended external access
c. It removes the need for constructors
d. It allows a class to inherit from multiple classes

4. Which of the following is false about inheritance in c++ ?

a. A derived class can access public members of the base class
b. It protects an object's internal state from unintended external access
c. It removes the need for constructors
d. It allows a class to inherit from multiple classes

4. Which of the following is false about inheritance in C++?

a. A derived class can access public members of the base class
b. Private members of the base class are not directly accessible in the derived class
c.  A base class constructor is always inherited and reused unchanged
d. A derived class can override a base class's virtual function

5. If a 2D array is declared as `int arr [3][4]` how many total elements does it hold?

a. 7
b. 12
c. 3
d. 4



---

**Section B: Short Answers**

1. What is the difference between pass-by-value and pass-by-reference in C++ ?

2. What kind of relationship should exist between a library and a Book class? State any special assumptions you may have.

3. What is the main role of a destructor in C++?

4. Why is polymorphism useful in object-oriented design?


---

**Section C: Program Writing**

1. What is wring with the following code? How would you correct it without entirely removing the chosen code snippet? Mention line numbers in your answer.

```c++
class Animal{ //line 6
	private:
		Aniaml()[;}
	protected:
		int age;
		string name;
};

class Dog: public Animal{
	private:
		Dog();
	public:
		string breed;
		
};

Dog::Dog()
:Animal(){
	;
} //line 25
```

What is wrong?
Line number(s)?
How to correct?
Line number(s)?

2. Consider the following code and answer the given questions

```c++
class Shape{
	public:
		virtual float perimeter() = 0;
};

class Rectangle: public Shape{
	private:
		Rectangle(){;}
	public:
		Rectangle(float length, float width){
			this->length = length;
			this->width = width;
		}
		float length;
		float width;
		virtual float perimeter() //complete this code
		
};

int main()
{
	Shape *s;
	//To Do
```

a. Why is there NO Implementation for the perimeter( ) method in the Shape Class?

b. Complete the Implementation for the perimeter( ) method in the Rectangle class?

c. Using the Shape pointer declared above, show how you can call the perimeter( ) method of a Rectangle object with length 4 and width 6 `[Hint: you may need more than one line of code to accomplish this]` 

3. Consider the following code

```c++
#include <iostream>
using namespace std;

struct Book{
	int id;
	string title;
};

int main(){
	Book b[5] = {
		{201, "Dune"},
		{202, "Emma"},
		{203, "IT"},
		{204, "Kim"},
		{205, "Room"}
	};
	
	//To Do
}
```

Task: Complete the main( ) to print the id and title of all 5 books using a loop


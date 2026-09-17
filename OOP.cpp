#include <iostream>
#include <string>
using namespace std;

// ----- ABSTRACTION + ENCAPSULATION -----
// Animal is now an abstract class — it defines *what* every animal must do,
// but not *how*. You can't create an Animal object directly anymore.
class Animal {
private:
    string name;   // hidden from outside access

protected:
    int age;       // accessible to derived classes

public:
    Animal(string n, int a) : name(n), age(a) {}

    string getName() const { return name; }  // controlled access (getter)

    void setAge(int a) {                     // controlled access (setter)
        if (a >= 0) age = a;                 // validation logic hidden inside
    }

    int getAge() const { return age; }

    // Pure virtual function -> makes Animal abstract.
    // Every subclass MUST provide its own implementation.
    virtual void makeSound() const = 0;

    virtual ~Animal() {}  // virtual destructor for safe cleanup
};

// ----- INHERITANCE -----
class Dog : public Animal {
public:
    Dog(string n, int a) : Animal(n, a) {}

    // ----- POLYMORPHISM (method overriding) -----
    void makeSound() const override {
        cout << getName() << " says: Woof! Woof!" << endl;
    }
};

class Cat : public Animal {
public:
    Cat(string n, int a) : Animal(n, a) {}

    void makeSound() const override {
        cout << getName() << " says: Meow!" << endl;
    }
};

class Bird : public Animal {
public:
    Bird(string n, int a) : Animal(n, a) {}

    void makeSound() const override {
        cout << getName() << " says: Tweet tweet!" << endl;
    }
};

int main() {
    // Animal a("generic", 1);  // ERROR: can't instantiate an abstract class

    Dog dog("Rex", 3);
    Cat cat("Whiskers", 2);
    Bird bird("Tweety", 1);

    // Polymorphism in action: base class pointer, different behavior at runtime
    Animal* animals[3] = { &dog, &cat, &bird };

    for (Animal* a : animals) {
        a->makeSound();  // calls the correct overridden version for each type
    }

    // Encapsulation in action: can't touch 'name' directly, must use getter/setter
    dog.setAge(4);
    cout << dog.getName() << " is now " << dog.getAge() << " years old." << endl;

    return 0;
}

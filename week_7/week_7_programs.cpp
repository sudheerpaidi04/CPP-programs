// WEEK 7 - C++ Programming Lab Programs
// Program 7a: Different Types of Inheritance
// Program 7b: Order of Constructor and Destructor Execution in Inheritance

#include<iostream>
#include<string>
using namespace std;

// ========== PROGRAM 7A: DIFFERENT TYPES OF INHERITANCE ==========

// SINGLE INHERITANCE
class Animal {
protected:
    string name;
public:
    void setName(string n) {
        name = n;
    }
};

class Dog : public Animal {
public:
    void display() {
        cout << "Dog's name: " << name << endl;
    }
};

// MULTIPLE INHERITANCE
class Father {
protected:
    string fatherName;
public:
    void setFatherName(string n) {
        fatherName = n;
    }
};

class Mother {
protected:
    string motherName;
public:
    void setMotherName(string n) {
        motherName = n;
    }
};

class Child : public Father, public Mother {
public:
    void display() {
        cout << "Father's name: " << fatherName << endl;
        cout << "Mother's name: " << motherName << endl;
    }
};

// MULTILEVEL INHERITANCE
class GrandParent {
protected:
    int grandAge;
public:
    void setGrandAge(int a) {
        grandAge = a;
    }
};

class Parent : public GrandParent {
protected:
    int parentAge;
public:
    void setParentAge(int a) {
        parentAge = a;
    }
};

class GrandChild : public Parent {
public:
    void display() {
        cout << "Grandparent's age: " << grandAge << endl;
        cout << "Parent's age: " << parentAge << endl;
    }
};

// HIERARCHICAL INHERITANCE
class Shape {
protected:
    float dimension;
public:
    void setDimension(float d) {
        dimension = d;
    }
};

class Square : public Shape {
public:
    float area() {
        return dimension * dimension;
    }
};

class Circle : public Shape {
public:
    float area() {
        return 3.14 * dimension * dimension;
    }
};

void program7a() {
    cout << "\n========== PROGRAM 7A: TYPES OF INHERITANCE ==========\n";
    
    // Single Inheritance
    cout << "\n1. SINGLE INHERITANCE:\n";
    Dog d;
    d.setName("Buddy");
    d.display();
    
    // Multiple Inheritance
    cout << "\n2. MULTIPLE INHERITANCE:\n";
    Child c;
    c.setFatherName("John");
    c.setMotherName("Mary");
    c.display();
    
    // Multilevel Inheritance
    cout << "\n3. MULTILEVEL INHERITANCE:\n";
    GrandChild gc;
    gc.setGrandAge(70);
    gc.setParentAge(45);
    gc.display();
    
    // Hierarchical Inheritance
    cout << "\n4. HIERARCHICAL INHERITANCE:\n";
    Square sq;
    sq.setDimension(5);
    cout << "Square area: " << sq.area() << endl;
    
    Circle ci;
    ci.setDimension(5);
    cout << "Circle area: " << ci.area() << endl;
}

// ========== PROGRAM 7B: CONSTRUCTOR AND DESTRUCTOR ORDER ==========
class Base1 {
public:
    Base1() {
        cout << "Base1 constructor called\n";
    }
    ~Base1() {
        cout << "Base1 destructor called\n";
    }
};

class Base2 {
public:
    Base2() {
        cout << "Base2 constructor called\n";
    }
    ~Base2() {
        cout << "Base2 destructor called\n";
    }
};

class Derived : public Base1, public Base2 {
public:
    Derived() {
        cout << "Derived constructor called\n";
    }
    ~Derived() {
        cout << "Derived destructor called\n";
    }
};

void program7b() {
    cout << "\n========== PROGRAM 7B: CONSTRUCTOR/DESTRUCTOR ORDER ==========\n";
    cout << "\nCreating derived object...\n";
    Derived obj;
    cout << "\nObject created. Now going out of scope...\n";
}

// ========== MAIN FUNCTION ==========
int main() {
    int choice;
    
    do {
        cout << "\n\n========================================";
        cout << "\n      WEEK 7 - PROGRAM MENU";
        cout << "\n========================================";
        cout << "\n1. Program 7a: Types of Inheritance";
        cout << "\n2. Program 7b: Constructor/Destructor Order";
        cout << "\n3. Run All Programs";
        cout << "\n4. Exit";
        cout << "\n========================================";
        cout << "\nEnter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                program7a();
                break;
            case 2:
                program7b();
                break;
            case 3:
                program7a();
                program7b();
                break;
            case 4:
                cout << "\nExiting program...\n";
                break;
            default:
                cout << "\nInvalid choice! Please try again.\n";
        }
    } while(choice != 4);
    
    return 0;
}

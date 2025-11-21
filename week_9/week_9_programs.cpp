// WEEK 9 - C++ Programming Lab Programs
// Program 9a: Virtual Functions and Runtime Polymorphism
// Program 9b: Pure Virtual Functions and Abstract Classes

#include<iostream>
#include<string>
using namespace std;

// ========== PROGRAM 9A: VIRTUAL FUNCTIONS AND RUNTIME POLYMORPHISM ==========
class Shape {
protected:
    float dimension1, dimension2;
public:
    void setDimensions(float d1, float d2) {
        dimension1 = d1;
        dimension2 = d2;
    }
    
    // Virtual function for runtime polymorphism
    virtual void area() {
        cout << "Area calculation for generic shape\n";
    }
    
    virtual void display() {
        cout << "This is a shape\n";
    }
};

class Rectangle : public Shape {
public:
    void area() override {
        cout << "Rectangle Area: " << (dimension1 * dimension2) << endl;
    }
    
    void display() override {
        cout << "This is a Rectangle\n";
    }
};

class Triangle : public Shape {
public:
    void area() override {
        cout << "Triangle Area: " << (0.5 * dimension1 * dimension2) << endl;
    }
    
    void display() override {
        cout << "This is a Triangle\n";
    }
};

void program9a() {
    cout << "\n========== PROGRAM 9A: VIRTUAL FUNCTIONS ==========\n";
    
    Shape *ptr;
    Rectangle rect;
    Triangle tri;
    
    // Pointing to Rectangle
    ptr = &rect;
    ptr->setDimensions(10, 5);
    cout << "\nUsing base class pointer for Rectangle:\n";
    ptr->display();
    ptr->area();
    
    // Pointing to Triangle
    ptr = &tri;
    ptr->setDimensions(10, 5);
    cout << "\nUsing base class pointer for Triangle:\n";
    ptr->display();
    ptr->area();
    
    cout << "\nNote: Virtual functions enable runtime polymorphism!\n";
}

// ========== PROGRAM 9B: PURE VIRTUAL FUNCTIONS AND ABSTRACT CLASSES ==========
class Animal {
protected:
    string name;
public:
    void setName(string n) {
        name = n;
    }
    
    // Pure virtual functions - makes this an abstract class
    virtual void sound() = 0;
    virtual void move() = 0;
    
    void display() {
        cout << "Animal: " << name << endl;
    }
};

class Dog : public Animal {
public:
    void sound() override {
        cout << "Sound: Woof! Woof!" << endl;
    }
    
    void move() override {
        cout << "Movement: Running on four legs" << endl;
    }
};

class Bird : public Animal {
public:
    void sound() override {
        cout << "Sound: Tweet! Tweet!" << endl;
    }
    
    void move() override {
        cout << "Movement: Flying in the sky" << endl;
    }
};

class Fish : public Animal {
public:
    void sound() override {
        cout << "Sound: Blub! Blub!" << endl;
    }
    
    void move() override {
        cout << "Movement: Swimming in water" << endl;
    }
};

void program9b() {
    cout << "\n========== PROGRAM 9B: ABSTRACT CLASSES ==========\n";
    
    // Cannot create object of abstract class Animal
    // Animal a; // This would cause error
    
    Animal *ptr;
    Dog dog;
    Bird bird;
    Fish fish;
    
    // Dog
    ptr = &dog;
    ptr->setName("Buddy");
    cout << "\n";
    ptr->display();
    ptr->sound();
    ptr->move();
    
    // Bird
    ptr = &bird;
    ptr->setName("Tweety");
    cout << "\n";
    ptr->display();
    ptr->sound();
    ptr->move();
    
    // Fish
    ptr = &fish;
    ptr->setName("Nemo");
    cout << "\n";
    ptr->display();
    ptr->sound();
    ptr->move();
    
    cout << "\nNote: Abstract class cannot be instantiated!\n";
}

// ========== MAIN FUNCTION ==========
int main() {
    int choice;
    
    do {
        cout << "\n\n========================================";
        cout << "\n      WEEK 9 - PROGRAM MENU";
        cout << "\n========================================";
        cout << "\n1. Program 9a: Virtual Functions";
        cout << "\n2. Program 9b: Abstract Classes";
        cout << "\n3. Run All Programs";
        cout << "\n4. Exit";
        cout << "\n========================================";
        cout << "\nEnter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                program9a();
                break;
            case 2:
                program9b();
                break;
            case 3:
                program9a();
                program9b();
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

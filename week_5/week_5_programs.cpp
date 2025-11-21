// WEEK 5 - C++ Programming Lab Programs
// Program 5a: Constructors and Destructors
// Program 5b: Constructor Overloading
// Program 5c: Copy Constructor

#include<iostream>
#include<string>
using namespace std;

// ========== PROGRAM 5A: CONSTRUCTORS AND DESTRUCTORS ==========
class Demo {
private:
    int value;
public:
    // Constructor
    Demo(int v) {
        value = v;
        cout << "Constructor called with value: " << value << endl;
    }
    
    // Destructor
    ~Demo() {
        cout << "Destructor called for value: " << value << endl;
    }
    
    void display() {
        cout << "Value: " << value << endl;
    }
};

void program5a() {
    cout << "\n========== PROGRAM 5A: CONSTRUCTORS AND DESTRUCTORS ==========\n";
    cout << "Creating objects...\n";
    Demo obj1(10);
    Demo obj2(20);
    cout << "\nDisplaying objects:\n";
    obj1.display();
    obj2.display();
    cout << "\nObjects going out of scope...\n";
}

// ========== PROGRAM 5B: CONSTRUCTOR OVERLOADING ==========
class Rectangle {
private:
    int length, width;
public:
    // Default constructor
    Rectangle() {
        length = 0;
        width = 0;
        cout << "Default constructor called\n";
    }
    
    // Parameterized constructor with one parameter
    Rectangle(int side) {
        length = side;
        width = side;
        cout << "Constructor with one parameter called (Square)\n";
    }
    
    // Parameterized constructor with two parameters
    Rectangle(int l, int w) {
        length = l;
        width = w;
        cout << "Constructor with two parameters called\n";
    }
    
    int area() {
        return length * width;
    }
    
    void display() {
        cout << "Length: " << length << ", Width: " << width << ", Area: " << area() << endl;
    }
};

void program5b() {
    cout << "\n========== PROGRAM 5B: CONSTRUCTOR OVERLOADING ==========\n";
    Rectangle r1;              // Default constructor
    Rectangle r2(5);           // One parameter (square)
    Rectangle r3(4, 6);        // Two parameters
    
    cout << "\nDisplaying rectangles:\n";
    cout << "Rectangle 1: ";
    r1.display();
    cout << "Rectangle 2 (Square): ";
    r2.display();
    cout << "Rectangle 3: ";
    r3.display();
}

// ========== PROGRAM 5C: COPY CONSTRUCTOR ==========
class Student {
private:
    int rollNo;
    string name;
    float marks;
public:
    // Parameterized constructor
    Student(int r, string n, float m) {
        rollNo = r;
        name = n;
        marks = m;
        cout << "Parameterized constructor called for " << name << endl;
    }
    
    // Copy constructor
    Student(const Student &s) {
        rollNo = s.rollNo;
        name = s.name;
        marks = s.marks;
        cout << "Copy constructor called for " << name << endl;
    }
    
    void display() {
        cout << "Roll No: " << rollNo << ", Name: " << name << ", Marks: " << marks << endl;
    }
};

void program5c() {
    cout << "\n========== PROGRAM 5C: COPY CONSTRUCTOR ==========\n";
    Student s1(101, "Alice", 85.5);
    cout << "\nCreating copy of student:\n";
    Student s2 = s1;  // Copy constructor called
    
    cout << "\nDisplaying original student:\n";
    s1.display();
    cout << "\nDisplaying copied student:\n";
    s2.display();
}

// ========== MAIN FUNCTION ==========
int main() {
    int choice;
    
    do {
        cout << "\n\n========================================";
        cout << "\n      WEEK 5 - PROGRAM MENU";
        cout << "\n========================================";
        cout << "\n1. Program 5a: Constructors and Destructors";
        cout << "\n2. Program 5b: Constructor Overloading";
        cout << "\n3. Program 5c: Copy Constructor";
        cout << "\n4. Run All Programs";
        cout << "\n5. Exit";
        cout << "\n========================================";
        cout << "\nEnter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                program5a();
                break;
            case 2:
                program5b();
                break;
            case 3:
                program5c();
                break;
            case 4:
                program5a();
                program5b();
                program5c();
                break;
            case 5:
                cout << "\nExiting program...\n";
                break;
            default:
                cout << "\nInvalid choice! Please try again.\n";
        }
    } while(choice != 5);
    
    return 0;
}

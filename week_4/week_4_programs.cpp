// WEEK 4 - C++ Programming Lab Programs
// Program 4a: Function Overloading
// Program 4b: Default Arguments
// Program 4c: Friend Function

#include<iostream>
#include<string>
using namespace std;

// ========== PROGRAM 4A: FUNCTION OVERLOADING ==========
class justin {
public:
    void display() {
        cout << "I am display function without any parameters" << endl;
    }
    
    void display(string a) {
        cout << "I am display function with parameter string: " << a << endl;
    }
    
    void display(int a) {
        cout << "I am display function with parameter int: " << a << endl;
    }
    
    int display(int a, int b) {
        return a + b;
    }
};

void program4a() {
    cout << "\n=== Program 4a: Function Overloading ===\n";
    justin v;
    cout << "The sum of two numbers is: " << v.display(17, 18) << endl;
    v.display();
    v.display(12);
    v.display("little biber");
}

// ========== PROGRAM 4B: DEFAULT ARGUMENTS ==========
void patient(int id = 11, string name = "jordan", string disease = "fever") {
    cout << "Patient id: " << id << endl;
    cout << "Patient name: " << name << endl;
    cout << "Patient disease: " << disease << endl << endl;
}

void program4b() {
    cout << "\n=== Program 4b: Default Arguments ===\n";
    patient(25, "Abel", "cold");
    patient(28);
    patient();
}

// ========== PROGRAM 4C: FRIEND FUNCTION ==========
class B;
class C;

class A {
private:
    int a;
    friend int sum(A, B, C);
public:
    A() { a = 10; }
};

class B {
private:
    int b;
    friend int sum(A, B, C);
public:
    B() { b = 10; }
};

class C {
private:
    int c;
    friend int sum(A, B, C);
public:
    C() { c = 10; }
};

int sum(A obj, B bobj, C cobj) {
    return obj.a + bobj.b + cobj.c;
}

void program4c() {
    cout << "\n=== Program 4c: Friend Function ===\n";
    A obj;
    B bobj;
    C cobj;
    cout << "The sum value: " << sum(obj, bobj, cobj) << endl;
}

// ========== MAIN FUNCTION ==========
int main() {
    int choice;
    cout << "\n*** WEEK 4 - C++ PROGRAMS ***\n";
    cout << "1. Program 4a: Function Overloading\n";
    cout << "2. Program 4b: Default Arguments\n";
    cout << "3. Program 4c: Friend Function\n";
    cout << "4. Run All Programs\n";
    cout << "Enter your choice: ";
    cin >> choice;
    
    switch(choice) {
        case 1:
            program4a();
            break;
        case 2:
            program4b();
            break;
        case 3:
            program4c();
            break;
        case 4:
            program4a();
            program4b();
            program4c();
            break;
        default:
            cout << "Invalid choice!" << endl;
    }
    
    return 0;
}

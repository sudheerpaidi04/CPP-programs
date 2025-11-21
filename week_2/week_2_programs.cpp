// WEEK 2 - C++ Programming Lab Programs
// Program 2a: Scope Resolution Operator and Namespaces
// Program 2b: Inline Functions

#include <iostream>
using namespace std;

// ========== PROGRAM 2A: SCOPE RESOLUTION OPERATOR AND NAMESPACES ==========
int value = 100; // Global variable

namespace weeknd {
    int value = 200;
    void display() {
        cout << "Inside namespace weeknd, value = " << value << endl;
    }
}

void program2a() {
    int value = 300; // Local variable
    cout << "\n=== Program 2a: Scope Resolution Operator and Namespaces ===\n";
    cout << "Local value = " << value << endl;
    cout << "Global value = " << ::value << endl;
    cout << "Namespace weeknd value = " << weeknd::value << endl;
    weeknd::display();
}

// ========== PROGRAM 2B: INLINE FUNCTIONS ==========
inline double cube(int a) {
    return a * a * a;
}

void program2b() {
    double n;
    cout << "\n=== Program 2b: Inline Functions ===\n";
    cout << "Enter the value of n: ";
    cin >> n;
    double num = cube(n);
    cout << "Cube of " << n << " = " << num << endl;
}

// ========== MAIN FUNCTION ==========
int main() {
    int choice;
    cout << "\n*** WEEK 2 - C++ PROGRAMS ***\n";
    cout << "1. Program 2a: Scope Resolution Operator and Namespaces\n";
    cout << "2. Program 2b: Inline Functions\n";
    cout << "3. Run All Programs\n";
    cout << "Enter your choice: ";
    cin >> choice;
    
    switch(choice) {
        case 1:
            program2a();
            break;
        case 2:
            program2b();
            break;
        case 3:
            program2a();
            program2b();
            break;
        default:
            cout << "Invalid choice!" << endl;
    }
    
    return 0;
}

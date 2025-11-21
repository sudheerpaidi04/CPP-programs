// WEEK 1 - C++ Programming Lab Programs
// Program 1a: Factorial Using Recursion
// Program 1b: Call by Value and Call by Reference

#include<iostream>
#include<string>
using namespace std;

// ========== PROGRAM 1A: FACTORIAL USING RECURSION ==========
int factorial(int fact) {
    if(fact == 0)
        return 1;
    else
        return fact * factorial(fact - 1);
}

void program1a() {
    int Num, factNum;
    cout << "\n=== Program 1a: Factorial Using Recursion ===\n";
    cout << "Enter the factorial number: ";
    cin >> Num;
    factNum = factorial(Num);
    cout << "The factorial of " << Num << " is: " << factNum << endl;
}

// ========== PROGRAM 1B: CALL BY VALUE AND CALL BY REFERENCE ==========
string CallbyValue(string a, string b) {
    a = "aditya";
    b = "viswadh";
    return "The Call by Value values of a, b: " + a + ", " + b;
}

string CallbyReference(string &a, string &b) {
    a = "abel";
    b = "travis";
    return "The Call by Reference values of a, b: " + a + ", " + b;
}

void program1b() {
    string a, b;
    cout << "\n=== Program 1b: Call by Value and Call by Reference ===\n";
    cout << "Enter the string value for a: ";
    cin >> a;
    cout << "Enter the string value for b: ";
    cin >> b;
    
    string result1 = CallbyValue(a, b);
    cout << result1 << endl;
    cout << "main function Values - a: " << a << ", b: " << b << endl;
    
    string result2 = CallbyReference(a, b);
    cout << result2 << endl;
    cout << "main function values - a: " << a << ", b: " << b << endl;
}

// ========== MAIN FUNCTION ==========
int main() {
    int choice;
    cout << "\n*** WEEK 1 - C++ PROGRAMS ***\n";
    cout << "1. Program 1a: Factorial Using Recursion\n";
    cout << "2. Program 1b: Call by Value and Call by Reference\n";
    cout << "3. Run All Programs\n";
    cout << "Enter your choice: ";
    cin >> choice;
    
    switch(choice) {
        case 1:
            program1a();
            break;
        case 2:
            program1b();
            break;
        case 3:
            program1a();
            program1b();
            break;
        default:
            cout << "Invalid choice!" << endl;
    }
    
    return 0;
}

// WEEK 11 - C++ Programming Lab Programs
// Program 11a: Exception Handling Basics
// Program 11b: Multiple Catch Statements

#include<iostream>
#include<string>
using namespace std;

// ========== PROGRAM 11A: EXCEPTION HANDLING BASICS ==========

void divideNumbers(int a, int b) {
    try {
        if(b == 0) {
            throw "Division by zero error!";
        }
        cout << "Result: " << (a / b) << endl;
    }
    catch(const char* msg) {
        cout << "Exception caught: " << msg << endl;
    }
}

void checkAge(int age) {
    try {
        if(age < 18) {
            throw age;
        }
        cout << "Age is valid: " << age << endl;
    }
    catch(int a) {
        cout << "Exception: Age " << a << " is below 18!" << endl;
    }
}

void program11a() {
    cout << "\n========== PROGRAM 11A: EXCEPTION HANDLING BASICS ==========\n";
    
    // Division by zero example
    cout << "\n--- Division Example ---\n";
    divideNumbers(10, 2);
    divideNumbers(10, 0);
    
    // Age validation example
    cout << "\n--- Age Validation ---\n";
    checkAge(25);
    checkAge(15);
    
    // Array index out of bounds
    cout << "\n--- Array Index Example ---\n";
    int arr[] = {1, 2, 3, 4, 5};
    int index;
    
    try {
        cout << "Enter array index (0-4): ";
        cin >> index;
        
        if(index < 0 || index >= 5) {
            throw index;
        }
        cout << "Element at index " << index << ": " << arr[index] << endl;
    }
    catch(int i) {
        cout << "Exception: Index " << i << " is out of bounds!" << endl;
    }
}

// ========== PROGRAM 11B: MULTIPLE CATCH STATEMENTS ==========

class NegativeNumberException {
public:
    void display() {
        cout << "Exception: Negative number not allowed!" << endl;
    }
};

class ZeroException {
public:
    void display() {
        cout << "Exception: Zero is not allowed!" << endl;
    }
};

void calculateSquareRoot(double num) {
    try {
        if(num < 0) {
            throw NegativeNumberException();
        }
        else if(num == 0) {
            throw ZeroException();
        }
        cout << "Square root of " << num << " = " << (num * num) << endl;
    }
    catch(NegativeNumberException e) {
        e.display();
    }
    catch(ZeroException e) {
        e.display();
    }
}

void testMultipleTypes(int value) {
    try {
        if(value < 0) {
            throw -1;  // Throw int
        }
        else if(value == 0) {
            throw 0.0;  // Throw double
        }
        else if(value > 100) {
            throw "Value too large!";  // Throw const char*
        }
        cout << "Valid value: " << value << endl;
    }
    catch(int e) {
        cout << "Integer Exception: Negative value!" << endl;
    }
    catch(double e) {
        cout << "Double Exception: Zero value!" << endl;
    }
    catch(const char* e) {
        cout << "String Exception: " << e << endl;
    }
    catch(...) {
        cout << "Unknown Exception!" << endl;
    }
}

void program11b() {
    cout << "\n========== PROGRAM 11B: MULTIPLE CATCH STATEMENTS ==========\n";
    
    // Custom exception classes
    cout << "\n--- Custom Exception Classes ---\n";
    calculateSquareRoot(16);
    calculateSquareRoot(-4);
    calculateSquareRoot(0);
    
    // Multiple data types
    cout << "\n--- Multiple Exception Types ---\n";
    testMultipleTypes(50);
    testMultipleTypes(-10);
    testMultipleTypes(0);
    testMultipleTypes(150);
    
    // Nested try-catch
    cout << "\n--- Nested Try-Catch ---\n";
    try {
        try {
            throw 20;
        }
        catch(int n) {
            cout << "Inner catch: " << n << endl;
            throw;  // Re-throw the exception
        }
    }
    catch(int n) {
        cout << "Outer catch: " << n << endl;
    }
}

// ========== MAIN FUNCTION ==========
int main() {
    int choice;
    
    do {
        cout << "\n\n========================================";
        cout << "\n      WEEK 11 - PROGRAM MENU";
        cout << "\n========================================";
        cout << "\n1. Program 11a: Exception Handling Basics";
        cout << "\n2. Program 11b: Multiple Catch Statements";
        cout << "\n3. Run All Programs";
        cout << "\n4. Exit";
        cout << "\n========================================";
        cout << "\nEnter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                program11a();
                break;
            case 2:
                program11b();
                break;
            case 3:
                program11a();
                program11b();
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

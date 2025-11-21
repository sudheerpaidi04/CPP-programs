// WEEK 10 - C++ Programming Lab Programs
// Program 10a: Function Templates
// Program 10b: Class Templates

#include<iostream>
#include<string>
using namespace std;

// ========== PROGRAM 10A: FUNCTION TEMPLATES ==========

// Template function to find maximum of two values
template <typename T>
T maximum(T a, T b) {
    return (a > b) ? a : b;
}

// Template function to swap two values
template <typename T>
void swapValues(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

// Template function to display array
template <typename T>
void displayArray(T arr[], int size) {
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void program10a() {
    cout << "\n========== PROGRAM 10A: FUNCTION TEMPLATES ==========\n";
    
    // Integer comparison
    int i1 = 10, i2 = 20;
    cout << "\nInteger values: " << i1 << ", " << i2;
    cout << "\nMaximum: " << maximum(i1, i2);
    
    // Float comparison
    float f1 = 15.5, f2 = 12.3;
    cout << "\n\nFloat values: " << f1 << ", " << f2;
    cout << "\nMaximum: " << maximum(f1, f2);
    
    // Character comparison
    char c1 = 'A', c2 = 'Z';
    cout << "\n\nCharacter values: " << c1 << ", " << c2;
    cout << "\nMaximum: " << maximum(c1, c2);
    
    // Swap integers
    cout << "\n\n--- Swapping Integers ---";
    cout << "\nBefore swap: " << i1 << ", " << i2;
    swapValues(i1, i2);
    cout << "\nAfter swap: " << i1 << ", " << i2;
    
    // Array display
    int intArr[] = {1, 2, 3, 4, 5};
    double doubleArr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    
    cout << "\n\nInteger array: ";
    displayArray(intArr, 5);
    
    cout << "Double array: ";
    displayArray(doubleArr, 5);
}

// ========== PROGRAM 10B: CLASS TEMPLATES ==========

// Template class for a generic array
template <typename T>
class Array {
private:
    T *arr;
    int size;
public:
    Array(int s) {
        size = s;
        arr = new T[size];
    }
    
    ~Array() {
        delete[] arr;
    }
    
    void input() {
        cout << "Enter " << size << " elements: ";
        for(int i = 0; i < size; i++) {
            cin >> arr[i];
        }
    }
    
    void display() {
        cout << "Array elements: ";
        for(int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    
    T sum() {
        T total = 0;
        for(int i = 0; i < size; i++) {
            total += arr[i];
        }
        return total;
    }
};

// Template class for a generic pair
template <typename T1, typename T2>
class Pair {
private:
    T1 first;
    T2 second;
public:
    Pair(T1 f, T2 s) {
        first = f;
        second = s;
    }
    
    void display() {
        cout << "First: " << first << ", Second: " << second << endl;
    }
};

void program10b() {
    cout << "\n========== PROGRAM 10B: CLASS TEMPLATES ==========\n";
    
    // Integer array
    cout << "\n--- Integer Array ---\n";
    Array<int> intArray(5);
    intArray.input();
    intArray.display();
    cout << "Sum: " << intArray.sum() << endl;
    
    // Float array
    cout << "\n--- Float Array ---\n";
    Array<float> floatArray(3);
    floatArray.input();
    floatArray.display();
    cout << "Sum: " << floatArray.sum() << endl;
    
    // Pair examples
    cout << "\n--- Pairs ---\n";
    Pair<int, int> p1(10, 20);
    cout << "Integer pair: ";
    p1.display();
    
    Pair<string, int> p2("Age", 25);
    cout << "String-Integer pair: ";
    p2.display();
    
    Pair<double, string> p3(98.6, "Temperature");
    cout << "Double-String pair: ";
    p3.display();
}

// ========== MAIN FUNCTION ==========
int main() {
    int choice;
    
    do {
        cout << "\n\n========================================";
        cout << "\n      WEEK 10 - PROGRAM MENU";
        cout << "\n========================================";
        cout << "\n1. Program 10a: Function Templates";
        cout << "\n2. Program 10b: Class Templates";
        cout << "\n3. Run All Programs";
        cout << "\n4. Exit";
        cout << "\n========================================";
        cout << "\nEnter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                program10a();
                break;
            case 2:
                program10b();
                break;
            case 3:
                program10a();
                program10b();
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

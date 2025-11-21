// WEEK 6 - C++ Programming Lab Programs
// Program 6a: Operator Overloading using Member Functions
// Program 6b: Operator Overloading using Friend Functions

#include<iostream>
using namespace std;

// ========== PROGRAM 6A: OPERATOR OVERLOADING USING MEMBER FUNCTIONS ==========
class Complex {
private:
    float real, imag;
public:
    Complex() {
        real = 0;
        imag = 0;
    }
    
    Complex(float r, float i) {
        real = r;
        imag = i;
    }
    
    // Overload + operator using member function
    Complex operator+(Complex c) {
        Complex temp;
        temp.real = real + c.real;
        temp.imag = imag + c.imag;
        return temp;
    }
    
    // Overload - operator using member function
    Complex operator-(Complex c) {
        Complex temp;
        temp.real = real - c.real;
        temp.imag = imag - c.imag;
        return temp;
    }
    
    void display() {
        if(imag >= 0)
            cout << real << " + " << imag << "i";
        else
            cout << real << " - " << -imag << "i";
    }
};

void program6a() {
    cout << "\n========== PROGRAM 6A: OPERATOR OVERLOADING (MEMBER FUNCTIONS) ==========\n";
    Complex c1(3.5, 2.5), c2(1.5, 4.5), c3, c4;
    
    cout << "\nFirst Complex Number: ";
    c1.display();
    cout << "\nSecond Complex Number: ";
    c2.display();
    
    c3 = c1 + c2;  // Calls operator+ function
    cout << "\n\nAddition Result: ";
    c3.display();
    
    c4 = c1 - c2;  // Calls operator- function
    cout << "\nSubtraction Result: ";
    c4.display();
    cout << endl;
}

// ========== PROGRAM 6B: OPERATOR OVERLOADING USING FRIEND FUNCTIONS ==========
class Distance {
private:
    int feet;
    float inches;
public:
    Distance() {
        feet = 0;
        inches = 0;
    }
    
    Distance(int f, float i) {
        feet = f;
        inches = i;
    }
    
    void display() {
        cout << feet << "' " << inches << "\"";
    }
    
    // Friend function declarations
    friend Distance operator+(Distance d1, Distance d2);
    friend Distance operator-(Distance d1, Distance d2);
};

// Overload + operator using friend function
Distance operator+(Distance d1, Distance d2) {
    Distance temp;
    temp.inches = d1.inches + d2.inches;
    temp.feet = d1.feet + d2.feet;
    
    // Convert inches to feet if >= 12
    if(temp.inches >= 12.0) {
        temp.feet += (int)(temp.inches / 12);
        temp.inches = temp.inches - ((int)(temp.inches / 12) * 12);
    }
    return temp;
}

// Overload - operator using friend function
Distance operator-(Distance d1, Distance d2) {
    Distance temp;
    temp.inches = d1.inches - d2.inches;
    temp.feet = d1.feet - d2.feet;
    
    // Handle negative inches
    if(temp.inches < 0) {
        temp.feet--;
        temp.inches += 12;
    }
    return temp;
}

void program6b() {
    cout << "\n========== PROGRAM 6B: OPERATOR OVERLOADING (FRIEND FUNCTIONS) ==========\n";
    Distance d1(5, 8.5), d2(3, 10.5), d3, d4;
    
    cout << "\nFirst Distance: ";
    d1.display();
    cout << "\nSecond Distance: ";
    d2.display();
    
    d3 = d1 + d2;  // Calls friend operator+ function
    cout << "\n\nAddition Result: ";
    d3.display();
    
    d4 = d1 - d2;  // Calls friend operator- function
    cout << "\nSubtraction Result: ";
    d4.display();
    cout << endl;
}

// ========== MAIN FUNCTION ==========
int main() {
    int choice;
    
    do {
        cout << "\n\n========================================";
        cout << "\n      WEEK 6 - PROGRAM MENU";
        cout << "\n========================================";
        cout << "\n1. Program 6a: Operator Overloading (Member Functions)";
        cout << "\n2. Program 6b: Operator Overloading (Friend Functions)";
        cout << "\n3. Run All Programs";
        cout << "\n4. Exit";
        cout << "\n========================================";
        cout << "\nEnter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                program6a();
                break;
            case 2:
                program6b();
                break;
            case 3:
                program6a();
                program6b();
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

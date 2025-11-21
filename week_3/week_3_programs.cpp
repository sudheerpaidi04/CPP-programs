// WEEK 3 - C++ Programming Lab Programs
// Program 3a: Bank Account Class
// Program 3b: Access Specifiers
// Program 3c: this Pointer

#include <iostream>
#include <string>
using namespace std;

// ========== PROGRAM 3A: BANK ACCOUNT CLASS ==========
class Bank {
private:
    int accNum;
    string name;
    double balance;

public:
    Bank(int acno, string acname, double bal) {
        accNum = acno;
        name = acname;
        balance = bal;
    }

    void deposit(double depo) {
        if (depo > 0) {
            balance += depo;
            cout << "Total balance: " << balance << endl;
        } else {
            cout << "Deposit not allowed! Amount must be positive" << endl;
        }
    }

    void withdraw(double amt) {
        if (amt > 0 && amt <= balance) {
            balance -= amt;
            cout << "Withdrawal successful. Remaining balance: " << balance << endl;
        } else if (amt > balance) {
            cout << "Insufficient balance!" << endl;
        } else {
            cout << "Withdrawal amount must be positive" << endl;
        }
    }

    void dispBalance() {
        cout << "Acc num: " << accNum << endl;
        cout << "Acc name: " << name << endl;
        cout << "Acc balance: " << balance << endl;
    }
};

void program3a() {
    cout << "\n=== Program 3a: Bank Account Class ===\n";
    Bank ob1(2521025, "Abel", 25000.0);
    ob1.dispBalance();
    ob1.deposit(12000.0);
    ob1.withdraw(5000.0);
    ob1.withdraw(50000.0);
    ob1.withdraw(-100);
}

// ========== PROGRAM 3B: ACCESS SPECIFIERS ==========
class Hospital {
private:
    string patientName;
    int patientAge;
    string patientDisease;

public:
    void setPatientDetails(string name, int age, string disease) {
        patientName = name;
        patientAge = age;
        patientDisease = disease;
    }

    void displayPatientDetails() {
        cout << "Patient Name: " << patientName << endl;
        cout << "Patient Age: " << patientAge << endl;
        cout << "Disease: " << patientDisease << endl;
    }
};

void program3b() {
    cout << "\n=== Program 3b: Access Specifiers ===\n";
    Hospital h1;
    h1.setPatientDetails("Travis", 32, "fever");
    h1.displayPatientDetails();
}

// ========== PROGRAM 3C: THIS POINTER ==========
class Employee {
private:
    int id;
    string name;

public:
    void setDetails(int id, string name) {
        this->id = id;
        this->name = name;
    }

    void showDetails() {
        cout << "Employee ID: " << this->id << endl;
        cout << "Employee Name: " << this->name << endl;
    }
};

void program3c() {
    cout << "\n=== Program 3c: this Pointer ===\n";
    Employee emp;
    emp.setDetails(101, "chico");
    emp.showDetails();
}

// ========== MAIN FUNCTION ==========
int main() {
    int choice;
    cout << "\n*** WEEK 3 - C++ PROGRAMS ***\n";
    cout << "1. Program 3a: Bank Account Class\n";
    cout << "2. Program 3b: Access Specifiers\n";
    cout << "3. Program 3c: this Pointer\n";
    cout << "4. Run All Programs\n";
    cout << "Enter your choice: ";
    cin >> choice;
    
    switch(choice) {
        case 1:
            program3a();
            break;
        case 2:
            program3b();
            break;
        case 3:
            program3c();
            break;
        case 4:
            program3a();
            program3b();
            program3c();
            break;
        default:
            cout << "Invalid choice!" << endl;
    }
    
    return 0;
}

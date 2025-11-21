// WEEK 8 - C++ Programming Lab Programs
// Program 8a: Pointers to Objects
// Program 8b: Virtual Base Classes

#include<iostream>
#include<string>
using namespace std;

// ========== PROGRAM 8A: POINTERS TO OBJECTS ==========
class Employee {
private:
    int empId;
    string name;
    float salary;
public:
    void setData(int id, string n, float s) {
        empId = id;
        name = n;
        salary = s;
    }
    
    void display() {
        cout << "Employee ID: " << empId << endl;
        cout << "Name: " << name << endl;
        cout << "Salary: $" << salary << endl;
    }
};

void program8a() {
    cout << "\n========== PROGRAM 8A: POINTERS TO OBJECTS ==========\n";
    
    // Creating object
    Employee emp1;
    emp1.setData(101, "John Doe", 50000);
    
    cout << "\nUsing object directly:\n";
    emp1.display();
    
    // Creating pointer to object
    Employee *ptr = &emp1;
    
    cout << "\nUsing pointer to object:\n";
    ptr->display();
    
    // Dynamic memory allocation
    Employee *emp2 = new Employee;
    emp2->setData(102, "Jane Smith", 60000);
    
    cout << "\nUsing dynamically allocated object:\n";
    emp2->display();
    
    delete emp2;  // Free memory
}

// ========== PROGRAM 8B: VIRTUAL BASE CLASSES ==========
// Without virtual base class, there would be ambiguity

class Person {
protected:
    string name;
    int age;
public:
    void setPerson(string n, int a) {
        name = n;
        age = a;
    }
    
    void displayPerson() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

// Virtual base class to avoid ambiguity
class Student : virtual public Person {
protected:
    int rollNo;
public:
    void setStudent(int r) {
        rollNo = r;
    }
    
    void displayStudent() {
        cout << "Roll No: " << rollNo << endl;
    }
};

class Employee8b : virtual public Person {
protected:
    int empId;
public:
    void setEmployee(int e) {
        empId = e;
    }
    
    void displayEmployee() {
        cout << "Employee ID: " << empId << endl;
    }
};

// Multiple inheritance - single copy of Person
class TeachingAssistant : public Student, public Employee8b {
private:
    string course;
public:
    void setCourse(string c) {
        course = c;
    }
    
    void display() {
        displayPerson();
        displayStudent();
        displayEmployee();
        cout << "Course: " << course << endl;
    }
};

void program8b() {
    cout << "\n========== PROGRAM 8B: VIRTUAL BASE CLASSES ==========\n";
    
    TeachingAssistant ta;
    
    // No ambiguity - only one copy of Person exists
    ta.setPerson("Alice Johnson", 25);
    ta.setStudent(2001);
    ta.setEmployee(501);
    ta.setCourse("Data Structures");
    
    cout << "\nTeaching Assistant Details:\n";
    ta.display();
    
    cout << "\nNote: Virtual base class ensures only one copy of Person exists.\n";
}

// ========== MAIN FUNCTION ==========
int main() {
    int choice;
    
    do {
        cout << "\n\n========================================";
        cout << "\n      WEEK 8 - PROGRAM MENU";
        cout << "\n========================================";
        cout << "\n1. Program 8a: Pointers to Objects";
        cout << "\n2. Program 8b: Virtual Base Classes";
        cout << "\n3. Run All Programs";
        cout << "\n4. Exit";
        cout << "\n========================================";
        cout << "\nEnter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                program8a();
                break;
            case 2:
                program8b();
                break;
            case 3:
                program8a();
                program8b();
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

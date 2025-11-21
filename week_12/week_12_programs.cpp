// WEEK 12 - C++ Programming Lab Programs
// Program 12a: STL Containers (Vector, List, Deque)
// Program 12b: STL Map Container

#include<iostream>
#include<vector>
#include<list>
#include<deque>
#include<map>
#include<string>
using namespace std;

// ========== PROGRAM 12A: STL CONTAINERS (VECTOR, LIST, DEQUE) ==========

void demonstrateVector() {
    cout << "\n--- VECTOR CONTAINER ---\n";
    vector<int> v;
    
    // Adding elements
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    
    cout << "Vector elements: ";
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    
    cout << "Size: " << v.size() << endl;
    cout << "First element: " << v.front() << endl;
    cout << "Last element: " << v.back() << endl;
    
    // Remove last element
    v.pop_back();
    cout << "After pop_back: ";
    for(int x : v) {
        cout << x << " ";
    }
    cout << endl;
}

void demonstrateList() {
    cout << "\n--- LIST CONTAINER ---\n";
    list<string> lst;
    
    // Adding elements
    lst.push_back("Alice");
    lst.push_back("Bob");
    lst.push_front("Charlie");
    lst.push_front("David");
    
    cout << "List elements: ";
    for(string name : lst) {
        cout << name << " ";
    }
    cout << endl;
    
    cout << "Size: " << lst.size() << endl;
    
    // Sort the list
    lst.sort();
    cout << "After sorting: ";
    for(string name : lst) {
        cout << name << " ";
    }
    cout << endl;
    
    // Reverse the list
    lst.reverse();
    cout << "After reversing: ";
    for(string name : lst) {
        cout << name << " ";
    }
    cout << endl;
}

void demonstrateDeque() {
    cout << "\n--- DEQUE CONTAINER ---\n";
    deque<int> dq;
    
    // Adding elements
    dq.push_back(10);
    dq.push_back(20);
    dq.push_front(5);
    dq.push_front(1);
    
    cout << "Deque elements: ";
    for(int x : dq) {
        cout << x << " ";
    }
    cout << endl;
    
    cout << "First element: " << dq.front() << endl;
    cout << "Last element: " << dq.back() << endl;
    
    // Remove from both ends
    dq.pop_front();
    dq.pop_back();
    cout << "After removing from both ends: ";
    for(int x : dq) {
        cout << x << " ";
    }
    cout << endl;
}

void program12a() {
    cout << "\n========== PROGRAM 12A: STL CONTAINERS ==========\n";
    demonstrateVector();
    demonstrateList();
    demonstrateDeque();
}

// ========== PROGRAM 12B: STL MAP CONTAINER ==========

void demonstrateMap() {
    cout << "\n========== PROGRAM 12B: STL MAP CONTAINER ==========\n";
    
    // Creating a map (key-value pairs)
    map<int, string> students;
    
    // Inserting elements
    students[101] = "Alice";
    students[102] = "Bob";
    students[103] = "Charlie";
    students[104] = "David";
    students[105] = "Eve";
    
    cout << "\nStudent Records:\n";
    for(auto pair : students) {
        cout << "ID: " << pair.first << ", Name: " << pair.second << endl;
    }
    
    // Finding an element
    int searchId = 103;
    auto it = students.find(searchId);
    if(it != students.end()) {
        cout << "\nStudent with ID " << searchId << " found: " << it->second << endl;
    } else {
        cout << "\nStudent with ID " << searchId << " not found." << endl;
    }
    
    // Size of map
    cout << "\nTotal students: " << students.size() << endl;
    
    // Erasing an element
    students.erase(102);
    cout << "\nAfter erasing ID 102:\n";
    for(auto pair : students) {
        cout << "ID: " << pair.first << ", Name: " << pair.second << endl;
    }
    
    // Map with string keys
    cout << "\n--- Map with String Keys ---\n";
    map<string, int> scores;
    scores["Alice"] = 95;
    scores["Bob"] = 88;
    scores["Charlie"] = 92;
    scores["David"] = 85;
    
    cout << "Student Scores:\n";
    for(auto pair : scores) {
        cout << pair.first << ": " << pair.second << endl;
    }
    
    // Check if key exists
    string searchName = "Bob";
    if(scores.count(searchName)) {
        cout << "\n" << searchName << "'s score: " << scores[searchName] << endl;
    }
}

void program12b() {
    demonstrateMap();
}

// ========== MAIN FUNCTION ==========
int main() {
    int choice;
    
    do {
        cout << "\n\n========================================";
        cout << "\n      WEEK 12 - PROGRAM MENU";
        cout << "\n========================================";
        cout << "\n1. Program 12a: STL Containers (Vector, List, Deque)";
        cout << "\n2. Program 12b: STL Map Container";
        cout << "\n3. Run All Programs";
        cout << "\n4. Exit";
        cout << "\n========================================";
        cout << "\nEnter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                program12a();
                break;
            case 2:
                program12b();
                break;
            case 3:
                program12a();
                program12b();
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

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

//  Requirement 1: Student Object / Structure
struct Student {
    string rollNo;
    string name;
    int age;
};

// Function Prototypes
void displayAllStudents();
void searchStudent();
void updateStudent();
void deleteStudent();
vector<Student> readAllStudents();
void writeAllStudents(const vector<Student>& students);

//  Requirement 2: Display all students from file
void displayAllStudents() {
    ifstream file("student.txt");
    if (!file.is_open()) {
        cout << " File not found or cannot be opened.\n\n";
        return;
    }

    string line;
    cout << "\n===== All Students =====\n";
    while (getline(file, line)) {
        // Split CSV line
        stringstream ss(line);
        string roll, name, ageStr;
        getline(ss, roll, ',');
        getline(ss, name, ',');
        getline(ss, ageStr, ',');

        cout << "Roll No: " << roll 
             << " | Name: " << name 
             << " | Age: " << ageStr << endl;
    }
    cout << "========================\n\n";
    file.close();
}

//  Requirement 3: Search student by Roll Number
void searchStudent() {
    string searchRoll;
    cout << "Enter Roll Number to search: ";
    cin >> searchRoll;

    ifstream file("student.txt");
    if (!file.is_open()) {
        cout << " File not found.\n\n";
        return;
    }

    string line;
    bool found = false;
    while (getline(file, line)) {
        stringstream ss(line);
        string roll, name, ageStr;
        getline(ss, roll, ',');
        getline(ss, name, ',');
        getline(ss, ageStr, ',');

        if (roll == searchRoll) {
            cout << "\n Student Found:\n";
            cout << "Roll No: " << roll << "\nName: " << name << "\nAge: " << ageStr << "\n\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << " Student not found\n\n";
    }
    file.close();
}

// Helper: Read all records into vector
vector<Student> readAllStudents() {
    vector<Student> list;
    ifstream file("student.txt");
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        string roll, name, ageStr;
        getline(ss, roll, ',');
        getline(ss, name, ',');
        getline(ss, ageStr, ',');

        Student s;
        s.rollNo = roll;
        s.name = name;
        s.age = stoi(ageStr);
        list.push_back(s);
    }
    file.close();
    return list;
}

// Helper: Write entire vector back to file
void writeAllStudents(const vector<Student>& students) {
    ofstream file("student.txt"); // overwrites file
    for (const auto& s : students) {
        file << s.rollNo << "," << s.name << "," << s.age << endl;
    }
    file.close();
}

//  Requirement 4: Update student info
void updateStudent() {
    string updateRoll;
    cout << "Enter Roll Number to update: ";
    cin >> updateRoll;
    cin.ignore();

    vector<Student> list = readAllStudents();
    bool found = false;

    for (auto& s : list) {
        if (s.rollNo == updateRoll) {
            cout << "Enter new Name: ";
            getline(cin, s.name);
            cout << "Enter new Age: ";
            cin >> s.age;
            found = true;
            break;
        }
    }

    if (found) {
        writeAllStudents(list);
        cout << " Student updated permanently.\n\n";
    } else {
        cout << " Student not found\n\n";
    }
}

//  Requirement 5: Delete student record
void deleteStudent() {
    string deleteRoll;
    cout << "Enter Roll Number to delete: ";
    cin >> deleteRoll;

    vector<Student> list = readAllStudents();
    vector<Student> updatedList;
    bool found = false;

    for (const auto& s : list) {
        if (s.rollNo != deleteRoll) {
            updatedList.push_back(s); // keep only others
        } else {
            found = true;
        }
    }

    if (found) {
        writeAllStudents(updatedList);
        cout << " Student deleted permanently.\n\n";
    } else {
        cout << " Student not found\n\n";
    }
}

int main() {
    //  Create initial data if file does not exist
    ifstream checkFile("student.txt");
    if (!checkFile.good()) {
        ofstream initFile("student.txt");
        initFile << "202312051,lithacynthia,18\n";
        initFile << "202312052,dessama,18\n";
        initFile << "202312053,david,20\n";
        initFile.close();
    }
    checkFile.close();

    int choice;
    //  Requirement 7: Menu-driven loop
    do {
        cout << "===== STUDENT RECORD SYSTEM =====\n";
        cout << "1. Display All Students\n";
        cout << "2. Search Student\n";
        cout << "3. Update Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";
        cout << "---------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
            case 1: displayAllStudents(); break;
            case 2: searchStudent(); break;
            case 3: updateStudent(); break;
            case 4: deleteStudent(); break;
            case 5: cout << " Program ended.\n"; break;
            default: cout << " Invalid choice! Try again.\n\n";
        }

    } while (choice != 5);

    return 0;
}
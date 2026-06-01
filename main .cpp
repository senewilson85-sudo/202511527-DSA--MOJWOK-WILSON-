
#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

// B. Student Structure
struct Student {
    int id;
    string name;
    int age;
    string course;
};

// C. Function Declarations
void addStudent();
void displayStudents();
void searchStudent();
void updateStudent();
void deleteStudent();

#endif
#include <iostream>
#include <string>
using namespace std;

// 
 Requirement 5: At least one function
void calculateResult(string name, int m1, int m2, int m3) {
    int total = m1 + m2 + m3;
    float average = total / 3.0;

    //  Requirement 2: Calculate total and average
    cout << "\n----- Result for " << name << " -----" << endl;
    cout << "Total Marks: " << total << endl;
    cout << "Average: " << average << endl;

    //  Requirement 3: Pass / Fail decision (pass if average ≥ 50)
    if (average >= 50) {
        cout << "Status: PASSED " << endl;
    } else {
        cout << "Status: FAILED " << endl;
    }
    cout << "--------------------------\n" << endl;
}

int main() {
    char choice;

    //  Requirement 4: Loop for multiple students
    do {
        string name;
        int sub1, sub2, sub3;

        //  Requirement 1: Accept name and 3 subject marks
        cout << "Enter student name: ";
        cin >> name;

        cout << "Enter marks for Subject 1: ";
        cin >> sub1;
        cout << "Enter marks for Subject 2: ";
        cin >> sub2;
        cout << "Enter marks for Subject 3: ";
        cin >> sub3;

        // Call function to process
        calculateResult(name, sub1, sub2, sub3);

        // Ask if user wants to enter another student
        cout << "Do you want to enter another student? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "Program ended. Thank you!" << endl;
    return 0;
}
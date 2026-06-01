#include "notepad.h"

// Function to create/write to a file
void writeFile(string filename) {
    ofstream file(filename); // Create/open file in write mode

    if (!file.is_open()) {
        cout << " Error: Could not create or open file.\n";
        return;
    }

    cout << " Enter text (type END on new line to stop):\n";
    string line;

    // Read lines until user types END
    while (true) {
        getline(cin, line);
        if (line == "END") {
            break;
        }
        file << line << endl; // Save each line
    }

    file.close(); // Always close file
    cout << "File saved successfully!\n\n";
}

// Function to read/display file content
void readFile(string filename) {
    ifstream file(filename); // Open file in read mode

    if (!file.is_open()) {
        cout << " Error: File not found or cannot be opened.\n\n";
        return;
    }

    cout << "\n File Content:\n";
    cout << "-------------------------\n";
    string line;

    // Read and display line by line
    while (getline(file, line)) {
        cout << line << endl;
    }

    cout << "-------------------------\n\n";
    file.close();
}

// Function to append text to existing file
void appendFile(string filename) {
    ofstream file(filename, ios::app); // Open in append mode

    if (!file.is_open()) {
        cout << " Error: File not found or cannot be opened.\n\n";
        return;
    }

    cout << " Enter text to append (type END on new line to stop):\n";
    string line;

    while (true) {
        getline(cin, line);
        if (line == "END") {
            break;
        }
        file << line << endl;
    }

    file.close();
    cout << " Text added successfully!\n\n";
}
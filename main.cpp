#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include "Vehicle.h"

using namespace std;

const string FILE_NAME = "records.txt";

// Function Prototypes
void addVehicle();
void viewAllVehicles();
void searchVehicle();
bool validatePlate(const string &plate);
bool validateYear(int year);
bool validateEmail(const string &email);
bool validatePhone(const string &phone);
vector<Vehicle> loadRecords();
void saveRecords(const vector<Vehicle> &records);

int main() {
    int choice;
    do {
        cout << "\n===== Vehicle Registration System =====" << endl;
        cout << "1. Add New Vehicle" << endl;
        cout << "2. View All Registered Vehicles" << endl;
        cout << "3. Search Vehicle by Plate Number" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear input buffer

        switch (choice) {
            case 1: addVehicle(); break;
            case 2: viewAllVehicles(); break;
            case 3: searchVehicle(); break;
            case 4: cout << "Exiting system..." << endl; break;
            default: cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 4);

    return 0;
}

// Add new vehicle with validation
void addVehicle() {
    string plate, type, name, email, phone;
    int year;

    cout << "\n--- Add New Vehicle ---" << endl;

    // Plate validation
    do {
        cout << "Enter Plate Number (e.g., RAA123A): ";
        getline(cin, plate);
        if (!validatePlate(plate)) cout << "Invalid format! Try again.\n";
    } while (!validatePlate(plate));

    // Vehicle type
    cout << "Enter Vehicle Type (e.g., Sedan, Truck): ";
    getline(cin, type);

    // Year validation
    do {
        cout << "Enter Manufacturing Year: ";
        cin >> year;
        cin.ignore();
        if (!validateYear(year)) cout << "Year must be between 1900 and 2026! Try again.\n";
    } while (!validateYear(year));

    // Owner details
    cout << "Enter Owner Name: ";
    getline(cin, name);

    // Email validation
    do {
        cout << "Enter Owner Email: ";
        getline(cin, email);
        if (!validateEmail(email)) cout << "Invalid email! Must contain '@' and '.'. Try again.\n";
    } while (!validateEmail(email));

    // Phone validation
    do {
        cout << "Enter Owner Phone (e.g., +250788123456): ";
        getline(cin, phone);
        if (!validatePhone(phone)) cout << "Invalid phone! Must start with '+' and be 12-15 digits. Try again.\n";
    } while (!validatePhone(phone));

    // Create objects
    VehicleOwner owner(name, email, phone);
    Vehicle vehicle(plate, type, year, owner);

    // Save to file
    vector<Vehicle> records = loadRecords();
    records.push_back(vehicle);
    saveRecords(records);

    cout << " Vehicle registered successfully!" << endl;
}

// View all vehicles in formatted way
void viewAllVehicles() {
    vector<Vehicle> records = loadRecords();
    if (records.empty()) {
        cout << "\n No records found!" << endl;
        return;
    }

    cout << "\n===== All Registered Vehicles =====" << endl;
    cout << "-------------------------------------------------------------------------" << endl;
    cout << "Plate No. | Type   | Year | Owner Name   | Email           | Phone" << endl;
    cout << "-------------------------------------------------------------------------" << endl;

    for (const auto &v : records) {
        cout << v.getPlateNumber() << " | "
             << v.getVehicleType() << " | "
             << v.getYear() << " | "
             << v.getOwner().getName() << " | "
             << v.getOwner().getEmail() << " | "
             << v.getOwner().getPhone() << endl;
    }
}

// Search vehicle by plate number
void searchVehicle() {
    string plate;
    cout << "\nEnter Plate Number to search: ";
    getline(cin, plate);

    vector<Vehicle> records = loadRecords();
    bool found = false;

    for (const auto &v : records) {
        if (v.getPlateNumber() == plate) {
            cout << "\n Vehicle Found:" << endl;
            cout << "Plate Number: " << v.getPlateNumber() << endl;
            cout << "Vehicle Type: " << v.getVehicleType() << endl;
            cout << "Year: " << v.getYear() << endl;
            cout << "Owner Name: " << v.getOwner().getName() << endl;
            cout << "Owner Email: " << v.getOwner().getEmail() << endl;
            cout << "Owner Phone: " << v.getOwner().getPhone() << endl;
            found = true;
            break;
        }
    }

    if (!found) cout << " Vehicle with plate " << plate << " not found." << endl;
}

// --- Validation Functions ---
bool validatePlate(const string &plate) {
    return plate.length() >= 5 && plate.length() <= 10; // Simple length check
}

bool validateYear(int year) {
    return year >= 1900 && year <= 2026;
}

bool validateEmail(const string &email) {
    return email.find('@') != string::npos && email.find('.') != string::npos;
}

bool validatePhone(const string &phone) {
    if (phone.empty() || phone[0] != '+') return false;
    return phone.length() >= 12 && phone.length() <= 15;
}

// --- File Handling ---
vector<Vehicle> loadRecords() {
    vector<Vehicle> records;
    ifstream file(FILE_NAME);
    string line;

    if (file.is_open()) {
        while (getline(file, line)) {
            if (!line.empty()) {
                records.push_back(Vehicle::fromCSV(line));
            }
        }
        file.close();
    }
    return records;
}

void saveRecords(const vector<Vehicle> &records) {
    ofstream file(FILE_NAME);
    if (file.is_open()) {
        for (const auto &v : records) {
            file << v.toCSV() << endl;
        }
        file.close();
    } else {
        cout << " Error saving file!" << endl;
    }
}
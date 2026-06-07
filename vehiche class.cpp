#ifndef VEHICLE_H
#define VEHICLE_H
#include <string>
#include "VehicleOwner.h"
using namespace std;

class Vehicle {
private:
    string plateNumber;
    string vehicleType;
    int year;
    VehicleOwner owner; // Association: Vehicle has an Owner

public:
    // Constructors
    Vehicle();
    Vehicle(string plate, string type, int year, VehicleOwner owner);

    // Getters and Setters
    string getPlateNumber() const;
    void setPlateNumber(const string &plate);

    string getVehicleType() const;
    void setVehicleType(const string &type);

    int getYear() const;
    void setYear(int year);

    VehicleOwner getOwner() const;
    void setOwner(const VehicleOwner &owner);

    // Convert to CSV string
    string toCSV() const;

    // Create Vehicle from CSV string
    static Vehicle fromCSV(const string &csvLine);
};

#endif
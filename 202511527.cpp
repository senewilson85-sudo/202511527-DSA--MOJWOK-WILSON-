#ifndef NOTEPAD_H
#define NOTEPAD_H

// Only allowed libraries
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function Declarations
void writeFile(string filename);
void readFile(string filename);
void appendFile(string filename);

#endif
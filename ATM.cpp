#include <iostream>
#include <vector> // to store guesses
using namespace std;

int main() {
    // 1. Variable to store chosen number
    int chosenNumber = 7;

    // 2. Variable to store user input
    int userGuess;

    // 3. Empty list/array to store all guesses
    vector<int> allGuesses;

    // While loop: runs until guess is correct
    while (userGuess != chosenNumber) {
        // Ask user for number
        cout << "Enter your guess: ";
        cin >> userGuess;

        // Store and save to list
        allGuesses.push_back(userGuess);

        // Compare and give feedback
        if (userGuess > chosenNumber) {
            cout << "Too high" << endl;
        }
        else if (userGuess < chosenNumber) {
            cout << "Too low" << endl;
        }
        else {
            cout << "Correct" << endl;
        }
    }

    // After loop: display all guesses
    cout << "\nAll your guesses: " << endl;
    for (int i = 0; i < allGuesses.size(); i++) {
        cout << allGuesses[i] << endl;
    }

    return 0;
}
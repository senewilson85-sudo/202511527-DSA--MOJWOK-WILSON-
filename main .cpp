#include <iostream>
using namespace std;

// Function using pointers
void swapNumbers(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x, y;
    cout << "Enter first number: ";
    cin >> x;
    cout << "Enter second number: ";
    cin >> y;

    cout << "Before swap: x = " << x << ", y = " << y << endl;
    swapNumbers(&x, &y); // pass addresses
    cout << "After swap:  x = " << x << ", y = " << y << endl;

    return 0;
}
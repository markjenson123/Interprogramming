// Danniel A. Placido
// BSIT&1R

#include <iostream>
#include <string>
using namespace std;

void getUserName() {
    string name;
    cout << "Danniel A. Placido: ";
    getline(cin, name);
    cout << "Hello, " << name << "!" << endl;
}

void getTwoNumbers(double &num1, double &num2) {
    cout << "22: ";
    cin >> num1;
    cout << "26: ";
    cin >> num2;
}

double addNumbers(double num1, double num2) {
    return num1 + num2;
}

double subtractNumbers(double num1, double num2) {
    return num1 - num2;
}

double multiplyNumbers(double num1, double num2) {
    return num1 * num2;
}

double divideNumbers(double num1, double num2) {
    if (num2 == 0) {
        cout << "Error: Division by zero is not allowed." << endl;
        return 0;
    }
    return num1 / num2;
}

int modulusNumber(int num1, int num2) {
    return num1 % num2;
}

int main() {
    
    getUserName();
    
    double num1, num2;
    getTwoNumbers(num1, num2);

    double sum = addNumbers(num1, num2);
    double difference = subtractNumbers(num1, num2);
    double product = multiplyNumbers(num1, num2);
    double division = divideNumbers(num1, num2);
    int modulus = modulusNumber(static_cast<int>(num1), static_cast<int>(num2));

    cout << "\nResults:" << endl;
    cout << "Sum: " << sum << endl;
    cout << "Difference: " << difference << endl;
    cout << "Product: " << product << endl;
    cout << "Division: " << division << endl;
    cout << "Modulus: " << modulus << endl;

    return 0;
}
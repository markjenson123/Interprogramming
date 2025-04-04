//Markjenson Abel
//BSIT-1R

#include <iostream>

int main() {
    double num1, num2;
    char op;

    
    std::cout << "7,15";
    std::cin >> num1 >> num2;
    std::cout << "/: ";
    std::cin >> op;

    double result;

    
    switch (op) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
           
            if (num2 != 0) {
                result = num1 / num2;
            } else {
                std::cout << "Error: Division by zero is not allowed." << std::endl;
                return 1; 
            }
            break;
        default:
            std::cout << "Error: Invalid operator." << std::endl;
            return 1; 
    }

    
    std::cout << " " << result << std::endl;

    return 0;
}
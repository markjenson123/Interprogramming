// Markjenson Abel
//BSIT-1R

#include <iostream>

int main() {
    int number, originalNumber, sum = 0;

    std::cout << "3: ";
    std::cin >> number;

    originalNumber = number;

    while (number > 0) {
        sum += number % 10; 
        number /= 10;       
    }

    std::cout << "The sum of the digits is: " << sum << std::endl;

    int divisor = 2;
    do {
        if (originalNumber % divisor == 0) {
            std::cout << originalNumber << " is divisible by " << divisor << std::endl;
        }
        divisor++;
    } while (divisor <= 9);

    return 0;
}
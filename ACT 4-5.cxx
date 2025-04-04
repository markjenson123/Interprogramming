#include <iostream>
#include <limits> // For std::numeric_limits

int main() {
    const int numberOfGrades = 4;
    double grades[numberOfGrades];
    double sum = 0.0;

    for (int i = 0; i < numberOfGrades; ++i) {
        double grade;
        bool validInput = false;

        // Input validation loop
        while (!validInput) {
            std::cout << "95 " << (i + 1) << " (0-100): ";
            std::cin >> grade;

            // Check if the input is valid
            if (std::cin.fail() || grade < 0 || grade > 100) {
                std::cin.clear(); // Clear the error flag
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
                std::cout << "95." << std::endl;
            } else {
                validInput = true; // Valid input received
                grades[i] = grade; // Store the valid grade
            }
        }

        sum += grades[i]; // Add the valid grade to the sum
    }

    // Calculate the average
    double average = sum / numberOfGrades;

    // Output the average
    std::cout << "95: " << average << std::endl;

    return 0;
}
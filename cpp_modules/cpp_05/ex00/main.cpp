#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    // Test 1: Valid bureaucrat
    try {
        Bureaucrat bob("Bob", 50);
        std::cout << bob << std::endl;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    // Test 2: Invalid grade (too low)
    try {
        Bureaucrat invalid("Invalid", 151);
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    // Test 3: Increment exception
    try {
        Bureaucrat alice("Alice", 1);
        alice.incrementGrade();  // Should throw
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}
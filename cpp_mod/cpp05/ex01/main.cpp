#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    // Test 1: Create valid form
    try {
        Form form("Contract", 50, 25);
        std::cout << form << std::endl;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    // Test 2: Successful signing
    try {
        Bureaucrat boss("Boss", 10);
        Form form("Report", 50, 25);
        
        boss.signForm(form);
        std::cout << form << std::endl;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    // Test 3: Failed signing (grade too low)
    try {
        Bureaucrat intern("Intern", 100);
        Form form("Top Secret", 50, 25);
        
        intern.signForm(form);  // Should fail
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    // Test 4: Invalid form grade
    try {
        Form invalid("Invalid", 0, 50);  // Should throw
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}
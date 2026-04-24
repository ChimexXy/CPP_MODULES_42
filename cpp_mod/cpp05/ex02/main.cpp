#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    // Test 1: Shrubbery
    try {
        Bureaucrat bob("Bob", 1);
        ShrubberyCreationForm form("home");
        
        bob.signForm(form);
        bob.executeForm(form);
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    // Test 2: Robotomy
    try {
        Bureaucrat alice("Alice", 1);
        RobotomyRequestForm form("Bender");
        
        alice.signForm(form);
        alice.executeForm(form);
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    // Test 3: Presidential Pardon
    try {
        Bureaucrat president("President", 1);
        PresidentialPardonForm form("Arthur");
        
        president.signForm(form);
        president.executeForm(form);
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    // Test 4: Unsigned form (should fail)
    try {
        Bureaucrat intern("Intern", 150);
        ShrubberyCreationForm form("garden");
        
        intern.executeForm(form);  // Not signed!
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}
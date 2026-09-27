#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include <iostream>

int main() {
    // Test 1: Valid form
    {
        Intern intern;
        AForm* form = intern.makeForm("shrubbery creation", "chimex");
        
        if (form) {
            Bureaucrat bob("Bob", 1);
            bob.signForm(*form);
            bob.executeForm(*form);
            delete form;
        }
    }
    
    // Test 2: Subject example
    {
        Intern someRandomIntern;
        AForm* rrf;
        
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        
        if (rrf) {
            std::cout << *rrf << std::endl;
            delete rrf;
        }
    }
    
    // Test 3: Invalid form
    {
        Intern intern;
        AForm* form = intern.makeForm("invalid form", "target");
        
        if (!form) {
            std::cout << "Form creation failed." << std::endl;
        }
    }
    
    return 0;
}
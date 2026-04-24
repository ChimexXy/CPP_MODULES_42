#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


int main() {
    try {

        Bureaucrat highRanker("Ma9La", 1);
        Bureaucrat lowRanker("ChaNkaR", 140);

        ShrubberyCreationForm shrubbery("Home");
        RobotomyRequestForm robotomy("Target");
        PresidentialPardonForm pardon("Eve");

        std::cout << "\n--- ShrubberyCreationForm ---" << std::endl;
        
        std::cout << shrubbery << std::endl;
        lowRanker.signForm(shrubbery);
        lowRanker.executeForm(shrubbery);
        highRanker.executeForm(shrubbery);
        std::cout << shrubbery << std::endl;

        std::cout << "\n--- RobotomyRequestForm ---\n";
        std::cout << robotomy << std::endl;
        highRanker.signForm(robotomy);
        highRanker.executeForm(robotomy);
        std::cout << robotomy << std::endl;

        std::cout << "\n--- PresidentialPardonForm ---\n";
        std::cout << pardon << std::endl;
        highRanker.signForm(pardon);
        highRanker.executeForm(pardon);
        std::cout << pardon << std::endl;

        std::cout << "\n--- Errors ---\n";
        try {
            lowRanker.signForm(pardon);
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }

        try {
            lowRanker.executeForm(pardon); 
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }

    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
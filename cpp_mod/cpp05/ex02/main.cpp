#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    try
    {
        Bureaucrat b1("Alice", 1);
        Bureaucrat b2("Bob", 150);

        ShrubberyCreationForm form1("home");
        PresidentialPardonForm form2("Charlie");
        RobotomyRequestForm form3("Dave");

        std::cout << form1 << std::endl;
        std::cout << form2 << std::endl;
        std::cout << form3 << std::endl;

        b1.signForm(form1);
        b1.signForm(form2);
        b1.signForm(form3);

        b1.executeForm(form1);
        b1.executeForm(form2);
        b1.executeForm(form3);

        b2.signForm(form1);
        b2.executeForm(form1);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
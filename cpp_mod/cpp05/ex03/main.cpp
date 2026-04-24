#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include <stdexcept>

static void safeDeleteForm(AForm* form)
{
    delete form;
}

static void processForm(Intern& intern, Bureaucrat& bureaucrat, const std::string& formName, const std::string& target)
{
    AForm* form = NULL;

    try
    {
        form = intern.makeForm(formName, target);
        if (!form)
            throw std::runtime_error("form creation failed");
        bureaucrat.signForm(*form);
        bureaucrat.executeForm(*form);
    }
    catch (const std::exception& e)
    {
        std::cout << "Error while processing \"" << formName << "\": " << e.what() << std::endl;
    }
    safeDeleteForm(form);
    std::cout << std::endl;
}

int main()
{
    Bureaucrat b1("b1", 1); 
    Bureaucrat b2("b2", 150);
    Intern intern;

    processForm(intern, b1, "shrubbery creation", "home");
    processForm(intern, b2, "robotomy request", "bender");
    processForm(intern, b1, "presidential pardon", "president");
    processForm(intern, b1, "invalid form name", "target");

    return 0;
}
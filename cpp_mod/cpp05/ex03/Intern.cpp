#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Default Constractor called" << std::endl;
}

Intern::Intern(const Intern& org)
{
	(void)org;
	std::cout << "copy constractor called" << std::endl;
}

Intern& Intern::operator=(const Intern& org)
{
	(void)org;
	std::cout << "operator assignment called" << std::endl;
	return *this;
}

Intern::~Intern()
{
	std::cout << "Destractor called" << std::endl;
}

AForm* Intern::makeForm(std::string formName, std::string target) {
    // Array of form names
    std::string formNames[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    
    int formIndex = -1;
    
    for (int i = 0; i < 3; i++) 
	{
        if (formNames[i] == formName)
		{
            formIndex = i;
            break;
        }
    }
    
    AForm* form = NULL;
    
    switch (formIndex) {
        case 0:
            form = new ShrubberyCreationForm(target);
            break;
        case 1:
            form = new RobotomyRequestForm(target);
            break;
        case 2:
            form = new PresidentialPardonForm(target);
            break;
        default:
            std::cout << "Error: Form \"" << formName << "\" does not exist!" << std::endl;
            return NULL;
    }
    
    std::cout << "Intern creates " << formName << std::endl;
    return form;
}
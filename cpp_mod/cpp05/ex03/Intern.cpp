#include"Intern.hpp"

Intern::Intern(){
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern& org){
	std::cout << "Intern copy constructor called" << std::endl;
	(void)org;
}

Intern& Intern::operator=(const Intern& org){
	std::cout << "Intern copy assignment operator called" << std::endl;
	(void)org;
	return *this;
}


Intern::~Intern(){
	std::cout << "Intern destructor called" << std::endl;
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target){
	if (formName == "shrubbery creation"){
		std::cout << "Intern creates " << formName << std::endl;
		return new ShrubberyCreationForm(target);
	}
	if (formName == "robotomy request"){
		std::cout << "Intern creates " << formName << std::endl;
		return new RobotomyRequestForm(target);
	}
	if (formName == "presidential pardon"){
		std::cout << "Intern creates " << formName << std::endl;
		return new PresidentialPardonForm(target);
	}
	std::cout << "Intern cannot create " << formName << " because it is not a valid form name" << std::endl;
	return NULL;
}


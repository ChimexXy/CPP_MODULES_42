#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	_name = "moad";
	_grade = 42;
	std::cout << "Default constractor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& org)
{
	std::cout << "copy constractor called" << std::endl;
	this->_name = org._name;
	this->_grade = org._grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& org)
{
	std::cout << "assignment operator called" << std::endl;
	if (this != &org)
	_grade = org._grade;
return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "destractor called for " << _name << std::endl;
}

// Bureaucrat::Bureaucrat(const std::string& name, int grade)
// {
		// this->_name = org._name;

// 	    std::cout << "Bureaucrat constructor called for " << _name << std::endl;
    
//     if (grade < HIGHEST_GRADE)
//         throw GradeTooHighException();
//     if (grade > LOWEST_GRADE)
//         throw GradeTooLowException();
    
//     _grade = grade;
// }
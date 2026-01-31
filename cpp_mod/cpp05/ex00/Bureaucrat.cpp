#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("chimex")
{
	_grade = 37;
	std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& org) : _name(org._name)
{
	std::cout << "copy constructor called" << std::endl;
	_grade = org._grade;
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
	std::cout << "destructor called for " << _name << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();

    _grade = grade;
}

const std::string& Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::incrementGrade()
{
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	_grade--;
}
void Bureaucrat::decrementGrade()
{
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() 
{
    return "Grade is too high! (Must be >= 1)";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low! (Must be <= 150)";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}

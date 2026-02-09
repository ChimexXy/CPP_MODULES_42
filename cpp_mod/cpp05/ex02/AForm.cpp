#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("chimex"), _gradeSign(1), _gradeExecute(1)
{
	_sig = false;
	std::cout << "Default constructor called" << std::endl;
}

AForm::AForm(const AForm& org) : _name(org._name), _gradeSign(org._gradeSign), _gradeExecute(org._gradeExecute), _sig(org._sig)
{
	std::cout << "copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& org) 
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &org)
	{
		_sig = org._sig;
	}
	return (*this);
}

AForm::~AForm()
{
	std::cout << "Destructor called" << std::endl;
}

AForm::AForm(const std::string& name, int gToSig, int gToExec) : _name(name), _gradeSign(gToSig), _gradeExecute(gToExec), _sig(false)
{
	if (gToSig < 1 || gToExec < 1)
		throw GradeTooHighException();

	if (gToSig > 150 || gToExec > 150)
		throw GradeTooLowException();
}

const std::string& AForm::getName() const {
    return _name;
}

bool AForm::getSign() const {
    return _sig;
}

int AForm::getGradeSign() const {
    return _gradeSign;
}

int AForm::getGradeExecute() const {
    return _gradeExecute;
}

const char* AForm::GradeTooHighException::what() const throw() 
{
    return "AForm Grade is too high! (Must be >= 1)";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "AForm Grade is too low! (Must be <= 150)";
}

void AForm::beSign(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeSign) {
        throw GradeTooLowException();
    }
    _sig = true;
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
    os << "AForm " << form.getName() 
       << ", signed: " << (form.getSign() ? "yes" : "no")
       << ", grade required to sign: " << form.getGradeSign()
       << ", grade required to execute: " << form.getGradeExecute();
    return os;
}
#include "Form.hpp"

Form::Form() : _name("chimex"), _gradeSign(1), _gradeExecute(1)
{
	_sig = false;
	std::cout << "Default constructor called" << std::endl;
}

Form::Form(const Form& org) : _name(org._name), _gradeSign(org._gradeSign), _gradeExecute(org._gradeExecute), _sig(org._sig)
{
	std::cout << "copy constructor called" << std::endl;
}

Form& Form::operator=(const Form& org) 
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &org)
	{
		_sig = org._sig;
	}
	return (*this);
}

Form::~Form()
{
	std::cout << "Destructor called" << std::endl;
}

Form::Form(const std::string& name, int gToSig, int gToExec) : _name(name), _gradeSign(gToSig), _gradeExecute(gToExec), _sig(false)
{
	if (gToSig < 1 || gToExec < 1)
		throw GradeTooHighException();

	if (gToSig > 150 || gToExec > 150)
		throw GradeTooLowException();
}

const std::string& Form::getName() const {
    return _name;
}

bool Form::getSign() const {
    return _sig;
}

int Form::getGradeSign() const {
    return _gradeSign;
}

int Form::getGradeExecute() const {
    return _gradeExecute;
}

const char* Form::GradeTooHighException::what() const throw() 
{
    return "Form Grade is too high! (Must be >= 1)";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Form Grade is too low! (Must be <= 150)";
}

void Form::beSign(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeSign) {
        throw GradeTooLowException();
    }
    _sig = true;
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << "Form " << form.getName() 
       << ", signed: " << (form.getSign() ? "yes" : "no")
       << ", grade required to sign: " << form.getGradeSign()
       << ", grade required to execute: " << form.getGradeExecute();
    return os;
}
#include "Form.hpp"

Form::Form() : _name("chimex"), _gradeSign(1), _gradeExecute(1)
{
	_sig = false;
	std::cout << "Default constructor called" << std::endl;
}

Form::Form(const Form& org) : _name(org._name), _gradeSign(org._gradeSign), _gradeExecute(org._gradeExecute)
{
	_sig = org._sig;
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
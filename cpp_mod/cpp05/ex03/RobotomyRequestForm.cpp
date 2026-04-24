#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("test")
{
	std::cout << "Default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& org) : AForm(org), _target(org._target)
{
	std::cout << "copy constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& org)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &org)
	{
		AForm::operator=(org);
		_target = org._target;
	}
	return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "Parameterized constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Destructor called" << std::endl;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	// if (!getSign())
	// 	throw AForm::FormNotSignedException();
	if (executor.getGrade() > getGradeExecute())
		throw AForm::GradeTooLowException();

	std::cout << "Bzzzzzz... " << _target << " has been robotomized successfully 50% of the time." << std::endl;
}
#include "RobotomyRequestForm.hpp"

RobotmyRequestForm::RobotmyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("test")
{
	std::cout << "Default constructor called" << std::endl;
}

RobotmyRequestForm::RobotmyRequestForm(const RobotmyRequestForm& org) : AForm(org), _target(org._target)
{
	std::cout << "copy constructor called" << std::endl;
}

RobotmyRequestForm& RobotmyRequestForm::operator=(const RobotmyRequestForm& org)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &org)
	{
		AForm::operator=(org);
		_target = org._target;
	}
	return (*this);
}

RobotmyRequestForm::RobotmyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "Parameterized constructor called" << std::endl;
}

RobotmyRequestForm::~RobotmyRequestForm()
{
	std::cout << "Destructor called" << std::endl;
}

void RobotmyRequestForm::execute(const Bureaucrat& executor) const
{
	// if (!getSign())
	// 	throw AForm::FormNotSignedException();
	if (executor.getGrade() > getGradeExecute())
		throw AForm::GradeTooLowException();

	std::cout << "Bzzzzzz... " << _target << " has been robotomized successfully 50% of the time." << std::endl;
}
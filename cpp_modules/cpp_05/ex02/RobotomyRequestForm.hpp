#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <exception>
#include <string>

class RobotomyRequestForm : public AForm{
private:
	std::string _target;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& org);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& org);
	~RobotomyRequestForm();

	virtual void execute(const Bureaucrat& executor) const;
} ;


#endif
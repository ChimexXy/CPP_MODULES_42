#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <exception>
#include <string>

class RobotmyRequestForm : public AForm{
private:
	std::string _target;
public:
	RobotmyRequestForm();
	RobotmyRequestForm(const std::string& target);
	RobotmyRequestForm(const RobotmyRequestForm& org);
	RobotmyRequestForm& operator=(const RobotmyRequestForm& org);
	~RobotmyRequestForm();

	virtual void execute(const Bureaucrat& executor) const;
} ;


#endif
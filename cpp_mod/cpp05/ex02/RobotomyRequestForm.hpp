#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <exception>
#include <string>

class ROBOTMYREQUESTFORM : public AForm{
private:
	std::string _target;
public:
	RobotMyRequestForm();
	RobotMyRequestForm(const std::string& target);
	RobotMyRequestForm(const RobotMyRequestForm& org);
	RobotMyRequestForm operator=(const RobotMyRequestForm& org);
	~RobotMyRequestForm();
} ;


#endif
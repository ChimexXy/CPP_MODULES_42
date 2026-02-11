#ifndef ROBOTMYREQUESTFORM_HPP
#define ROBOTMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm{
private:
	std::string _tar;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm& org);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& org);
	~RobotomyRequestForm();

	RobotomyRequestForm(const std::string& tar);
	void execute(Bureaucrat const & executor) const;
};

#endif
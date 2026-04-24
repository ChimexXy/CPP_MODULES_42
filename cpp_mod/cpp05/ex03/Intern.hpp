#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern{
public:
	Intern();
	Intern(const Intern& org);
	Intern& operator=(const Intern& org);
	~Intern();
	AForm* makeForm(const std::string& formName, const std::string& target);
} ;


#endif
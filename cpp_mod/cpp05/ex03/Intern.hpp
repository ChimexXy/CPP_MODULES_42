#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
public:
	Intern();
	Intern(const Intern& org);
	Intern& operator=(const Intern& org);
	~Intern();

	AForm* makeForm(std::string formName, std::string target);
};

#endif
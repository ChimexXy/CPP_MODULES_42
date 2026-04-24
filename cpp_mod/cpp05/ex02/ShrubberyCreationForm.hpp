#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <exception>
#include <string>

class SHRUBBERYCREATIONFORM : public AForm{
private:
	std::string _target;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& org);
	ShrubberyCreationForm operator=(const ShrubberyCreationForm& org);
	~ShrubberyCreationForm();
} ;


#endif
#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <exception>
#include <string>
#include <fstream>

class ShrubberyCreationForm : public AForm{
private:
	std::string _target;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& org);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& org);
	~ShrubberyCreationForm();

	void execute(Bureaucrat const & executor) const;
} ;


#endif
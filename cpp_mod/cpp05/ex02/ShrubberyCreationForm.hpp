// #pragma once
#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {
private:
	std::string _tar;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm& org);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& org);
	~ShrubberyCreationForm();

	ShrubberyCreationForm(const std::string& tar);
	void execute(Bureaucrat const & executor) const;
};

#endif
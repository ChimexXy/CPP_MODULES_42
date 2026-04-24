#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() _target("test") , AForm("ShrubberyCreationForm", "145", "137") 
{
	std::cout << "Default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& org) Aform(org) , _target(org._target)
{
	std::cout << "copy constructor called" << std::endl;
}



ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Destructor called" << std::endl;
}
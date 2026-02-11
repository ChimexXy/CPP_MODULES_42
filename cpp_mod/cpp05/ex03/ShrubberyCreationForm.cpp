#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _tar("chimex")
{
	std::cout << "default constractor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& org) : AForm(org), _tar(org._tar) 
{
	std::cout << "copy constractor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm:: operator=(const ShrubberyCreationForm& org)
{
	std::cout << "copy assignment called" << std::endl;
	if (this != &org)
	{
		AForm::operator=(org);
		_tar = org._tar;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Destractor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& tar) : AForm("ShrubberyCreationForm", 145, 137), _tar(tar)
{
	std::cout << "constractor called for " << _tar << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    // Check if form is signed
    if (!this->getSign()) {
        throw FormNotSignedException();
    }
    
    // Check if executor has high enough grade
    if (executor.getGrade() > this->getGradeExecute()) {
        throw GradeTooLowException();
    }
    
    // Execute: create file with ASCII trees
    std::string filename = _tar + "_shrubbery";
    std::ofstream file(filename.c_str());
    
    if (!file.is_open()) {
        std::cout << "Error: Could not create file " << filename << std::endl;
        return;
    }
    
    file << "       ###" << std::endl;
    file << "      #o###" << std::endl;
    file << "    #####o###" << std::endl;
    file << "   #o#\\#|#/###" << std::endl;
    file << "    ###\\|/#o#" << std::endl;
    file << "     # }|{  #" << std::endl;
    file << "       }|{" << std::endl;
    file << std::endl;
    file << "       ###" << std::endl;
    file << "      #o###" << std::endl;
    file << "    #####o###" << std::endl;
    file << "   #o#\\#|#/###" << std::endl;
    file << "    ###\\|/#o#" << std::endl;
    file << "     # }|{  #" << std::endl;
    file << "       }|{" << std::endl;
    
    file.close();
    std::cout << "Created shrubbery file: " << filename << std::endl;
}
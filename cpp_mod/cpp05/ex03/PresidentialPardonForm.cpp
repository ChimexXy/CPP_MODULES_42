#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _tar("chimex")
{
	std::cout << "default constractor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& org) : AForm(org), _tar(org._tar) 
{
	std::cout << "copy constractor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm:: operator=(const PresidentialPardonForm& org)
{
	std::cout << "copy assignment called" << std::endl;
	if (this != &org)
	{
		AForm::operator=(org);
		_tar = org._tar;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Destractor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& tar) : AForm("PresidentialPardonForm", 25, 5), _tar(tar)
{
	std::cout << "constractor called for " << _tar << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    // Check if form is signed
    if (!this->getSign()) {
        throw FormNotSignedException();
    }
    
    // Check if executor has high enough grade
    if (executor.getGrade() > this->getGradeExecute()) {
        throw GradeTooLowException();
    }
    
    // Execute: inform of pardon
    std::cout << _tar << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
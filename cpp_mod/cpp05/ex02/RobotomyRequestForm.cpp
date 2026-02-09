#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _tar("chimex")
{
	std::cout << "default constractor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& org) : AForm(org), _tar(org._tar) 
{
	std::cout << "copy constractor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm:: operator=(const RobotomyRequestForm& org)
{
	std::cout << "copy assignment called" << std::endl;
	if (this != &org)
	{
		AForm::operator=(org);
		_tar = org._tar;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Destractor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& tar) : AForm("RobotomyRequestForm", 72, 45), _tar(tar)
{
	std::cout << "constractor called for " << _tar << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    // Check if form is signed
    if (!this->getSign()) {
        throw FormNotSignedException();
    }
    
    // Check if executor has high enough grade
    if (executor.getGrade() > this->getGradeExecute()) {
        throw GradeTooLowException();
    }
    
    // Execute: make drilling noises and robotomize
    std::cout << "* BZZZZZZZT * DRILLING NOISES * BZZZZZZZT *" << std::endl;
    
    // 50% success rate
    srand(time(NULL));
    if (rand() % 2 == 0) {
        std::cout << _tar << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << "Robotomy failed on " << _tar << "!" << std::endl;
    }
}

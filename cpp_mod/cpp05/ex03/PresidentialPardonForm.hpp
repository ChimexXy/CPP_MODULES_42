#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm{
private:
	std::string _tar;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm& org);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& org);
	~PresidentialPardonForm();

	PresidentialPardonForm(const std::string& tar);
	void execute(Bureaucrat const & executor) const;
};

#endif
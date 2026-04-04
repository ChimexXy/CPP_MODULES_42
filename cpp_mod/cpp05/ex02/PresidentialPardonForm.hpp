#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <exception>
#include <string>

class PresidentialPardonForm : public AForm {
private:
    std::string _target;
public:
    PresidentialPardonForm();
    PresidentialPardonForm(const std::string& target);
    PresidentialPardonForm(const PresidentialPardonForm& org);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& org);
    ~PresidentialPardonForm();

    void execute(Bureaucrat const & executor) const;
};

#endif
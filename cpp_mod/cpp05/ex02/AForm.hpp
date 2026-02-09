#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class AForm {
private:
	const std::string _name;
	const int _gradeSign;
	const int _gradeExecute;
	bool _sig;

public:
	AForm();
	AForm(const AForm& org);
	AForm& operator=(const AForm& org);
	virtual ~AForm();

	AForm(const std::string& name, int gToSig, int gToExec);
	virtual void execute(Bureaucrat const & executor) const = 0;

	const std::string& getName() const;
	bool getSign() const;
	int getGradeSign() const;
	int getGradeExecute() const;

	void beSign(const Bureaucrat& bureaucrat);

	class GradeTooHighException : public std::exception{
	public:
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception{
	public:
		virtual const char* what() const throw();
	};
	class FormNotSignedException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif
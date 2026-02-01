#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class Form {
private:
	const std::string _name;
	const int _gradeSign;
	const int _gradeExecute;
	bool _sig;

public:
	Form();
	Form(const Form& org);
	Form& operator=(const Form& org);
	~Form();

	Form(const std::string& name, int gToSig, int gToExec);

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

};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
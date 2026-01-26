#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat{
private:
	const std::string _name;
	int _grade;
	static const int _highset = 1;
	static const int _lowset = 150;

public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat& org);
	Bureaucrat& operator=(const Bureaucrat& org);
	~Bureaucrat();

	Bureaucrat(const std::string& name, int grade);
};

#endif
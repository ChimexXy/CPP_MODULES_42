#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
private:
	std::string ideas[100];
	std::string type;
public:
	Brain();
	Brain(const Brain& org);
	Brain& operator=(const Brain& org);
	~Brain();

};

#endif

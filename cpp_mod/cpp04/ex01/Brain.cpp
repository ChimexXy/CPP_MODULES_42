#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& org)
{
	std::cout << "Brain copy constructor called" << std::endl;
	this->type = org.type;
}

Brain& Brain::operator=(const Brain& org)
{
	std::cout << "Brain assigenment operator called" << std::endl;
	if (this != &org)
	{
		type = org.type;
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain Destructor called" << std::endl;
	 
}


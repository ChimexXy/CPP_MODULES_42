#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& org)
{
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++) {
        this->ideas[i] = org.ideas[i];
    }
}

Brain& Brain::operator=(const Brain& org)
{
	std::cout << "Brain assigenment operator called" << std::endl;
	if (this != &org)
	{
		 for (int i = 0; i < 100; i++) {
            this->ideas[i] = org.ideas[i];
        }
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain Destructor called" << std::endl;

}


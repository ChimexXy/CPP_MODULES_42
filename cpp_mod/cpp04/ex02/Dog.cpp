#include "Dog.hpp"

Dog::Dog() : AAnimal()
{
    type = "Dog";
	this->brain = new Brain(); 
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& org) : AAnimal(org)
{
	this->brain = new Brain(*org.brain);
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& org)
{
	std::cout << "Dog Copy assignment operator called" << std::endl;
    if (this != &org)
	{
        AAnimal::operator=(org);
		delete this->brain;
        this->brain = new Brain(*org.brain);
	}
    return *this;
}

Dog::~Dog()
{
	delete this->brain;
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Woof woof!" << std::endl;
}

#include "Cat.hpp"

Cat::Cat() : AAnimal()
{
    type = "Cat";
	this->brain = new Brain(); 
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& org) : AAnimal(org)
{
	this->brain = new Brain(*org.brain);
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& org)
{
	std::cout << "Cat Copy assignment operator called" << std::endl;
    if (this != &org)
	{
        AAnimal::operator=(org);
		delete this->brain;
        this->brain = new Brain(*org.brain);
	}
    return *this;
}

Cat::~Cat()
{
	delete this->brain;
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meow Meow!" << std::endl;
}

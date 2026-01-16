#include "Animal.hpp"

Animal::Animal()
{
    type = "Animal";
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal& org)
{
	std::cout << "Animal Copy constructor called" << std::endl;
    this->type = org.type;
}

Animal& Animal::operator=(const Animal& org)
{
	std::cout << "Animal Copy assignment operator called" << std::endl;
    if (this != &org)
        type = org.type;
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const
{
    return type;
}

void Animal::makeSound() const
{
    std::cout << "Animal makes a sound" << std::endl;
}

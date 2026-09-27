#include "Animal.hpp"

AAnimal::AAnimal()
{
    type = "AAnimal";
    std::cout << "AAnimal constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& org)
{
	std::cout << "AAnimal Copy constructor called" << std::endl;
    this->type = org.type;
}

AAnimal& AAnimal::operator=(const AAnimal& org)
{
	std::cout << "AAnimal Copy assignment operator called" << std::endl;
    if (this != &org)
        type = org.type;
    return *this;
}

AAnimal::~AAnimal()
{
    std::cout << "AAnimal destructor called" << std::endl;
}

std::string AAnimal::getType() const
{
    return type;
}

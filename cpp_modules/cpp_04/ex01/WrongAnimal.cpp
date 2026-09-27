#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	type = "WrongAnimal";
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& org)
{
	std::cout << "WrongAnimal Copy constructor called" << std::endl;
    this->type = org.type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& org)
{
	std::cout << "Copy assignment operator called" << std::endl;
    if (this != &org)
        type = org.type;
    return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

void WrongAnimal::MakeSound() const
{
	std::cout << "WrongAnimal sound" << std::endl;
}

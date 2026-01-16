#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	type = "WrongCat";
	std::cout << "WrongCat constractor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& org) : WrongAnimal(org)
{
	std::cout << "WrongCat Copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& org)
{
	std::cout << "Copy assignment operator called" << std::endl;
    if (this != &org)
        type = org.type;
    return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::MakeSound() const
{
	std::cout << "WrongCat sound" << std::endl;
}

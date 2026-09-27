#include "Ice.hpp"

Ice::Ice()
{
	type = "ice";
    std::cout << "Ice constructor called" << std::endl;
}

Ice::Ice(const Ice& org) : AMateria(org)
{
    std::cout << "Ice copy constructor called" << std::endl;
}

Ice& Ice::operator=(const Ice& org)
{
    std::cout << "Ice assignment operator called" << std::endl;
    if (this != &org)
	{
        AMateria::operator=(org);
    }
    return *this;
}

Ice::~Ice()
{
    std::cout << "Ice destructor called" << std::endl;
}

AMateria* Ice::clone() const
{
    return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
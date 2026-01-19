#include "Cure.hpp"

Cure::Cure()
{
	type = "Cure";
    std::cout << "Cure constructor called" << std::endl;
}

Cure::Cure(const Cure& org) : AMateria(org)
{
    std::cout << "Cure copy constructor called" << std::endl;
}

Cure& Cure::operator=(const Cure& org) 
{
    std::cout << "Cure assignment operator called" << std::endl;
    if (this != &org)
	{
        AMateria::operator=(org);
    }
    return *this;
}

Cure::~Cure()
{
    std::cout << "Cure destructor called" << std::endl;
}

AMateria* Cure::clone() const 
{
    return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
#include "AMateria.hpp"

AMateria::AMateria()
{
    type = "chimex";
    std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& org) 
{
    std::cout << "AMateria copy constructor called" << std::endl;
    this->type = org.type;
}

AMateria& AMateria::operator=(const AMateria& org)
{
    std::cout << "AMateria Copy assignment operator called" << std::endl;
    if (this != &org) {}
    return *this;
}

AMateria::~AMateria() 
{
    std::cout << "AMateria destructor called" << std::endl;
}

std::string const & AMateria::getType() const
{
    return this->type;
}

void AMateria::use(ICharacter& target)
{
    (void)target;
    std::cout << "* uses some materia *" << std::endl;
}
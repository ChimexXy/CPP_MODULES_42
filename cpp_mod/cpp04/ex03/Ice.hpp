#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria {
public:
    Ice();
    Ice(const Ice& org);
    Ice& operator=(const Ice& org);
    ~Ice();

    AMateria* clone() const;    
    void use(ICharacter& target);
};

#endif
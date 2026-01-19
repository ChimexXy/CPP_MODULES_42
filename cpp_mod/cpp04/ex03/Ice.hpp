#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria {
public:
    Ice();
    Ice(const Ice& other);
    Ice& operator=(const Ice& other);
    ~Ice();
    
    // Override pure virtual
    AMateria* clone() const;
    
    // Override use
    void use(ICharacter& target);
};

#endif
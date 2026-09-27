#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include <iostream>

class ICharacter;

class AMateria {
protected:
    std::string type;

public:
    AMateria();
    AMateria(const AMateria& org);
    AMateria& operator=(const AMateria& org);
    virtual ~AMateria();

    std::string const & getType() const;
    
    virtual AMateria* clone() const = 0;
    
    virtual void use(ICharacter& target);
};

#endif
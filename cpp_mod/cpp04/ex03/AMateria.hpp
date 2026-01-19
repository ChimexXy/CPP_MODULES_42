#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include <iostream>

// Forward declaration (we'll use ICharacter later)
class ICharacter;

class AMateria {
protected:
    std::string _type;

public:
    // Orthodox Canonical Form
    AMateria();
    AMateria(std::string const & type);
    AMateria(const AMateria& other);
    AMateria& operator=(const AMateria& other);
    virtual ~AMateria();
    
    // Getters
    std::string const & getType() const;  // Returns the materia type
    
    // Pure virtual - makes this class abstract
    virtual AMateria* clone() const = 0;
    
    // Virtual method with implementation
    virtual void use(ICharacter& target);
};

#endif
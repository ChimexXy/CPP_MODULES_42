#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal
{
protected:
    std::string type;

public:
    AAnimal();
    AAnimal(const AAnimal& org);
    AAnimal& operator=(const AAnimal& org);
    virtual ~AAnimal();

    virtual void makeSound() const = 0;
    std::string getType() const;
};

#endif

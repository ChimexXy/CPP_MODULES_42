#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
public:
    Dog();
    Dog(const Dog& org);
    Dog& operator=(const Dog& org);
    ~Dog();

    void makeSound() const;
};

#endif

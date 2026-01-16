#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
public:
    Cat();
    Cat(const Cat& org);
    Cat& operator=(const Cat& org);
    ~Cat();

    void makeSound() const;
};

#endif

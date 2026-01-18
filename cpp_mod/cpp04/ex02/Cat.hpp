#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
private:
	Brain* brain;
public:
    Cat();
    Cat(const Cat& org);
    Cat& operator=(const Cat& org);
    ~Cat();

    void makeSound() const;
};

#endif

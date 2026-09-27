#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"
#include <iostream>

int main()
{
const Animal* j = new Dog();
const Animal* i = new Cat();

delete j;//should not create a leak
delete i;

}
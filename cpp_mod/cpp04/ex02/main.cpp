#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"


int main() {
    std::cout << "=== Ex02: Abstract Animal Test ===" << std::endl;
    
    // This would NOT compile:
    // Animal animal;  // Error! Animal is abstract
    
    std::cout << "\n--- Creating array of Animals ---" << std::endl;
    const int size = 4;
    AAnimal* animals[size];
    
    for (int i = 0; i < size; i++) {
        if (i < size / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }
    
    std::cout << "\n--- Testing polymorphism ---" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << animals[i]->getType() << " says: ";
        animals[i]->makeSound();
    }
    
    std::cout << "\n--- Deleting animals ---" << std::endl;
    for (int i = 0; i < size; i++) {
        delete animals[i];
    }
    
    std::cout << "\n--- Deep copy test ---" << std::endl;
    Dog originalDog;
    {
        Dog copyDog = originalDog;
        std::cout << "Copy dog making sound: ";
        copyDog.makeSound();
    }  // copyDog destroyed here
    
    std::cout << "Original dog still works: ";
    originalDog.makeSound();
    
    std::cout << "\n=== Test complete ===" << std::endl;
    
    return 0;
}
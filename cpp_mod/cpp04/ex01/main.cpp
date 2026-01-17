#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    std::cout << "=== Testing WrongAnimal OCF ===" << std::endl;
    
    // Default constructor
    WrongAnimal wa1;
    
    // Copy constructor
    WrongAnimal wa2(wa1);
    
    // Assignment operator
    WrongAnimal wa3;
    wa3 = wa1;
    
    std::cout << "\n=== Testing WrongCat OCF ===" << std::endl;
    
    // Default constructor
    WrongCat wc1;
    
    // Copy constructor
    WrongCat wc2(wc1);
    
    // Assignment operator
    WrongCat wc3;
    wc3 = wc1;
    
    return 0;
}
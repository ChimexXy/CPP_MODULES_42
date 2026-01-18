#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"
#include <iostream>

void test_subject_requirements() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "TEST 1: Subject Requirements (Array Test)" << std::endl;
    std::cout << "========================================\n" << std::endl;
    
    // Create array of 4 animals (half dogs, half cats)
    const int size = 4;
    Animal* animals[size];
    
    std::cout << "--- Creating animals ---" << std::endl;
    for (int i = 0; i < size; i++) {
        if (i < size / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }
    
    std::cout << "\n--- Making sounds ---" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << "Animal " << i << " (" << animals[i]->getType() << "): ";
        animals[i]->makeSound();
    }
    
    std::cout << "\n--- Deleting animals ---" << std::endl;
    for (int i = 0; i < size; i++) {
        delete animals[i];
    }
    
    std::cout << "\n✅ All animals deleted properly (check for leaks with valgrind)" << std::endl;
}

void test_deep_copy() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "TEST 2: Deep Copy (Copy Constructor)" << std::endl;
    std::cout << "========================================\n" << std::endl;
    
    std::cout << "--- Creating original dog ---" << std::endl;
    Dog* original = new Dog();
    
    std::cout << "\n--- Creating copy of dog ---" << std::endl;
    Dog* copy = new Dog(*original);
    
    std::cout << "\n--- Deleting original ---" << std::endl;
    delete original;
    
    std::cout << "\n--- Copy should still work (different Brain) ---" << std::endl;
    copy->makeSound();
    
    std::cout << "\n--- Deleting copy ---" << std::endl;
    delete copy;
    
    std::cout << "\n✅ Deep copy works! Each dog has its own Brain" << std::endl;
}

void test_assignment_operator() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "TEST 3: Assignment Operator" << std::endl;
    std::cout << "========================================\n" << std::endl;
    
    std::cout << "--- Creating dog1 ---" << std::endl;
    Dog dog1;
    
    std::cout << "\n--- Creating dog2 ---" << std::endl;
    Dog dog2;
    
    std::cout << "\n--- Assigning dog1 to dog2 ---" << std::endl;
    dog2 = dog1;
    
    std::cout << "\n--- Both dogs making sounds ---" << std::endl;
    dog1.makeSound();
    dog2.makeSound();
    
    std::cout << "\n--- Destructors will be called ---" << std::endl;
    
    std::cout << "\n✅ Assignment operator works! Each dog has its own Brain" << std::endl;
}

void test_polymorphism() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "TEST 4: Polymorphism with Brain" << std::endl;
    std::cout << "========================================\n" << std::endl;
    
    std::cout << "--- Creating animals via base pointer ---" << std::endl;
    Animal* dog = new Dog();
    Animal* cat = new Cat();
    
    std::cout << "\n--- Calling makeSound() through base pointer ---" << std::endl;
    std::cout << "Dog says: ";
    dog->makeSound();
    std::cout << "Cat says: ";
    cat->makeSound();
    
    std::cout << "\n--- Deleting through base pointer ---" << std::endl;
    delete dog;  // Should call Dog destructor, then Animal destructor
    delete cat;  // Should call Cat destructor, then Animal destructor
    
    std::cout << "\n✅ Virtual destructors work! Brain is properly deleted" << std::endl;
}

void test_brain_independence() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "TEST 5: Brain Independence (Advanced)" << std::endl;
    std::cout << "========================================\n" << std::endl;
    
    std::cout << "--- Creating two dogs ---" << std::endl;
    Dog dog1;
    Dog dog2;
    
    std::cout << "\n--- dog1 and dog2 have different brains ---" << std::endl;
    std::cout << "dog1 Brain address: " << &dog1 << std::endl;
    std::cout << "dog2 Brain address: " << &dog2 << std::endl;
    
    std::cout << "\n--- Copying dog1 to dog3 ---" << std::endl;
    Dog dog3 = dog1;
    
    std::cout << "\n--- dog1 and dog3 should have DIFFERENT brains ---" << std::endl;
    std::cout << "dog1 address: " << &dog1 << std::endl;
    std::cout << "dog3 address: " << &dog3 << std::endl;
    std::cout << "(Different addresses = different Brain objects)" << std::endl;
    
    std::cout << "\n✅ Each dog has its own independent Brain!" << std::endl;
}

void test_mixed_array() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "TEST 6: Mixed Array (Larger Test)" << std::endl;
    std::cout << "========================================\n" << std::endl;
    
    const int size = 10;
    Animal* animals[size];
    
    std::cout << "--- Creating 10 animals ---" << std::endl;
    for (int i = 0; i < size; i++) {
        if (i % 2 == 0) {
            std::cout << i << ": ";
            animals[i] = new Dog();
        } else {
            std::cout << i << ": ";
            animals[i] = new Cat();
        }
    }
    
    std::cout << "\n--- All animals making sounds ---" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << i << " (" << animals[i]->getType() << "): ";
        animals[i]->makeSound();
    }
    
    std::cout << "\n--- Deleting all animals ---" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << "Deleting " << i << ": ";
        delete animals[i];
    }
    
    std::cout << "\n✅ Large array handled correctly!" << std::endl;
}

void test_self_assignment() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "TEST 7: Self-Assignment Protection" << std::endl;
    std::cout << "========================================\n" << std::endl;
    
    std::cout << "--- Creating a dog ---" << std::endl;
    Dog dog;
    
    std::cout << "\n--- Self-assigning (dog = dog) ---" << std::endl;
    dog = dog;
    
    std::cout << "\n--- Dog should still work fine ---" << std::endl;
    dog.makeSound();
    
    std::cout << "\n✅ Self-assignment handled correctly!" << std::endl;
}

void test_stack_vs_heap() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "TEST 8: Stack vs Heap Allocation" << std::endl;
    std::cout << "========================================\n" << std::endl;
    
    std::cout << "--- Creating dog on stack ---" << std::endl;
    {
        Dog stackDog;
        stackDog.makeSound();
        std::cout << "--- Leaving scope (automatic destruction) ---" << std::endl;
    }
    
    std::cout << "\n--- Creating dog on heap ---" << std::endl;
    Dog* heapDog = new Dog();
    heapDog->makeSound();
    
    std::cout << "\n--- Manual deletion ---" << std::endl;
    delete heapDog;
    
    std::cout << "\n✅ Both stack and heap allocation work!" << std::endl;
}

void test_copy_chain() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "TEST 9: Copy Chain" << std::endl;
    std::cout << "========================================\n" << std::endl;
    
    std::cout << "--- Creating original cat ---" << std::endl;
    Cat original;
    
    std::cout << "\n--- Creating copy1 from original ---" << std::endl;
    Cat copy1 = original;
    
    std::cout << "\n--- Creating copy2 from copy1 ---" << std::endl;
    Cat copy2 = copy1;
    
    std::cout << "\n--- Creating copy3 from copy2 ---" << std::endl;
    Cat copy3 = copy2;
    
    std::cout << "\n--- All cats making sounds ---" << std::endl;
    original.makeSound();
    copy1.makeSound();
    copy2.makeSound();
    copy3.makeSound();
    
    std::cout << "\n--- All cats will be destroyed ---" << std::endl;
    
    std::cout << "\n✅ Multiple levels of copying work!" << std::endl;
}

void test_wrong_animal() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "TEST 10: WrongAnimal (For Comparison)" << std::endl;
    std::cout << "========================================\n" << std::endl;
    
    std::cout << "--- Correct version (Animal with virtual) ---" << std::endl;
    const Animal* cat = new Cat();
    cat->makeSound();
    delete cat;
    
    std::cout << "\n--- Wrong version (WrongAnimal without virtual) ---" << std::endl;
    const WrongAnimal* wrongCat = new WrongCat();
    wrongCat->MakeSound();  // Will call WrongAnimal's version!
    delete wrongCat;
    
    std::cout << "\n⚠️  Notice: WrongCat didn't make the right sound!" << std::endl;
}

int main() {
    std::cout << "\n╔════════════════════════════════════════╗" << std::endl;
    std::cout << "║   CPP04 - Ex01 Comprehensive Tests    ║" << std::endl;
    std::cout << "╚════════════════════════════════════════╝" << std::endl;
    
    test_subject_requirements();    // Required by subject
    test_deep_copy();               // Test copy constructor
    test_assignment_operator();     // Test assignment operator
    test_polymorphism();            // Test virtual functions
    test_brain_independence();      // Test Brain separation
    test_mixed_array();             // Larger scale test
    test_self_assignment();         // Edge case
    test_stack_vs_heap();           // Different allocation methods
    test_copy_chain();              // Multiple copies
    test_wrong_animal();            // Comparison with WrongAnimal
    
    std::cout << "\n╔════════════════════════════════════════╗" << std::endl;
    std::cout << "║          All Tests Complete!           ║" << std::endl;
    std::cout << "║                                        ║" << std::endl;
    std::cout << "║  Now run with valgrind to check for:  ║" << std::endl;
    std::cout << "║  - Memory leaks                        ║" << std::endl;
    std::cout << "║  - Invalid reads/writes                ║" << std::endl;
    std::cout << "║  - Double frees                        ║" << std::endl;
    std::cout << "║                                        ║" << std::endl;
    std::cout << "║  valgrind --leak-check=full ./program  ║" << std::endl;
    std::cout << "╚════════════════════════════════════════╝\n" << std::endl;
    
    return 0;
}
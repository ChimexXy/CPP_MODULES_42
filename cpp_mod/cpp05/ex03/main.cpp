#include "Bureaucrat.hpp"

void test_valid_bureaucrat() {
    try {
        Bureaucrat bob("Bob", 50);  // ← Parameterized constructor
        std::cout << bob << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

void test_grade_too_high() {
    try {
        Bureaucrat invalid("Invalid", 0);  // ← Parameterized constructor
        std::cout << invalid << std::endl;
    } catch (Bureaucrat::GradeTooHighException& e) {
        std::cout << "Caught: " << e.what() << std::endl;
    }
}

void test_default_constructor() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "Test: Default Constructor" << std::endl;
    std::cout << "========================================\n" << std::endl;
    
    try {
        Bureaucrat defaultBureaucrat;  // ← No parameters!
        std::cout << defaultBureaucrat << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

void test_all_constructors() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "Test: All Constructors" << std::endl;
    std::cout << "========================================\n" << std::endl;
    
    std::cout << "--- 1. Default Constructor ---" << std::endl;
    Bureaucrat defaultBur;
    std::cout << defaultBur << std::endl;
    
    std::cout << "\n--- 2. Parameterized Constructor ---" << std::endl;
    Bureaucrat paramBur("Bob", 50);
    std::cout << paramBur << std::endl;
    
    std::cout << "\n--- 3. Copy Constructor ---" << std::endl;
    Bureaucrat copyBur(paramBur);
    std::cout << copyBur << std::endl;
    
    std::cout << "\n--- 4. Assignment Operator ---" << std::endl;
    defaultBur = paramBur;
    std::cout << defaultBur << std::endl;
    
    std::cout << "\n--- Destructors will be called ---" << std::endl;
}

int main() {
    std::cout << "╔════════════════════════════════════════╗" << std::endl;
    std::cout << "║   CPP05 - Ex00: Bureaucrat Tests      ║" << std::endl;
    std::cout << "╚════════════════════════════════════════╝" << std::endl;
    
    test_default_constructor();  // ← Add this!
    test_valid_bureaucrat();
    test_grade_too_high();
	test_all_constructors();
}
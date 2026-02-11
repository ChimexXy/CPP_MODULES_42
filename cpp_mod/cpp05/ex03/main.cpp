#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void separator(const std::string& title) {
    std::cout << "\n========================================" << std::endl;
    std::cout << title << std::endl;
    std::cout << "========================================\n" << std::endl;
}

void test_shrubbery() {
    separator("Test 1: Shrubbery Creation Form");
    try {
        Bureaucrat bob("Bob", 1);
        ShrubberyCreationForm form("home");
        
        std::cout << form << std::endl;
        bob.signForm(form);
        bob.executeForm(form);
        
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

void test_robotomy() {
    separator("Test 2: Robotomy Request Form");
    try {
        Bureaucrat alice("Alice", 1);
        RobotomyRequestForm form("Bender");
        
        std::cout << form << std::endl;
        alice.signForm(form);
        alice.executeForm(form);
        alice.executeForm(form);  // Try again for different result
        
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

void test_presidential() {
    separator("Test 3: Presidential Pardon Form");
    try {
        Bureaucrat president("President", 1);
        PresidentialPardonForm form("Arthur Dent");
        
        std::cout << form << std::endl;
        president.signForm(form);
        president.executeForm(form);
        
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

void test_unsigned_form() {
    separator("Test 4: Execute Unsigned Form");
    try {
        Bureaucrat bob("Bob", 1);
        ShrubberyCreationForm form("garden");
        
        std::cout << "Trying to execute unsigned form..." << std::endl;
        bob.executeForm(form);  // Not signed!
        
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

void test_grade_too_low_execute() {
    separator("Test 5: Grade Too Low to Execute");
    try {
        Bureaucrat intern("Intern", 150);
        Bureaucrat boss("Boss", 1);
        ShrubberyCreationForm form("office");
        
        boss.signForm(form);  // Boss signs it
        intern.executeForm(form);  // Intern tries to execute
        
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

void test_grade_too_low_sign() {
    separator("Test 6: Grade Too Low to Sign");
    try {
        Bureaucrat intern("Intern", 150);
        PresidentialPardonForm form("Ford Prefect");
        
        intern.signForm(form);  // Too low to sign
        
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

void test_all_forms() {
    separator("Test 7: All Three Forms");
    try {
        Bureaucrat supreme("Supreme Leader", 1);
        
        ShrubberyCreationForm shrubbery("park");
        RobotomyRequestForm robotomy("Wall-E");
        PresidentialPardonForm pardon("Marvin");
        
        std::cout << "=== Shrubbery ===" << std::endl;
        supreme.signForm(shrubbery);
        supreme.executeForm(shrubbery);
        
        std::cout << "\n=== Robotomy ===" << std::endl;
        supreme.signForm(robotomy);
        supreme.executeForm(robotomy);
        
        std::cout << "\n=== Presidential Pardon ===" << std::endl;
        supreme.signForm(pardon);
        supreme.executeForm(pardon);
        
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

void test_polymorphism() {
    separator("Test 8: Polymorphism with Base Pointer");
    try {
        Bureaucrat god("God", 1);
        
        AForm* forms[3];
        forms[0] = new ShrubberyCreationForm("forest");
        forms[1] = new RobotomyRequestForm("R2-D2");
        forms[2] = new PresidentialPardonForm("Zaphod");
        
        for (int i = 0; i < 3; i++) {
            std::cout << *forms[i] << std::endl;
            god.signForm(*forms[i]);
            god.executeForm(*forms[i]);
            std::cout << std::endl;
        }
        
        for (int i = 0; i < 3; i++) {
            delete forms[i];
        }
        
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

void test_grade_boundaries() {
    separator("Test 9: Grade Boundaries");
    try {
        // ShrubberyCreationForm: sign 145, exec 137
        Bureaucrat exact("Exact", 137);
        Bureaucrat tooLow("TooLow", 138);
        
        ShrubberyCreationForm form("boundary");
        
        Bureaucrat signer("Signer", 145);
        signer.signForm(form);
        
        std::cout << "Exact grade (137) executing:" << std::endl;
        exact.executeForm(form);
        
        std::cout << "\nToo low grade (138) executing:" << std::endl;
        tooLow.executeForm(form);
        
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

int main() {
    std::cout << "╔════════════════════════════════════════╗" << std::endl;
    std::cout << "║    CPP05 - Ex02: Concrete Forms       ║" << std::endl;
    std::cout << "╚════════════════════════════════════════╝" << std::endl;
    
    test_shrubbery();
    test_robotomy();
    test_presidential();
    test_unsigned_form();
    test_grade_too_low_execute();
    test_grade_too_low_sign();
    test_all_forms();
    test_polymorphism();
    test_grade_boundaries();
    
    std::cout << "\n╔════════════════════════════════════════╗" << std::endl;
    std::cout << "║         All Tests Complete!            ║" << std::endl;
    std::cout << "╚════════════════════════════════════════╝" << std::endl;
    
    return 0;
}
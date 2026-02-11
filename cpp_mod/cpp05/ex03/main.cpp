#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

void separator(const std::string& title) {
    std::cout << "\n========================================" << std::endl;
    std::cout << title << std::endl;
    std::cout << "========================================\n" << std::endl;
}

void test_create_shrubbery() {
    separator("Test 1: Create Shrubbery Form");
    try {
        Intern intern;
        AForm* form;
        
        form = intern.makeForm("shrubbery creation", "garden");
        
        if (form) {
            std::cout << *form << std::endl;
            
            Bureaucrat bob("Bob", 1);
            bob.signForm(*form);
            bob.executeForm(*form);
            
            delete form;
        }
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

void test_create_robotomy() {
    separator("Test 2: Create Robotomy Form");
    try {
        Intern intern;
        AForm* form;
        
        form = intern.makeForm("robotomy request", "Bender");
        
        if (form) {
            std::cout << *form << std::endl;
            
            Bureaucrat alice("Alice", 1);
            alice.signForm(*form);
            alice.executeForm(*form);
            
            delete form;
        }
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

void test_create_presidential() {
    separator("Test 3: Create Presidential Form");
    try {
        Intern intern;
        AForm* form;
        
        form = intern.makeForm("presidential pardon", "Arthur Dent");
        
        if (form) {
            std::cout << *form << std::endl;
            
            Bureaucrat president("President", 1);
            president.signForm(*form);
            president.executeForm(*form);
            
            delete form;
        }
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

void test_invalid_form() {
    separator("Test 4: Invalid Form Name");
    try {
        Intern intern;
        AForm* form;
        
        form = intern.makeForm("invalid form", "target");
        
        if (form) {
            std::cout << "This should not happen!" << std::endl;
            delete form;
        } else {
            std::cout << "Form creation failed as expected." << std::endl;
        }
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

void test_subject_example() {
    separator("Test 5: Subject Example");
    try {
        Intern someRandomIntern;
        AForm* rrf;
        
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        
        if (rrf) {
            std::cout << *rrf << std::endl;
            delete rrf;
        }
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

void test_all_forms() {
    separator("Test 6: Create All Forms");
    try {
        Intern intern;
        Bureaucrat god("God", 1);
        
        std::string formNames[3] = {
            "shrubbery creation",
            "robotomy request",
            "presidential pardon"
        };
        
        std::string targets[3] = {
            "home",
            "Marvin",
            "Zaphod"
        };
        
        for (int i = 0; i < 3; i++) {
            std::cout << "\n--- Creating form " << i + 1 << " ---" << std::endl;
            AForm* form = intern.makeForm(formNames[i], targets[i]);
            
            if (form) {
                std::cout << *form << std::endl;
                god.signForm(*form);
                god.executeForm(*form);
                delete form;
            }
        }
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

void test_multiple_interns() {
    separator("Test 7: Multiple Interns");
    try {
        Intern intern1;
        Intern intern2;
        Intern intern3;
        
        AForm* form1 = intern1.makeForm("shrubbery creation", "park");
        AForm* form2 = intern2.makeForm("robotomy request", "C-3PO");
        AForm* form3 = intern3.makeForm("presidential pardon", "Ford");
        
        Bureaucrat boss("Boss", 1);
        
        if (form1) {
            boss.signForm(*form1);
            boss.executeForm(*form1);
            delete form1;
        }
        
        if (form2) {
            boss.signForm(*form2);
            boss.executeForm(*form2);
            delete form2;
        }
        
        if (form3) {
            boss.signForm(*form3);
            boss.executeForm(*form3);
            delete form3;
        }
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

void test_case_sensitivity() {
    separator("Test 8: Case Sensitivity");
    try {
        Intern intern;
        
        std::cout << "Trying 'Robotomy Request' (capital letters):" << std::endl;
        AForm* form1 = intern.makeForm("Robotomy Request", "target");
        if (!form1) {
            std::cout << "Failed as expected (case sensitive)\n" << std::endl;
        }
        
        std::cout << "Trying 'robotomy request' (lowercase):" << std::endl;
        AForm* form2 = intern.makeForm("robotomy request", "target");
        if (form2) {
            std::cout << "Success!" << std::endl;
            delete form2;
        }
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

void test_memory_management() {
    separator("Test 9: Memory Management");
    try {
        Intern* intern = new Intern();
        AForm* form = intern->makeForm("presidential pardon", "Memory Test");
        
        if (form) {
            std::cout << "Form created successfully" << std::endl;
            std::cout << *form << std::endl;
            delete form;
        }
        
        delete intern;
        std::cout << "No memory leaks!" << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

void test_polymorphism() {
    separator("Test 10: Polymorphism");
    try {
        Intern intern;
        Bureaucrat supreme("Supreme", 1);
        
        AForm* forms[3];
        forms[0] = intern.makeForm("shrubbery creation", "forest");
        forms[1] = intern.makeForm("robotomy request", "Bender");
        forms[2] = intern.makeForm("presidential pardon", "Arthur");
        
        for (int i = 0; i < 3; i++) {
            if (forms[i]) {
                std::cout << "\nForm " << i + 1 << ":" << std::endl;
                std::cout << *forms[i] << std::endl;
                supreme.signForm(*forms[i]);
                supreme.executeForm(*forms[i]);
                delete forms[i];
            }
        }
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

int main() {
    std::cout << "╔════════════════════════════════════════╗" << std::endl;
    std::cout << "║      CPP05 - Ex03: Intern Tests       ║" << std::endl;
    std::cout << "╚════════════════════════════════════════╝" << std::endl;
    
    test_create_shrubbery();
    test_create_robotomy();
    test_create_presidential();
    test_invalid_form();
    test_subject_example();
    test_all_forms();
    test_multiple_interns();
    test_case_sensitivity();
    test_memory_management();
    test_polymorphism();
    
    std::cout << "\n╔════════════════════════════════════════╗" << std::endl;
    std::cout << "║         All Tests Complete!            ║" << std::endl;
    std::cout << "╚════════════════════════════════════════╝" << std::endl;
    
    return 0;
}
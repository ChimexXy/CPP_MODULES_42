#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

void separator(const std::string& title) {
    std::cout << "\n========================================" << std::endl;
    std::cout << title << std::endl;
    std::cout << "========================================\n" << std::endl;
}

void test_form_creation() {
    separator("Test 1: Valid Form Creation");
    try {
        Form form("Tax Form", 100, 50);
        std::cout << form << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

void test_form_invalid_grade_high() {
    separator("Test 2: Form Grade Too High");
    try {
        Form form("Invalid Form", 0, 50);
        std::cout << form << std::endl;
    } catch (Form::GradeTooHighException& e) {
        std::cout << "Caught: " << e.what() << std::endl;
    }
}

void test_form_invalid_grade_low() {
    separator("Test 3: Form Grade Too Low");
    try {
        Form form("Invalid Form", 100, 151);
        std::cout << form << std::endl;
    } catch (Form::GradeTooLowException& e) {
        std::cout << "Caught: " << e.what() << std::endl;
    }
}

void test_successful_signing() {
    separator("Test 4: Successful Form Signing");
    try {
        Bureaucrat bob("Bob", 50);
        Form form("Tax Form", 100, 50);
        
        std::cout << "Before signing:" << std::endl;
        std::cout << form << std::endl;
        
        bob.signForm(form);
        
        std::cout << "\nAfter signing:" << std::endl;
        std::cout << form << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

void test_failed_signing() {
    separator("Test 5: Failed Signing (Grade Too Low)");
    try {
        Bureaucrat intern("Intern", 150);
        Form form("Top Secret", 50, 25);
        
        std::cout << "Before signing attempt:" << std::endl;
        std::cout << intern << std::endl;
        std::cout << form << std::endl;
        std::cout << std::endl;
        
        intern.signForm(form);
        
        std::cout << "\nAfter signing attempt:" << std::endl;
        std::cout << form << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

void test_multiple_bureaucrats() {
    separator("Test 6: Multiple Bureaucrats, Same Form");
    try {
        Form form("Contract", 75, 50);
        Bureaucrat ceo("CEO", 1);
        Bureaucrat manager("Manager", 50);
        Bureaucrat intern("Intern", 100);
        
        std::cout << form << std::endl;
        std::cout << std::endl;
        
        ceo.signForm(form);
        std::cout << form << std::endl;
        std::cout << std::endl;
        
        manager.signForm(form);  // Already signed
        std::cout << std::endl;
        
        intern.signForm(form);   // Grade too low + already signed
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

void test_edge_grades() {
    separator("Test 7: Edge Case Grades");
    try {
        Form topSecret("Top Secret", 1, 1);
        Form publicDoc("Public Doc", 150, 150);
        
        Bureaucrat president("President", 1);
        Bureaucrat janitor("Janitor", 150);
        
        std::cout << "President signing top secret:" << std::endl;
        president.signForm(topSecret);
        std::cout << topSecret << std::endl;
        std::cout << std::endl;
        
        std::cout << "Janitor signing public doc:" << std::endl;
        janitor.signForm(publicDoc);
        std::cout << publicDoc << std::endl;
        std::cout << std::endl;
        
        std::cout << "Janitor trying to sign top secret:" << std::endl;
        janitor.signForm(topSecret);
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

void test_form_copy() {
    separator("Test 8: Form Copy Constructor");
    try {
        Form original("Original", 100, 50);
        Bureaucrat signer("Signer", 50);
        
        signer.signForm(original);
        std::cout << "Original: " << original << std::endl;
        
        Form copy(original);
        std::cout << "Copy: " << copy << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

void test_subject_example() {
    separator("Test 9: Subject Example");
    try {
        Bureaucrat bureaucrat("ash", 2);
        Form form("formA", 5, 3);
        
        std::cout << bureaucrat << std::endl;
        std::cout << form << std::endl;
        std::cout << std::endl;
        
        bureaucrat.signForm(form);
        std::cout << std::endl;
        std::cout << form << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

void test_grade_boundary() {
    separator("Test 10: Grade Boundary Testing");
    try {
        Form form("Boundary Form", 100, 50);
        
        Bureaucrat exact("Exact", 100);      // Exact match
        Bureaucrat better("Better", 99);     // Better (lower number)
        Bureaucrat worse("Worse", 101);      // Worse (higher number)
        
        std::cout << "Exact grade (100) signing form requiring 100:" << std::endl;
        exact.signForm(form);
        std::cout << std::endl;
        
        Form form2("Another Form", 100, 50);
        std::cout << "Better grade (99) signing form requiring 100:" << std::endl;
        better.signForm(form2);
        std::cout << std::endl;
        
        Form form3("Third Form", 100, 50);
        std::cout << "Worse grade (101) signing form requiring 100:" << std::endl;
        worse.signForm(form3);
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

int main() {
    std::cout << "╔════════════════════════════════════════╗" << std::endl;
    std::cout << "║     CPP05 - Ex01: Form Tests          ║" << std::endl;
    std::cout << "╚════════════════════════════════════════╝" << std::endl;
    
    test_form_creation();
    test_form_invalid_grade_high();
    test_form_invalid_grade_low();
    test_successful_signing();
    test_failed_signing();
    test_multiple_bureaucrats();
    test_edge_grades();
    test_form_copy();
    test_subject_example();
    test_grade_boundary();
    
    std::cout << "\n╔════════════════════════════════════════╗" << std::endl;
    std::cout << "║         All Tests Complete!            ║" << std::endl;
    std::cout << "╚════════════════════════════════════════╝" << std::endl;
    
    return 0;
}
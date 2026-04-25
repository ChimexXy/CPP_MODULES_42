#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <limits>
#include <cmath>
#include <cstdlib>

class ScalarConverter {
private:

// Helper methods
    static bool isChar(const std::string& str);
    static bool isInt(const std::string& str);
    static bool isFloat(const std::string& str);
    static bool isDouble(const std::string& str);
    static bool isPseudoLiterals(const std::string& str);
    
    static void convertFromChar(const std::string& str);
    static void convertFromInt(const std::string& str);
    static void convertFromFloat(const std::string& str);
    static void convertFromDouble(const std::string& str);
    static void convertPseudoLiterals(const std::string& str);
    
    public:
    // Private constructor - cannot be instantiated
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);
    ~ScalarConverter();
    
    // Public static method
    static void convert(const std::string& literal);
};

#endif
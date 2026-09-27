#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <cmath>

class ScalarConverter {
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);
    ~ScalarConverter();

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
    static void convert(const std::string& literal);
};

#endif
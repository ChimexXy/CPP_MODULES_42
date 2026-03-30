#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) { (void)other; }

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other){  (void)other; return *this; }

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string &str)
{
    if (isChar(str))
        convertFromChar(str);
    else if (isInt(str))
        convertFromInt(str);
    else if (isFloat(str))
        convertFromFloat(str);
    else if (isDouble(str))
        convertFromDouble(str);
    else if (isPseudoLiterals(str))
        convertPseudoLiterals(str);
    else
        std::cout << "Error: Invalid string format." << std::endl;
}

bool ScalarConverter::isChar(const std::string &str)
{
    if (str.empty())
        return false;

    else if (str.length() == 1 && !std::isdigit(str[0]))
        return true;

    return false;
}

bool ScalarConverter::isInt(const std::string &str)
{
    if (str.empty())
        return false;

    size_t start = 0;

    if (str[0] == '-' || str[0] == '+')
        start = 1;

    for (size_t i = start; i < str.length(); i++)
    {
        if (!std::isdigit(str[i]))
            return false;
    }

    return true;
}

bool ScalarConverter::isFloat(const std::string &str)
{
    if (str.empty())
        return false;

    size_t i = 0;
    int dot = 0;

    if (str[0] == '-' || str[0] == '+')
        i++;

    while (str[i])
    {
        if (str[i] == '.')
            dot++;
        else if (!std::isdigit(str[i]) && str[i] != 'f')
            return false;
        i++;
    }

    if (dot != 1  || str[i - 1] != 'f')
            return false;

    return true;
}

bool ScalarConverter::isDouble(const std::string &str)
{
    if (str.empty())
        return false;

    size_t i = 0;
    int dot = 0;

    if (str[i] == '-' || str[i] == '+')
        i++;

    while (str[i])
    {
        if (str[i] == '.')
            dot++;
        else if (!std::isdigit(str[i]))
            return false;
        i++;
    }

    if (dot != 1)
            return false;

    return true;
}

bool ScalarConverter::isPseudoLiterals(const std::string &str)
{
    if (str.empty())
        return false;

    if(str == "nan" || str == "nanf" ||
       str == "+inf" || str == "+inff" ||
       str == "-inf" || str == "-inff")
        return true;

    return false;
}

void ScalarConverter::convertFromChar(const std::string &str)
{
    char c = str[0];
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void ScalarConverter::convertFromInt(const std::string &str)
{
    int i = std::stoi(str);
    std::cout << "char: ";
    if (i >= 32 && i <= 126)
        std::cout << "'" << static_cast<char>(i) << "'";
    else
        std::cout << "No Printable Character";
    std::cout << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(i) << std::endl;
}

void ScalarConverter::convertFromFloat(const std::string &str)
{
    float f = std::stof(str);
    std::cout << "char: ";
    if (std::isnan(f) || std::isinf(f) || f < 32 || f > 126)
        std::cout << "No Printable Character";
    else
        std::cout << "'" << static_cast<char>(f) << "'";
    std::cout << std::endl;
    std::cout << "int: ";
    if (std::isnan(f) || std::isinf(f) || f < static_cast<float>(std::numeric_limits<int>::min()) || f > static_cast<float>(std::numeric_limits<int>::max()))
        std::cout << "impossible";
    else
        std::cout << static_cast<int>(f);
    std::cout << std::endl;
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void ScalarConverter::convertFromDouble(const std::string &str)
{
    double d = std::stod(str);
    std::cout << "char: ";
    if (std::isnan(d) || std::isinf(d) || d < 32 || d > 126)
        std::cout << "No Printable Character";
    else
        std::cout << "'" << static_cast<char>(d) << "'";
    std::cout << std::endl;
    std::cout << "int: ";
    if (std::isnan(d) || std::isinf(d) || d < static_cast<double>(std::numeric_limits<int>::min()) || d > static_cast<double>(std::numeric_limits<int>::max()))
        std::cout << "impossible";
    else
        std::cout << static_cast<int>(d);
    std::cout << std::endl;
    std::cout << "float: ";
    if (std::isnan(d) || std::isinf(d) || d < -std::numeric_limits<float>::max() || d > std::numeric_limits<float>::max())
        std::cout << "impossible";
    else
        std::cout << static_cast<float>(d) << "f";
    std::cout << std::endl;
    std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convertPseudoLiterals(const std::string &str)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    if (str == "nan" || str == "nanf")
    {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    else if (str == "+inf" || str == "+inff")
    {
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    }
    else if (str == "-inf" || str == "-inff")
    {
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
}


#ifndef RPN_HPP
# define RPN_HPP

# include <string>
#include <sstream>
#include <stack>
#include <stdexcept>

class RPN
{
private:
    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();

    static bool isOperator(const std::string& token);
    static bool isNumber(const std::string& token);
    static int  applyOperator(int left, int right, char op);

public:
    static int  calculate(const std::string& expression);
};

#endif
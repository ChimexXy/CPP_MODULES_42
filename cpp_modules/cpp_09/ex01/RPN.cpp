#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other) { (void)other; }

RPN& RPN::operator=(const RPN& other)
{
    (void)other;
    return (*this);
}

RPN::~RPN() {}

bool RPN::isOperator(const std::string& token)
{
    return (
        token.length() == 1
        && (token[0] == '+'
            || token[0] == '-'
            || token[0] == '*'
            || token[0] == '/')
    );
}

bool RPN::isNumber(const std::string& token)
{
    return (
        token.length() == 1
        && token[0] >= '0'
        && token[0] <= '9'
    );
}

int RPN::applyOperator(int left, int right, char op)
{
    if (op == '+')
        return (left + right);
    if (op == '-')
        return (left - right);
    if (op == '*')
        return (left * right);
    if (op == '/')
    {
        if (right == 0)
            throw std::runtime_error("Error");
        return (left / right);
    }
    throw std::runtime_error("Error");
}

int RPN::calculate(const std::string& expression)
{
    std::stringstream ss(expression);
    std::stack<int> stack;
    std::string token;

    while (ss >> token)
    {
        if (isNumber(token))
            stack.push(token[0] - '0');
        else if (isOperator(token))
        {
            int right;
            int left;
            int result;

            if (stack.size() < 2)
                throw std::runtime_error("Error");
            right = stack.top();
            stack.pop();
            left = stack.top();
            stack.pop();
            result = applyOperator(left, right, token[0]);
            stack.push(result);
        }
        else
            throw std::runtime_error("Error");
    }
    if (stack.size() != 1)
        throw std::runtime_error("Error");
    return (stack.top());
}
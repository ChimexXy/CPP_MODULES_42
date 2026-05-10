#include "Span.hpp"

Span::Span() : N(0) {}
Span::Span(unsigned int Nb){ N = Nb; }
// Span::Span(Span& oth) { *this = oth; }
Span::~Span() {}

void Span::addNumber(long num)
{
    if (num >= INT_MAX || num <= INT_MIN)
        throw std::runtime_error("Number is out of range for int type");
    std::vector<int>::iterator it = std::find(vec.begin(), vec.end(), num);
    if (vec.size() >= N || it != vec.end())
        throw std::runtime_error("Span is full or number already exists");
    vec.push_back(num);
}
int Span::shortestSpan()
{
    if (vec.size() < 2)
        throw std::out_of_range("Not enough numbers to find a span");

    std::vector<int> tmpVec = vec;
    std::sort(tmpVec.begin(), tmpVec.end());
    int min;

    for (size_t i = 0; i < tmpVec.size(); i++)
    {
        if (i == 0)
            min = tmpVec[i + 1] - tmpVec[i];
        else if (tmpVec[i] - tmpVec[i - 1] < min)
            min = tmpVec[i] - tmpVec[i - 1];
    }

    return min;
}
int Span::longestSpan() 
{
    if (vec.size() < 2)
        throw std::out_of_range("Not enough numbers to find a span");

    std::vector<int> tmpVec = vec;
    std::sort(tmpVec.begin(), tmpVec.end());
    size_t i = tmpVec.size() - 1;
    int max = tmpVec[i] - tmpVec[0];

    return max;
}
#include "Span.hpp"

Span::Span() : N(0) {}
Span::Span(unsigned int Nb){ N = Nb; }
Span::Span(const Span& other) : N(other.N), vec(other.vec) {}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        this->N = other.N;
        this->vec = other.vec;
    }
    return *this;
}
Span::~Span() {}

void Span::addNumber(unsigned int num)
{
    if (vec.size() >= N)
        throw std::runtime_error("Span is full");
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

    int min = *std::min_element(vec.begin(), vec.end());
    int max = *std::max_element(vec.begin(), vec.end());

    return max - min;
}
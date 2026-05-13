#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <exception>
#include <limits>

class Span
{
private:
    unsigned int N;
    std::vector<int> vec;

public:
    Span();
    Span(unsigned int N);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    template <typename It>
    void addRange(It begin, It end)
    {
        if (std::distance(begin, end) + vec.size() > N)
            throw std::runtime_error("Adding this range would exceed the capacity of the Span");
        vec.insert(vec.end(), begin, end);
    }

    void addNumber(int num);
    int shortestSpan();   
    int longestSpan();

};

#endif
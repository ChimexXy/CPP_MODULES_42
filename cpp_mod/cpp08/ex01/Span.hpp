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
    // Span(Span& oth);
    ~Span();

    void addNumber(long num);
    int shortestSpan();   
    int longestSpan();


};

#endif
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
    Span(const Span& other); // Copy constructor
    Span& operator=(const Span& other); // Assignment operator
    ~Span();

    Span(unsigned int N);
    void addNumber(unsigned int num);
    int shortestSpan();   
    int longestSpan();

};

#endif
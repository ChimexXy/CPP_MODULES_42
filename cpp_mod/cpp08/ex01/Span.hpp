#ifndef SPAN_HPP
#define SPAN_HPP

class Span
{
private:
    unsigned int N;
public:
    Span();
    Span(unsigned int N);
    Span(Span& oth);
    ~Span();

    void addNumber();
    void shortestSpan();   
    void longestSpan();
};

#endif
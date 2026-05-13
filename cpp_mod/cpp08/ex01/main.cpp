#include "Span.hpp"

int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(21);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;    
    std::cout << sp.longestSpan() << std::endl;

    // Span sp(10);
    // std::vector<int> values = {1, 2, 3, 4, 5};
    // sp.addRange(values.begin(), values.end());

    // std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    // std::cout << "Longest span: " << sp.longestSpan() << std::endl;

    // try
    // {
    //     std::vector<int> more = {6, 7, 8, 9, 10, 11};
    //     sp.addRange(more.begin(), more.end());
    // } catch (const std::exception& e)
    // {
    //     std::cout << "Exception caught: " << e.what() << std::endl;
    // }

    return 0;
}
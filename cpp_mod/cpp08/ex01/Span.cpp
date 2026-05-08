#include "Span.hpp"

Span::Span() : N(0) {}
Span::Span(unsigned int Nb){ N = Nb; }
Span::Span(Span& oth) { *this = oth; }
Span::~Span() {}

void Span::addNumber(){}
void Span::shortestSpan(){}
void Span::longestSpan() {}
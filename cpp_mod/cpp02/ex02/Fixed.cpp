#include "Fixed.hpp"

// Constructors
Fixed::Fixed() : _rawBits(0) {}

Fixed::Fixed(const int n) {
    _rawBits = n << _fractionalBits;
}

Fixed::Fixed(const float f) {
    _rawBits = roundf(f * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed& other) {
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other)
        _rawBits = other._rawBits;
    return *this;
}

Fixed::~Fixed() {}

// Conversions
float Fixed::toFloat() const {
    return (float)_rawBits / (1 << _fractionalBits);
}

int Fixed::toInt() const {
    return _rawBits >> _fractionalBits;
}

// Comparison
bool Fixed::operator>(const Fixed& o) const { return _rawBits > o._rawBits; }
bool Fixed::operator<(const Fixed& o) const { return _rawBits < o._rawBits; }
bool Fixed::operator>=(const Fixed& o) const { return _rawBits >= o._rawBits; }
bool Fixed::operator<=(const Fixed& o) const { return _rawBits <= o._rawBits; }
bool Fixed::operator==(const Fixed& o) const { return _rawBits == o._rawBits; }
bool Fixed::operator!=(const Fixed& o) const { return _rawBits != o._rawBits; }

// Arithmetic
Fixed Fixed::operator+(const Fixed& o) const {
    return Fixed(this->toFloat() + o.toFloat());
}

Fixed Fixed::operator-(const Fixed& o) const {
    return Fixed(this->toFloat() - o.toFloat());
}

Fixed Fixed::operator*(const Fixed& o) const {
    return Fixed(this->toFloat() * o.toFloat());
}

Fixed Fixed::operator/(const Fixed& o) const {
    return Fixed(this->toFloat() / o.toFloat());
}

// Increment / Decrement
Fixed& Fixed::operator++() {
    _rawBits++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed tmp(*this);
    _rawBits++;
    return tmp;
}

Fixed& Fixed::operator--() {
    _rawBits--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed tmp(*this);
    _rawBits--;
    return tmp;
}

// Min / Max
Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b ? a : b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b ? a : b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b ? a : b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b ? a : b);
}

// <<
std::ostream& operator<<(std::ostream& os, const Fixed& f) {
    os << f.toFloat();
    return os;
}

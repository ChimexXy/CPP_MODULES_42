#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n) {
    std::cout << "Int constructor called" << std::endl;
    _value = n << _fractionalBits;
}

Fixed::Fixed(const float n) {
    std::cout << "Float constructor called" << std::endl;
    _value = roundf(n * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        _value = other.getRawBits();
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    return _value;
}

void Fixed::setRawBits(int const raw) {
    _value = raw;
}

float Fixed::toFloat(void) const {
    return (float)_value / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
    return _value >> _fractionalBits;
}

std::ostream& operator<<(std::ostream& out, const Fixed& f) {
    out << f.toFloat();
    return out;
}

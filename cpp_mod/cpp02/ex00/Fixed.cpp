#include "Fixed.hpp"

// Default constructor
Fixed::Fixed() : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

// Copy constructor
Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    this->_value = other.getRawBits();
}

// Copy assignment operator
Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_value = other.getRawBits();
    return *this;
}

// Destructor
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

// Getter
int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_value;
}

// Setter
void Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
    int _value;
    static const int _bits = 8;

public:
    Fixed();                    // default constructor
    Fixed(const Fixed &other);  // copy constructor
    Fixed &operator=(const Fixed &other); // assignment
    ~Fixed();                   // destructor

    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif
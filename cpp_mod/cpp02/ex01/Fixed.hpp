#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int                 _value;
    static const int    _fractionalBits = 8;

public:
    // Orthodox Canonical Form
    Fixed();
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);
    ~Fixed();

    // New constructors
    Fixed(const int n);
    Fixed(const float n);

    // Getters / setters
    int     getRawBits(void) const;
    void    setRawBits(int const raw);

    // Conversions
    float   toFloat(void) const;
    int     toInt(void) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& f);

#endif

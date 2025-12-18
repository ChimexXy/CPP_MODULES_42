#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed{
private:
	int _rawbits;
	static const int _frabits = 8;

public:
	Fixed();
	Fixed(const Fixed &other);
	Fixed& operator=(const Fixed &othre);
	~Fixed();

	int getRawBits( void ) const;
	void setRawBits( int const raw );

};


#endif
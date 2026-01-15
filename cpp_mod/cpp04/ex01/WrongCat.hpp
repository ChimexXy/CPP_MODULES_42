#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <iostream>

class WrongCat : public WrongAnimal
{
protected:
	std::string type;
public:
	WrongCat();
	WrongCat(const WrongCat& org);
	WrongCat &operator=(const WrongCat& org);
	~WrongCat();

	void MakeSound() const;
};

#endif
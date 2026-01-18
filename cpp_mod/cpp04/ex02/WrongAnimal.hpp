#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
protected:
	std::string type;
public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal& org);
	WrongAnimal &operator=(const WrongAnimal& org);
	~WrongAnimal();

	void MakeSound() const;
};

#endif
#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    _name = "Default";
    _hp = 10;
    _ep = 10;
    _ad = 0;
    std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
    _name = name;
    _hp = 10;
    _ep = 10;
    _ad = 0;
    std::cout << "Constructor called"<< std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    *this = other;
    std::cout << "Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if (this != &other)
    {
        _name = other._name;
        _hp = other._hp;
        _ep = other._ep;
        _ad = other._ad;
    }
    std::cout << "Assignment operator called" << std::endl;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (_hp <= 0 || _ep <= 0)
    {
        std::cout << "ClapTrap " << _name << " No Hit point or No Energy Point" << std::endl;
        return;
    }
    _ep--;
    std::cout << "ClapTrap " << _name << " attacks " << target
              << ", causing " << _ad << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    _hp -= amount;
    if (_hp < 0)
        _hp = 0;

    std::cout << "ClapTrap " << _name << " takes " << amount << " damage" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_ep <= 0 || _hp <= 0)
	{
		std::cout << "ClapTrap " << _name << " No Hit point or No Energy Point" << std::endl;
        return;
	}
    _ep--;
    _hp += amount;
    std::cout << "ClapTrap " << _name << " repairs self  " << amount << " HP" << std::endl;
}

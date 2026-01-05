#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("FragTrap")
{
    _hp = 100;
    _ep = 100;
    _ad = 30;
    std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    _hp = 100;
    _ep = 100;
    _ad = 30;
    std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    *this = other;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    if (this != &other)
        ClapTrap::operator=(other);
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destroyed" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
    if (_hp <= 0 || _ep <= 0)
	{
		std::cout << "FragTrap " << _name << " No Hit point or No Energy Point" << std::endl;
        return;
	}

    _ep--;
    std::cout << "FragTrap " << _name << " attacks " << target
              << ", causing " << _ad << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << _name
              << " requests a high five" << std::endl;
}

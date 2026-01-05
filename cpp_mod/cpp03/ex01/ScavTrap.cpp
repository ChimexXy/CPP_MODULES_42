#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("ScavTrap")
{
    _hp = 100;
    _ep = 50;
    _ad = 20;
    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    _hp = 100;
    _ep = 50;
    _ad = 20;
    std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    *this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destroyed" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (_hp <= 0 || _ep <= 0)
	{
		std::cout << "ScavTrap " << _name << " No Hit point or No Energy Point" << std::endl;
        return;
	}
    _ep--;
    std::cout << "ScavTrap " << _name << " attacks " << target
              << ", causing " << _ad << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode" << std::endl;
}

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    _name = "Default";
    _hitPoints = 10;
    _energyPoints = 10;
    _attackDamage = 0;
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
    _name = name;
    _hitPoints = 10;
    _energyPoints = 10;
    _attackDamage = 0;
    std::cout << "ClapTrap constructor called for " << _name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    *this = other;
    std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if (this != &other)
    {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    std::cout << "ClapTrap assignment operator called" << std::endl;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called for " << _name << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (_hitPoints <= 0)
    {
        std::cout << "ClapTrap " << _name << " is dead" << std::endl;
        return;
    }
    if (_energyPoints <= 0)
    {
        std::cout << "ClapTrap " << _name << " has no energy" << std::endl;
        return;
    }
    _energyPoints--;

    std::cout << "ClapTrap " << _name
              << " attacks " << target
              << ", causing " << _attackDamage
              << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    _hitPoints -= amount;
    if (_hitPoints < 0)
        _hitPoints = 0;

    std::cout << "ClapTrap " << _name
              << " takes " << amount
              << " damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_energyPoints <= 0 || _hitPoints <= 0)
        return;

    _energyPoints--;
    _hitPoints += amount;

    std::cout << "ClapTrap " << _name
              << " repairs itself for "
              << amount << " hit points!" << std::endl;
}

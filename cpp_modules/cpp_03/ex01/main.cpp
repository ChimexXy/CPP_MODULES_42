#include "ScavTrap.hpp"

int main()
{
    ClapTrap a("Clap");
    ScavTrap b("Scav");

    a.attack("enemy");
    b.attack("enemy");
    b.guardGate();

    return 0;
}
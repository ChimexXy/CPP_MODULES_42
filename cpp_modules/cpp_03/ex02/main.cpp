#include "FragTrap.hpp"

int main()
{
    ClapTrap a("Clap");
    ScavTrap b("Scav");
    FragTrap c("Frag");

    a.attack("enemy");
    b.attack("enemy");
    b.guardGate();

    c.attack("enemy");
    c.highFivesGuys();

    return 0;
}

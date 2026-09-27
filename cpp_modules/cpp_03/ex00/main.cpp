#include "ClapTrap.hpp"

int main()
{
    ClapTrap a("A");
    ClapTrap b("B");

    a.attack("B");
    b.takeDamage(0);

    b.beRepaired(5);
    b.attack("A");

    return 0;
}

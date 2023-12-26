#include"ScavTrap.hpp"

int main()
{
    ScavTrap a("a"), b("b");

    a.attack("b");
    b.takeDamage(a.getAttackDamage());
    b.beRepaired(3);
}
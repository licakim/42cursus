#include"ClapTrap.hpp"
#include"iomanip"

int main()
{
    ClapTrap a("a"), b("b");

    a.attack("b");
    b.takeDamage(a.getAttackDamage());
    b.beRepaired(3);
}
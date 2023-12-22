#include "Zombie.hpp"

int main()
{
	Zombie *zombie = newZombie("hehe");
	zombie->announce();
	delete zombie;
	randomChump("haha");
	return 0;
}
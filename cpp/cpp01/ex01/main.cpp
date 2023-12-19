#include "Zombie.hpp"

int main()
{
	Zombie *zombies = zombieHorde(10, "haha");
	for(int i =0; i<10;i++)
		zombies[i].announce();
	delete[] zombies;
}
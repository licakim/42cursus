#ifndef Zombie_HPP
#define Zombie_HPP
#include<iostream>

class Zombie{
private:
	std::string name;
public:
	Zombie();
	Zombie(std::string name);
	void announce(void);
	~Zombie();
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif
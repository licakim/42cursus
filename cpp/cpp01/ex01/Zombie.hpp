#ifndef Zombie_HPP
#define Zombie_HPP

#include<iostream>

class Zombie{
private:
	std::string name;
public:
	Zombie();
	void announce(void);
	void setName(std::string name);
	~Zombie();
};

Zombie* zombieHorde( int N, std::string name);

#endif
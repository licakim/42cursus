#include "Zombie.hpp"

void Zombie::announce()
{
	std::cout<<name<<": BraiiiiiiinnnzzzZ..."<<std::endl;
}

Zombie::Zombie(std::string name)
{
	this->name = name;
	this->announce();
}

Zombie::~Zombie()
{
	std::cout<<this->name << " died"<<std::endl;
}



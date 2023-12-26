#include"ScavTrap.hpp"

ScavTrap::ScavTrap() :ClapTrap()
{
    this-> hitPoints = 100;
    this-> energyPoints = 50;
    this-> attackDamage = 20;
    std::cout<<"Scaptrap default constructor called\n";
};

ScavTrap::ScavTrap(std::string name) :ClapTrap(name)
{
    this->name = name;
    this->hitPoints = 100;
    this-> energyPoints = 50;
    this-> attackDamage = 20;
    std::cout<<"Scaptrap string constructor called\n";
};

ScavTrap::ScavTrap(const ScavTrap& obj) : ClapTrap(obj)
{
    std::cout << name << " ScavTrap copy constructor called\n";
}


ScavTrap::~ScavTrap(){
    std::cout << "ScavTrap " << this->name << " destructor called\n";    
};

void ScavTrap::attack(const std::string& target)
{
    if(this->hitPoints == 0 || this->energyPoints == 0)
        return;
        std::cout<<"ScavTrap "<<this->name<<" attacks "<<target<<", causing "<<this->attackDamage<<" points of damage!\n";
    this->hitPoints--;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& obj)
{
    if(this != &obj)
    {
        this -> name =obj.name;
        this->hitPoints = obj.hitPoints;
        this->energyPoints = obj.energyPoints;
        this->attackDamage = obj.attackDamage;
    }
    return *this;
}


void ScavTrap::guardGate()
{
    std::cout<<"ScavTrap "<< this->name <<"is now in Gate keeper mode\n";
}
#include"ClapTrap.hpp"

ClapTrap::ClapTrap(): hitPoints(10), energyPoints(10), attackDamage(0){
    std::cout<<"Default constructor called\n";
}

ClapTrap::ClapTrap(std::string name): name(name),hitPoints(10), energyPoints(10), attackDamage(0){
    std::cout<<"String constructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap& obj)
{
    std::cout<<"Copy constructor called\n";
    *this = obj;
}

ClapTrap::~ClapTrap(){
    std::cout<<"Destructor called\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap &obj)
  {
    if(this != &obj)
    {
        this->hitPoints = obj.hitPoints;
        this->energyPoints = obj.energyPoints;
        this->attackDamage = obj.attackDamage;
    }
    return *this;
  }

  unsigned int ClapTrap::getHitPoints() const
  {
    return this->hitPoints;
  }
unsigned int ClapTrap::getEnergyPoints() const
        {
            return this->energyPoints;
        }
        unsigned int ClapTrap::getAttackDamage() const
        {
            return this->attackDamage;
        }


void ClapTrap::takeDamage(unsigned int amount)
{
    this->hitPoints -= amount;
     std::cout<<"ClapTrap "<<this->name <<" hit points are reduced to "<<this->hitPoints<<", taking "<<amount<<" points of damage!\n";
}

void ClapTrap::attack(const std::string& target)
{
    if(this->hitPoints <= 0 || this->energyPoints <=0)
        return;
    this->energyPoints--;
    std::cout<<"ClapTrap "<<this->name<<" attacks "<<target<<", causing "<<this->attackDamage<<" points of damage!\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if(this->hitPoints <= 0 || this->energyPoints <=0)
        return;   
    this->hitPoints += amount;
    this->energyPoints--;
    std::cout<<"ClapTrap "<<this->name<<" hit points increase to "<<this->hitPoints<< " as it repairs "<<amount<<" points!\n";
}
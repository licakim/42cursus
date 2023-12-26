#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
 public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap(const FragTrap& obj);
        ~FragTrap();
        FragTrap& operator=(const FragTrap& obj);
        void attack(const std::string& target);
        void highFiveGuys(void);
};
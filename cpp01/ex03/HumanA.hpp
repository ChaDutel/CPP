#ifndef HUMANA_HPP
# define HUMANA_HPP
// # include <iostream>
// # include <iomanip>
// # include <string>
# include "Weapon.hpp"

class    HumanA
{
    public:
        HumanA(std::string name, Weapon &weaponType);
        ~HumanA();

        Weapon          &weapon;
        void            attack();
        std::string     getName() const;
        void            setName(std::string name);
        //<name> attacks with their <weapon type>

    private:
        std::string    _name;
        
};


#endif

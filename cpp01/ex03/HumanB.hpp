#ifndef HUMANB_HPP
# define HUMANB_HPP
// # include <iostream>
// # include <iomanip>
// # include <string>
# include "Weapon.hpp"

class    HumanB
{
    public:
        HumanB(std::string name);
        ~HumanB();

        Weapon          weapon;
        void            setWeapon(Weapon weapon);
        void            attack();
        std::string     getName();
        void            setName(std::string name);
        //<name> attacks with their <weapon type>

    private:
        std::string    _name;
        
};


#endif

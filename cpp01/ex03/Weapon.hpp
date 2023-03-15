#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <iostream>
# include <iomanip>
# include <string>
// # include "HumanA.hpp"

class Weapon
{
    public:
        Weapon(std::string nameType);
        ~Weapon();

        // const std::string        getType();
        const std::string&        getType() const;
        void                    setType(std::string newType);
        // • Une fonction membre getType() retournant une référence constante sur type.
    // • Une fonction membre setType() qui attribue à type la nouvelle valeur passée en
    // paramètre.

    private:
        std::string type;
};

#endif

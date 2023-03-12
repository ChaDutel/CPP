#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <iostream>
# include <string>
# include "Contact.hpp"

class PhoneBook
{
    public:
        Contact  listContact[8];
        PhoneBook();
        ~PhoneBook();

    private:
};

#endif

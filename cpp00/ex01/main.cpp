/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:46:34 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/03/12 18:10:38 by cdutel-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

int main()
{
    std::string  test;
    Contact         newContact;
    PhoneBook       phoneContacts;
    int          i;

    std::cout << "Enter a command like : ADD, SEARCH, EXIT\n";
    std::getline(std::cin, test);
    i = 0;
    while (!std::cin.eof())
    {
        if (test == "EXIT")
            break;
        else if (test == "ADD")
        {
            phoneContacts.addInformations(&phoneContacts.listContact[i]);
            i++;
            if (i > 7)
                i = 0;
        }
        else if (test == "SEARCH")
		{
			phoneContacts.showMiniList(phoneContacts);
            std::cout << "Enter an index of contact between 0 and 7\n";
   			std::getline(std::cin, test);
			while (!std::cin.eof() && (test.size() != 1 || test[0] < '0' || test[0] > '7'))
			{
				std::cout << "Error : Enter a valid index\n";
   				std::getline(std::cin, test);
			}
			if (std::cin.eof())
				return (0);
			phoneContacts.searchInformation(phoneContacts.listContact[test[0] - 48]);
		}
        std::cout << "Enter a command like : ADD, SEARCH, EXIT\n";
        std::getline(std::cin, test);
    }
	return (0);
}

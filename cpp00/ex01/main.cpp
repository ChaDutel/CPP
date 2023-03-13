/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:46:34 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/03/13 14:31:45 by cdutel-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

int main()
{
	std::string		info;
	Contact			newContact;
	PhoneBook		phoneContacts;
	int				i;

	std::cout << "Enter a command like : ADD, SEARCH, EXIT\n";
	std::getline(std::cin, info);
	i = 0;
	while (!std::cin.eof())
	{
		if (info == "EXIT")
			break;
		else if (info == "ADD")
		{
			phoneContacts.addInformations(&phoneContacts.listContact[i]);
			i++;
			if (i > 7)
				i = 0;
		}
		else if (info == "SEARCH")
		{
			phoneContacts.showMiniList(phoneContacts);
			std::cout << "Enter an index of contact between 0 and 7\n";
			std::getline(std::cin, info);
			while (!std::cin.eof() && (info.size() != 1 || info[0] < '0' || info[0] > '7'))
			{
				std::cout << "Error : Enter a valid index\n";
				std::getline(std::cin, info);
			}
			if (std::cin.eof())
				return (0);
			phoneContacts.searchInformation(phoneContacts.listContact[info[0] - 48]);
		}
		std::cout << "Enter a command like : ADD, SEARCH, EXIT\n";
		std::getline(std::cin, info);
	}
	return (0);
}

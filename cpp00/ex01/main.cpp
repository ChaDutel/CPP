/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:46:34 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/03/12 15:35:06 by cdutel-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

// void	addSeparator(std::string info)
// {
// 	int	size;

// 	size = info.size();
// 	if (size > 10)
// 		size = 10;
// 	size -= 1;
// 	for (int i = 0; info[i]; i++)
// 	{
// 		std::cout << info[i];
// 		if (i != size)
// 			std::cout << " | ";
// 	}
// 	std::cout << std::endl;
// }

// void	searchInformation(Contact choosingContact)
// {
//     std::cout << "First name : ";
// 	addSeparator(choosingContact.getFirstName());
// 	std::cout << "Last name : ";
// 	addSeparator(choosingContact.getLastName());
// 	std::cout << "Nickname : ";
// 	addSeparator(choosingContact.getNickName());
// 	std::cout << "Phone number: ";
// 	addSeparator(choosingContact.getPhoneNb());
// 	std::cout << "Darkest secret: ";
// 	addSeparator(choosingContact.getDarkestSecret());
// }

std::string	checkSizeInfo(std::string info)
{
	if (info.size() <= 10)
		return (info);
	else
	{
		info[9] = '.';
		for (int i = 10; info[i]; i++)
			info[i] = '\0';
		return (info);
	}
}

// // void	addSpaceAndPipe(Contact choosingContact)
// {
// 	for (int i = choosingContact.size; i <= 10; i++)
// 		std::cout << " ";
// 	std::cout << '|';
// }
void	addSpaceAndPipe(std::string info)
{
	for (int i = info.size(); i < 10; i++)
		std::cout << " ";
	std::cout << '|';
}

void	searchInformation(Contact choosingContact)
{
    std::cout << "First name : " << choosingContact.getFirstName() << std::endl;
	std::cout << "Last name : " << choosingContact.getLastName() << std::endl;
	std::cout << "Nickname : " << choosingContact.getNickName() << std::endl;
	std::cout << "Phone number: " << choosingContact.getPhoneNb() << std::endl;
	std::cout << "Darkest secret: " << choosingContact.getDarkestSecret() << std::endl;
}


void	showMiniList(PhoneBook contacts)
{
	for (int i = 0; i < 8; i++)
	{
		std::cout << "[" << i << "]|" << checkSizeInfo(contacts.listContact[i].getFirstName());
		addSpaceAndPipe(contacts.listContact[i].getFirstName());
		std::cout << checkSizeInfo(contacts.listContact[i].getLastName());
		addSpaceAndPipe(contacts.listContact[i].getLastName());
		std::cout << checkSizeInfo(contacts.listContact[i].getNickName()) << std::endl;
	}
}

int	checkValidCharacter(std::string info)
{
	for (int i = 0; info[i]; i++)
	{
		if (info[i] > 32 && info[i] <= 126)
			return (0);
	}
	return (-1);
}

std::string	checkValidInfo(std::string info, std::string typeOfInfo)
{
	while (info.empty() == true || checkValidCharacter(info) == -1)
	{
		std::cout << "Error : Enter a valid information" << std::endl;
		std::cout << typeOfInfo;
		std::getline(std::cin, info);
	}
	return (info);
}

void    addInformations(Contact *newContact)
{
    std::string info;

    std::cout << "Enter a first name: ";
    std::getline(std::cin, info);
	info = checkValidInfo(info, "Enter a first name: ");
	// info = checkSizeInfo(info);
    newContact->setFirstName(info);
    std::cout << newContact->getFirstName() << std::endl;

    std::cout << "Enter a last name: ";
    std::getline(std::cin, info);
	info = checkValidInfo(info, "Enter a last name: ");
	// info = checkSizeInfo(info);
    newContact->setLastName(info);
    std::cout << newContact->getLastName() << std::endl;

    std::cout << "Enter a nickname: ";
    std::getline(std::cin, info);
	info = checkValidInfo(info, "Enter a nickname: ");
	// info = checkSizeInfo(info);
    newContact->setNickName(info);
    std::cout << newContact->getNickName() << std::endl;

    std::cout << "Enter a phone number: ";
    std::getline(std::cin, info);
	info = checkValidInfo(info, "Enter a phone number: ");
	// info = checkSizeInfo(info);
    newContact->setPhoneNb(info);
    std::cout << newContact->getPhoneNb() << std::endl;

    std::cout << "Enter a darkest secret: ";
    std::getline(std::cin, info);
    info = checkValidInfo(info, "Enter a darkest secret: ");
	// info = checkSizeInfo(info);
    newContact->setDarkestSecret(info);
    std::cout << newContact->getDarkestSecret() << std::endl;
}

// void    checkNbContacts(PhoneBook phoneContact, int i)
// {
//     //if (phoneContact.listContact[i].getFirstName() == "")
//       addInformations(phoneContact.listContact[i]);
// }

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
            addInformations(&phoneContacts.listContact[i]);
            i++;
            if (i > 8)
                i = 0;
        }
        else if (test == "SEARCH")
		{
			showMiniList(phoneContacts);
            std::cout << "Enter an index of contact between 0 and 7\n";
   			std::getline(std::cin, test);
			while (std::stoi(test) < 0 && std::stoi(test) > 7)
   				std::getline(std::cin, test);
			searchInformation(phoneContacts.listContact[std::stoi(test)]);
		}
        std::cout << "Enter a command like : ADD, SEARCH, EXIT\n";
        std::getline(std::cin, test);
    }
}
// int main()
// {
// 	std::string  test;
// 	Contact     contactTest;

// 	std::cin >> test;
// 	while (test != "EXIT")
// 	{
// 		if (test == "ADD")
// 			add_informations(contactTest);
// 		else if (test == "SEARCH")
// 		std::cin >> test;
// 	}
// }

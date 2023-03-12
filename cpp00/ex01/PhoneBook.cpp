/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 12:11:40 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/03/12 18:13:39 by cdutel-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/// BUILDERS ///

PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{
}


/// DISPLAY SEARCH ///

std::string	PhoneBook::checkSizeInfo(std::string info)
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

void	PhoneBook::addSpaceAndPipe(std::string info)
{
	for (int i = info.size(); i < 10; i++)
		std::cout << " ";
	std::cout << '|';
}

void	PhoneBook::searchInformation(Contact choosingContact)
{
	std::cout << std::endl;
    std::cout << "First name : " << choosingContact.getFirstName() << std::endl;
	std::cout << "Last name : " << choosingContact.getLastName() << std::endl;
	std::cout << "Nickname : " << choosingContact.getNickName() << std::endl;
	std::cout << "Phone number: " << choosingContact.getPhoneNb() << std::endl;
	std::cout << "Darkest secret: " << choosingContact.getDarkestSecret() << std::endl;
	std::cout << std::endl;
}

void	PhoneBook::showMiniList(PhoneBook contacts)
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


/// ADD ///

int	PhoneBook::checkValidCharacter(std::string info)
{
	for (int i = 0; info[i]; i++)
	{
		if (info[i] > 32 && info[i] <= 126)
			return (0);
	}
	return (-1);
}

std::string	PhoneBook::checkValidInfo(std::string info, std::string typeOfInfo)
{
	while (info.empty() == true || checkValidCharacter(info) == -1)
	{
		std::cout << "Error : Enter a valid information" << std::endl;
		std::cout << typeOfInfo;
		std::getline(std::cin, info);
	}
	return (info);
}

void    PhoneBook::addInformations(Contact *newContact)
{
    std::string info;

	std::cout << std::endl;
    std::cout << "Enter a first name: ";
    std::getline(std::cin, info);
	info = checkValidInfo(info, "Enter a first name: ");
    newContact->setFirstName(info);

    std::cout << "Enter a last name: ";
    std::getline(std::cin, info);
	info = checkValidInfo(info, "Enter a last name: ");
    newContact->setLastName(info);

    std::cout << "Enter a nickname: ";
    std::getline(std::cin, info);
	info = checkValidInfo(info, "Enter a nickname: ");
    newContact->setNickName(info);

    std::cout << "Enter a phone number: ";
    std::getline(std::cin, info);
	info = checkValidInfo(info, "Enter a phone number: ");
    newContact->setPhoneNb(info);

    std::cout << "Enter a darkest secret: ";
    std::getline(std::cin, info);
    info = checkValidInfo(info, "Enter a darkest secret: ");
    newContact->setDarkestSecret(info);
	std::cout << std::endl;
}

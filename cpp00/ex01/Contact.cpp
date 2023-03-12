/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 12:12:06 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/03/12 12:12:09 by cdutel-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "Contact.hpp"

/// BUILDERS ///

Contact::Contact()	:	firstName(""), lastName(""), nickName(""), phoneNumber(""), darkestSecret("")
{
}

Contact::~Contact()
{
}

/// SET_INFO_CONTACT ///

void	Contact::setFirstName(std::string firstName)
{
	this->firstName = firstName;
}

void	Contact::setLastName(std::string lastName)
{
	this->lastName = lastName;
}

void	Contact::setNickName(std::string nickName)
{
	this->nickName = nickName;
}

void	Contact::setPhoneNb(std::string phoneNb)
{
	this->phoneNumber = phoneNb;
}

void	Contact::setDarkestSecret(std::string darkSecret)
{
	this->darkestSecret = darkSecret;
}


/// GET_INFO_CONTACT ///

std::string	Contact::getFirstName(void) const
{
	return (this->firstName);
}

std::string	Contact::getLastName(void) const
{
	return (this->lastName);
}

std::string	Contact::getNickName(void) const
{
	return (this->nickName);
}

std::string	Contact::getPhoneNb(void) const
{
	return (this->phoneNumber);
}

std::string	Contact::getDarkestSecret(void) const
{
	return (this->darkestSecret);
}

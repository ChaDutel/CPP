/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 12:12:06 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/03/13 14:25:40 by cdutel-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "Contact.hpp"

/// BUILDERS ///

Contact::Contact()	:	_firstName(""), _lastName(""), _nickName(""), _phoneNumber(""), _darkestSecret("")
{
}

Contact::~Contact()
{
}

/// SET_INFO_CONTACT ///

void	Contact::setFirstName(std::string firstName)
{
	this->_firstName = firstName;
}

void	Contact::setLastName(std::string lastName)
{
	this->_lastName = lastName;
}

void	Contact::setNickName(std::string nickName)
{
	this->_nickName = nickName;
}

void	Contact::setPhoneNb(std::string phoneNb)
{
	this->_phoneNumber = phoneNb;
}

void	Contact::setDarkestSecret(std::string darkSecret)
{
	this->_darkestSecret = darkSecret;
}


/// GET_INFO_CONTACT ///

std::string	Contact::getFirstName(void) const
{
	return (this->_firstName);
}

std::string	Contact::getLastName(void) const
{
	return (this->_lastName);
}

std::string	Contact::getNickName(void) const
{
	return (this->_nickName);
}

std::string	Contact::getPhoneNb(void) const
{
	return (this->_phoneNumber);
}

std::string	Contact::getDarkestSecret(void) const
{
	return (this->_darkestSecret);
}

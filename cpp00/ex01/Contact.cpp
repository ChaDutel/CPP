#include <string>
#include "Contact.hpp"

/// SET_INFO_CONTACT ///

void	Contact::setFirstName(std::string firstName)
{
	Contact	contacts;
	contacts.first_name = firstName;
}

void	Contact::setLastName(std::string lastName)
{
	Contact	contacts;
	contacts.last_name = lastName;
}

void	Contact::setFirstName(std::string nickName)
{
	Contact	contacts;
	contacts.nickname = nickName;
}

void	Contact::setPhoneNb(std::string phone_nb)
{
	Contact	contacts;
	contacts.phone_number = phone_nb;
}

void	Contact::setDarkestSecret(std::string dark_secret)
{
	Contact	contacts;
	contacts.darkest_secret = dark_secret;
}


/// GET_INFO_CONTACT ///

std::string	Contact::getFirstName(void)
{
	Contact	contacts;
	return (contacts.first_name);
}

std::string	Contact::getLastName(void)
{
	Contact	contacts;
	return (contacts.last_name);
}

std::string	Contact::getFirstName(void)
{
	Contact	contacts;
	return (contacts.nickname);
}

std::string	Contact::getPhoneNb(void)
{
	Contact	contacts;
	return (contacts.phone_number);
}

std::string	Contact::getDarkestSecret(void)
{
	Contact	contacts;
	return (contacts.darkest_secret);
}

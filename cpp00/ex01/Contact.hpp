#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>
# include <string>

class Contact
{
	public:
		Contact();
		~Contact();

		// trucType	getTruc(void)	const;
		// void	setTruc(trucType truc);

		void setFirstName(std::string firstName);
		void setLastName(std::string lastName);
		void setNickName(std::string nickName);
		void setPhoneNb(std::string phoneNb);
		void setDarkestSecret(std::string darkSecret);

		std::string getFirstName(void) const;
		std::string getLastName(void) const;
		std::string getNickName(void) const;
		std::string getPhoneNb(void) const;
		std::string getDarkestSecret(void) const;
	private:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darkestSecret;
};

#endif

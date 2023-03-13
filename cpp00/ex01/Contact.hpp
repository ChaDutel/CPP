#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>
# include <string>

class Contact
{
	public:
		Contact();
		~Contact();

		/// SET INFO ///
		void setFirstName(std::string firstName);
		void setLastName(std::string lastName);
		void setNickName(std::string nickName);
		void setPhoneNb(std::string phoneNb);
		void setDarkestSecret(std::string darkSecret);

		/// GET INFO ///
		std::string getFirstName(void) const;
		std::string getLastName(void) const;
		std::string getNickName(void) const;
		std::string getPhoneNb(void) const;
		std::string getDarkestSecret(void) const;

	private:
		/// INFO ///
		std::string _firstName;
		std::string _lastName;
		std::string _nickName;
		std::string _phoneNumber;
		std::string _darkestSecret;
};

#endif

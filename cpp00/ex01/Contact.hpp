#include <iostream>
#include <string>

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
		void setPhoneNb(std::string phone_nb);
		void setDarkestSecret(std::string dark_secret);

		std::string getFirstName(void);
		std::string getLastName(void);
		std::string getNickName(void);
		std::string getPhoneNb(void);
		std::string getDarkestSecret(void);
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
};

Contact::Contact(/* args */)
{
}

Contact::~Contact()
{
}

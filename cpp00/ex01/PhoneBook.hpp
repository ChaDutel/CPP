#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <iostream>
# include <string>
# include "Contact.hpp"

class PhoneBook
{
	public:
		Contact  listContact[8];

		/// ADD ///
		void			addInformations(Contact *newContact);

		/// DISPLAY SEARCH ///
		void			searchInformation(Contact choosingContact);
		void			showMiniList(PhoneBook contacts);

		PhoneBook();
		~PhoneBook();

	private:
		/// DISPLAY SEARCH ///
		void			addSpaceAndPipe(std::string info);
		std::string		checkSizeInfo(std::string info);

		/// ADD ///
		std::string		checkValidInfo(std::string info, std::string typeOfInfo);
		int				checkValidCharacter(std::string info);
};

#endif

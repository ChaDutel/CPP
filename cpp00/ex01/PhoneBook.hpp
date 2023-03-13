#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <iostream>
# include <iomanip>
# include <string>
# include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();

		Contact  listContact[8];

		/// ADD ///
		void			addInformations(Contact *newContact);

		/// DISPLAY SEARCH ///
		void			searchInformation(Contact choosingContact);
		void			showMiniList(PhoneBook contacts);

	private:
		/// DISPLAY SEARCH ///
		void			_addSpaceAndPipe(std::string info);
		std::string		_checkSizeInfo(std::string info);

		/// ADD ///
		std::string		_checkValidInfo(std::string info, std::string typeOfInfo);
		int				_checkValidCharacter(std::string info);
		int				_checkValidPhoneNumber(std::string info);
};

#endif

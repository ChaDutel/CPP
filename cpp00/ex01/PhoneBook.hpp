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

		/// ADD ///
		void		addInformations(int i);

		/// DISPLAY SEARCH ///
		void		searchInformation(int i) const;
		void		showMiniList(PhoneBook contacts) const;

	private:
		Contact  _listContact[8];

		/// DISPLAY SEARCH ///
		void		_addSpaceAndPipe(std::string info) const;
		std::string	_checkSizeInfo(std::string info) const;

		/// ADD ///
		std::string	_checkValidInfo(std::string info, std::string typeOfInfo);
		int			_checkValidCharacter(std::string info);
		int			_checkValidPhoneNumber(std::string info);
};

#endif

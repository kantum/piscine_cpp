#ifndef CONTACT_CLASS_H
#define CONTACT_CLASS_H

#include <string>

class	Contact
{
	public:
		Contact(void);
		~Contact(void);

		std::wstring		firstName;
		std::wstring		lastName;
		std::wstring		nickName;
		std::wstring		login;
		std::wstring		postalAddress;
		std::wstring		emailAddress;
		std::wstring		phoneNumber;
		std::wstring		birthdayDate;
		std::wstring		favoriteMeal;
		std::wstring		underwearColor;
		std::wstring		darkestSecret;

		static int		getSize(void);
		static bool		increaseSize(void);
		void			inc(void);
		int				getIndex(void);
	private:
		int				index;
		static int		_size;
};

#endif

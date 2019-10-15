#ifndef CONTACT_CLASS_H
#define CONTACT_CLASS_H

#include <string>
#include <iostream>
#include <iomanip>

class	Contact
{
	private:

		int				index;
		static int		_size;

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
};

void	showList(Contact *l);
void	print(std::string str);
void	printnl(std::string str);
void	wprint(std::wstring str);
void	headerContact(void);
void	showField(Contact *l);
void	showContact(std::wstring fname, std::wstring lname, std::wstring nname);

#endif

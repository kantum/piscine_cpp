#include <string>
#include <iostream>
#include <iomanip>

#include "contact.class.hpp"

void		fillField(std::wstring name, std::wstring &field)
{
	wprint(name + L": ");
	getline(std::wcin, field);
}

Contact		addContact(void)
{
	Contact		tmp;

	Contact::increaseSize();
	fillField(L"First Name", tmp.firstName);
	fillField(L"Last Name", tmp.lastName);
	fillField(L"Nick Name", tmp.nickName);
	fillField(L"Login", tmp.login);
	fillField(L"Postal Adress", tmp.postalAddress);
	fillField(L"Email Address", tmp.emailAddress);
	fillField(L"Phone Number", tmp.phoneNumber);
	fillField(L"Birthday Date", tmp.birthdayDate);
	fillField(L"Favorite Meal", tmp.favoriteMeal);
	fillField(L"Underwear Color", tmp.underwearColor);
	fillField(L"Darkest Secret", tmp.darkestSecret);

	return (tmp);
}

void	welcome(void)
{
	printnl("################################################################################");
	printnl("Welcome to your phonebook");
	printnl("Commands");
	printnl("ADD:    Add a new contact");
	printnl("SEARCH: List existing contacts");
	printnl("EXIT:   Exit your preferred phonebook");
	printnl("################################################################################");
}

void	headerContact(void)
{
	std::cout << "|     index|";
	std::cout << "first name|";
	std::cout << " last name|";
	std::cout << "  nickname|" << std::endl;
}

std::string	cutWord(std::string str)
{
	return (str.substr(0, 9) + ".");
}

int	main(void)
{
	setlocale(LC_ALL, "en_US.utf8");
	std::locale loc("en_US.UTF-8");
	std::wcout.imbue(loc);

	Contact		phoneBook[8];
	std::string user_input;
	int	timeout = 1000;

	welcome();
	while (42)
	{
		getline (std::cin, user_input);
		if (!user_input.compare("ADD"))
		{
			int size = Contact::getSize();
			if (size > 7)
				printnl("You have too much friends, consider buying an extension");
			else
				phoneBook[size] = addContact();
		}
		else if (!user_input.compare("SEARCH"))
		{
			if (!showList(phoneBook))
				showField(phoneBook);
		}
		else if (!user_input.compare("EXIT"))
			break;
		else
		{
			printnl("WRONG INPUT");
			if (!timeout--)
				break;
		}
	}
	return (0);
}

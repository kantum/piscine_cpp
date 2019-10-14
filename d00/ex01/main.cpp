#include <string>
#include <cstring>
#include <ctype.h>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <list>
#include <string_view>

#include "contact.class.hpp"

void	wprint(std::wstring str)
{
	std::wcout << str;
}

void	print(std::string str)
{
	std::cout << str;
}

void	printnl(std::string str)
{
	std::cout << str << std::endl;
}

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

void	showContact(std::wstring fname, std::wstring lname, std::wstring nname)
{
	if (fname.size() > 9)
		std::wcout << fname.substr(0, 9) + L".";
	else
		std::wcout << std::right << std::setw(10) << fname;
	print("|");
	if (lname.size() > 9)
		std::wcout << lname.substr(0, 9) + L".";
	else
		std::wcout << std::right << std::setw(10) << lname;
	print("|");
	if (nname.size() > 9)
		std::wcout << nname.substr(0, 9) + L".";
	else
		std::wcout << std::right << std::setw(10) << nname;
	printnl("|");
}

void showList(std::list<Contact> l)
{
	if (Contact::getSize() == 0)
	{
		printnl("You don't have any friend, do you want to try 42 ?");
		return;
	}
	printnl("");
	headerContact();
	for (std::list<Contact>::iterator it = l.begin(); it != l.end(); it++)
	{
		print("|");
		std::cout << std::right << std::setw(10) << it->getIndex();
		print("|");
		showContact(it->firstName, it->lastName, it->nickName);
	}
}

int	main(void)
{
	setlocale(LC_ALL, "en_US.utf8");
	std::locale loc("en_US.UTF-8");
	std::wcout.imbue(loc);

	std::list<Contact>		phoneBook;
	std::string user_input;
	int	timeout = 1000;

	welcome();
	while (42)
	{
		getline (std::cin, user_input);
		if (!user_input.compare("ADD"))
		{
			if (Contact::getSize() > 7)
				printnl("You have too much friends, consider buying an extension");
			else
				phoneBook.push_back(addContact());
		}
		else if (!user_input.compare("SEARCH"))
			showList(phoneBook);
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

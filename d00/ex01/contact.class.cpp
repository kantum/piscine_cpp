#include <string>
#include <iostream>
#include <iomanip>

#include "contact.class.hpp"

Contact::Contact(void)
{
	return;
}

Contact::~Contact(void)
{
	return;
}

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

bool	Contact::increaseSize(void)
{
	Contact::_size++;
	if (_size > 8)
		return 1;
	else
		return 0;
}

int		Contact::getSize(void)
{
	return Contact::_size;
}

bool is_number(const std::string& s)
{
	std::string::const_iterator it = s.begin();
	while (it != s.end() && std::isdigit(*it)) ++it;
	return !s.empty() && it == s.end();
}

void showField(Contact *l)
{
	std::string sindex;
	int index = 0;
	print("Index: ");
	getline(std::cin, sindex);

	if (is_number(sindex))
		index = stoi(sindex);
	else
	{
		std::cout << "This is not a number" << std::endl;
		return;
	}
	std::cout << index << std::endl;
	std::wcout << "First Name:      " << l[index].firstName << std::endl;
	std::wcout << "Last Name:       " << l[index].lastName << std::endl;
	std::wcout << "Nick Name:       " << l[index].nickName << std::endl;
	std::wcout << "Login:           " << l[index].login << std::endl;
	std::wcout << "Postal Adress:   " << l[index].postalAddress << std::endl;
	std::wcout << "Email Address:   " << l[index].emailAddress << std::endl;
	std::wcout << "Phone Number:    " << l[index].phoneNumber << std::endl;
	std::wcout << "Birthday Date:   " << l[index].birthdayDate << std::endl;
	std::wcout << "Favorite Meal:   " << l[index].favoriteMeal << std::endl;
	std::wcout << "Underwear Color: "<< l[index].underwearColor << std::endl;
	std::wcout << "Darkest Secret:  "<< l[index].darkestSecret << std::endl;
}

bool showList(Contact *l)
{
	if (Contact::getSize() == 0)
	{
		printnl("You don't have any friend, do you want to try 42 ?");
		return 1;
	}
	printnl("");
	headerContact();
	for (int i = 0; i < Contact::getSize(); i++)
	{
		print("|");
		std::cout << std::right << std::setw(10) << i;
		print("|");
		showContact(l[i].firstName, l[i].lastName, l[i].nickName);
	}
	return 0;
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

int	Contact::_size = 0;

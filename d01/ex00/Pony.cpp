#include "Pony.hpp"

Pony::Pony(std::string name) : _name(name)
{
	std::cout << "Pony " << this->_name << 	" is born" << std::endl;
}

Pony::~Pony()
{
	std::cout << "Pony " << this->_name << 	" is dead" << std::endl;
}

void 		Pony::setName(std::string name)
{
	this->_name = name;
}

std::string	Pony::getName() const
{
	return this->_name;
}

void 		Pony::setSex(std::string sex)
{
	this->_sex = sex;
	std::cout << "Pony " << this->_name << 	" is changing sex" << std::endl;
}

std::string	Pony::getSex() const
{
	return this->_sex;
}

void 		Pony::setPrice(std::string price)
{
	this->_price = price;
	std::cout << "Pony " << this->_name << 	" is changing price" << std::endl;
}

std::string	Pony::getPrice() const
{
	return this->_price;
}

void 		Pony::setRunningTime(std::string runningTime)
{
	this->_runningTime += runningTime;
	std::cout << "Pony " << this->_name << 	" has runned" << std::endl;
}

std::string	Pony::getRunningTime() const
{
	return this->_runningTime;
}

void 		Pony::setBeersByDay(std::string beers)
{
	this->_beersByDay = beers;
	std::cout << "Pony " << this->_name << 	" is drinking beer" << std::endl;
}

std::string	Pony::getBeersByDay() const
{
	return this->_beersByDay;
}

void 		Pony::setPreferredCar(std::string preferredCar)
{
	this->_preferredCar = preferredCar;
	std::cout << "Pony " << this->_name << 	" changed his mind about teslas" << std::endl;
}

std::string	Pony::getPreferredCar() const
{
	return this->_preferredCar;
}

void 		Pony::getInfos()
{
	std::cout << std::endl << "Infos:"     << std::endl << std::endl;
	std::cout << "name         " << this->_name         << std::endl;
    std::cout << "sex          " << this->_sex          << std::endl;
    std::cout << "price        " << this->_price        << std::endl;
    std::cout << "runningTime  " << this->_runningTime  << std::endl;
    std::cout << "beersByDay   " << this->_beersByDay   << std::endl;
    std::cout << "preferredCar " << this->_preferredCar << std::endl;
}
Pony	*ponyOnTheHeap(std::string name)
{
	Pony *ret = new Pony(name);
	ret->setSex ("male");
	ret->setPrice ("2000");
	ret->setRunningTime ("3000h");
	ret->setBeersByDay ("5");
	ret->setPreferredCar ("tesla");
	return (ret);
}

Pony	ponyOnTheStack(std::string name)
{
	Pony ret = Pony(name);
	ret.setSex ("male");
	ret.setPrice ("2000");
	ret.setRunningTime ("3000h");
	ret.setBeersByDay ("5");
	ret.setPreferredCar ("tesla");

	return (ret);
}

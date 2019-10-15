#ifndef PONY_HPP
#define PONY_HPP

#include <string>
#include <iostream>

class	Pony
{
	private:
		std::string _name;
		std::string _sex;
		std::string _price;
		std::string _runningTime;
		std::string _beersByDay;
		std::string _preferredCar;

	public:

		Pony(std::string name);
		~Pony();

		void 		setName(std::string name);
		std::string	getName() const;
		void 		setSex(std::string sex);
		std::string	getSex() const;
		void 		setPrice(std::string price);
		std::string	getPrice() const;
		void 		setRunningTime(std::string runningTime);
		std::string	getRunningTime() const;
		void 		setBeersByDay(std::string beers);
		std::string	getBeersByDay() const;
		void 		setPreferredCar(std::string preferredCar);
		std::string	getPreferredCar() const;
		void 		getInfos();
};

Pony	*ponyOnTheHeap(std::string name);
Pony	ponyOnTheStack(std::string name);

#endif

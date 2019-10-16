#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanB
{
	private:

		std::string		_name;
		Weapon			*_weapon;
		std::string		_attack;

	public:

		HumanB(std::string name);
		~HumanB(void);

		void 		setWeapon(Weapon weapon);
		std::string	getWeapon() const;
		void 		attack(void) const;
};

#endif

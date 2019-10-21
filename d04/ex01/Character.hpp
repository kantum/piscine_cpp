#ifndef CHARACTER_HPP
# define CHARACTER_HPP
#include <iostream>
#include "AWeapon.hpp"
#include "Enemy.hpp"

class Character
{
	private:
		std::string	_name;
		int		_actionPoints;
		AWeapon*	_weaponPtr;
	public:
		Character(void);
		Character(std::string const & name);
		Character(Character const & src);
		~Character(void);
		
		Character& operator=(Character const & rhs);
		
		std::string	getName() const;
		int		getActionPoints() const;
		AWeapon*	getWeaponPtr() const;

		void		recoverAP();
		void		equip(AWeapon*);
		void		attack(Enemy*);
		
};

std::ostream& operator<<(std::ostream &out, const Character& c);

#endif

#ifndef AWEAPON_HPP
# define AWEAPON_HPP
#include <iostream>

class AWeapon
{
	private:
		std::string	_name;
		int		_damagePoints;
		int		_apCost;
	public:
		AWeapon(void);
		AWeapon(std::string const & name, int apcost, int damage);
		AWeapon(AWeapon const & src);
		virtual ~AWeapon(void);
		
		AWeapon& operator=(AWeapon const & rhs);
		
		std::string const &	getName() const;
		int			getAPCost() const;
		int			getDamage() const;
		
		virtual void attack() const = 0;
};

#endif

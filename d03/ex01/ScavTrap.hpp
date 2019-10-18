#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
#include <iostream>

class ScavTrap {
	private:

		int			_hitPoints;
		int			_maxHitPoints;
		int			_energyPoints;
		int			_maxEnergyPoints;
		int			_level;
		std::string	_name;
		int			_meleeAttackDamage;
		int			_rangedAttackDamage;
		int			_armorDamageReduction;

	public:

		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const & src);
		ScavTrap & operator=(ScavTrap const & rhs);
		~ScavTrap(void);

		void		setHitPoints(int n);
		void		setMaxHitPoints(int n);
		void		setEnergyPoints(int n);
		void		setMaxEnergyPoints(int n);
		void		setLevel(int n);
		void		setName(std::string s);
		void		setMeleeAttackDamage(int n);
		void		setRangedAttackDamage(int n);
		void		setArmorDamageReduction(int n);

		int			getHitPoints() const;
		int			getMaxHitPoints() const;
		int			getEnergyPoints() const;
		int			getMaxEnergyPoints() const;
		int			getLevel() const;
		std::string	getName() const;
		int			getMeleeAttackDamage() const;
		int			getRangedAttackDamage() const;
		int			getArmorDamageReduction() const;

		void		rangedAttack(std::string const & target);
		void		meleeAttack(std::string const & target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		void		challengeNewcomer(std::string const & target);
};

#endif

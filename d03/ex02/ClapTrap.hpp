#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
#include <iostream>

class ClapTrap
{
	private:

	protected:

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

		ClapTrap(std::string name);
		ClapTrap(ClapTrap const &);
//		ClapTrap& operator=(ClapTrap const &);
		~ClapTrap(void);

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
		void		vaulthunter_dot_exe(std::string const & target);
		void		showValues(void);
};

#endif


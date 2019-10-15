#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class	Zombie
{
	private:

		std::string _name;
		std::string _type;

	public:

		Zombie();
		~Zombie(void);

		void 		setName(std::string name);
		std::string	getName() const;
		void 		setType(std::string type);
		std::string	getType() const;
		void		announce();
};

#endif

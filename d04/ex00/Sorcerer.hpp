#ifndef SORCERER_HPP
# define SORCERER_HPP
#include <iostream>
#include "Victim.hpp"

class Sorcerer
{
	private:
		std::string	_name;
		std::string	_title;
	public:
		Sorcerer(void);
		Sorcerer(std::string name, std::string title);
		Sorcerer(Sorcerer const & src);
		~Sorcerer(void);

		Sorcerer& operator=(Sorcerer const & rhs);
		
		std::string	getName(void) const;
		std::string	getTitle(void) const;
	
		void		introduce(void);
		void		polymorph(Victim const &) const;
};

std::ostream& operator<<(std::ostream &out, const Sorcerer& c);

#endif

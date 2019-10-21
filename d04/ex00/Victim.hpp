#ifndef VICTIM_HPP
# define VICTIM_HPP
#include <iostream>

class Victim
{
	protected:
		std::string	_name;
	public:
		Victim(void);
		Victim(std::string name);
		Victim(Victim const & src);
		~Victim(void);

		Victim& operator=(Victim const & rhs);
		
		std::string	getName(void) const;
		
		void		introduce(void);
		virtual void	getPolymorphed(void) const;
};

std::ostream& operator<<(std::ostream &out, const Victim& c);

#endif

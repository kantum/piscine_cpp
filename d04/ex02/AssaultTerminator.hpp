#ifndef ASSAULTTERMINATOR_HPP
# define ASSAULTTERMINATOR_HPP
# include <iostream>
#include "ISpaceMarine.hpp"

class AssaultTerminator : public ISpaceMarine
{
	public:
		AssaultTerminator(void);
		AssaultTerminator(AssaultTerminator const & src);
		virtual ~AssaultTerminator(void);

		AssaultTerminator& operator=(AssaultTerminator const & rhs);
		
		virtual	ISpaceMarine*	clone() const;
		virtual void		battleCry() const;
		virtual void		rangedAttack() const;
		virtual void		meleeAttack() const;
};

#endif

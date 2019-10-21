#ifndef TACTICALMARINE_HPP
# define TACTICALMARINE_HPP
# include <iostream>
#include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine
{
	public:
		TacticalMarine(void);
		TacticalMarine(TacticalMarine const & src);
		virtual ~TacticalMarine(void);

		TacticalMarine& operator=(TacticalMarine const & rhs);
		
		virtual	ISpaceMarine*	clone() const;
		virtual void		battleCry() const;
		virtual void		rangedAttack() const;
		virtual void		meleeAttack() const;
};

#endif

#ifndef SQUAD_HPP
# define SQUAD_HPP
#include <iostream>
#include "ISpaceMarine.hpp"
#include "ISquad.hpp"

class Squad : public ISquad
{
	typedef struct			s_unitPtr
  	{
    		ISpaceMarine*		marine_ptr;
    		struct s_unitPtr	*next;
  	}				t_unitPtr;
	private:	
		t_unitPtr*		_lst;
		int			_nbUnits;
	public:
		Squad(void);
		Squad(Squad const & src);
		virtual ~Squad(void);

		Squad& operator=(Squad const & rhs);
		
		virtual int		getCount() const;
		virtual ISpaceMarine*	getUnit(int) const;
		virtual int		push(ISpaceMarine*);
};

#endif

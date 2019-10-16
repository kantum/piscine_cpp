#ifndef HUMAN_HPP
# define HUMAN_HPP

#include "Brain.hpp"
#include "Human.hpp"

class Human
{
	private:

		const Brain		_brain;

	public:

		Human();
		~Human(void);

		std::string		identify(void) const;
		const Brain&	getBrain(void) const;
};

#endif

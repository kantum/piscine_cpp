#ifndef ENEMY_HPP
# define ENEMY_HPP
#include <iostream>

class Enemy
{
	private:
		int		_hp;
		std::string	_type;
	public:
		Enemy(void);
		Enemy(int hp, std::string const & type);
		Enemy(Enemy const & src);
		virtual ~Enemy(void);

		Enemy& operator=(Enemy const & rhs);
		
		std::string	getType() const;
		int		getHP() const;

		virtual void	takeDamage(int);
};

#endif

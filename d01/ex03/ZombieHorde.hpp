#ifndef ZOMBIEHORDE_HPP
#define ZOMBIEHORDE_HPP

class	ZombieHorde
{
	private:
		Zombie 			*horde;
		unsigned int	nzombie;

	public:
		ZombieHorde(unsigned int n);
		~ZombieHorde(void);

	void	announce(void);
};

#endif


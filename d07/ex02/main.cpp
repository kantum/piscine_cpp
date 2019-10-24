#include <iostream>
#include <string>
#include <cstdlib>
#include "Array.hpp"

template< typename T >void	iter(T *addr, int size, void (*f)(T const & t))
{
	for (int i = 0; i < size; i++)
		(*f)(addr[i]);
}

template< typename T >void	print(T const & t)
{
	std::cout << t << std::endl;
}

int	main(void)
{
	Array<int> *a = new Array<int>(42);
	Array<float> *b = new Array<float>(42);

	int t = a[3];
	int c = 2432;
	std::cout << b << std::endl;
	std::cout << t << std::endl;
	return(0);
}

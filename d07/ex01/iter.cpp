#include <iostream>
#include <string>

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
	int		array1[42] = {
		42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,
		42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,
	};
	float	array2[42] = {
		4.2,4.2,4.2,4.2,4.2,4.2,4.2,4.2,4.2,4.2,4.2,4.2,4.2,4.2,4.2,4.2,
		4.2,4.2,4.2,4.2,4.2,4.2,4.2,4.2,4.2,4.2,4.2,4.2,4.2,4.2,4.2,4.2,
		4.2,4.2, 4.2,4.2,4.2,4.2,4.2,4.2,4.2,4.2,
	};
	std::string	array3[42] = {
		"quarante deux","quarante deux","quarante deux","quarante deux",
		"quarante deux","quarante deux","quarante deux","quarante deux",
		"quarante deux","quarante deux","quarante deux","quarante deux",
		"quarante deux","quarante deux","quarante deux","quarante deux",
		"quarante deux","quarante deux","quarante deux","quarante deux",
		"quarante deux","quarante deux","quarante deux","quarante deux",
		"quarante deux","quarante deux","quarante deux","quarante deux",
		"quarante deux","quarante deux","quarante deux","quarante deux",
		"quarante deux","quarante deux","quarante deux","quarante deux",
		"quarante deux","quarante deux","quarante deux","quarante deux",
		"quarante deux","quarante deux",
	};

	iter(array1, 42, print);
	iter(array2, 42, print);
	iter(array3, 42, print);

	return(0);
}

#include <iostream>
#include <string>

std::string	ft_str_toupper(std::string str)
{
	std::string ret;

	for (unsigned int i = 0; i < str.length(); i++)
		ret += static_cast<char>(toupper(str[i]));
	return ret;
}

int	main(int argc, char** argv)
{
	if (argc > 1)
	{
		for (int i = 1; i < argc; i++)
			std::cout << ft_str_toupper(argv[i]);
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
}

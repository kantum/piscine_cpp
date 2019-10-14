#include <iostream>
#include <string>

void	ft_print(std::string str)
{
	std::cout << str;
}

void	ft_printnl(std::string str)
{
	std::cout << str << std::endl;
}

std::string	ft_str_toupper(std::string str)
{
	std::string ret;

	for (unsigned int i = 0; i < str.length(); i++)
	{
		ret += static_cast<char>(toupper(str[i]));
	}
	return ret;
}

int	main(int argc, char** argv)
{
	if (argc > 1)
	{
		for (int i = 1; i < argc; i++)
			ft_print(ft_str_toupper(argv[i]));
		std::cout << std::endl;
	}
	else
	{
		ft_printnl("* LOUD AND UNBEARABLE FEEDBACK NOISE *");
	}
}

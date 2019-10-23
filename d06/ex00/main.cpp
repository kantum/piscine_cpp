#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Scalar.hpp"

int	main(int argc, char **argv)
{
	for(int i = 1; i < argc; i++)
	{
		Scalar input(argv[i]);
		std::cout << std::fixed << std::setprecision(9);

		std::cout << "char: ";
		try
		{
			char c = static_cast<char>(input);

			if (c >= '!' && c <= '~')
			{
				std::cout << "'";
				std::cout << static_cast<char>(c);
				std::cout << "'" << std::endl;
			}
			else
				std::cout << "Non displayable" << std::endl;
		}
		catch (Scalar::ScalarException &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << "int: ";
		try
		{
			std::cout << static_cast<int>(input) << std::endl;
		}
		catch (Scalar::ScalarException &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << "float: ";
		try
		{
			std::cout << static_cast<float>(input) << "f" << std::endl;
		}
		catch (Scalar::ScalarException &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << "double: ";
		try
		{
			std::cout << static_cast<double>(input) << std::endl;
		}
		catch (Scalar::ScalarException &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	return (0);
}

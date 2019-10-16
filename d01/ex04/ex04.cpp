#include <iostream>

// clang++ -std=c++98 -Wall -Wextra -Werror ex04.cpp && ./a.out
int	main()
{
    std::string		str = "HI THIS IS BRAIN";
	std::string		*str_ptr = &str;
	std::string		&str_ref = str;

    std::cout << *str_ptr << std::endl;
    std::cout << str_ref << std::endl;

    return 0;
}

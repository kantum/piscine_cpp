#include <iostream>
#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"
#include "Spoon.hpp"
#include "WildDog.hpp"

int		main()
{
	Sorcerer	robert("Robert", "the Magnificent");
	Victim		jim("Jimmy");
	Peon		joe("Joe");
	Spoon		kitty("Kitty");
	WildDog		wouffi("Wouffi");

	std::cout << robert << jim << joe << kitty << wouffi;
	robert.polymorph(jim);
	robert.polymorph(joe);
	robert.polymorph(kitty);
	robert.polymorph(wouffi);

	return 0;
}

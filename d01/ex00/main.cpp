#include "Pony.hpp"

int main(void)
{
	Pony *bob = ponyOnTheHeap("Linus");
	Pony boris = ponyOnTheStack("Stallman");

	bob->setPrice("5000");
	bob->getInfos();
	boris.setSex("Male");
	boris.getInfos();
	delete bob;
}

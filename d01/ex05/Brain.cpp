#include <sstream> //for std::stringstream 
#include <string>  //for std::string
#include "Brain.hpp"

Brain::Brain(void) { }

Brain::~Brain(void) { }

std::string		Brain::identify(void) const
{
	const void * address = static_cast<const void*>(this);
	std::stringstream ss;
	ss << address;  
	std::string name = ss.str(); 
	//std::cout << "identify Brain" << std::endl;
	return name; 
}

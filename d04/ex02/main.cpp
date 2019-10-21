#include "ISpaceMarine.hpp"
#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"
#include "ISquad.hpp"
#include "Squad.hpp"

int main()
{
	std::cout << "* NEW PEOPLE / NEW SQUAD *" << std::endl << std::endl;
	ISpaceMarine* a = new TacticalMarine;
	ISpaceMarine* c = new AssaultTerminator;
	ISpaceMarine* b = new TacticalMarine;
	ISpaceMarine* d = new AssaultTerminator;
	ISquad* bestSquad = new Squad;;

	std::cout << std::endl << std::endl;
	
	bestSquad->push(a);
	bestSquad->push(c);
	bestSquad->push(b);
	bestSquad->push(d);
	std::cout << std::endl << std::endl;
	for (int i = 0; i < bestSquad->getCount(); ++i)
	{
		ISpaceMarine* cur = bestSquad->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}
	std::cout << std::endl << "*DELETING SQUAD *" << std::endl << std::endl;
	delete bestSquad;
	
	std::cout << std::endl << "* NEW SQUAD *" << std::endl << std::endl;
	Squad une;
	ISpaceMarine*   p = new TacticalMarine;
	ISpaceMarine*	q = new AssaultTerminator;
	
	std::cout << std::endl << std::endl;
	une.push(p);
	une.push(q);
	std::cout << std::endl << "* MAKING A COPY OF A SQUAD *" << std::endl;
	Squad deux = une;
	
	std::cout << std::endl << "End of main, objects will die" << std::endl << std::endl;
	return 0;
}

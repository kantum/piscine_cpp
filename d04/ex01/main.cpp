#include "Character.hpp"
#include "AWeapon.hpp"
#include "Enemy.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "SuperMutant.hpp"
#include "RadScorpion.hpp"
#include "UglyDragon.hpp"
#include "Spoon.hpp"

int		main()
{
	Character* zaz = new Character("zaz");
	std::cout << *zaz;
	
	Enemy* mutant = new SuperMutant();
	Enemy* b = new RadScorpion();
	Enemy* dragon = new UglyDragon();
	AWeapon* pr = new PlasmaRifle();
	AWeapon* pf = new PowerFist();
	AWeapon* spoon = new Spoon();

	zaz->equip(pr);
	std::cout << *zaz;
	zaz->equip(pf);
	zaz->attack(b);
	std::cout << *zaz;
	zaz->equip(pr);
	std::cout << *zaz;
	zaz->attack(b);
	std::cout << *zaz;
	zaz->attack(b);
	std::cout << *zaz;
	zaz->attack(dragon);
	std::cout << *zaz;
	zaz->attack(dragon);
	std::cout << *zaz;
	zaz->equip(spoon);
	std::cout << *zaz;
	zaz->attack(dragon);
	std::cout << *zaz;
	zaz->attack(mutant);
	std::cout << *zaz;

	return 0;
}

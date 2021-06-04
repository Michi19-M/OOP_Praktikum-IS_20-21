#include "Enemy.h"
#include "Enemies.h"
#include "Hero.h"

int main()
{
	try {
		Mob* m1 = new Hero("Dobur", 450.35, 178.90, 700);
		Mob* e2 = new Enemy("Gaden", 350, 175.34, "big");
		Mob* t = new Enemies;

		m1->print();
		std::cout << std::endl;
		e2->print();
		std::cout << std::endl;
		t->print();
		std::cout << std::endl;

		e2->attack(m1);
		m1->print();
		std::cout << std::endl;

		m1->attack(e2);
		e2->print();
	}
	catch (std::invalid_argument& err) {
		std::cout << err.what();
	}
	catch (std::logic_error& err)
	{
		std::cout << err.what();
	}

	return 0;
}
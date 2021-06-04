#include "Enemies.h"

Enemies::Enemies()
{
	size = 0;
	capacity = 2;
	enemies = new Mob * [capacity];
}

Enemies::Enemies(const Enemies& other)
{
	copy(other);
}

Enemies& Enemies::operator=(const Enemies& other)
{
	if (this != &other)
	{
		destroy();
		copy(other);
	}
	return *this;
}

Enemies::~Enemies()
{
	destroy();
}

void Enemies::add(Mob* champ)
{
	if (champ->getType() != "enemy")
	{
		throw std::logic_error("Enemy/Enemies can attack only Heros!\n");
	}
	if (size >= capacity)
	{
		resize();
	}
	enemies[size++] = champ;
}

const char* Enemies::getType() const
{
	return "enemies";
}

void Enemies::attack(Mob* other)
{
	if (other->getHealth() <= 0)
	{
		throw std::logic_error("Mob already dead\n");
	}
	for (int i = 0; i < size; i++)
	{
		double damage = enemies[i]->getDmg();
		double hp = other->getHealth();
		other->setHealth(hp -= damage);
		if (other->getHealth() <= 0)
		{
			other->die();
			break;
		}
	}
}

void Enemies::die()
{
	for (int i = 0; i < size; i++)
	{
		enemies[i]->die();
		/*enemies[i]->setHealth(0);
		enemies[i]->setLife(false);*/
	}
}

int Enemies::getEnemiesSize()
{
	return size;
}

void Enemies::print() const
{
	std::cout << "Type: " << getType() << std::endl;
	std::cout << "Number of enemies: " << size << std::endl;
	for (int i = 0; i < size; i++)
	{
		std::cout << "Name: " << name.getString() << std::endl;
		std::cout << "Damage: " << dmg << std::endl;
		std::cout << "Health: " << health << std::endl;
		std::cout << std::boolalpha << "Is alive: " << isAlive << std::endl;
	}
}

Enemies* Enemies::clone() const
{
	return new Enemies(*this);
}

void Enemies::copy(const Enemies& other)
{
	size = other.size;
	capacity = other.capacity;
	enemies = new Mob * [capacity];
	for (int i = 0; i < size; i++)
	{
		enemies[i] = other.enemies[i]->clone(); // clone() -> to make deep copy
	}
}

void Enemies::destroy()
{
	for (int i = 0; i < size; i++)
	{
		delete enemies[i];
	}
	delete[] enemies;
}

void Enemies::resize()
{
	capacity *= 2;
	Mob** biggerArr = new Mob * [capacity];

	for (int i = 0; i < size; i++)
	{
		biggerArr[i] = enemies[i]->clone();
	}
	destroy();
	enemies = biggerArr;
}

//std::ostream& operator<<(std::ostream& out, const Enemies& other)
//{
//	for (int i = 0; i < other.size; i++)
//	{
//		out << "Type: " << other.getType();
//		out << "Name: " << other.name.getString();
//		out << "Damage: " << other.dmg;
//		out << "Health: " << other.health;
//		out << "Is alive: " << other.isAlive;
//	}
//	return out;
//}

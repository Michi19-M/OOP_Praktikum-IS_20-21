#include "Mob.h"

Mob::Mob() : health(1), dmg(0), isAlive(true), armor(0) {}

Mob::Mob(const char* _name, double _health, double _dmg)
{
	name.setString(_name, strlen(_name) + 1, strlen(_name) + 2);
	health = _health;
	dmg = _dmg;
	isAlive = true;
	armor = 0;
}

void Mob::setHealth(const double _hp)
{
	health = _hp;
}

void Mob::setArmor(const int _armor)
{
	armor = _armor;
}

double Mob::getHealth() const
{
	return health;
}

double Mob::getDmg() const
{
	return dmg;
}

int Mob::getArmor() const
{
	return armor;
}

int Mob::getEnemiesSize()
{
	return 0;
}

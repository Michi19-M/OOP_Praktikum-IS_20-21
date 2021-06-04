#include "Hero.h"

Hero::Hero() : Mob(), armor(0) {}

Hero::Hero(const char* _name, double _health, double _dmg, int _armor) : Mob(_name, _health, _dmg)
{
	armor = _armor;
	setArmor(armor);
}

const char* Hero::getType() const
{
	return "hero";
}

void Hero::setArmor(const int _armor)
{
	armor = _armor;
}

void Hero::attack(Mob* other)
{
	if (other->getType() == "hero") {
		throw std::logic_error("Hero can attack only Enemy/Enemies!\n");
	}
	if (other->getHealth() <= 0) {
		throw std::logic_error("Mob already dead\n");
	}
	else if (other->getType() == "enemy")
	{
		double hp = other->getHealth();
		other->setHealth(hp -= this->dmg);
		if (other->getHealth() <= 0)
		{
			other->die();
		}
	}
	else
	{
		char attackType[7];
		std::cout << "Enter 'splash' for splash attack OR 'normal for normal attack: ";
		std::cin >> attackType;

		if (attackType == "splash")
		{
			for (int i = 0; i < other->getEnemiesSize(); i++)
			{
				double hp = other[i].getHealth();
				other[i].setHealth(hp -= this->dmg);
				if (other[i].getHealth() <= 0)
				{
					other[i].die();
				}
			}
		}
		else if (attackType == "normal")
		{
			for (int i = 0; i < other->getEnemiesSize(); i++)
			{
				if (other[i].getHealth() > 0)
				{
					double hp = other[i].getHealth();
					other[i].setHealth(hp -= this->dmg);
					if (other[i].getHealth() <= 0)
					{
						other[i].die();
					}
				}
			}
		}
	}
}

void Hero::die()
{
	this->setHealth(0);
	this->isAlive = false;
}

void Hero::print() const
{
	std::cout << "Type: " << getType() << std::endl;
	std::cout << "Name: " << name.getString() << std::endl;
	std::cout << "Damage: " << dmg << std::endl;
	std::cout << "Armor: " <<armor << std::endl;
	std::cout << "Health: " << health << std::endl;
	std::cout << std::boolalpha << "Is alive: " << isAlive << std::endl;
}

void Hero::attackHelper(Mob* other)
{
	double hp = other->getHealth();
	other->setHealth(hp -= this->dmg);
	if (other->getHealth() <= 0)
	{
		other->die();
	}
}

Hero* Hero::clone() const
{
	return new Hero(*this);
}

//std::ostream& operator<<(std::ostream& out, const Hero& other)
//{
//	out << "Type: " << other.getType();
//	out << "Name: " << other.name.getString();
//	out << "Damage: " << other.dmg;
//	out << "Armor: " << other.armor;
//	out << "Health: " << other.health;
//	out << "Is alive: " << other.isAlive;
//
//	return out;
//}

#include "Enemy.h"

Enemy::Enemy() : Mob()
{
	enemyType = EnemyType::SMALL;
}

Enemy::Enemy(const char* _name, double _health, double _dmg, const char* _enemyType) : Mob(_name, _health, _dmg)
{
	if (_enemyType == "small") {
		enemyType = EnemyType::SMALL;
	}
	else if (_enemyType == "average") {
		enemyType = EnemyType::AVERAGE;
	}
	else if (_enemyType == "big") {
		enemyType = EnemyType::BIG;
	}
	else {
		throw std::invalid_argument("Invalid type input (must be small/average/big)\n");
	}
}

Enemy::Enemy(const Enemy& other)
{
	name.setString(other.name.getString(), other.name.getSize(), other.name.getCapacity());
	health = other.health;
	dmg = other.dmg;
	isAlive = other.isAlive;
	enemyType = other.enemyType;
}

void Enemy::attack(Mob* other)
{
	if (other->getType() == "hero")
	{
		if (other->getHealth() <= 0)
		{
			throw std::logic_error("Mob already dead\n");
		}
		// first armor must be 0. Attack ends when Hero's hp == 0
		// if type is small -> dmg remàins the same, BUT ne zachita bronqta, direktno svalq hp-to
		// if type is average -> dmg * 1.5
		// if type is big -> dmg * 2
		double hp = other->getHealth();
		double tempDmg = this->dmg;
		if (enemyType == EnemyType::AVERAGE) {
			tempDmg *= 1.5;
		}
		if (enemyType == EnemyType::BIG) {
			tempDmg *= 2;
		}
		if (enemyType != EnemyType::SMALL) {
			double armor = other->getArmor();
			if (armor > 0)
			{
				other->setArmor(armor -= tempDmg);
			}
			else {
				other->setArmor(0);
				other->setHealth(hp -= tempDmg);
			}
		}
		else
		{
			other->setHealth(hp -= tempDmg);
		}
		
		if (other->getHealth() <= 0)	{
			other->die();
		}
	}
	else {
		throw std::logic_error("Enemy can attack only a Hero!\n");
	}
}

void Enemy::die()
{
	this->setHealth(0);
	this->isAlive = false;
}

const char* Enemy::getType() const
{
	return "enemy";
}

const char* Enemy::getEnemyType(EnemyType _e) const
{
	if (_e == EnemyType::SMALL)
	{
		return "small";
	}
	if (_e == EnemyType::AVERAGE)
	{
		return "average";
	}
	if (_e == EnemyType::BIG)
	{
		return "big";
	}
}

void Enemy::print() const
{
	std::cout << "Type: " << getType() << std::endl;
	std::cout << "Enemy type: " << getEnemyType(enemyType) << std::endl;
	std::cout << "Name: " << name.getString() << std::endl;
	std::cout << "Damage: " << dmg << std::endl;
	std::cout << "Health: " << health << std::endl;
	std::cout << std::boolalpha << "Is alive: " << isAlive << std::endl;
}

Enemy* Enemy::clone() const
{
	return new Enemy(*this);
}

//std::ostream& operator<<(std::ostream& out, const Enemy& other)
//{
//	out << "Type: " << other.getType();
//	out << "Name: " << other.name.getString();
//	out << "Damage: " << other.dmg;
//	out << "Health: " << other.health;
//	out << "Is alive: " << other.isAlive;
//
//	return out;
//}

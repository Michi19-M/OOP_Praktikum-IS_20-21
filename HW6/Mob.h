#pragma once
#include <exception>
#include "String.h"

class Mob
{
public:
	Mob();
	Mob(const char* _name, double _health, double _dmg);

	void setHealth(const double _hp);
	virtual void setArmor(const int _armor);

	double getHealth() const;
	double getDmg() const;
	int getArmor() const;

	virtual void attack(Mob* other) = 0;
	virtual void die() = 0;
	virtual const char* getType() const = 0;

	virtual int getEnemiesSize();
	virtual Mob* clone() const = 0;

	//virtual friend std::ostream& operator<<(std::ostream& out, const Mob& other) = 0;

	virtual void print() const = 0;
protected:
	String name;
	double health;
	double dmg;
	bool isAlive;
private:
	int armor;
};
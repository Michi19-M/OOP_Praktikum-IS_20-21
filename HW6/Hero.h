#pragma once
#include "Mob.h"
#include "Enemies.h"

class Hero : public Mob
{
public:
	Hero();
	Hero(const char* _name, double _health, double _dmg, int _armor);

	const char* getType() const override;

	void setArmor(const int _armor) override;

	void attack(Mob* other) override;
	void die() override;

	Hero* clone() const override;
	//friend std::ostream& operator<<(std::ostream& out, const Hero& other);

	void print() const override;
private:
	int armor;

	void attackHelper(Mob* other);
};
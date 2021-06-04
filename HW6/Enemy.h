#pragma once
#include "Mob.h"

enum class EnemyType { SMALL, AVERAGE, BIG };

class Enemy : public Mob
{
private:
	EnemyType enemyType;
public:
	Enemy();
	Enemy(const char* _name, double _health, double _dmg, const char* _type);
	Enemy(const Enemy& other);

	void attack(Mob* other) override;
	void die() override;

	const char* getType() const override;

	Enemy* clone() const override;
	//friend std::ostream& operator<<(std::ostream& out, const Enemy& other);

	const char* getEnemyType(EnemyType _e) const;

	void print() const override;
};
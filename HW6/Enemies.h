#pragma once
#include "Mob.h"

class Enemies : public Mob
{
public:
	Enemies();
	Enemies(const Enemies& other);
	Enemies& operator=(const Enemies& other);
	~Enemies();

	void add(Mob* champ);

	const char* getType() const override;

	void attack(Mob* other) override;
	void die() override;

	int getEnemiesSize() override;

	Enemies* clone() const override;
//	friend std::ostream& operator<<(std::ostream& out, const Enemies& other);

	void print() const override;
private:
	Mob** enemies;
	int size;
	int capacity;

	void copy(const Enemies& other);
	void destroy();
	void resize();
};
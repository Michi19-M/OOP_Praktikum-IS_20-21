#pragma once
#include "Technology.h"

class Computer : public Technology
{
public:
	Computer();
	Computer(const char*, double, double);
	void setCapacity(double _capacity);
	Type getType() const override;

	void printTechnology() const override;
private:
	double capacity;
};
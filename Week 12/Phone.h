#pragma once
#include "Technology.h"

class Phone : public Technology
{
public:
	Phone();
	Phone(const char*, double, double, size_t);

	void setScreenSize(double);
	void setMemory(size_t);
	Type getType() const override;

	void printTechnology() const override;
private:
	double screenSize;
	size_t memory;
};
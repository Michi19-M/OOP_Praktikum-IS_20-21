#pragma once
#include "Technology.h"

class Laptop : public Technology
{
public:
	Laptop();
	Laptop(const char*, double, double, size_t);
	void setScreenSize(double scrSz);
	void setRam(size_t _ram);
	Type getType() const override;

	void printTechnology() const override;
private:
	double screenSize;
	size_t ram;
};
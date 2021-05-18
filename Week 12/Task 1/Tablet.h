#pragma once
#include "Technology.h"

class Tablet : public Technology
{
public:
	Tablet();
	Tablet(const char*, double, double, double, size_t);

	void setScreenSize(double);
	void setWidth(double);
	void setNumberOfCores(size_t);

	Type getType() const override;
	void printTechnology() const override;
private:
	double screenSize;
	double width;
	size_t numberOfCores;
};
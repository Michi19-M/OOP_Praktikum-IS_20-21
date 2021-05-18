#pragma once
#include "Vector.h"
#include "Laptop.h"
#include "Computer.h"
#include "Tablet.h"
#include "Phone.h"

class TechShop
{
public:
	void addTech(Technology* other);

	void lowerComputerPrices(double n);
	void lowerTabletPrices(double n);
	void lowerPhonePrices(double n);

	void printAllTechnologies() const;
private:
	Vector<Technology*> technologies;

	bool validPercentage(double n);
	double calculatePercentage(double finalPrice, double n);
	void calculateDiscount(double n, Type type);
};
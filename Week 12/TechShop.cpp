#include "TechShop.h"

void TechShop::printAllTechnologies() const
{
	for (size_t i = 0; i < technologies.getSize(); i++)
	{
		technologies[i]->printTechnology();
		std::cout << std::endl;
	}
}

bool TechShop::validPercentage(double n)
{
	return n >= 0 && n <= 100;
}

double TechShop::calculatePercentage(double finalPrice, double n)
{
	finalPrice = finalPrice - finalPrice * (n / 100);
	return finalPrice;
}

void TechShop::calculateDiscount(double n, Type type)
{
	if (!validPercentage(n)) {
		std::cout << "Invalid percentage input!\n";
		return;
	}
	for (size_t i = 0; i < technologies.getSize(); i++)
	{
		if (technologies[i]->getType() == type)
		{
			technologies[i]->setPrice(calculatePercentage(technologies[i]->getPrice(), n));
		}
	}
}

void TechShop::addTech(Technology* other)
{
	technologies.addToBack(other);
}

void TechShop::lowerComputerPrices(double n)
{
	calculateDiscount(n, Type::COMPUTER);
}

void TechShop::lowerTabletPrices(double n)
{
	calculateDiscount(n, Type::TABLET);
}

void TechShop::lowerPhonePrices(double n)
{
	calculateDiscount(n, Type::PHONE);
}

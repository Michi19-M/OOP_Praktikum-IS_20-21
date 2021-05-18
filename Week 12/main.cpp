#include "TechShop.h"

int main()
{	
	Technology* tech1 = new Computer("Alienware", 2350, 420);
	Technology* tech2 = new Laptop("Lenovo", 1299.99, 15, 8);
	Technology* tech3 = new Tablet("Huawei", 449.99, 8.4, 7, 6);
	Technology* tech4 = new Phone("Samsung", 750, 5.5, 32);

	TechShop technologies2;
	technologies2.addTech(tech1);
	technologies2.addTech(tech2);
	technologies2.addTech(tech3);
	technologies2.addTech(tech4);

	technologies2.printAllTechnologies();

	technologies2.lowerComputerPrices(20);
	technologies2.lowerTabletPrices(15);
	technologies2.lowerPhonePrices(30);

	std::cout << "After discounts:\n\n";

	technologies2.printAllTechnologies();

	return 0;
}
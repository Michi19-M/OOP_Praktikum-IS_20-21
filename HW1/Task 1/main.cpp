# include <iostream>
#include "Crypto.h"

int main()
{
	Crypto c1;
	c1.setCryptoName("Bitcoin");
	c1.setLastPrice(500);
	c1.setCurrentPrice(400);
	c1.printCrypto();
	std::cout << "Price difference: " << c1.priceDifference() << '%' << std::endl;

	return 0;
}
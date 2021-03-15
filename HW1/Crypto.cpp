#include "Crypto.h"

Crypto::Crypto()
{
	strcpy_s(cryptoName, 2, " ");
	lastPrice = 0;
	currentPrice = 0;
}

Crypto::Crypto(char* other_cryptoName, double other_lastPrice, double other_currentPrice)
{
	strcpy_s(cryptoName, strlen(other_cryptoName) + 1, other_cryptoName);
	other_lastPrice = lastPrice;
	other_currentPrice = currentPrice;
}

double Crypto::priceDifference()
{
	double difference = currentPrice - lastPrice;
	return (difference / lastPrice) * 100;
}

void Crypto::setCryptoName(const char* other_cryptoName)
{
	strcpy_s(cryptoName, strlen(other_cryptoName) + 1, other_cryptoName);
}

void Crypto::setLastPrice(const double other_lastPrice)
{
	lastPrice = other_lastPrice;
}

void Crypto::setCurrentPrice(const double other_currentPrice)
{
	currentPrice = other_currentPrice;
}

const char* Crypto::getCryptoName() const
{
	return cryptoName;
}

double Crypto::getLastPrice() const
{
	return lastPrice;
}

double Crypto::getCurrentPrice() const
{
	return currentPrice;
}

void Crypto::printCrypto()
{
	std::cout << "Crypto name: " << cryptoName << std::endl;
	std::cout << "Last price: " << lastPrice << std::endl;
	std::cout << "Current price: " << currentPrice << std::endl;
}
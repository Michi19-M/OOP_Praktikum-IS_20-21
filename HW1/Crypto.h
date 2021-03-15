#pragma once
#include <iostream>

class Crypto
{
private:
	char cryptoName[31];
	double lastPrice;
	double currentPrice;
public:
	Crypto();
	Crypto(char* other_cryptoName, double other_lastPrice, double other_currentPrice);

	double priceDifference();

	void setCryptoName(const char* other_cryptoName);
	void setLastPrice(const double other_lastPrice);
	void setCurrentPrice(const double other_currentPrice);

	const char* getCryptoName() const;
	double getLastPrice() const;
	double getCurrentPrice() const;

	void printCrypto();
};
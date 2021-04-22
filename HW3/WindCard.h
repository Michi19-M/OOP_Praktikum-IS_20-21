#pragma once
#include "String.h"
#include "CardType.h"

class WindCard
{
public:
	WindCard();
	WindCard(const char*, size_t, size_t);

	void setCardName(const char* name);
	void setStartPower(const size_t power);
	void setBonusPower(const size_t bonus);

	const char* getCardName() const;
	size_t getStartPower() const;
	size_t getBonusPower() const;
	int getCardType() const;

	friend std::ostream& operator<<(std::ostream& out, const WindCard& card);
private:
	String cardName;
	size_t startPower;
	size_t bonusPower;
	CardType cardType;
};
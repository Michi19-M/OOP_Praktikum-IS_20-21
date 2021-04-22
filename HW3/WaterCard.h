#pragma once
#include "String.h"
#include "CardType.h"

class WaterCard
{
public:
	WaterCard();
	WaterCard(const char* other_cardName, size_t other_startPower, size_t other_bonus);

	void setCardName(const char* name);
	void setStartPower(const size_t power);
	void setBonusPower(const size_t bonus);

	const char* getCardName() const;
	size_t getStartPower() const;
	size_t getBonusPower() const;
	int getCardType() const;  // CardType& ???

	friend std::ostream& operator<<(std::ostream& out, const WaterCard& card);
private:
	String cardName;
	size_t startPower;
	size_t bonusPower;
	CardType cardType;
};
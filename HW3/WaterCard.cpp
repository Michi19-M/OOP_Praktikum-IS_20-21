#include "WaterCard.h"

WaterCard::WaterCard()
{
	startPower = 0;
	bonusPower = 0;
	cardType = WATERCARD;
}

WaterCard::WaterCard(const char* other_cardName, size_t other_startPower, size_t other_bonus)
{
	cardName.setString(other_cardName, strlen(other_cardName) + 1, strlen(other_cardName) + 2);
	startPower = other_startPower;
	bonusPower = other_bonus;
	cardType = WATERCARD;
}

void WaterCard::setCardName(const char* name)
{
	cardName.setString(name, strlen(name) + 1, strlen(name) + 2);
}

void WaterCard::setStartPower(const size_t power)
{
	startPower = power;
}

void WaterCard::setBonusPower(const size_t bonus)
{
	bonusPower = bonus;
}

const char* WaterCard::getCardName() const
{
	return cardName.getString();
}

size_t WaterCard::getStartPower() const
{
	return startPower;
}

size_t WaterCard::getBonusPower() const
{
	return bonusPower;
}

int WaterCard::getCardType() const
{
	return cardType;
}

std::ostream& operator<<(std::ostream& out, const WaterCard& card)
{
	out << "Card name: " << card.cardName.getString() << std::endl;
	out << "Card start power: " << card.getStartPower() << std::endl;
	out << "Card bonus power: " << card.getBonusPower() << std::endl;
	out << "Card type: " << card.getCardType() << std::endl;

	return out;
}

#include "EarthCard.h"

EarthCard::EarthCard()
{
	startPower = 0;
	bonusPower = 0;
	cardType = EARTHCARD;
}

EarthCard::EarthCard(const char* other_cardName, size_t other_stPower, size_t other_bonusPower)
{
	cardName.setString(other_cardName, strlen(other_cardName) + 1, strlen(other_cardName) + 2);
	startPower = other_stPower;
	bonusPower = other_bonusPower;
	cardType = EARTHCARD;
}

void EarthCard::setCardName(const char* name)
{
	cardName.setString(name, strlen(name) + 1, strlen(name) + 2);
}

void EarthCard::setStartPower(const size_t power)
{
	startPower = power;
}

void EarthCard::setBonusPower(const size_t bonus)
{
	bonusPower = bonus;
}

const char* EarthCard::getCardName() const
{
	return cardName.getString();
}

size_t EarthCard::getStartPower() const
{
	return startPower;
}

size_t EarthCard::getBonusPower() const
{
	return bonusPower;
}

int EarthCard::getCardType() const
{
	return cardType;
}

std::ostream& operator<<(std::ostream& out, const EarthCard& card)
{
	out << "Card name: " << card.cardName.getString() << std::endl;
	out << "Card start power: " << card.getStartPower() << std::endl;
	out << "Card bonus power: " << card.getBonusPower() << std::endl;
	out << "Card type: " << card.getCardType() << std::endl;

	return out;
}

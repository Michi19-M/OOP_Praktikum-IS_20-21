#include "WindCard.h"

WindCard::WindCard()
{
	startPower = 0;
	bonusPower = 0;
	cardType = WINDCARD;
}

WindCard::WindCard(const char* other_cardName, size_t other_stPower, size_t other_bonusPower)
{
	cardName.setString(other_cardName, strlen(other_cardName) + 1, strlen(other_cardName) + 2);
	startPower = other_stPower;
	bonusPower = other_bonusPower;
	cardType = WINDCARD;
}

void WindCard::setCardName(const char* name)
{
	cardName.setString(name, strlen(name) + 1, strlen(name) + 2);
}

void WindCard::setStartPower(const size_t power)
{
	startPower = power;
}

void WindCard::setBonusPower(const size_t bonus)
{
	bonusPower = bonus;
}

const char* WindCard::getCardName() const
{
	return cardName.getString();
}

size_t WindCard::getStartPower() const
{
	return startPower;
}

size_t WindCard::getBonusPower() const
{
	return bonusPower;
}

int WindCard::getCardType() const
{
	return cardType;
}

std::ostream& operator<<(std::ostream& out, const WindCard& card)
{
	out << "Card name: " << card.cardName.getString() << std::endl;
	out << "Card start power: " << card.getStartPower() << std::endl;
	out << "Card bonus power: " << card.getBonusPower() << std::endl;
	out << "Card type: " << card.getCardType() << std::endl;

	return out;
}

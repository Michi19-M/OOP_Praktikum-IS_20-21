#include "FireCard.h"

FireCard::FireCard()
{
	startPower = 0;
	bonusPower = 0;
	cardType = FIRECARD;
}

FireCard::FireCard(const char* other_cardName, size_t other_stPower, size_t other_bonusPower)
{
	cardName.setString(other_cardName, strlen(other_cardName) + 1, strlen(other_cardName) + 2);
	startPower = other_stPower;
	bonusPower = other_bonusPower;
	cardType = FIRECARD;
}

void FireCard::setCardName(const char* name)
{
	cardName.setString(name, strlen(name) + 1, strlen(name) + 2);
}

void FireCard::setStartPower(const size_t power)
{
	startPower = power;
}

void FireCard::setBonusPower(const size_t bonus)
{
	bonusPower = bonus;
}

const char* FireCard::getCardName() const
{
	return cardName.getString();
}

size_t FireCard::getStartPower() const
{
	return startPower;
}

size_t FireCard::getBonusPower() const
{
	return bonusPower;
}

int FireCard::getCardType() const
{
	return cardType;
}

std::ostream& operator<<(std::ostream& out, const FireCard& card)
{
	out << "Card name: " << card.cardName.getString() << std::endl;
	out << "Card start power: " << card.getStartPower() << std::endl;
	out << "Card bonus power: " << card.getBonusPower() << std::endl;
	out << "Card type: " << card.getCardType() << std::endl;

	return out;
}

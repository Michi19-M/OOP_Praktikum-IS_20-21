#include "Game.h"

Game::Game(const Player<WaterCard, FireCard, EarthCard, WindCard>& other_p1, const Player<WaterCard, FireCard, EarthCard, WindCard>& other_p2)
{
	p1.setPlayer(other_p1);
	p2.setPlayer(other_p2);
}

void Game::action()
{
	while (p1.getWins() < 5 || p2.getWins() < 5)
	{
		size_t firstPlayerPower = 0;
		size_t secondPlayerPower = 0;
		
		if (counteredCards())
		{
			firstPlayerPower = p1.getFirstDeck().drawCard().getStartPower() + p1.getFirstDeck().drawCard().getBonusPower();
			secondPlayerPower = p2.getSecondDeck().drawCard().getStartPower() + p2.getSecondDeck().drawCard().getBonusPower();
			if (firstPlayerPower > secondPlayerPower)
			{
				++p1;
			}
			if (secondPlayerPower < firstPlayerPower)
			{
				++p2;
			}
		}
		else
		{
			firstPlayerPower = p1.getFirstDeck().drawCard().getStartPower();
			secondPlayerPower = p2.getSecondDeck().drawCard().getStartPower();
			if (firstPlayerPower > secondPlayerPower)
			{
				++p1;
			}
			if (secondPlayerPower < firstPlayerPower)
			{
				++p2;
			}
		}
	}

	if (p1.getWins() >= 5)
	{
		std::cout << "Player1 WINS!\n";
	}
	else
	{
		std::cout << "Player2 WINS!\n";
	}
}

bool Game::counteredCards() const
{
	if ((p1.getFirstDeck().getDeck().getCardType() == 2 && p2.getSecondDeck().getDeck().getCardType() == 4) || (p1.getFirstDeck().getDeck().getCardType() == 4 && p2.getSecondDeck().getDeck().getCardType() == 2))
	{
		return true;
	}
	if ((p1.getFirstDeck().getDeck().getCardType() == 1 && p2.getSecondDeck().getDeck().getCardType() == 2) || (p1.getFirstDeck().getDeck().getCardType() == 2 && p2.getSecondDeck().getDeck().getCardType() == 1))
	{
		return true;
	}
	if ((p1.getFirstDeck().getDeck().getCardType() == 3 && p2.getSecondDeck().getDeck().getCardType() == 1) || (p1.getFirstDeck().getDeck().getCardType() == 1 && p2.getSecondDeck().getDeck().getCardType() == 3))
	{
		return true;
	}
	if ((p1.getFirstDeck().getDeck().getCardType() == 4 && p2.getSecondDeck().getDeck().getCardType() == 3) || (p1.getFirstDeck().getDeck().getCardType() == 3 && p2.getSecondDeck().getDeck().getCardType() == 4))
	{
		return true;
	}
	return false;
}

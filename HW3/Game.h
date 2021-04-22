#pragma once
#include "Player.h"

class Game
{
public:
	Game(const Player<WaterCard, FireCard, EarthCard, WindCard>& other_p1, const Player<WaterCard, FireCard, EarthCard, WindCard>& other_p2);

	void action();
	bool counteredCards() const;
private:
	Player<WaterCard, FireCard, EarthCard, WindCard> p1;
	Player< WaterCard, FireCard, EarthCard, WindCard> p2;
};
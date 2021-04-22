#include <iostream>
#include "Game.h"

int main()
{
	WaterCard Poseidon("Poseidon", 220, 80);
	WaterCard Nereids("Nereids", 90, 150);
	WaterCard Kraken("Kraken", 180, 95);

	FireCard Ragnaros("Ragnaros", 300, 50);
	FireCard Dragon("Dragon", 130, 95);
	FireCard Phoenix("Phoenix", 190, 80);

	EarthCard Golem("Golem", 100, 75);
	EarthCard Botanikin("Botanikin", 240, 65);
	EarthCard Troll("Troll", 85, 190);

	WindCard Griffin("Griffin", 165, 100);
	WindCard Gargoyle("Gargoyle", 170, 80);
	WindCard Fairies("Fairies", 70, 135);

	Deck<WaterCard> deck1;
	deck1.addCard(Poseidon);
	deck1.addCard(Nereids);
	deck1.addCard(Kraken);

	Deck<FireCard> deck2;
	deck2.addCard(Ragnaros);
	deck2.addCard(Dragon);
	deck2.addCard(Phoenix);

	Deck<EarthCard> deck3;
	deck3.addCard(Botanikin);
	deck3.addCard(Troll);
	deck3.addCard(Golem);

	Deck<WindCard> deck4;
	deck4.addCard(Griffin);
	deck4.addCard(Gargoyle);
	deck4.addCard(Fairies);

	Player<WaterCard, FireCard, EarthCard, WindCard> p1("Martin", 0, 0, deck1, deck2);
	p1.savePlayer("test.txt");
	p1.loadPlayer("test.txt");

	Player<WaterCard, FireCard, EarthCard, WindCard> p2("Ivan", 0, 0, deck4, deck3);

	Game game1(p1, p2);

	return 0;
}
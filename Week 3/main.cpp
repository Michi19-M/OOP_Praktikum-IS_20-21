#include <iostream>
#include "Location.h"
#include "Map.h"

int main()
{
	Location l1;
	l1.setLocationName("Kyustendil");
	l1.setCoordX(9);
	l1.setCoordY(5);
	l1.printLocation();

	std::cout << std::endl;

	Location l2;
	l2.printLocation();

	Location l3 = l1;

	Location l4;
	l4.setLocationName("Varna");
	l4.setCoordX(7);
	l4.setCoordY(11);

	std::cout << std::endl;

	Map map;
	map.addLocation(l1);
	map.addLocation(l2);
	map.addLocation(l3);
	map.addLocation(l4);
	map.printMap();

	std::cout << "Distance: " << map.distance(0, 3) <<'\n' << '\n';

	map.getShortestDistance(3);

	return 0;
}
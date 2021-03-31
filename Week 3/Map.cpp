#include "Map.h"

Map::Map()
{
	capacity = 3;
	size = 0;
	locations = new Location[capacity];
}

Map::Map(const Map& other)
{
	copy(other);
}

Map& Map::operator=(const Map& other)
{
	if (this != &other)
	{
		delete[] locations;
		copy(other);
	}
	return *this;
}

Map::~Map()
{
	delete[] locations;
}

void Map::addLocation(const Location& newLocation)
{
	if (size >= capacity)
	{
		resize();
	}
	locations[size++] = newLocation;
}

void Map::printMap() const
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << i + 1 << ". ";
		locations[i].printLocation();
		std::cout << std::endl;
	}
}

double Map::distance(size_t firstIndex, size_t secondIndex)
{
	double differenceOfCoordinatesX = pow(locations[secondIndex].getCoordX() - locations[firstIndex].getCoordX(), 2);
	double differenceOfCoordinatesY = pow(locations[secondIndex].getCoordY() - locations[firstIndex].getCoordY(), 2);
	return sqrt(differenceOfCoordinatesX + differenceOfCoordinatesY);
}

void Map::getShortestDistance(size_t index)
{
	double shortestDistance = distance(0, index);
	size_t indexOfShortestDistance = 0;
	for (size_t i = 1; i < size; i++)
	{
		if (i != index)		// за да не мери дистанцията със себе си
		{
			if (distance(i, index) < shortestDistance)
			{
				shortestDistance = distance(i, index);
				indexOfShortestDistance = i;
			}
		}
	}
	std::cout << "Shortest distance of locations to " << locations[index].getLocationName() << " is " << locations[indexOfShortestDistance].getLocationName() << " and is " << shortestDistance << "km away!\n";
}

void Map::copy(const Map& other)
{
	size = other.size;
	capacity = other.capacity;
	locations = new Location[capacity];
	for (size_t i = 0; i < other.size; i++)
	{
		locations[i] = other.locations[i];
	}
}

void Map::resize()
{
	capacity *= 2;
	Location* temp = new Location[capacity];
	for (size_t i = 0; i < size; i++)
	{
		temp[i] = locations[i];
	}
	delete[] locations;
	locations = temp;
}

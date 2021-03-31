#pragma once
#include <iostream>
#include "Location.h"

class Map
{
public:
	Map();
	Map(const Map& other);
	Map& operator=(const Map& other);
	~Map();
	
	void addLocation(const Location& newLocation);
	void printMap() const;

	double distance(size_t firstIndex, size_t secondIndex);
	void getShortestDistance(size_t index);
private:
	Location* locations;
	size_t size;
	size_t capacity;

	void copy(const Map& other);
	void resize();
};
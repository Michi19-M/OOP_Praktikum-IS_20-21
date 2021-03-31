#pragma once
#include <iostream>

class Location
{
public:
	Location();
	Location(const Location& other);
	Location& operator=(const Location& other);
	~Location();

	void setLocationName(const char* other_name);
	void setCoordX(double other_coordX);
	void setCoordY(double other_coordY);

	const char* getLocationName() const;
	double getCoordX() const;
	double getCoordY() const;

	void printLocation() const;
private:
	char* locationName;
	double coordX;
	double coordY;

	void copy(const Location& other);
	void erase();
};

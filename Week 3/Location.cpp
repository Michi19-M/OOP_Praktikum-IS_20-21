#include "Location.h"

Location::Location()
{
	locationName = new char[6];
	strcpy_s(locationName, 6, "Empty");
	coordX = 0;
	coordY = 0;
}

Location::Location(const Location& other)
{
	copy(other);
}

Location& Location::operator=(const Location& other)
{
	if (this != &other)
	{
		this->erase();
		this->copy(other);
	}
	return *this;
}

Location::~Location()
{
	this->erase();
}

void Location::setLocationName(const char* other_name)
{
	delete[] this->locationName;
	this->locationName = new char[strlen(other_name) + 1];
	strcpy_s(this->locationName, strlen(other_name) + 1, other_name);
}

void Location::setCoordX(double other_coordX)
{
	this->coordX = other_coordX;
}

void Location::setCoordY(double other_coordY)
{
	this->coordY = other_coordY;
}

const char* Location::getLocationName() const
{
	return this->locationName;
}

double Location::getCoordX() const
{
	return this->coordX;
}

double Location::getCoordY() const
{
	return this->coordY;
}

void Location::printLocation()
{
	std::cout << "Location: " << this->locationName << "\n";
	std::cout << "Coord X: " << this->coordX << '\n';
	std::cout << "Coord Y: " << this->coordY << '\n';
}

void Location::copy(const Location& other)
{
	locationName = new char[strlen(other.locationName) + 1];
	strcpy_s(locationName, strlen(other.locationName) + 1, other.locationName);
	coordX = other.coordX;
	coordY = other.coordY;
}

void Location::erase()
{
	delete[] locationName;
}

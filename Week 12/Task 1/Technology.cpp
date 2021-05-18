#include "Technology.h"

int Technology::id_counter = 1000;

Technology::Technology()
{
	name = new char[1];
	name[0] = '\0';
	price = 0;
	id = id_counter;
	id_counter++;
}

Technology::Technology(const Technology& other)
{
	copy(other);
}

Technology& Technology::operator=(const Technology& other)
{
	if (this != &other)
	{
		delete[] name;
		copy(other);
	}
	return *this;
}

Technology::~Technology()
{
	delete[] name;
}

Technology::Technology(const char* _name, double _price)
{
	id = id_counter;
	id_counter++;
	price = _price;
	delete[] name;
	name = new char[strlen(_name) + 1];
	strcpy_s(name, strlen(_name) + 1, _name);
}

void Technology::setPrice(double _price)
{
	price = _price;
}

double Technology::getPrice() const
{
	return price;
}

void Technology::copy(const Technology& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy_s(name, strlen(other.name) + 1, other.name);
	price = other.price;
}
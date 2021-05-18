#include "Laptop.h"

Laptop::Laptop() : Technology()
{
	screenSize = 0;
	ram = 0;
	Type::LAPTOP;
}

Laptop::Laptop(const char* _name, double _price, double _scrSz, size_t _ram) : Technology(_name, _price)
{
	screenSize = _scrSz;
	ram = _ram;
	Type::LAPTOP;
}

void Laptop::setScreenSize(double scrSz)
{
	screenSize = scrSz;
}

void Laptop::setRam(size_t _ram)
{
	ram = _ram;
}

Type Laptop::getType() const
{
	return Type::LAPTOP;
}

void Laptop::printTechnology() const
{
	std::cout << "Laptop: " << Technology::name << std::endl;
	std::cout << "ID: " << Technology::id << std::endl;
	std::cout << "RAM: " << ram << " GB\n";
	std::cout << "Screen size: " << screenSize << std::endl;
	std::cout << "Price: " << Technology::price << " lv\n";
}

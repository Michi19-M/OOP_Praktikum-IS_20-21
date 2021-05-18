#include "Tablet.h"

Tablet::Tablet() : Technology()
{
	screenSize = 0;
	width = 0;
	numberOfCores = 0;
	Type::TABLET;
}

Tablet::Tablet(const char* _name, double _price, double _scrSz, double _width, size_t _cores) : Technology(_name, _price)
{
	screenSize = _scrSz;
	width = _width;
	numberOfCores = _cores;
	Type::TABLET;
}

void Tablet::setScreenSize(double _screen)
{
	screenSize = _screen;
}

void Tablet::setWidth(double _width)
{
	width = _width;
}

void Tablet::setNumberOfCores(size_t _cores)
{
	numberOfCores = _cores;
}

Type Tablet::getType() const
{
	return Type::TABLET;
}

void Tablet::printTechnology() const
{
	std::cout << "Tablet: " << Technology::name << std::endl;
	std::cout << "ID: " << Technology::id << std::endl;
	std::cout << "Screen size: " << screenSize << std::endl;
	std::cout << "Width: " << width << " mm\n";
	std::cout << "Number of cores: " << numberOfCores << std::endl;
	std::cout << "Price: " << Technology::price << " lv\n";
}

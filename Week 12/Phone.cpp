#include "Phone.h"

Phone::Phone() :Technology()
{
	screenSize = 0;
	memory = 0;
	Type::PHONE;
}

Phone::Phone(const char* _name, double _price, double _screen, size_t _memory) : Technology(_name, _price)
{
	screenSize = _screen;
	memory = _memory;
	Type::PHONE;
}

void Phone::setScreenSize(double _screen)
{
	screenSize = _screen;
}

void Phone::setMemory(size_t _memory)
{
	memory = _memory;
}

Type Phone::getType() const
{
	return Type::PHONE;
}

void Phone::printTechnology() const
{
	std::cout << "Phone: " << Technology::name << std::endl;
	std::cout << "ID: " << Technology::id << std::endl;
	std::cout << "Screen size: " << screenSize << std::endl;
	std::cout << "Memory: " << memory << " GB\n";
	std::cout << "Price: " << Technology::price << " lv\n";
}

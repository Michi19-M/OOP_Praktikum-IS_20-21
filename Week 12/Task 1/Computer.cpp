#include "Computer.h"

Computer::Computer() : Technology()
{
	capacity = 0;
	Type::COMPUTER;
}

Computer::Computer(const char* _name, double _price, double _capacity) : Technology(_name, _price)
{
	capacity = _capacity;
	Type::COMPUTER;
}

void Computer::setCapacity(double _capacity)
{
	capacity = _capacity;
}

Type Computer::getType() const
{
	return Type::COMPUTER;
}

void Computer::printTechnology() const
{
	std::cout << "Computer: " << Technology::name << std::endl;
	std::cout << "ID: " << Technology::id << std::endl;
	std::cout << "Capacity to need on the desk: " << capacity << " sq.cm\n";
	std::cout << "Price: " << Technology::price << " lv\n";
}

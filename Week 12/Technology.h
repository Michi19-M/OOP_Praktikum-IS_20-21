#pragma once
#include <iostream>

enum class Type { PHONE, TABLET, COMPUTER, LAPTOP };

class Technology
{
public:
	Technology();
	Technology(const Technology& other);
	Technology& operator=(const Technology& other);
	~Technology();

	Technology(const char*, double);

	void setPrice(double _price);

	double getPrice() const;
	virtual Type getType() const = 0;

	virtual void printTechnology() const = 0;
protected:
	char* name;
	double price;
	int id;
private:
	static int id_counter;
	void copy(const Technology& other);
};
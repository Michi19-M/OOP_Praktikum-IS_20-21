#include <iostream>
#include "Rational.h"

int main()
{
	Rational r1;
	r1.setNumerator(3);
	r1.setDenominator(2);
	r1.printRational();

	Rational r2(9, 4);
	r2.printRational();

	std::cout << r1.operator+(r2) << std::endl;
	std::cout << r2.operator-(r1) << std::endl;
	std::cout << r1.operator*(r2) << std::endl;
	std::cout << r2.operator/(r1) << std::endl;
	std::cout << std::boolalpha << r2.operator>=(r1) << std::endl;
	std::cout << std::boolalpha << r2.operator<=(r1) << std::endl;
	std::cout << std::boolalpha << r1.operator==(r2) << std::endl;
	std::cout << std::boolalpha << r1.operator!=(r2) << std::endl;

	r1.operator+=(r2);

	return 0;
}
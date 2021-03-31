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

	std::cout << std::boolalpha << r2.operator>=(r1) << std::endl;
	std::cout << std::boolalpha << r2.operator<=(r1) << std::endl;
	std::cout << std::boolalpha << r1.operator==(r2) << std::endl;
	std::cout << std::boolalpha << r1.operator!=(r2) << std::endl;

	Rational r3 = r1 * r2;
	r3.printRational();

	Rational r4;
	r4 = r1 + r2;
	r4.printRational();

	Rational r5 = r1 - r2;
	r5.printRational();

	Rational r6 = r1 / r2;
	r6.printRational();

	r6 /= r1;
	r6.printRational();

	Rational r7;
	r7 = r1 * r2;
	r7.printRational();

	return 0;
}
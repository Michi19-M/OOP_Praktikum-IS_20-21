#include "Rational.h"

double Rational::makeItRational(const Rational& other)
{
	return (double)other.numerator / other.denominator;
}

Rational::Rational()
{
	numerator = 0;
	denominator = 1;
}

Rational::Rational(int other_numerator, int other_denominator)
{
	numerator = other_numerator;
	denominator = other_denominator;
}

void Rational::setNumerator(int other_numerator)
{
	numerator = other_numerator;
}

void Rational::setDenominator(int other_denominator)
{
	denominator = other_denominator;
}

int Rational::getNumerator() const
{
	return numerator;
}

int Rational::getDenominator() const
{
	return denominator;
}

void Rational::printRational() const
{
	std::cout << "Rational number: " << (double)numerator / denominator << std::endl;
}

double Rational::operator+(const Rational other)
{
	return makeItRational(*this) + makeItRational(other);
}

double Rational::operator-(const Rational other)
{
	return makeItRational(*this) - makeItRational(other);
}

double Rational::operator*(const Rational other)
{
	return makeItRational(*this) * makeItRational(other);
}

double Rational::operator/(const Rational other)
{
	return makeItRational(*this) / makeItRational(other);
}

bool Rational::operator>=(const Rational other)
{
	return makeItRational(*this) >= makeItRational(other);
}

bool Rational::operator<=(const Rational other)
{
	return makeItRational(*this) <= makeItRational(other);
}

bool Rational::operator==(const Rational other)
{
	return makeItRational(*this) == makeItRational(other);
}

bool Rational::operator!=(const Rational other)
{
	return makeItRational(*this) != makeItRational(other);
}

Rational& Rational::operator=(const Rational& other)
{
	if (*this != other)
	{
		numerator = other.numerator;
		denominator = other.denominator;
	}
	return *this;
}

Rational& Rational::operator+=(const Rational& other)
{
	this->operator+(other);
	return *this;
}

Rational& Rational::operator-=(const Rational& other)
{
	this->operator-(other);
	return *this;
}

Rational& Rational::operator*=(const Rational& other)
{
	this->operator*(other);
	return *this;
}

Rational& Rational::operator/=(const Rational& other)
{
	this->operator/(other);
	return *this;
}

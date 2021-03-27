#pragma once
#include <iostream>

class Rational
{
private:
	int numerator;		// числител
	int denominator;	// знаменател

	double makeItRational(const Rational& other);
public:
	Rational();
	Rational(int other_numerator, int other_denominator);

	void setNumerator(int other_numerator);
	void setDenominator(int other_denominator);

	int getNumerator() const;
	int getDenominator() const;

	void printRational() const;

	double operator+(const Rational other);
	double operator-(const Rational other);
	double operator*(const Rational other);
	double operator/(const Rational other);

	bool operator>=(const Rational other);
	bool operator<=(const Rational other);
	bool operator==(const Rational other);
	bool operator!=(const Rational other);

	Rational& operator=(const Rational& other);

	Rational& operator+=(const Rational& other);
	Rational& operator-=(const Rational& other);
	Rational& operator*=(const Rational& other);
	Rational& operator/=(const Rational& other);
};
//Fraction Header Code V0.1
//TODO: Add comments


#pragma once
#include <iostream>
#include <numeric>


class Fraction
{
public:
	Fraction();
	Fraction(int num, int den);

	bool isEqualTo(Fraction& right) { return *(this) == right; };
	Fraction addedTo(Fraction& right) { return *(this) + right; };
	Fraction subtract(Fraction& right) { return *(this) - right; };
	Fraction multipliedBy(Fraction& right) { return *(this) * right; };
	Fraction dividedBy(Fraction& right) { return *(this) / right; };
	int getNumerator() { return Numerator; };
	int getDenominator() { return Denominator; };
	void print() { std::cout << *(this); };
	void setNumerator(int num) { Numerator = num; };
	void setDenominator(int den) { Denominator = den; };

private:
	friend std::ostream& operator<< (std::ostream& out, Fraction& frac);
	Fraction operator+ (Fraction& right);
	Fraction operator- (Fraction& right);
	Fraction operator* (Fraction& right);
	Fraction operator/ (Fraction& right);
	bool    operator== (Fraction& right);
	int Numerator;
	int Denominator;

};


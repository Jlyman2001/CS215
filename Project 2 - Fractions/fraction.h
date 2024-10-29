//Fraction Header Code V0.1
//TODO: Add comments


#pragma once
#include <iostream>
#include <numeric>
#include <assert.h>

class Fraction
{
public:
	Fraction();
	Fraction(int num, int den);

	bool isEqualTo(Fraction& right) const { return *(this) == right; };
	Fraction addedTo(Fraction& right) { return *(this) + right; };
	Fraction subtract(Fraction& right) { return *(this) - right; };
	Fraction multipliedBy(Fraction& right) { return *(this) * right; };
	Fraction dividedBy(Fraction& right) { return *(this) / right; };
	int getNumerator() const { return Numerator; };
	int getDenominator() const { return Denominator; };
	void print() const { std::cout << *(this); };
	void setNumerator(int num) { Numerator = num; };
	void setDenominator(int den) { Denominator = den; };
	bool    operator== (const Fraction& right) const;
	Fraction operator= (const Fraction& right);
	Fraction simplify();

private:
	friend std::ostream& operator<< (std::ostream& out, const Fraction& frac);
	Fraction operator+ (Fraction& right);
	Fraction operator- (Fraction& right);
	Fraction operator* (Fraction& right);
	Fraction operator/ (Fraction& right);
	int Numerator;
	int Denominator;

};


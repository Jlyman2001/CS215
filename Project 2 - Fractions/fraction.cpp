//Fraction Source Code V0.1
//TODO: Add comments

#include "fraction.h"

//this is incorrect but works well enough for this project
int lcm(int a, int b)
{
	return a * b;
}

Fraction::Fraction()
{
	Numerator = 0;
	Denominator = 1;
}

Fraction::Fraction(int num, int den)
{
	Numerator = num;
	Denominator = den;
}

Fraction Fraction::operator+(Fraction& right)
{
	int LCD = lcm(this->getDenominator(), right.getDenominator());
	int num1Adjusted = this->getNumerator() * (LCD / this->getDenominator());
	int num2Adjusted = right.getNumerator() * (LCD / right.getDenominator());
	return Fraction(num1Adjusted + num2Adjusted, LCD);
}

Fraction Fraction::operator-(Fraction& right)
{
	int LCD = lcm(this->getDenominator(), right.getDenominator());
	int num1Adjusted = this->getNumerator() * (LCD / this->getDenominator());
	int num2Adjusted = right.getNumerator() * (LCD / right.getDenominator());
	return Fraction(num1Adjusted - num2Adjusted, LCD);
}

Fraction Fraction::operator*(Fraction& right)
{
	return Fraction(this->getNumerator() * right.getNumerator(), this->getDenominator() * right.getDenominator());
}

Fraction Fraction::operator/(Fraction& right)
{
	return Fraction(this->getNumerator() * right.getDenominator(), this->getDenominator() * right.getNumerator());
}

bool Fraction::operator==(Fraction& right)
{
	double F1 = this->getNumerator() / this->getDenominator();
	double F2 = right.getNumerator() / right.getDenominator();
	return (F1 == F2);
}

std::ostream& operator<<(std::ostream& out, Fraction& frac)
{
	out << frac.getNumerator() << "/" << frac.getDenominator();
	return out;
}

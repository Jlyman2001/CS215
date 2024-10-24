//Fraction Source Code V0.1
//TODO: Add comments

#include "fraction.h"


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

/*const*/ Fraction Fraction::operator+ (/*const*/ Fraction& right) 
{
	//find common denominator between the two fractions
	int commonDenominator = this->getDenominator() * right.getDenominator();

	//multiply fraction 1 numerator by common denominator divided by fraction 1 den
	//this adjusts the numerator to be scaled properly
	int num1Adjusted = this->getNumerator() * (commonDenominator / this->getDenominator());

	//multiply fraction 2 numerator by common denominator divided by fraction 2 den
	//this adjusts the numerator to be scaled properly
	int num2Adjusted = right.getNumerator() * (commonDenominator / right.getDenominator());

	//create new Fraction object as the sum of the two 
	return Fraction(num1Adjusted + num2Adjusted, commonDenominator);
}

/*const*/ Fraction Fraction::operator- ( /*const*/ Fraction& right)
{
	//find common denominator between the two fractions
	int commonDenominator = this->getDenominator() * right.getDenominator();

	//multiply fraction 1 numerator by common denominator divided by fraction 1 den
	//this adjusts the numerator to be scaled properly
	int num1Adjusted = this->getNumerator() * (commonDenominator / this->getDenominator());

	//multiply fraction 2 numerator by common denominator divided by fraction 2 den
	//this adjusts the numerator to be scaled properly
	int num2Adjusted = right.getNumerator() * (commonDenominator / right.getDenominator());

	//create new Fraction object as the difference of the two 
	return Fraction(num1Adjusted - num2Adjusted, commonDenominator);
}

/*const*/ Fraction Fraction::operator*  ( /*const*/ Fraction& right)
{
	//multiply numerator and denominator and return new Fraction with them as parameters
	return Fraction(this->getNumerator() * right.getNumerator(), this->getDenominator() * right.getDenominator());
}

/*const*/ Fraction Fraction::operator/  ( /*const*/ Fraction& right)
{
	//Take advantage of the fact that fraction division is the opposite of multiplication,
	//multiply numerator by denominator and vice versa
	return Fraction(this->getNumerator() * right.getDenominator(), this->getDenominator() * right.getNumerator());
}

/*const*/ bool Fraction::operator==  ( /*const*/ Fraction& right)
{
	double F1 = this->getNumerator() / this->getDenominator();
	double F2 = right.getNumerator() / right.getDenominator();
	return (F1 == F2);
}

std::ostream& operator<<(std::ostream& out, /*const*/ Fraction& frac)
{
	out << frac.getNumerator() << "/" << frac.getDenominator();
	return out;
}

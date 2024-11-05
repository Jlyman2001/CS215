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
	assert(den != 0);
	Numerator = num;
	Denominator = den;
	simplify();
}


Fraction Fraction::operator+(Fraction& right)
{
	int commonDenominator = this->getDenominator() * right.getDenominator();
	int num1Adjusted = this->getNumerator() * (commonDenominator / this->getDenominator());
	int num2Adjusted = right.getNumerator() * (commonDenominator / right.getDenominator());
	Fraction returnVal(num1Adjusted + num2Adjusted, commonDenominator);
	return returnVal.simplify();
}

Fraction Fraction::operator-(Fraction& right)
{
	int commonDenominator = this->getDenominator() *right.getDenominator();
	int num1Adjusted = this->getNumerator() * (commonDenominator / this->getDenominator());
	int num2Adjusted = right.getNumerator() * (commonDenominator / right.getDenominator());
	Fraction returnVal(num1Adjusted - num2Adjusted, commonDenominator);
	return returnVal.simplify();
}

Fraction Fraction::operator*(Fraction& right)
{
	Fraction returnVal(this->getNumerator() * right.getNumerator(), this->getDenominator() * right.getDenominator());
	return returnVal.simplify();
}

Fraction Fraction::operator*(int right)
{
	Fraction returnVal(this->getNumerator() * right, this->getDenominator());
	return returnVal.simplify();
}

Fraction Fraction::operator/(Fraction& right)
{
	Fraction returnVal(this->getNumerator() * right.getDenominator(), this->getDenominator() * right.getNumerator());
	return returnVal.simplify();
}

Fraction Fraction::operator/(int right)
{
	Fraction returnVal(this->getNumerator(), this->getDenominator() * right);
	return returnVal.simplify();
}

bool Fraction::operator==(const Fraction& right) const
{
	double F1 = this->getNumerator() / this->getDenominator();
	double F2 = right.getNumerator() / right.getDenominator();
	return (F1 == F2);
}

Fraction Fraction::operator=(const Fraction& right)
{
	this->Numerator = right.Numerator;
	this->Denominator = right.Denominator;


	return *this;
}

Fraction Fraction::simplify()
{
	int GCF = 1;
	if (Numerator == 0 || Denominator == 1)
	{
		return *this;
	}
	int remainder = 1;
	int smallerValue = (Numerator < Denominator) ? Numerator : Denominator;

	//determine greatest common factor
	for (int value = smallerValue; value > 0; value--)
	{
		//the factor is the greatest common factor if it divides both evenly
		//and also is the largest valued one
		if (Numerator % value == 0 && Denominator % value == 0 && value > GCF)
		{
			GCF = value;
		}
	}

	Numerator /= GCF;
	Denominator /= GCF;
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Fraction& frac)
{
	if (frac.Numerator == 0)
	{
		out << 0;
	}
	else if (frac.Denominator == 1)
	{
		out << frac.Numerator;
	}
	else
	{
		out << frac.getNumerator() << "/" << frac.getDenominator();
	}
	return out;
}

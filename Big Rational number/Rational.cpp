#include "Rational.h"

namespace p2
{
ostream& operator << (ostream& outstream,const Rational& output)
{
	outstream << output.numerator << "/" << output.denominator;
	return outstream;
}
Rational::Rational()
{
	denominator=BigInt(1);
	numerator=BigInt(0);
}
Rational::Rational(int x)
{
	numerator=BigInt(x);
	denominator=BigInt(1);
}
Rational::Rational(const char input[])
{
	numerator=BigInt(input);
	denominator=BigInt(1);
}
Rational::Rational(const char first[],const char second[])
{
	numerator=BigInt(first);
	denominator=BigInt(second);
}
Rational::Rational(BigInt first,BigInt second)
{
	numerator=BigInt(first);
	denominator=BigInt(second);
}
const Rational operator +(const Rational& firstRational,const Rational& secRational)
{
	Rational answer;
	BigInt factor,zero(0);
	answer.numerator=firstRational.numerator*secRational.denominator+secRational.numerator*firstRational.denominator;
	answer.denominator=firstRational.denominator*secRational.denominator;
	if(answer.denominator==zero||answer.numerator==zero)
		return Rational(0);
	return answer;
}

const Rational operator * (const Rational& firstRational,const Rational& secRational)
{
	Rational newone;
	BigInt factor,zero(0);
	newone.numerator=firstRational.numerator*secRational.numerator;
	newone.denominator=firstRational.denominator*secRational.denominator;
	if(newone.numerator==zero||newone.denominator==zero)
		return Rational(0);
	return newone;
}
const Rational operator / (const Rational& firstRational,const Rational& secRational)
{
	Rational newone;
	BigInt factor,zero(0);
	newone.numerator=firstRational.numerator*secRational.denominator;
	newone.denominator=firstRational.denominator*secRational.numerator;
	if(newone.numerator==zero||newone.denominator==zero)
		return Rational(0);
	return newone;
}
const Rational operator -(const Rational& firstRational,const Rational& secRational)
{
	Rational answer;
	BigInt factor,zero;
	answer.numerator=firstRational.numerator*secRational.denominator-secRational.numerator*firstRational.denominator;
	answer.denominator=firstRational.denominator*secRational.denominator;
	if(answer.denominator==zero||answer.numerator==zero)
		return Rational(0);
	return answer;
}
const bool operator ==(const Rational& firstRational,const Rational& secRational)
{
	if(firstRational.numerator==secRational.numerator&&firstRational.denominator==secRational.denominator)
		return 1;
	else
		return 0;
}
const Rational deal(const Rational&  number)
{
	BigInt factor;
	if(number.numerator>number.denominator||number.numerator==number.denominator)
		factor=GCD(number.denominator,number.numerator);
	else
		factor=GCD(number.numerator,number.denominator);
	return Rational(number.numerator/factor,number.denominator/factor);
}

}   // end namespace

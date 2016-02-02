
#include "BigInt.h"
using namespace p3;

namespace p2
{
class Rational
{
	public:
		Rational();
		// let Rational is 0/1
		Rational(int x);
		// let Rational is x/1
		Rational(const char input[]);
		// let input[] become bigint(input[])/1;
		Rational(const char first[],const char second[]);
		// let Rational becom BigInt(first[])/BigInt(second[])
		Rational(BigInt first,BigInt second);
		// let Rational become first/second; 
		friend ostream& operator << (ostream& outstream,const Rational& output);
		//output Rational number
		friend const Rational operator * (const Rational& firstRational,const Rational& secRational);
		friend const Rational operator / (const Rational& firstRational,const Rational& secRational);
		friend const Rational operator + (const Rational& firstRational,const Rational& secRational);
		friend const Rational operator - (const Rational& firstRational,const Rational& secRational);
		friend const bool operator ==(const Rational& firstRational,const Rational& secRational);
		//overloading == such as A==B
		//if firstRational==secRational return 1;else return 0
		friend const Rational deal(const Rational& firstRational);
		// reduction the firstRational
	private:
		BigInt numerator;
		BigInt denominator;
};

}   // end namespace

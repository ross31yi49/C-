#include "Rational.h"
using namespace p2;

namespace p1
{
class Complex{
	public:
		Complex();
		Complex(Rational first,Rational second);
		friend const Complex operator /(const Complex& first,const Complex& second);
		friend istream& operator >> (istream& instream,Complex& input);
		friend ostream& operator << (ostream& outstream,const Complex& output);
	private:
		Rational real;
		Rational empty;
};

}   // end namespace

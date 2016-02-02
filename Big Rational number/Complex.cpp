#include "Complex.h"

namespace p1
{
istream& operator >> (istream& instream,Complex& input)
{
	string data;
	int i,j,walk;
	char firNumerator[5000],secNumerator[5000],firDenominator[5000],secDenominator[5000];
	instream >> data;
	for(walk=0;;walk++)
	{
		if(data[walk]=='/')
			break;
		firNumerator[walk]=data[walk];
	}
	firNumerator[walk]='\0';
	for(i=0,walk=walk+1;;walk++,i++)
	{
		if(i!=0&&(data[walk]=='-'||data[walk]=='+'))
			break;
		firDenominator[i]=data[walk];
	}
	firDenominator[i]='\0';
	for(i=0;;walk++,i++)
	{
		if(data[walk]=='+')
		{
			i--;
			continue;
		}
		if(data[walk]=='/')
			break;
		secNumerator[i]=data[walk];
	}
	secNumerator[i]='\0';
	for(i=0,walk=walk+1;;walk++,i++)
	{
		if(data[walk]=='i'||data[walk]=='\0')
			break;
		secDenominator[i]=data[walk];
	}
	secDenominator[i]='\0';
	if(firNumerator[strlen(firNumerator)-1]=='!'||firDenominator[strlen(firDenominator)-1]=='!')
	{
		if(firNumerator[strlen(firNumerator)-1]=='!'&&firDenominator[strlen(firDenominator)-1]!='!')
		{
			firNumerator[strlen(firNumerator)-1]='\0';
			input.real=Rational(hierarchy(firNumerator,"1"),BigInt(firDenominator));
		}
		else if(firNumerator[strlen(firNumerator)-1]!='!'&&firDenominator[strlen(firDenominator)-1]=='!')
		{
			firDenominator[strlen(firDenominator)-1]='\0';
			input.real=Rational(BigInt(firNumerator),hierarchy(firDenominator,"1"));
		}
		else if(firNumerator[strlen(firNumerator)-1]=='!'&&firDenominator[strlen(firDenominator)-1]=='!')
		{
			firNumerator[strlen(firNumerator)-1]='\0';
			firDenominator[strlen(firDenominator)-1]='\0';
			if(absolute(atoi(firNumerator))>absolute(atoi(firDenominator)))
				input.real=Rational(hierarchy(firNumerator,firDenominator),BigInt(1));
			else
				input.real=Rational(BigInt(1),hierarchy(firDenominator,firNumerator));
		}
	}
	else
		input.real=Rational(firNumerator,firDenominator);
	if(secNumerator[strlen(secNumerator)-1]=='!'||secDenominator[strlen(secDenominator)-1]=='!')
	{
		if(secNumerator[strlen(secNumerator)-1]=='!'&&secDenominator[strlen(secDenominator)-1]!='!')
		{
			secNumerator[strlen(secNumerator)-1]='\0';
			input.empty=Rational(hierarchy(secNumerator,"1"),BigInt(secDenominator));
		}
		else if(secNumerator[strlen(secNumerator)-1]!='!'&&secDenominator[strlen(secDenominator)-1]=='!')
		{
			secDenominator[strlen(secDenominator)-1]='\0';
			input.empty=Rational(BigInt(secNumerator),hierarchy(secDenominator,"1"));
		}
		else if(secNumerator[strlen(secNumerator)-1]=='!'&&secDenominator[strlen(secDenominator)-1]=='!')
		{
			secNumerator[strlen(secNumerator)-1]='\0';
			secDenominator[strlen(secDenominator)-1]='\0';
			if(absolute(atoi(secNumerator))>absolute(atoi(secDenominator)))
				input.empty=Rational(hierarchy(secNumerator,secDenominator),BigInt(1));
			else
				input.empty=Rational(BigInt(1),hierarchy(secDenominator,secNumerator));
		}
	}
	else
		input.empty=Rational(secNumerator,secDenominator);
	return instream;
}
ostream& operator << (ostream& outstream,const Complex& output)
{
	outstream << output.real << "+" << output.empty << "i";
	return outstream;
}
Complex::Complex()
{
	real=Rational(0);
	empty=Rational(0);
}
Complex::Complex(Rational first,Rational second)
{
	real=first;
	empty=second;
}
const Complex operator /(const Complex& first,const Complex& second)
{
	Complex ans;
	Rational zero(0),down,upreal,upempty,real,empty;
	down=(second.real*second.real)+(second.empty*second.empty);
	if(down==zero)
	{
		ans.real=Rational(0);
		ans.empty=Rational(0);
		return ans;
	}
	upreal=first.real*second.real+first.empty*second.empty;
	upempty=first.empty*second.real-first.real*second.empty;
	real=upreal/down;
	empty=upempty/down;
	return Complex(deal(real),deal(empty));
}

}       //end namespace

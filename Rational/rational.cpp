// Ä¬­§µ¾ 499410054 5/2/2011
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Rational
{
	public:
		Rational();
		/* initialize 0/1*/
		Rational(int x);
		/* initialize an integer such as x/1 */
		Rational(int x,int y);
		/* initialize a Rational number such as x/y */
		int getNumerator() const;
		/* get Numerator for non-memberfunction */
		int getDenominator()const;
		/* get Denominator for non-memberfunction */
		friend istream& operator >> (istream& instream,Rational& input);
		/* use in "cin" ,it will return Rational object which already read Numerator and Denominator*/
		friend ostream& operator << (ostream& outstream,const Rational& output);
		/* use in "cout",it will output Rational object directly*/
		friend const Rational operator * (const Rational& firstRational,const Rational& secRational);
		/* pass:two Rational object which doing Multiplication*/
		/* return : Rational object which is the result of Multiplication*/
		friend const Rational operator / (const Rational& firstRational,const Rational& secRational);
		/* pass: two Rational object which doing Division*/
		/*return: Rational object which is the result of Division*/
		friend const bool operator == (const Rational& firstRational,const Rational& secRational);
		/*pass two Rational object which comparing for equality*/
		/*if equality return 1,else return 0*/
		const bool operator < (const Rational& secRational)const;
		/*pass two Rational object which comparing for smaller*/
		/*if front is smaller return 1 else return 0*/
		const bool operator <= (const Rational& secRational)const;
		/*pass two Rational object which comparing for smaller or equality*/
		/*if front is smaller or equal than back return 1 else return 0*/
		const bool operator > (const Rational& secRational)const;
        /*pass two Rational object which comparing for bigger*/
        /*if front is bigger than back return 1,else return 0*/ 
		const bool operator >= (const Rational& secRational)const;
		/*pass two Rational object which comparing for bigger or equal*/
		/*if front is bigger or equal than back return 1,else return 0*/
		const int operator [] (int number)const;
		/*pass one Rational object */
		/*if number is 0 return Rational object's Numerator(),number is 1 return Rational object's Denominator()*/

	private:
		int numerator;
		int denominator;
};

int GCD(int smaller,int bigger);
const Rational operator + (const Rational& firstRational,const Rational& secRational);
/*pass:two Rational object which doing Addtion*/
/*return : Rational object which is the result of Addtion */
const Rational operator - (const Rational& firstRational,const Rational& secRational);
/*pass:two Rational object which doing Subtraction*/
/*return : Rational object which is the result of Subtraction */
const Rational operator - (const Rational& Rationalnum);
/*pass: one Rational object*/
/*return : negtive Rational object which pass in */

int main()
{
	Rational firRational;
	Rational secRational;
	int action;
	cout << "Enter first Rational number:\n"; 
	cin >> firRational;
	if(firRational.getDenominator()==0)
	{
		cout << "Denominator can't be Zero\n";
		return 0;
	}
	cout << "Enter second Rational number\n";
	cin >> secRational;
	if(secRational.getDenominator()==0)
	{
		cout << "Denominator can't be Zero\n";
		return 0;
	}
	while(1)
	{
		cout << "-->Please select the operation:\n(1)Add\n(2)Sub\n(3)Mult\n(4)Divide\n(5)Compare\n(6)Negtive\n(7)Overloading[]\n(8)All\n(9)Exit\n";
		cout << "select:";
		cin >> action;
		if(action==9)
			break;
		cout << endl;
		switch(action)
		{
			case 1:
				cout << firRational << "+" << secRational << "=" << firRational+secRational << endl ;
				break;
			case 2:
				cout << firRational << "-" << secRational << "=" << firRational-secRational <<endl ;
				break;
			case 3:
				cout << firRational << "*" << secRational << "=" << firRational*secRational <<endl ;
				break;
			case 4:
				cout << firRational << "/" << secRational << "=" << firRational/secRational <<endl ;
				break;
			case 5:
				if(firRational==secRational)
					cout << firRational << "==" << secRational <<endl ;
				if(firRational>secRational)
					cout << firRational << ">" << secRational <<endl ;
				if(firRational>=secRational)
					cout << firRational << ">=" << secRational <<endl ;
				if(firRational<secRational)
					cout << firRational << "<" << secRational <<endl ;
				if(firRational<=secRational)
					cout << firRational << "<=" << secRational <<endl ;
				break;
			case 6:
				cout << -firRational << endl;
				cout << -secRational << endl;
				break;
			case 7:
				cout << firRational << " firRational[0]=" << firRational[0] << " firRational[1]=" << firRational[1] << endl;
				cout << secRational << " secRational[0]=" << secRational[0] << " secRational[1]=" << secRational[1] << endl;
				break;
			case 8:
				cout << "Add Sub Mult Div:\n";
				cout << firRational << "+" << secRational << "=" << firRational+secRational << endl ;
				cout << firRational << "-" << secRational << "=" << firRational-secRational <<endl ;
				cout << firRational << "*" << secRational << "=" << firRational*secRational <<endl ;
				cout << firRational << "/" << secRational << "=" << firRational/secRational <<endl ;
				cout << "Compare:\n";
				if(firRational==secRational)
					cout << firRational << "==" << secRational <<endl ;
				if(firRational>secRational)
					cout << firRational << ">" << secRational <<endl ;
				if(firRational>=secRational)
					cout << firRational << ">=" << secRational <<endl ;
				if(firRational<secRational)
					cout << firRational << "<" << secRational <<endl ;
				if(firRational<=secRational)
					cout << firRational << "<=" << secRational <<endl ;
				cout << "Negtive:\n";
					cout << -firRational << endl;
				cout << -secRational << endl;
				cout << "Overloading []:\n";
					cout << firRational << " firRational[0]=" << firRational[0] << " firRational[1]=" << firRational[1] << endl;
				cout << secRational << " secRational[0]=" << secRational[0] << " secRational[1]=" << secRational[1] << endl;
				break;
			default:
				continue;
		}
		cout << endl;
	}
	return 0;
}
istream& operator >> (istream& instream,Rational& input)
{
	string intputString;
	char tmp[10];
	int i,j,count=0,number;
	bool negtive=0;
	instream >> intputString;
	for(i=0,j=0;i<intputString.length();i++)
	{
		if(intputString[i]=='-')
			negtive=1;
		if(intputString[i]>='0'&&intputString[i]<='9')
		{
			tmp[j]=intputString[i];
			j++;
		}
		else if(intputString[i]=='/')
		{
			if(negtive==1)
				number=-atoi(tmp);
			else
				number=atoi(tmp);
			j=0;count++;negtive=0;
		}
	}
	if(count==0)
	{
		if(negtive==1)
			input=Rational(-atoi(tmp));
		else
			input=Rational(atoi(tmp));
	}
	else
	{
		if(negtive==1)
			input=Rational(number,-atoi(tmp));
		else
			input=Rational(number,atoi(tmp));
	}
	return instream;
}
ostream& operator << (ostream& outstream,const Rational& output)
{
	outstream << output.numerator << "/" << output.denominator;	
}
Rational::Rational()
{
	denominator=1;
	numerator=0;
}
Rational::Rational(int x)
{
	numerator=x;
	denominator=1;
}
Rational::Rational(int x,int y)
{
	numerator=x;
	denominator=y;
}
int Rational::getNumerator()const
{	return numerator;}
int Rational::getDenominator()const
{	return denominator;}
int GCD(int smaller,int bigger)
{
	if(bigger%smaller==0)
		return smaller;
	else
		return GCD(bigger%smaller,smaller);
}
const Rational operator +(const Rational& firstRational,const Rational& secRational)
{
	int newNumerator,newDenominator,factor;
	newNumerator=firstRational.getNumerator()*secRational.getDenominator()+firstRational.getDenominator()*secRational.getNumerator();
	newDenominator=firstRational.getDenominator()*secRational.getDenominator();
	if(newNumerator==0||newDenominator==0)
		return Rational(0);
	if(newNumerator>=newDenominator)
		factor=GCD(newDenominator,newNumerator);
	else
		factor=GCD(newNumerator,newDenominator);
	if(factor<0)
		factor=-factor;
	return Rational(newNumerator/factor,newDenominator/factor);
}
const Rational operator -(const Rational& firstRational,const Rational& secRational)
{
	int newNumerator,newDenominator,factor;
	newNumerator=firstRational.getNumerator()*secRational.getDenominator()-firstRational.getDenominator()*secRational.getNumerator();
	newDenominator=firstRational.getDenominator()*secRational.getDenominator();
	if(newNumerator==0||newDenominator==0)
		return Rational(0);
	if(newNumerator>=newDenominator)
		factor=GCD(newDenominator,newNumerator);
	else
		factor=GCD(newNumerator,newDenominator);
	if(factor<0)
		factor=-factor;
	return Rational(newNumerator/factor,newDenominator/factor);
}
const Rational operator - (const Rational& Rationalnum)
{
	if((Rationalnum.getNumerator()>0&&Rationalnum.getDenominator()>0)||(Rationalnum.getNumerator()<0&&Rationalnum.getDenominator()<0))
		return Rational(-Rationalnum.getNumerator(),Rationalnum.getDenominator());
	else if(Rationalnum.getNumerator()>0&&Rationalnum.getDenominator()<0)
		return Rational(Rationalnum.getNumerator(),-Rationalnum.getDenominator());
	else if(Rationalnum.getNumerator()<0&&Rationalnum.getDenominator()>0)
		return Rational(-Rationalnum.getNumerator(),Rationalnum.getDenominator());

}
const Rational operator * (const Rational& firstRational,const Rational& secRational)
{
	Rational newone;
	int factor;
	newone.numerator=firstRational.numerator*secRational.numerator;
	newone.denominator=firstRational.denominator*secRational.denominator;
	if(newone.numerator==0||newone.denominator==0)
		return Rational(0);
	if(newone.numerator>=newone.denominator)
		factor=GCD(newone.denominator,newone.numerator);
	else
		factor=GCD(newone.numerator,newone.denominator);
	if(factor<0)
		factor=-factor;
	newone.numerator/=factor;
	newone.denominator/=factor;
	return newone;
}
const Rational operator / (const Rational& firstRational,const Rational& secRational)
{
	Rational newone;
	int factor;
	newone.numerator=firstRational.numerator*secRational.denominator;
	newone.denominator=firstRational.denominator*secRational.numerator;
	if(newone.numerator==0||newone.denominator==0)
		return Rational(0);
	if(newone.numerator>=newone.denominator)
		factor=GCD(newone.denominator,newone.numerator);
	else
		factor=GCD(newone.numerator,newone.denominator);
	if(factor<0)
		factor=-factor;
	newone.numerator/=factor;
	newone.denominator/=factor;
	return newone;
}
const bool operator == (const Rational& firstRational,const Rational& secRational)
{
	if((firstRational.numerator*secRational.denominator)==(firstRational.denominator*secRational.numerator))
		return 1;
	else
		return 0;
}
const bool Rational::operator < (const Rational& secRational)const
{
	if(denominator>0&&secRational.denominator>0&&numerator*secRational.denominator<secRational.numerator*denominator)
		return 1;
	else
		return 0;
}
const bool Rational::operator <= (const Rational& secRational)const
{
	if(denominator>0&&secRational.denominator>0&&numerator*secRational.denominator<=secRational.numerator*denominator)
		return 1;
	else
		return 0;
}
const bool Rational::operator > (const Rational& secRational)const
{
	if(denominator>0&&secRational.denominator>0&&numerator*secRational.denominator>secRational.numerator*denominator)
		return 1;
	else
		return 0;
}
const bool Rational::operator >= (const Rational& secRational)const
{
	if(denominator>0&&secRational.denominator>0&&numerator*secRational.denominator>=secRational.numerator*denominator)
		return 1;
	else
		return 0;
}
const int Rational::operator [] (int number)const
{
	if(number==0)
		return numerator;
	else
		return denominator;
}

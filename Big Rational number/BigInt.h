#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
using namespace std;

namespace p3
{
class BigInt
{
	public:
		BigInt();
		// BigInt is zero
		BigInt(int x);
		//Let a int become to BigInt
		BigInt(const char input[]);
		//Let string become to BigInt
		BigInt(const BigInt& copy);
		// to do deep copy
		~BigInt();
		//distructor
		friend istream& operator >> (istream& instream,BigInt& input);
		// input BigInt
		friend ostream& operator << (ostream& outstream,const BigInt& output);
		//output Bigint
		friend const BigInt operator + (const BigInt& first,const BigInt& second);
		//overloading + such as A+B
		//return BigInt
		friend const BigInt operator - (const BigInt& first,const BigInt& second);
		//overloading - such as A-B
		//return BigInt
		friend const BigInt operator - (const BigInt& change);
		//overloading - ,let A become to -A
		//return BigInt
		friend const BigInt operator * (const BigInt& first,const BigInt& second);
		//overloading * ,such as A*B
		//return BigInt
		friend const BigInt operator / (const BigInt& first,const BigInt& second);
		//overloading / ,such as A/B
		//return BigInt
		friend const BigInt operator % (const BigInt& first,const BigInt& second);
		//overloading % ,such as A%B
		////return BigInt
		friend const bool operator > (const BigInt& first,const BigInt& second);
		//overloading A>B
		//if first>second return 1 else 0
		friend const bool operator < (const BigInt& first,const BigInt& second);
		//overloading A<B
		//if first<second return 1 else 0
		friend const bool operator == (const BigInt& first,const BigInt& second);
		// overloading A==B
		//if first==second return 1 else 0
		BigInt& operator = (const BigInt& right);
		// overloadind A=B
		//return Bigint
		friend const BigInt GCD(const BigInt& small,const BigInt& big);
		// return Common factor of small and big
	private:
		BigInt leftshift(int shiftnumber)const;
		int whichBig(const BigInt& compare) const;
		char* number;
		int length;
		int sign;
};

const BigInt hierarchy(const char start[],const char end[]);
//do the hierarchy from start[] to end[] and return the ans
int absolute(int number);
// absolute number

}   // end namespace

#include "BigInt.h"

namespace p3
{
istream& operator >> (istream& instream,BigInt& input)
{
	int i;
	char string[512];
	instream >> string;
	input=BigInt(string);
	return instream;
}
ostream& operator << (ostream& outstream,const BigInt& output)
{
	int i;
	if(output.sign==1)
		outstream << '-';
	for(i=0;i<output.length;i++)
		outstream << output.number[i];
	return outstream;
}
BigInt::BigInt()
{
	number=new char[2];
	number[0]='0';
	number[1]='\0';
	length=1;
	sign=0;
}
BigInt::BigInt(const char input[])
{
	int i=0,j=0;
	length=strlen(input);
	if(input[0]=='-')
	{
		sign=1;
		i++;
	}
	else
		sign=0;
			number=new char[length+5];
			for(i,j=0;i<length;i++,j++)
				number[j]=input[i];
	if(sign==1)
		length--;
}
BigInt::BigInt(int input)
{
	int i,j;
	char buffer[15];
		number =new char[5000];
	if(input==0)
	{
		length=1;
		number[0]='0';number[1]='\0';
	}
	else
	{
		if(input<0)
		{
			input=-input;
			sign=1;
		}
		else
			sign=0;
		for(i=0;input>0;i++)
		{
			buffer[i]=(input%10)+'0';
			input/=10;
		}
		length=i;
		for(i=length-1,j=0;i>=0;i--,j++)
			number[j]=buffer[i];
		number[j]='\0';
	}
}
BigInt::BigInt(const BigInt& copy)
{
	int i;
		number= new char[5000];
	length=copy.length;
	sign=copy.sign;
	for(i=0;i<length;i++)
		number[i]=copy.number[i];
	number[i]='\0';
}
BigInt::~BigInt()
{
	delete [] number;
}
BigInt& BigInt::operator = (const BigInt& right)
{
	if(this==&right)
		return *this;
			int i;
	length=right.length;
	sign=right.sign;
	delete [] number;
	number = new char[8000];
	for(i=0;i<length;i++)
		number[i]=right.number[i];
			number[i]='\0';
	return *this;
}
const BigInt operator + (const BigInt& first,const BigInt& second)
{
	int newLength,newsign,i,j,k;
	char *ansNum,*temp;
	BigInt answer;
	if(first.sign==1&&second.sign==0)
		return second-(-first);
	else if(first.sign==0&&second.sign==1)
		return first-(-second);
	else
	{
		if(first.length>=second.length)
			newLength=first.length;
		else
			newLength=second.length;
		if(first.sign==0&&second.sign==0)
			newsign=0;
		else if(first.sign==1&&second.sign==1)
			newsign=1;
		temp=new char[newLength+3];
		for(i=0;i<newLength+3;i++)
			temp[i]=0;
		for(i=first.length-1,j=second.length-1,k=0;k<newLength;k++,i--,j--)
		{
			if(i<0)
				temp[k]=temp[k]+second.number[j];
			else if(j<0)
				temp[k]=temp[k]+first.number[i];
			else
				temp[k]=temp[k]+first.number[i]+second.number[j]-'0';
			if(temp[k]>'9')
			{
				temp[k+1]=1;
				temp[k]-=10;
			}
			else
				temp[k+1]=0;
		}
		if(temp[newLength]==1)
		{
			temp[newLength]='1';
			temp[newLength+1]='\0';
			newLength++;
		}
		else
			temp[newLength]='\0';
		if(newsign==1)
		{
			temp[newLength]='-';
			newLength++;
		}
		ansNum=new char[newLength+1];
		for(i=0,j=newLength-1;j>=0;i++,j--)
			ansNum[i]=temp[j];
		ansNum[newLength]='\0';
		answer=BigInt(ansNum);
		delete [] ansNum;
		delete [] temp;
		return answer;
	}
}
int BigInt::whichBig(const BigInt& compare)const
{
	int i;
	if(length>compare.length)
		return 3;
	else if(length<compare.length)
		return 2;
	else if(length==compare.length)
	{
		for(i=0;i<length;i++)
		{
			if(number[i]>compare.number[i])
				return 3;
			else if(number[i]<compare.number[i])
				return 2;
		}
		if(i==length)
			return	4;
	}
}
const BigInt operator - (const BigInt& first,const BigInt& second)
{
	char temp[5000],ansNum[5000];
	int i,j,k,newLength,newsign;
	BigInt answer;
	if(first.sign!=0||second.sign!=0)
		return first+(-second);
	else
	{
		if(first.whichBig(second)>second.whichBig(first))
			newsign=0;
		else if(first.whichBig(second)<second.whichBig(first))
			newsign=1;
		else if(first.whichBig(second)==second.whichBig(first))
			return BigInt();
		if(first.length>=second.length)
			newLength=first.length;
		else
			newLength=second.length;
		for(i=0;i<newLength;i++)
			temp[i]=0;
		for(i=first.length-1,j=second.length-1,k=0;k<newLength;k++,i--,j--)
		{
			if(i<0)
				temp[k]=temp[k]+second.number[j];
			else if(j<0)
				temp[k]=temp[k]+first.number[i];
			else
			{
				if(newsign==0)
					temp[k]=temp[k]+first.number[i]-second.number[j]+'0';
				else
					temp[k]=temp[k]+second.number[j]-first.number[i]+'0';
			}
			if(temp[k]<'0')
			{
				temp[k+1]=-1;
				temp[k]+=10;
			}
			else
				temp[k+1]=0;
		}
		for(i=newLength-1;i>=0;i--)
		{
			if(temp[i]=='0')
			{
				temp[i]='\0';
				newLength--;
			}
			else
				break;
		}
		i=0,j=0;
		if(newsign!=0)
		{
			ansNum[0]='-';
			j++;
		}
		for(i=newLength-1,j;i>=0;i--,j++)
		{
			ansNum[j]=temp[i];
		}
		if(newsign!=0)
			ansNum[newLength+1]='\0';
		else
			ansNum[newLength]='\0';
		answer=BigInt(ansNum);
		return answer;
	}
}
const BigInt operator - (const BigInt& change)
{
	BigInt newone;
	newone=change;
	if(newone.sign==1)
		newone.sign=0;
	else
		newone.sign=1;
	return newone;
}
const BigInt operator * (const BigInt& first,const BigInt& second)
{
	BigInt temp(0),answer(0);
	int i,j,k;
	for(i=0;i<second.length;i++)
	{
		temp=BigInt();
		for(j=0;j<second.number[i]-'0';j++)
			temp=temp+first;
		temp=temp.leftshift(second.length-i-1);
		answer=answer+temp;
	}
	if((first.sign==1&&second.sign==0)||(first.sign==0&&second.sign==1))
		answer.sign=1;
	return answer;
}
const BigInt operator / (const BigInt& first,const BigInt& second)
{
	BigInt dividend(first),divisor,ans;
	char temp[6000];
	int i=0,j,k,weights;
	if(first.whichBig(second)<second.whichBig(first))
		return BigInt(0);
	weights=first.length-second.length;
	if(first.sign==1)
		dividend.sign=0;
	if(second.sign==1)
		divisor.sign=0;
	if((first.sign==1&&second.sign==0)||(first.sign==0&&second.sign==1))
		temp[i++]='-';
	divisor=second.leftshift(weights);
	for(i;;i++)
	{
		if(dividend.whichBig(second)<second.whichBig(dividend))
		{
			for(k=0;k<=weights;k++,i++)
				temp[i]='0';
			break;
		}
		if(dividend.whichBig(divisor)<divisor.whichBig(dividend))
		{
			if((i==0)||(i==1&&(first.sign==1||second.sign==1)))
				i--;
			else
				temp[i]='0';
			weights--;
		}
		else
		{
			for(j=0;;j++)
			{
				if(dividend.whichBig(divisor)<divisor.whichBig(dividend))
					break;
				dividend=dividend-divisor;
			}
			temp[i]=j+'0';
			weights--;
		}
		divisor.number[divisor.length-1]='\0';
		divisor.length--;
	}
	temp[i]='\0';
	ans=BigInt(temp);
	return ans;
}
const BigInt operator % (const BigInt& first,const BigInt& second)
{
	BigInt dividend(first),divisor,ans;
	int i,j,weights;
	if(first.whichBig(second)<second.whichBig(first))
		return dividend;
	weights=first.length-second.length;
	if(first.sign==1)
		dividend.sign=0;
	if(second.sign==1)
		divisor.sign=0;
	divisor=second.leftshift(weights);
	for(i;;i++)
	{
		if(dividend.whichBig(second)<second.whichBig(dividend))
		{
			break;
		}
		if(dividend.whichBig(divisor)<divisor.whichBig(dividend))
			weights--;
		else
		{
			for(j=0;;j++)
			{
				if(dividend.whichBig(divisor)<divisor.whichBig(dividend))
					break;
				dividend=dividend-divisor;
			}
			weights--;
		}
		divisor.number[divisor.length-1]='\0';
		divisor.length--;
	}
	return dividend;
}
BigInt BigInt::leftshift(int shiftnumber)const
{
	char* temp;
	int i,j,k;
	BigInt shiftint;
	temp=new char[length+shiftnumber+1];
	for(i=0;i<length;i++)
		temp[i]=number[i];
	for(j=i,k=0;k<shiftnumber;j++,k++)
		temp[j]='0';
	temp[j]='\0';
	shiftint=BigInt(temp);
	delete [] temp;
	return shiftint;
}
const bool operator > (const BigInt& first,const BigInt& second)
{
	if(first.whichBig(second)>second.whichBig(first))
		return 1;
	else
		return 0;
}
const bool operator < (const BigInt& first,const BigInt& second)
{
	if(first.whichBig(second)<second.whichBig(first))
		return 1;
	else
		return 0;
}
const bool operator ==(const BigInt& first,const BigInt& second)
{
	if(first.whichBig(second)==second.whichBig(first))
		return 1;
	else
		return 0;
}
const BigInt GCD(const BigInt& small,const BigInt& big)
{
	BigInt zero(0),use;
	if((big%small)==zero)
	{
		use=small;
		if(use.sign==1)
			use.sign=0;
		return use;
	}
	else
		return GCD(big%small,small);
}
const BigInt hierarchy(const char start[],const char end[])
{
	int i,begin,goodbye;
	BigInt answer(start);
	if(atoi(start)<0)
		begin=-atoi(start);
	else
		begin=atoi(start);
	if(atoi(end)<0)
		goodbye=-atoi(end);
	else
		goodbye=atoi(end);
	for(i=begin-1;i>goodbye;i--)
		answer=answer*BigInt(i);
	if(atoi(start)<0&&atoi(end)<0||atoi(end)<0)
		return -answer;
	else
		return answer;
}
int absolute(int number)
{
	if(number<0)
		return -number;
}

} // end namespace

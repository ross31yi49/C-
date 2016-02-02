/*Ä¬­§µ¾ 499410054 2012/3/25*/
#include <iostream>
using namespace std;

bool inputYrMn(int& year,int& month);
/*this function  read the data,if date is invalid return false ,
  if date is valid return true*/
void get1stDayOfMonth(int year,int month,int& weekday,int& day);
/*This function need pass "year","month","weekday","day" for 
  compute the weekday.the result will store in "weekday"(call by reference)*/
void showCalendar(int dayOfWeek,int year,int month);
/*This function need to pass weekday,year,month for print the calendar
  Because this function is printing calendar ,it do not return values*/
bool CheckLeapYear(int year);
/*pass "year" to check if it is leap year*/

int main()
{
	int year,month,day,weekday;
	while(1)
	{
		if((inputYrMn(year,month))==1)
		{
			get1stDayOfMonth(year,month,weekday,day);
			showCalendar(weekday,year,month);
			break;
		}
		else
			cout << "Wrong input,please try again\n";
	}
	return 0;	
}
bool inputYrMn(int& year,int& month)
{
	cin >> year
		>> month;
	if((year<=2099&&year>=1901)&&(month<=12&&month>0))
		return true;
	else
		return false;
}
void get1stDayOfMonth(int yearin,int monthin,int& weekday,int& day)
{
	/* I use "Zeller's congruence" to compute the day of the week
	   The formula is h={q+[13*(m+1)/5]+k+(k/4)+(j/4)-2j}%7
	   h is the day of the week(0=sat 1=sun 2=mon)
	   q is the day of the month
	   m is the month 
	   k is year of century
	   j is the cemtury
	   notice if m is 1 or 2 in Zeller's congruence,
	   we let 1 or 2 becom 13 or 14,and k have to sub 1	*/
	int century,yearOfCentury,dayOfWeek,year(yearin),month(monthin);
	day=1;
	if(month==1||month==2)
	{
		month+=12;
		year--;
	}
    century=year/100;
    yearOfCentury=year%100;
    dayOfWeek=day+((13*(month+1))/5)+yearOfCentury+(yearOfCentury/4)+(century/4)-(2*century);
	weekday=dayOfWeek%7;
}
void showCalendar(int dayOfWeek,int year,int month)
{
	string monthName[]={"January ","February","March","April","May","June","July","August","Setember","October","Nevember","December"};
	int i,j,count;
	const int monthDay[13]={31,28,31,30,31,30,31,31,30,31,30,31,29};
	dayOfWeek=(dayOfWeek+6)%7;/*let 0=sun 1=mon ....6=sat*/
	if(dayOfWeek<0)
		dayOfWeek+=7;
	count=dayOfWeek;
	cout << "-------------------------------------\n"
		 << "          " << year << "      " << monthName[month-1] << endl
		 << "-------------------------------------\n"
         << "  Sun  Mon  Tue  Wen  Thu  Fri  Sat\n";
    if(CheckLeapYear(year)==1&&month==2)
		month+=11;
    for(i=0;i<dayOfWeek;i++)
		cout << "     ";
	for(j=1;j<=monthDay[month-1];j++)
	{
		if(j<10)
			cout << "    "<<j;
		else
			cout << "   "<<j;
		count++;
		if(count>=7)
        {
			cout << endl;
            count=0;
        }
	}
	cout << endl;
}
bool CheckLeapYear(int year)
{
	if((year%4)!=0||year%4==0&&year%100==0&&year%400!=0)
		return false;
	else
		return true;
}

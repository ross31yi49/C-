/* 499410054 Ä¬­§µ¾ 4/13/2012*/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
using namespace std; 
class LIFE
{
	public:
		LIFE(int width,int height);	//16 <= width <=256,  16<= height <=256
		LIFE();	//initialize by default constructor, w = 80, h = 23
		void initialize(int p);	//initialized by user, p=pattern, 1 <= p <=100
		void proceed(int proceed_generation,int sleep_sec);	//preceed n generation, 0 =< proceed_generation, sleep_sec = how many microsecond it'll stop between proceeding generation and generation, 0 <= sleep_sec
		void display() const;	//display the present circustance of the cell 
	private:
		bool cell[256][256];	//"cell" holds the cells of whole organism, 0 denotes a dead cell while a living one
		int w,h,generation;	//w = width, and h = height of the whole world, generation = the present generation
};

int main()
{
	char option,yn;
	LIFE cell,test;
	int w,h,p,generation,time;
	while(1)
	{
		cout<<"Please enter your option:\n 'S' for showing all four pattern after proceeding 100 generations.\n 'I' for initializing a new cell.\n 'D' for displaying the cell.\n 'P' for proceeding a number of generations.\n 'E' for exiting the program.\n##";
		cin>>option;
		switch(option)	//construct the user interface
		{
			case 'S':
				cout<<"This option is mainly for testing, and will not effect the present world\n";
				cout<<"All 4 patterns of world with default size(width = 80, height = 23) will be showed proceeding 100 generation in 5 seconds, separating each pattern with 3 seconds\n";
				sleep(5);
				cout<<"pattern 1:\n";
				test.initialize(1);
				test.proceed(100,60000);
				sleep(3);
				cout<<"pattern 2:\n";
				test.initialize(2);
				test.proceed(100,60000);
				sleep(3);
				cout<<"pattern 3:\n";
				test.initialize(3);
				test.proceed(100,60000);
				sleep(3);
				cout<<"pattern 4(with 25\% coverage):\n";
				test.initialize(25);
				test.proceed(100,60000);
				sleep(3);
				cout<<"The test ends\n"; 
				break;
			case 'I':
				cout<<"Notice that the cells of old organism would be gone after initializing\n";
				cout<<"Do you want to set the size yourself?(y/n)\n";
				cin>>yn;
				if(yn=='y')
				{cout<<"Please enter the width and height separating each other with a space:\n";
					cin>>w>>h;
					cell=LIFE(w,h);
				}
				else 
				{cout<<"The width and height will be set as dafault 80 and 23\n";}
				cout<<"Please enter the initialization pattern :\n";
				cin>>p;
				cell.initialize(p);
				break;
			case 'D':
				cell.display();
				break;
			case 'P':
				cout << "Please enter the generation number:\n";
				cin >> generation;
				cout << "Please enter the freeze time(in microsecond) before next generation proceed (enter 0 for no freeze time)\n";
				cin >> time;
				cell.proceed(generation,time);
				break;
			case 'E':
				exit(0);
			default:
				cout<<"Error option!! Please select again.\n";}
	}
	return 0;
}

LIFE:: LIFE(const int width,const int height)	//initialize as the user wanted, 16 <= width <= 256, 16 <= height <=256
{w=width;h=height;generation=0;}
LIFE:: LIFE()	//initialize by default
{w=80;h=23;generation=0;}

void LIFE:: initialize(int p)	//p = pattern, 1 <= p <= 100
{
if(w>256||w<16||h<16||h>256||p<1||p>100)
	{cout<<"error input!\n";exit(1);}
	int temp,temp2;
	for(temp=0;temp<h;temp++)	//initialize the empty world as all cells are 0
		for(temp2=0;temp2<w;temp2++)
			cell[temp][temp2]=0;
			generation=0;
	if(p>100)
	{
	cout<<"Error pattern! pattern can't be more than 100\n";
	return;
	}
	else if(p>=4)
	{
		p=(w*h*p)/100;	//let p become the number of cells that should be occupied
		srand(time(NULL));
		while(p)
		{
			temp=rand()%(w*h);	//occurs a random number that is < w*h
			if(cell[temp/w][temp%w]==0)	//set the correspondent 
			{cell[temp/w][temp%w]=1;p--;}
		}
	}
	else if(p==3)	//just set the occupied cells according to the PDF when p < 4
	{
		for(temp=1;temp>=-1;temp-=2)	//set a quarter manully and it'll loop the reset of 3/4
			for(temp2=1;temp2>=-1;temp2-=2)
			{cell[h/2+temp2][w/2+temp*2]=1;cell[h/2+temp2][w/2+temp*3]=1;cell[h/2+temp2][w/2+temp*4]=1;
				cell[h/2+temp2*2][w/2+temp]=1;cell[h/2+temp2*2][w/2+temp*3]=1;cell[h/2+temp2*2][w/2+temp*5]=1;
				cell[h/2+temp2*3][w/2+temp]=1;cell[h/2+temp2*3][w/2+temp*2]=1;cell[h/2+temp2*3][w/2+temp*4]=1;cell[h/2+temp2*3][w/2+temp*5]=1;cell[h/2+temp2*3][w/2+temp*6]=1;
				cell[h/2+temp2*4][w/2+temp]=1;cell[h/2+temp2*4][w/2+temp*3]=1;cell[h/2+temp2*4][w/2+temp*6]=1;
				cell[h/2+temp2*5][w/2+temp*2]=1;cell[h/2+temp2*5][w/2+temp*3]=1;
				cell[h/2+temp2*6][w/2+temp*3]=1;cell[h/2+temp2*6][w/2+temp*4]=1;
			}
	}
	else if(p==2)
	{cell[h/2-2][w/2-1]=1;cell[h/2-2][w/2+2]=1;
		cell[h/2-1][w/2-2]=1;
		cell[h/2][w/2+2]=1;cell[h/2][w/2-2]=1;
		temp=-2;
		while(temp<2)
		{cell[h/2+1][w/2+temp]=1;temp++;}
	}
	else	//p=1, the first pattern
	{cell[h/2-1][w/2-1]=1;cell[h/2-1][w/2]=1;cell[h/2-1][w/2+1]=1;
		cell[h/2][w/2-1]=1;
		cell[h/2+1][w/2]=1;}
	cout<<"initialization has been done successfully!!\n";
	return;
}
void LIFE::proceed(int proceed_generation,int sleep_sec)	//preoceed_generation = how many generations that will be proceed, 0 <= preceed_generation, sleep_sec >= 0
{
	int i,j,k,survival=0,stop,next[256][256];
	for(i=0;i<proceed_generation;i++)
	{
		generation++;
		system("clear");
		for(j=0;j<h;j++)
			for(k=0;k<k;k++)
				next[j][k]=0;
		display();
		for(j=0;j<h;j++)
		{
			for(k=0;k<w;k++)
			{
				if((j-1)>=0&&(k-1)>=0)	//judge the surviving cells around this cell
				{
					if(cell[j-1][k-1]==1)
						survival++;		//if one of the surrounding cells is surviving currently, survival++
				}
				if((j-1)>=0)
				{
					if(cell[j-1][k]==1)
						survival++;
				}
				if((j-1)>=0&&(k+1)!=w)
				{
					if(cell[j-1][k+1]==1)
						survival++;
				}
				if((k-1)>=0)
				{
					if(cell[j][k-1]==1)
						survival++;
				}
				if((k+1)!=w)
				{
					if(cell[j][k+1]==1)
						survival++;
				}
				if((j+1)!=h&&(k-1)>=0)
				{
					if(cell[j+1][k-1]==1)
						survival++;
				}
				if((j+1)!=h)
				{
					if(cell[j+1][k]==1)
						survival++;
				}
				if((j+1)!=h&&(k+1)!=w)
				{
					if(cell[j+1][k+1]==1)
						survival++;
				}
				next[j][k]=survival;	//store it in next
				survival=0;
			}
		}
		for(j=0;j<h;j++)
		{
			for(k=0;k<w;k++)
			{
				if(cell[j][k]==0&&next[j][k]==3)	//if the number of the living surrounding cells = 3, a new cell is born
					cell[j][k]=1;
				else if(cell[j][k]==1&&(next[j][k]>3||next[j][k]<2))	//if there are more than 3 or less than 2 surrounding cells, the cell in the middle will die
					cell[j][k]=0;
					//if there it is surrounded by 2 cells, the cell remains unchanged 
			}
		}
		usleep(sleep_sec);	//hold for n microsecond before proceeding to next generation
	}
}

void LIFE:: display() const	//display the present situation of the cell world
{
	cout<<" present generation = "<<generation<<endl;	//show present generation
	int i,j;
	for(i=0;i<h;i++)
	{
		for(j=0;j<w;j++)
		{
			if(cell[i][j])
				cout << "O";
			else
				cout << " ";
		}
		cout << endl;
	}
	return ;
}


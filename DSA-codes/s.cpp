#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
	int day,month,year,yearday;
	cout<<"enter the day month and the year respectively\n";
	cin>>day>>month>>year;
	switch(month)
	{
		case 1:yearday=0;break;
		case 2:yearday=31;break;
		case 3:yearday=59;break;
		case 4:yearday=90;break;
		case 5:yearday=120;break;
		case 6:yearday=151;break;
		case 7:yearday=181;break;
		case 8:yearday=212;break;
		case 9:yearday=243;break;
		case 10:yearday=273;break;
		case 11:yearday=304;break;
		case 12:yearday=334;break;
	}
	if(month>2)
	{
		if(year%400==0||(year%4==0&&year%100!=0))
		{yearday=yearday+1;}
	}
	yearday=yearday+day;
	cout<<yearday;
		    


	
	return 0;
}

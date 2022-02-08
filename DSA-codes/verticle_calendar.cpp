#include<bits/stdc++.h>
using namespace std;
int main()
{
	int year;
	cout<<"enter the year: ";
	cin>>year;
	int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};	
	if(year%4==0&&year%100!=0||year%400==0)
	{month[1]=29;}
	string month_name[12]={"January","February","March","April","May","June","July","August","September","October","November","December"};
	string day_name[7]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
	cout<<"enter the first day of the year: ";
	string first_day;
	cin>>first_day;
	transform(first_day.begin(),first_day.end(),first_day.begin(),::toupper);
	int gap=0;
	for(int i=0;i<7;i++)
	{o
		if(day_name[i]==first_day)
			{
				gap=i;
				break;
			}
	}
	int a[12][10][10],l,n;
	for(int i=0;i<12;i++)
	{
		l=1;n=gap;
		for(int j=0;j<7;j++)
		{
			for(int k=0;k<7;k++)
			{
				if((l>month[i])||(gap!=0))
				{
					gap--;
					a[i][j][k]=0;
				}
				else{
					a[i][j][k]=l++;
				}
			}
		}
		gap=35-month[i]-n;
		if(gap==0){gap=7;}
		gap=7-gap;
	}
	for(int i=0;i<12;i++)
	{
		cout<<month_name[i]<<", "<<year<<"\n\n";
		for(int j=0;j<7;j++)
		{
			cout<<day_name[j]<<"   ";
			for(int k=0;k<7;k++)
			{
				if(a[i][k][j]==0)
				{
					cout<<"  "<<"   ";
				}
				else{
					cout<<setw(2)<<a[i][k][j]<<"   ";
				}
			}
			cout<<"\n\n";
		}
	}
}
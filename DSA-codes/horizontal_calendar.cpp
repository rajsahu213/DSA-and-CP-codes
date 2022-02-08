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
	string day_name[7]={"MON","TUE","WED","THURS","FRI","SAT","SUN"};
	cout<<"enter the first day of the year: ";
	string first_day;
	cin>>first_day;
	transform(first_day.begin(),first_day.end(),first_day.begin(),::toupper);
	int gap=0;
	for(int i=0;i<7;i++)
	{
		if(day_name[i]==first_day)
			{
				gap=i;
				break;
			}
	}
	int k;
	for(int i=0;i<12;i++)
	{
		cout<<month_name[i]<<", "<<year<<endl;
		cout<<endl;
		cout<<"MON"<<"   "<<"TUE"<<"   "<<"WED"<<"    "<<"THURS"<<"    "<<"FRI"<<"    "<<"SAT"<<"   "<<"SUN"<<endl;
		for(int g=0;g<gap;g++)
		{
			cout<<"       ";
		}
		k=gap;
		for(int a=1;a<=month[i];a++)
		{
			if(k==7)
			{
				k=0;
				cout<<endl;
			}
			
			cout<<setw(2)<<a<<"     ";
			k++;
		}
		cout<<endl;
		cout<<"\n\n";
		gap=35-month[i]-gap;
		gap=7-gap;
	}
}
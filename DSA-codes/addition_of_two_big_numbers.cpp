#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s1;
	cout<<"enter the first number\n";
	cin>>s1;
	string s2;
	cout<<"enter the second number\n";
	cin>>s2;
	int a1[10000],a2[10000];
	int n1=s1.length();
	int n2=s2.length();
	for(int i=0;i<n1;i++)
	{
		a1[i]=s1[i]-'0';
	}
	for(int j=0;j<n2;j++)
	{
		a2[j]=s2[j]-'0';
	}
	int carry=0,a3[10000],k=0;
	if(n1>n2)
	{
		int b1=n1,b2=n2,sum;
		while(k<n2)
		{
			b1--;b2--;
			sum=a1[b1]+a2[b2]+carry;
			if(sum>=10){carry=1;sum=sum-10;}
			else{carry=0;}
			a3[b1]=sum;
			k++;
		}
		for(int i=0;i<n1-n2;i++)
		{
			a3[i]=a1[i];
		}
		cout<<"the addition of those two numbers is: ";
		for(int i=0;i<n1;i++)
		{
			cout<<a3[i];
		}
	}
	else
	{
		int b1=n1,b2=n2,sum;
		while(k<n1)
		{
			b1--;b2--;
			sum=a1[b1]+a2[b2]+carry;
			if(sum>=10){carry=1;sum=sum-10;}
			else{carry=0;}
			a3[b2]=sum;
			k++;
		}
		for(int i=0;i<n2-n1;i++)
		{
			a3[i]=a2[i];
		}
		cout<<"the addition of those two numbers is: ";
		for(int i=0;i<n2;i++)
		{
			cout<<a3[i];
		}
	}
	cout<<endl;
	return 0;
}

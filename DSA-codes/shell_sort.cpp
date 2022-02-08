#include<bits/stdc++.h>
using namespace std;

void shell_sort(int a[],int n)
{
	int h=n/2,i=0;
	while(h>=1)
	{
		i=0;
		while(i+h<n)
		{
			if(a[i]>a[i+h])swap(a[i],a[i+h]);
			i++;
		}
		h=h/2;
	}
	int value,hole;
	for(int i=1;i<n;i++)
	{
		value=a[i];
		hole=i;
		while(hole>0&&a[hole-1]>value)
		{
			a[hole]=a[hole-1];
			hole--;
		}
		a[hole]=value;
	}
}

int main()
{
	cout<<"enter n: ";
	int n;cin>>n;
	int a[n];
	cout<<"enter the numbers\n";
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	shell_sort(a,n);
	cout<<"the sorted array is\n";
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
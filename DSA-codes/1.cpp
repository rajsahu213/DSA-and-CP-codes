#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[n];
	cout<<"enter the array\n";
	for(int i=0;i<n;i++)cin>>a[i];
	int b[n];
	for(int i=0;i<n;i++)b[i]=0;
	for(int i=0;i<n;i++)
	{
		if(b[a[i]]==0)b[a[i]]++;
		else
		{
			if(b[a[i]+1]==0)b[a[i]+1]++;
			else if(a[i]>0&&b[a[i]-1]==0)b[a[i]-1]++;
			else b[a[i]]++;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(b[i]>0)
		{
			cout<<b[i]<<" ";
			i--;
		}
	}
}
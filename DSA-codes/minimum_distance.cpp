#include<iostream>
#include<climits>
using namespace std;
int main()
{
	cout<<"enter n: ";
	int n;cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int prev;
	cout<<"enter x and y: "<<endl;
	int x,y,i;cin>>x>>y;
	for(i=0;i<n;i++)
	{
		if(a[i]==x||a[i]==y)
		{
			prev=i;
			break;
		}
	}
	int l,minl=INT_MAX;
	for( ;i<n;i++)
	{
		if(a[i]==x||a[i]==y)
		{
			if(a[prev]!=a[i]&&(i-prev)<minl)
			{
				minl=i-prev;
				prev=i;
			}
			else{
				prev=i;
			}
		}
	}
	cout<<"the min distance is: "<<minl<<endl;
}

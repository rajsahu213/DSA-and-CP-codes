#include<bits/stdc++.h>
using namespace std;

int main()
{
	cout<<"enter the number of members: ";
	int n;cin>>n;
	for(int i=1;i<=n;i++)cout<<i<<" ";
	cout<<endl;int count=1;
	if(n>4)
	{
		if(n%2==0)count=n/2-1;
		else count=n/2;
		for(int k=1;k<count;k++)
		{
			int i=1;
			for(int m=0;m<n;m++)
			{
				cout<<i<<" ";
				if((i+k+1)!=n)i=(i+k+1)%n;
				else i=n;
			}
			cout<<endl;
		}
	}
	cout<<"no of days is: "<<count<<endl;
}
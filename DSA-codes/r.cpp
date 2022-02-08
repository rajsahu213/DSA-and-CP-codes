#include<iostream>

using namespace std;
int main()
{   float s=0,p=1,x,n,i,j,b;
	
	cout<<"enter the value of n and x\n";
	cin>>b>>x;
	n=b-1;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=i;j++)
		{
			p=p*(x/j);
		}
		s=s+p;
	}
	float v=s+1;
	cout<<v;


	return 0;
}

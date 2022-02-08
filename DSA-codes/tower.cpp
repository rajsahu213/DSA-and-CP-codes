#include<bits/stdc++.h>
using namespace std;

void tower(char a,char b,char c,int n)
{
	if(n==1)
	{
		cout<<a<<" "<<c<<endl;
		return;
	}
	else
	{
		tower(a,c,b,n-1);
		cout<<a<<" "<<c<<endl;
		tower(b,a,c,n-1);
	}
}

int main()
{
	cout<<"enter n: ";
	int n;cin>>n;
	tower('a','b','c',n);
	return 0;
}
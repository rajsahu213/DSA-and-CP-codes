#include<iostream>
using namespace std;
int main()
{
	cout<<"enter n: ";
	int n;cin>>n;
	cout<<"enter the numbers\n";
	int a[n];
	for(int i=0;i<n-1;i++)
	{
		cin>>a[i];
	}
	int sum=(n*(n+1))/2;
	int sum1=0;
	for(int i=0;i<n-1;i++)
	{
		sum1+=a[i];
	}
	cout<<"the missing number is: "<<sum-sum1<<endl;
}
#include<iostream>
using namespace std;

int findmax(int a1[],int a2[],int n)
{
	int maxlenght=0;
	int sum1,sum2,length,i,j;
	for(i=0;i<n;i++)
	{
		sum1=0;
		sum2=0;
		for(j=i;j<n;j++)
		{
			sum1=sum1+a1[j];
			sum2=sum2+a2[j];
			if(sum1==sum2)
			{
				length=j-i+1;
				if(length>maxlenght)
				{
					maxlenght=length;
				}
			}
		}
	}
	return maxlenght;
}

int main()
{
	cout<<"enter n: ";
	int n;cin>>n;
	int a1[n],a2[n];
	cout<<"enter the first binary array\n";
	for(int i=0;i<n;i++)
	{
		cin>>a1[i];
	}
	cout<<"enter the second binary array\n";
	for(int i=0;i<n;i++)
	{
		cin>>a2[i];
	}
	cout<<"the maximum sum of a common subarray is: "<<findmax(a1,a2,n)<<endl;
}
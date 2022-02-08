#include<iostream>
#include<cmath>
using namespace std;

int binary_search(int n)
{
	int low=1;
	int high=n;
	int ans=0;
	while(low<=high)
	{
		int mid=low+(high-low)/2;
		if(mid*mid<=n){ans=mid;low=mid+1;}
		else{high=mid-1;}
	}
	return ans;
}

int main()
{
	cout<<"enter a number: ";
	int n;cin>>n;
	int n1=binary_search(n);
	float sum=n1;
	cout<<"enter precision: ";
	int p;cin>>p;
	float flag=1.0;
	for(int j=0;j<p;j++)
	{
		flag=flag/10;
		for(int i=1;i<10;i++)
		{
			if(sum*sum>n)
			{
				sum=sum-flag;
				break;
			}		
			else{
				sum=sum+flag;
			}
		}
	}	
	cout<<sum<<endl;
}
#include<bits/stdc++.h>
using namespace std;

long long int dp[120][120];

int lcs(int a[],int num,int i,int j)
{
	if(i==j && a[i]>=num)return 1;
	else 
	{
		int x=1;
		for(int itr=i;itr<=j;itr++)
		{
			if(a[itr]>=num)
			{
				x=max(x,1+lcs(a,a[itr],itr+1,j));
			}
		}
		return x;
	}
}

int main()
{
	int n;cin>>n;
	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	int dp[n];
	for(int i=0;i<n;i++)dp[i]=1;
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(a[i]>=a[j])
			{
				dp[i]=max(dp[i],1+dp[j]);
			}
		}
	}
	int ans=-1;
	for(int i=0;i<n;i++)
	{
		if(dp[i]>ans)ans=dp[i];
	}
	cout<<ans<<endl;
}
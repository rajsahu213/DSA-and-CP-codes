#include<bits/stdc++.h>

using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl

int main()
{
	float a;cin>>a;
	int i=1,count1=0;
	float ans=0,fact=1;
	while((ans*ans*ans)<a)
	{
		ans=ans+fact;
		int count=0;
		while((ans*ans*ans)<a)
		{
			ans+=fact;
			count++;
			if(count>15)break;
		}
		ans=ans-fact;
		fact=fact/10;
		count1++;
		if(count1>15)break;
	}
	cout<<setprecision(10)<<ans<<endl;
}
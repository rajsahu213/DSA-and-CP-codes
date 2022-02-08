#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct character
{
	ll times;
	ll last_occur;
	ll first_occur;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;cin>>t;
	while(t--)
	{
		ll n;cin>>n;
		string s;
		cin>>s;
		if(n==1)cout<<0<<endl;
		else
		{
			character a[26];
			ll min[26];
			for(int i=0;i<26;i++)
			{
				a[i].times=0;
				a[i].last_occur=n+1;
				a[i].first_occur=-1;
				min[i]=10000000;
			}
			for(ll i=0;i<n;i++)
			{
				if(a[s[i]-'a'].times==0)
				{
					a[s[i]-'a'].times++;
					a[s[i]-'a'].first_occur=i;
				}
				else
				{
					ll dis=i-a[s[i]-'a'].first_occur;
					if(dis<min[s[i]-'a'])min[s[i]-'a']=dis;
					a[s[i]-'a'].first_occur=i;
					a[s[i]-'a'].times++;
				}
			}
			ll max=-1;
			for(int i=0;i<26;i++)
			{
				if(a[i].times>=2)
				{
					if((n-min[i])>max)max=n-min[i];
				}
			}
			if(max==-1)
			{
				cout<<0<<endl;
			}
			else
			{
				cout<<max<<endl;
			}
		}
	}
	return 0;	
}
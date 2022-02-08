#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll val(char c) 
{ 
    if (c >= '0' && c <= '9') 
        return (int)c - '0'; 
    else
        return (int)c - 'A' + 10; 
}
ll toDeci(string str,ll base) 
{ 
    int len = str.length(); 
    ll power = 1;
    ll num = 0;  
    int i; 
    for (i = len - 1; i >= 0; i--) 
    { 
        num += val(str[i]) * power; 
        power = power * base; 
    } 
    return num; 
} 

int main() {
	ll t;cin>>t;
	while(t--)
	{
	    ll n;cin>>n;
	    ll a[n*50];
	    ll k=0;
	    for(ll i=0;i<n;i++)
	    {
	        ll b;
	        string y;
	        cin>>b>>y;
	        if(b==-1)
	        {
	          for(int j=2;j<=36;j++)
	          {
	              a[k++]=toDeci(y,j);
	          }
	        }
	        else
	        {
	            a[k++]=toDeci(y,b) ;  
	            for(int j=1;j<=34;j++)
	            {
	                a[k++]=-2;
	            }
	        }
	    }
		sort(a,a+k);
		ll count=0;
		ll i;
		for(i=0;i<k;i++)
		{
			if(a[i]!=-2)
			{
				break;
			}
		} 
		ll temp;
		int flag=0;
		for(ll j=i;j<k;j++)
		{
			count=1;
			for(ll l=j+1;l<k;l++)
			{
				if(a[l]==a[j])
				{
					count++;
				}
				else break;
			}
			if(count==n)
			{
				flag=1;
				cout<<a[j]<<endl;
				break;
			}
		}  
		if(flag==0)cout<<-1<<endl;
	}
	return 0;
}
















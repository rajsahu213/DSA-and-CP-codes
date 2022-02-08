#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<string>
using namespace std;

typedef long long int ll;

ll power(ll x,ll y,ll p) 
{ 
    ll res = 1;
    x = x % p;
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % p;  
        y = y>>1;
        x = (x*x) % p;   
    } 
    return res; 
} 

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;cin>>t;
	while(t--)
	{
        ll n;cin>>n;
        if(n==0)
        {
            cout<<0<<" "<<0<<endl;
        }
        else
        {
            ll mod=1000000007;
            ll ans=power(2,n-1,mod);
            cout<<ans-1<<" "<<ans<<endl;
        }
	}
}
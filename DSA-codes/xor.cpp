#include<iostream>
using namespace std;
typedef long long int ll;

ll power(ll x, ll y, ll p) 
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
ll modInverse(ll n, ll p) 
{ 
    return power(n, p-2, p); 
} 
ll nCrModPFermat(ll n, ll r, ll p,ll fac[]) 
{  
   if (r==0) 
      return 1; 
  
    return (fac[n]* modInverse(fac[r], p) % p * 
            modInverse(fac[n-r], p) % p) % p; 
} 

ll mod(ll a,ll b)
{
	if(a>b)return a-b;
	else return b-a;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	ll t;cin>>t;
	while(t--)
	{
		ll n;cin>>n;
		string a,b;
		cin>>a>>b;
		ll m=1000000007;
		ll no1_a=0,no1_b=0;
		for(ll i=0;i<n;i++)
		{
			if(a[i]=='1')no1_a++;
			if(b[i]=='1')no1_b++;
		}
		ll min1=mod(no1_a,no1_b);
		ll max1=no1_a+no1_b;
		if(max1>n)
		{
			max1=max1-n;
			max1=n-max1;
		}
        ll fac[n+1]; 
        fac[0] = 1; 
        for (ll i=1 ; i<=n; i++) 
            fac[i] = fac[i-1]*i%m; 		
		ll ans=0;
		for(ll i=min1;i<=max1;i=i+2)
		{
			ans+=nCrModPFermat(n, i, m,fac);
		}
		cout<<ans%m<<endl;
	}
}
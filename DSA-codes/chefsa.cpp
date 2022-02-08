#include<bits/stdc++.h>

using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define mod 1000000007 
#define N 10000000

typedef long long int ll;
typedef long double ld;
typedef long int li;

ll modFact(ll n,ll p) 
{ 
    if(n>=p)return 0;
    ll result = 1; 
    for (ll i = 1; i <= n; i++) 
        result = ((result%mod) *(i%mod))%p; 
  
    return result; 
}

ll power(ll x,ll y,ll p) 
{ 
    ll res = 1;
    x=x%p;  
    while (y>0) 
    { 
        if (y & 1) 
            res = ((res%p)*(x%p))%p; 
        y = y>>1; 
        x = ((x%p)*(x%p))%p; 
    } 
    return res; 
} 
ll modInverse(ll n,ll p) 
{ 
    return power(n, p-2, p); 
} 

int main()
{
    // clock_t tStart = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;cin>>t;
    while(t--)
    {
    	ll n;cin>>n;
    	ll a[2*n];
    	ll sum=0;
    	for(ll i=0;i<2*n;i++)
    	{
    		cin>>a[i];
    		sum+=a[i];
    	}
    	if(sum%(n+1)!=0)
    	{
    		cout<<0<<"\n";
    		continue;
    	}
    	if(n==1)
    	{
    		if(a[0]==a[1])cout<<1<<"\n";
    		else cout<<0<<"\n";
    		continue;
    	}
    	sum=sum/(n+1);
    	ll x[2*n],k=0,m=0;
    	for(ll i=0;i<2*n;i++)
    	{
    		if(a[i]==sum&&k<2)k++;
    		else
    		{
    			x[m++]=a[i];
    		}
    	}
    	if(k<2)
    	{
    		cout<<0<<"\n";
    		continue;
    	}
    	sort(x,x+2*n-2);
    	vector<pair<ll,ll>> v;
    	ll i=0,j=2*n-3;
    	bool flag=false;
    	while(i<j)
    	{
    		if((x[i]+x[j])==sum)
    		{
    			v.push_back(pair<ll,ll>(x[i],x[j]));
    		}
    		else
    		{
    			flag=true;
    			break;
    		}
    		i++;j--;
    	}
    	if(flag||(v.size()<n-1))
    	{
    		cout<<0<<"\n";
    		continue;
    	}
    	vector<ll> freq;
    	for(ll i=0;i<v.size();i++)
    	{
    		ll count=0,it=0;
    		for(ll j=i+1;j<v.size();j++)
    		{
    			if(v[i].first==v[j].first&&v[i].second==v[j].second)count++;
    			else break;
    			it++;
    		}
    		freq.push_back(count+1);
    		i=i+it;
    	}
    	ll same=0;
    	for(ll i=0;i<v.size();i++)
    	{
    		if(v[i].first==v[i].second)same++;
    	}
    	ll ans1=1;
    	for(ll i=0;i<freq.size();i++)
    	{
    		ans1=((ans1%mod)*(modFact(freq[i],mod))%mod);
    	}
    	ll ans2=modFact(n-1,mod);
    	ll ans3=(ans2%mod)*(modInverse(ans1,mod)%mod)%mod;
    	ll ans4=power(2,v.size()-same,mod);
    	ll ans=((ans3%mod)*(ans4%mod))%mod;
    	cout<<ans<<"\n";
    }
    // printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}    
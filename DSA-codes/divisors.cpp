#include<bits/stdc++.h>

using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define mod 1000000007 
#define N 10000000

typedef long long int ll;
typedef long double ld;
// typedef long ll li;

void solve(ll n,vector<ll> &div)
{
	for(ll i=1;i<=sqrt(n);i++)
	{
		if(n%i==0)
		{
			if(n/i==i)div.push_back(i);
			else {div.push_back(i);div.push_back(n/i);}
		}
	}
}

ll product(vector<ll> arr,ll n) 
{ 
	ll ans = 1; 
	for (ll i = 0; i < n; ++i ) 
		ans = ((ans%mod)*((arr[i] + 1)%mod))%mod; 
	return (ans%mod-1%mod)%mod; 
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
    	vector<ll> div;
    	solve(n,div);
    	ll ans=product(div,div.size());
    	cout<<ans<<"\n";
    }
    // prllf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}        	
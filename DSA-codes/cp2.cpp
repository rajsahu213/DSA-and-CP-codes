#include<iostream>
#include<vector>
#include<ctime>
#include<algorithm>
#include<limits>
#include <cmath> 
#include <iomanip> 
using namespace std;
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long int ll;
typedef long double ld;

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
	// clock_t tStart = clock();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;cin>>t;
	while(t--)
	{
		ll v,h,k;
        cin>>v>>h>>k;
        ll m=1000000007;
        v=v*v;
        // watch(v);
        ll ft=v/1000000;
        // watch(ft);
        ll st=v+2000*h;
        // watch(st);
        ll lt=((ft)*(st));
        // watch(lt);
        ll ans=power(lt,k/2,m);
        cout<<ans<<endl;
	}
	// printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	return 0;
}
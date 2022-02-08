#include <bits/stdc++.h>
using namespace std;

#define fio 					ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define watch(x) 				cout << (#x) << " is " << (x) << endl
#define f(t) 					for(ll i=0;i<t;i++)
#define ll 						long long int
#define ld 						long double
#define umpl 					unordered_map<ll,ll>
#define vl 						vector<ll>
#define vld 					vector<ld>
#define vvl 					vector<vl>
#define pb 						push_back
#define pll 					pair<ll,ll>
#define inf 					1e18
#define pcout(x,p) 				cout<<fixed<<setprecision(p)<<x
#define all(a) 					a.begin(),a.end()
#define endl 					"\n"


const ll mod = 1e9 + 7;
inline ll mul(ll a, ll b) { ll c = (a * 1ll * b) % mod; if (c < 0) c += mod; return c; }
inline ll sub(ll a, ll b) { ll c = a - b; if (c < 0) c += mod; return c; }
inline ll add(ll a, ll b) { ll c = a + b; if (c >= mod) c -= mod; return c; }
inline ll max(ll a, ll b) {return a > b ? a : b;}
inline ll min(ll a, ll b) {return a < b ? a : b;}
inline ll ceil(ll a, ll b) {return (a % b == 0) ? (a / b) : (a / b + 1);}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fio;

}

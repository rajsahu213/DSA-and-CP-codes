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


const ll mod = 998244353;
inline ll mul(ll a, ll b) { ll c = (a * 1ll * b) % mod; if (c < 0) c += mod; return c; }
inline ll sub(ll a, ll b) { ll c = a - b; if (c < 0) c += mod; return c; }
inline ll add(ll a, ll b) { ll c = a + b; if (c >= mod) c -= mod; return c; }
inline ll max(ll a, ll b) {return a > b ? a : b;}
inline ll min(ll a, ll b) {return a < b ? a : b;}
inline ll ceil(ll a, ll b) {return (a % b == 0) ? (a / b) : (a / b + 1);}

ll power(ll x, ll y, ll p) {
	ll res = 1;
	x = x % p;
	while (y > 0) {
		if (y & 1) {
			res = (res * x) % p;
		}
		y = y >> 1;
		x = (x * x) % p;
	}
	return res;
}

ll modInverse(ll n, ll p) {
	return power(n, p - 2, p);
}

ll solve(ll k, ll n) {
	ll fact[n + 1];
	fact[0] = 1;
	for (ll i = 1; i <= n; i++) {
		fact[i] = mul(fact[i - 1], i);
	}
	ll ans = 0, col = 1;
	for (ll i = 0; i < n; i++) {
		ll temp1 = mul(fact[i], fact[n - i - 1]);
		ll temp2 = mul(fact[n - 1], modInverse(temp1, mod));
		if (i == 0)col = mul(col, k);
		else col = mul(col, k - 1);
		ll col1 = mul(col, temp2);
		ans = add(ans, mul(i + 1, col1));
	}
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fio;
	ll m, n, k; cin >> m >> n >> k;
	ll deno = power(k, mul(n, m), mod);
	ll ans;
	if (m == 1) {
		ans = solve(k, n);
	} else {
		ll temp = solve(k, mul(2 , n));
		ll temp2;
		if (n == 1) {
			temp2 = 0;
		} else {
			temp2 = mul(k - 1, power(k, sub(mul(2 , (n - 1)) , 1), mod));
		}
		temp2 = mul(temp2, sub(mul(k , k) , 1));
		ans = ((temp % mod - temp2 % mod) % mod + mod) % mod;
	}
	cout << mul(ans, modInverse(deno, mod)) << endl;
}

#include <bits/stdc++.h>
using namespace std;
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define watch(x) cout << (#x) << " is " << (x) << endl
#define f(t) for(ll i=0;i<t;i++)
#define ll long long int
#define ld long double
#define umpl unordered_map<ll,ll>
#define vl vector<ll>
#define vld vector<ld>
#define vvl vector<vl>
#define pb push_back
#define pll pair<ll,ll>
#define inf 1e18
#define pcout(x,p) cout<<fixed<<setprecision(p)<<x
#define all(a) a.begin(),a.end()
#define endl "\n"
const ll mod = 998244353;
inline ll mul(ll a, ll b) { return (a * 1ll * b) % mod; }
inline ll sub(ll a, ll b) { ll c = a - b; if (c < 0) c += mod; return c; }
inline ll add(ll a, ll b) { ll c = a + b; if (c >= mod) c -= mod; return c; }
inline ll max(ll a, ll b) {return a > b ? a : b;}
inline ll min(ll a, ll b) {return a < b ? a : b;}
inline ll ceil(ll a, ll b) {return (a % b == 0) ? (a / b) : (a / b + 1);}
template<class T> ostream& operator<<(ostream &os, vector<T> V) {
	for (auto v : V) os << v << "  ";
	return os;
}
template<class T> ostream& operator<<(ostream &os, set<T> S) {
	os << "{ ";
	for (auto s : S) os << s << " ";
	return os << "}";
}
template<class L, class R> ostream& operator<<(ostream &os, pair<L, R> P) {
	return os << "(" << P.first << "," << P.second << ")";
}
template<class L, class R> ostream& operator<<(ostream &os, map<L, R> M) {
	os << "{ ";
	for (auto m : M) os << "(" << m.first << ":" << m.second << ") ";
	return os << "}";
}
struct comp {
	template<class T1, class T2, class T3, class T4>
	bool operator()(const pair<T1, T2> &p1, const pair<T3, T4> &p2) {
		return p1.first < p2.first;
	}
};
ll power(ll x, ll y, ll p)
{
	ll res = 1;
	x = x % p;
	while (y > 0)
	{
		if (y & 1)
			res = (res * x) % p;
		y = y >> 1;
		x = (x * x) % p;
	}
	return res;
}

ll modInverse(ll n, ll p)
{
	return power(n, p - 2, p);
}
void rec(vl &a, ll low, ll high, ll &ans, vl &temp, map<ll, ll> &mp) {
	if (low > high) {
		ll m = inf;
		for (ll i = 0; i < a.size(); i++) {
			m = min(m, min(temp[i], a[i] - temp[i]));
		}
		ans = add(ans, m);
		mp[m]++;
	} else {
		for (ll i = 0; i <= a[low]; i++) {
			temp[low] = i;
			rec(a, low + 1, high, ans, temp, mp);
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fio;
	ll t; cin >> t;
	while (t--) {
		ll n; cin >> n;
		vl a(n);
		f(n)cin >> a[i];
		ll q = 1;
		f(n) {
			q = mul(q, a[i] + 1);
		}
		sort(all(a));
		if (a[0] == 0 || a[0] == 1) {
			cout << mul(0, modInverse(q, mod)) << endl;
			continue;
		}
		ll ans = 0; vl temp(n, 0);
		map<ll, ll> mp;
		rec(a, 0, n - 1, ans, temp, mp);
		cout << mp << endl;
		cout << ans << endl;
	}
}
#include<bits/stdc++.h>

using namespace std;

typedef    long long int                   ll;
typedef    pair<ll, ll>                    pll;
typedef    long double                     ld;
typedef    vector<ll>                      vl;
typedef    unordered_set<ll>               usl;
typedef    unordered_multiset<ll>          umsl;
typedef    multiset<ll>                    msl;
typedef    set<ll>                         sl;
typedef    vector<pll>                     vpl;
typedef    vector<vl>                      vvl;
typedef    map<ll, ll>                     ml;
typedef    unordered_map<ll, ll>           umpl;

#define fio                ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pb                 push_back
#define pq                 priority_queue
#define ff                 first
#define se                 second
#define setbits(a)         __builtin_popcountll(a)
#define zrobits(a)         __builtin_ctzll(a)
#define loop(a,b,i)        for(ll i=a;i<b;i++)
#define all(a)             a.begin(),a.end()
#define sz(a)              (ll)a.size()
#define endl               "\n"

const ll mod = 1e9 + 7;
const ll inf = 1e18;

inline ll mul(ll a, ll b)     { ll c = (a * 1ll * b) % mod; if (c < 0) c += mod; return c; }
inline ll sub(ll a, ll b)     { ll c = a - b; return (c % mod + mod) % mod; }
inline ll add(ll a, ll b)     { ll c = a + b; if (c >= mod) c -= mod; return c; }
inline ll max(ll a, ll b)     { return a > b ? a : b; }
inline ll min(ll a, ll b)     { return a < b ? a : b; }
inline ll gcd(ll a, ll b)     { return __gcd(a, b);}
inline ll lcm(ll a, ll b)     { return (a * b) / gcd(a, b);}
inline ll ceil(ll a, ll b)    { return (a % b == 0) ? (a / b) : (a / b + 1); }

vector<int> calcPrefixFunction(string s) {
	int n = s.size(), k = 0;
	vector<int> result(n);
	result[0] = 0;
	for (int i = 1; i < n; i++) {
		while (k > 0 && s[i] != s[k]) k = result[k - 1];
		if (s[k] == s[i]) k++;
		result[i] = k;
	}
	return result;
}

int KMP(string text, string s) {
	vector<int> preFun = calcPrefixFunction(s);
	int maxPrefixLength = 0;
	for (int i = 0; i < text.length(); i++) {
		while (maxPrefixLength > 0 && text[i] != s[maxPrefixLength]) {
			maxPrefixLength = preFun[maxPrefixLength - 1];
		}
		if (s[maxPrefixLength] == text[i]) maxPrefixLength++;
		if (maxPrefixLength == s.length()) {
			int idx = i - s.length() + 1;
			maxPrefixLength = preFun[maxPrefixLength - 1];
		}
	}
	return maxPrefixLength;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fio;
	vector<int> a = {1, 2, 3, 4, 7, 6}, b = {4, 5, 6};
	cout << fun(6, a, 3, b) << endl;
	return 0;
}

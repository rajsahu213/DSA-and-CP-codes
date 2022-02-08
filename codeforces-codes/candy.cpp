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
const ll mod = 1e9 + 7;
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

int main() {
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif
	fio;
	ll t; cin >> t;
	while (t--) {
		ll n; cin >> n;
		vl a(n);
		f(n)cin >> a[i];
		ll pos1 = -1;
		f(n)if (a[i] == 1)pos1 = i;
		ll q; cin >> q;
		if (pos1 == 0) {
			while (q--) {
				ll r; cin >> r;
				if (n == 1) {
					cout << r % mod << endl;
				} else {
					ll temp = r / n, rem = r % n;
					if (temp == 0) {
						temp = add(temp, 1);
					} else {
						if (rem > 1)temp = add(temp % mod, 1);
					}
					cout << temp << endl;
				}
			}
		} else if (pos1 == (n - 1)) {
			vl ans(n + 1, 0);
			for (ll i = 1; i <= n; i++) {
				if ((a[i - 1] % 2 != 0) && a[i - 1] != 1) {
					ans[i] = add(ans[i - 1], sub(a[i - 1], 1));
				} else {
					ans[i] = add(ans[i - 1], a[i - 1]);
				}
			}
			while (q--) {
				ll r; cin >> r;
				ll temp = r / n, rem = r % n;
				temp = mul(temp % mod, ans[n] % mod);
				if (rem != 0) {
					temp = add(temp, ans[rem]);
					if (a[rem - 1] & 1) {
						temp = add(temp, 1);
					}
				}
				cout << temp << endl;
			}
		} else if (pos1 != -1) {
			vl ans(n + 1, 0);
			for (ll i = 1; i <= n; i++) {
				if (i == pos1) {
					if (a[i - 1] % 2 == 0) {
						ans[i] = add(ans[i - 1], sub(a[i - 1], 1));
					} else {
						ans[i] = add(ans[i - 1], a[i - 1]);
					}
				} else {
					bool flag = (a[i - 1] % 2 != 0);
					if (i == n) {
						flag = !flag;
					}
					if (flag) {
						ans[i] = add(ans[i - 1], sub(a[i - 1], 1));
					} else {
						ans[i] = add(ans[i - 1], a[i - 1]);
					}
				}
			}
			while (q--) {
				ll r; cin >> r;
				ll temp = r / n, rem = r % n;
				temp = mul(temp % mod, ans[n] % mod);
				if (rem == 0) {
					if (a[n - 1] % 2 == 0) {
						temp = add(temp, 1);
					}
				} else {
					if (rem == pos1) {
						if (a[rem - 1] % 2 == 0) {
							temp = add(temp, 1);
						}
					} else if ((rem - 1) == pos1) {
						if (a[rem - 2] % 2 == 0) {
							temp = add(temp, 2);
						}
					} else {
						if (a[rem - 1] & 1) {
							temp = add(temp, 1);
						}
					}
					temp = add(temp, ans[rem]);
				}
				cout << temp << endl;
			}
		} else {
			vl ans(n + 1, 0);
			for (ll i = 1; i <= n; i++) {
				bool flag = (a[i - 1] % 2 != 0);
				if (i == n) {
					flag = !flag;
				}
				if (flag) {
					ans[i] = add(ans[i - 1], sub(a[i - 1], 1));
				} else {
					ans[i] = add(ans[i - 1], a[i - 1]);
				}
			}
			while (q--) {
				ll r; cin >> r;
				ll temp = r / n, rem = r % n;
				temp = mul(temp % mod, ans[n] % mod);
				if (rem == 0) {
					if (a[n - 1] % 2 == 0) {
						temp = add(temp, 1);
					}
				} else {
					if (a[rem - 1] & 1) {
						temp = add(temp, 1);
					}
					temp = add(temp, ans[rem]);
				}
				cout << temp << endl;
			}
		}
	}
}

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

int main() {
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fio;
	ll t; cin >> t;
	while (t--) {
		ll n; cin >> n;
		vvl lines(n);
		map<ll, vl> pos_line_ids, neg_line_ids;
		vector<map<ll, ll>> position(n);
		for (ll i = 0; i < n; i++) {
			ll m; cin >> m;
			lines[i].resize(m);
			for (ll j = 0; j < m; j++) {
				ll x; cin >> x;
				lines[i][j] = x;
				position[i][x] = j + 1;
				if (x < 0) {
					neg_line_ids[x].pb(i);
				} else {
					pos_line_ids[x].pb(i);
				}
			}
		}
		vector<map<ll, ll>> cross(n);
		for (ll i = 0; i < n; i++) {
			bool flag = false;
			for (ll j = lines[i].size() - 1; j >= 0; j--) {
				if (lines[i][j] < 0) {
					if (!flag) {
						cross[i][lines[i][j]] = 0;
						flag = !flag;
					} else {
						if (neg_line_ids[lines[i][j + 1]].size() == 1 && pos_line_ids.find(lines[i][j + 1] * (-1)) == pos_line_ids.end()) {
							cross[i][lines[i][j]] = cross[i][lines[i][j + 1]] + 1;
						} else {
							cross[i][lines[i][j]] = cross[i][lines[i][j + 1]];
						}
					}
				} else {
					cross[i][lines[i][j]] = 0;
				}
			}
		}
		set<ll> originCol;
		ll ans = 0;
		for (auto line : pos_line_ids) {
			ll x = line.first;
			if (line.second.size() == 1) {
				ll lineNum = line.second[0];
				if (neg_line_ids.find(x * (-1)) == neg_line_ids.end()) {
					auto it = cross[lineNum].upper_bound(x * (-1));
					if (it == cross[lineNum].begin()) {
						ans += it->second;
						if (neg_line_ids.find(it->first) != neg_line_ids.end() && neg_line_ids[it->first].size() == 1 && pos_line_ids.find(it->first * (-1)) == pos_line_ids.end()) {
							ans++;
						}
					} else {
						it--;
						ans += it->second;
						ans += position[lineNum][it->first];
					}
				} else {
					auto it = cross[lineNum].upper_bound(x * (-1));
					if (it == cross[lineNum].begin()) {
						ans += it->second;
						if (neg_line_ids.find(it->first) != neg_line_ids.end() && neg_line_ids[it->first].size() == 1 && pos_line_ids.find(it->first * (-1)) == pos_line_ids.end()) {
							ans++;
						}
					} else {
						it--;
						ans += it->second;
					}
					ans++;
					originCol.insert(x * (-1));
					ans += (ll)lines[lineNum].size() - position[lineNum][x];
				}
			} else {
				ans++;
				originCol.insert(x * (-1));
				for (ll lineNum : line.second) {
					auto it = cross[lineNum].upper_bound(x * (-1));
					if (it == cross[lineNum].begin()) {
						ans += it->second;
						if (neg_line_ids.find(it->first) != neg_line_ids.end() && neg_line_ids[it->first].size() == 1 && pos_line_ids.find(it->first * (-1)) == pos_line_ids.end()) {
							ans++;
						}
					} else {
						it--;
						ans += it->second;
					}
					ans += (ll)lines[lineNum].size() - position[lineNum][x];
				}
			}
		}
		for (auto line : neg_line_ids) {
			ll x = line.first;
			if (line.second.size() == 1) {
				if (pos_line_ids.find(x * (-1)) != pos_line_ids.end()) {
					ans += position[line.second[0]][x] - 1;
				}
			} else {
				if (originCol.find(x) == originCol.end()) {
					ans++;
				}
				for (ll lineNum : line.second) {
					ans += position[lineNum][x] - 1;
				}
			}
		}
		cout << ans << endl;
	}
}

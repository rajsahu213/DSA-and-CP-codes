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
const ll mod = pow(2, 32);
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

class SegmentTree {
private:
	ll size;
	vl segtree;
public:
	void init(ll n) {
		size = 1;
		while (size < n)size = size * 2;
		segtree.resize(2 * size, 0);
	}

	void build(vl &a, ll root, ll left, ll right) {
		if ((right - left) == 1) {
			if (left < (ll)a.size()) {
				segtree[root] = a[left];
			}
			return;
		}
		ll mid = left + (right - left) / 2;
		build(a, 2 * root + 1, left, mid);
		build(a, 2 * root + 2, mid, right);
		segtree[root] = max(segtree[2 * root + 1], segtree[2 * root + 2]);
	}

	void build(vl &a) {
		build(a, 0, 0, size);
	}

	ll query(ll &l, ll &r, ll root, ll left, ll right) {
		if (l >= right || r <= left)return 0;
		if (left >= l && right <= r)return segtree[root];
		ll mid = left + (right - left) / 2;
		ll m1 = query(l, r, 2 * root + 1, left, mid);
		ll m2 = query(l, r, 2 * root + 2, mid, right);
		return max(m1, m2);
	}

	ll query(ll l, ll r) {
		return query(l, r, 0, 0, size);
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fio;
	ll n, q, s1;
	cin >> n >> q >> s1;
	vl a(n);
	f(n)cin >> a[i];
	map<ll, vl> mp;
	f(n) {
		mp[a[i]].pb(i);
	}
	vl prefix(n, 0), suffix(n, 0);
	stack<int> s;
	for (ll i = n - 1; i >= 0; i--) {
		while (!s.empty() && a[s.top()] <= a[i]) {
			s.pop();
		}
		if (!s.empty()) {
			// graph[i].pb(s.top());
			suffix[i] = max(suffix[i], 1 + suffix[s.top()]);
		} else {
			suffix[i] = 1;
		}
		s.push(i);
	}
	while (!s.empty())s.pop();
	for (ll i = 0; i < n; i++) {
		while (!s.empty() && a[s.top()] >= a[i]) {
			s.pop();
		}
		if (!s.empty()) {
			prefix[i] = max(prefix[i], 1 + prefix[s.top()]);
		} else {
			prefix[i] = 1;
		}
		s.push(i);
	}
	SegmentTree tree1, tree2, tree3;
	tree1.init(n); tree2.init(n); tree3.init(n);
	tree1.build(a); tree2.build(prefix); tree3.build(suffix);
	// cout << prefix << endl;
	// cout << suffix << endl;
	ll ans1 = 0;
	while (q--) {
		ll x, y; cin >> x >> y;
		ll l = (x + s1 * ans1 - 1) % n + 1, r = (y + s1 * ans1 - 1) % n + 1;
		if (l > r)swap(l, r);
		// cout << l << " " << r << endl;
		l--; ans1 = 0;
		ll mx = tree1.query(l, r);
		// cout << mx << " ";
		auto it = lower_bound(all(mp[mx]), r);
		it--;
		// cout << *it << " ";
		ll mx1 = tree3.query(l, *it);
		if (mx1 == 0) {
			ans1 = max(ans1, 1);
		} else {
			ans1 = max(ans1, mx1 - suffix[*it] + 1);
		}
		// auto it1 = lower_bound(all(mp[mx]), l);
		// cout << *it1 << " ";
		// cout << mx1 << " ";
		ll mx2 = tree2.query((*it) + 1, r);
		// cout << mx2 << endl;
		ans1 = max(ans1, mx2);
		cout << ans1 << endl;
	}
}
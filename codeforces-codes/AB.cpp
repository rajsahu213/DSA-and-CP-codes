#include<bits/stdc++.h>
using namespace std;
#define ll long long int
class SegmentTree {
private:
	vector<ll> segtree;
	ll size;
public:
	void init(ll n) {
		size = 1;
		while (size <= n)size = (size << 1);
		segtree.resize(size, LLONG_MAX);
	}
	void build(vl &a, ll node, ll low, ll high) {
		if (low == (high - 1)) {
			segtree[node] = a[low];
			return;
		}
		ll mid = low + (high - low) / 2;
		build(a, 2 * node + 1, low, mid);
		build(a, 2 * node + 2, mid, high);
		segtree[node] = min(segtree[2 * node + 1], segtree[2 * node + 2]);
	}
	void build(vl &a) {
		build(a, 0, 0, size);
	}
	ll query(ll node, ll &l, ll &r, ll low, ll high) {
		if (l >= high || r <= low)return LLONG_MAX;
		if (low >= l && high <= r)return segtree[node];
		ll mid = low + (high - low) / 2;
		ll lq = query(2 * node + 1, l, r, low, mid);
		ll rq = query(2 * node + 2, l, r, mid, high);
		return min(lq, rq);
	}
	ll query(ll l, ll r) {
		return query(0, l, r, 0, size);
	}
};

int main() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}
// for minimum

class SegmentTree {
private:
	ll size;
	vl segtree;
public:
	void init(ll n) {
		size = 1;
		while (size < n)size = size * 2;
		segtree.resize(2 * size, inf);
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
		segtree[root] = min(segtree[2 * root + 1], segtree[2 * root + 2]);
	}

	void build(vl &a) {
		build(a, 0, 0, size);
	}

	void set(ll &index, ll &value, ll root, ll left, ll right) {
		if ((right - left) == 1) {
			segtree[root] = value;
			return;
		}
		ll mid = left + (right - left) / 2;
		if (index < mid) {
			set(index, value, 2 * root + 1, left, mid);
		} else {
			set(index, value, 2 * root + 2, mid, right);
		}
		segtree[root] = min(segtree[2 * root + 1], segtree[2 * root + 2]);
	}

	void set(ll index, ll value) {
		set(index, value, 0, 0, size);
	}

	ll query(ll &l, ll &r, ll root, ll left, ll right) {
		if (l >= right || r <= left)return inf;
		if (left >= l && right <= r)return segtree[root];
		ll mid = left + (right - left) / 2;
		ll m1 = query(l, r, 2 * root + 1, left, mid);
		ll m2 = query(l, r, 2 * root + 2, mid, right);
		return min(m1, m2);
	}

	ll query(ll l, ll r) {
		return query(l, r, 0, 0, size);
	}
};

// for sum

class SegmentTree {
private:
	ll size;
	vl segtree;
public:
	void init(ll n) {
		size = 1;
		while (size < n)size *= 2;
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
		segtree[root] = segtree[2 * root + 1] + segtree[2 * root + 2];
	}

	void build(vl &a) {
		build(a, 0, 0, size);
	}

	void set(ll &index, ll &value, ll root, ll left, ll right) {
		if ((right - left) == 1) {
			segtree[root] = value;
			return;
		}
		ll mid = left + (right - left) / 2;
		if (index < mid) {
			set(index, value, 2 * root + 1, left, mid);
		} else {
			set(index, value, 2 * root + 2, mid, right);
		}
		segtree[root] = segtree[2 * root + 1] + segtree[2 * root + 2];
	}

	void set(ll index, ll value) {
		set(index, value, 0, 0, size);
	}

	ll query(ll &l, ll &r, ll root, ll left, ll right) {
		if (l >= right || r <= left)return 0;
		if (right <= r && left >= l)return segtree[root];
		ll mid = left + (right - left) / 2;
		ll sum1 = query(l, r, 2 * root + 1, left, mid);
		ll sum2 = query(l, r, 2 * root + 2, mid, right);
		return sum1 + sum2;
	}

	ll query(ll l, ll r) {
		return query(l, r, 0, 0, size);
	}
};

// for maximum

class SegmentTree {
private:
	vector<ll> segtree;
	ll size;
public:
	void init(ll n) {
		size = 1;
		while (size < n)size = size * 2;
		segtree.resize(2 * size, 0);
	}
	void build(vector<ll> &a, ll node, ll low, ll high) {
		if (low == (high - 1)) {
			if (low < a.size()) {
				segtree[node] = a[low];
			}
			return;
		}
		ll mid = low + (high - low) / 2;
		build(a, 2 * node + 1, low, mid);
		build(a, 2 * node + 2, mid, high);
		segtree[node] = max(segtree[2 * node + 1] , segtree[2 * node + 2]);
	}
	void build(vector<ll> &a) {
		build(a, 0, 0, size);
	}
	ll query(ll node, ll &l, ll &r, ll low, ll high) {
		if (high <= l || low >= r)return 0;
		if (low >= l && high <= r)return segtree[node];
		ll mid = low + (high - low) / 2;
		ll lq = query(2 * node + 1, l, r, low, mid);
		ll rq = query(2 * node + 2, l, r, mid, high);
		return max(lq , rq);
	}
	ll query(ll l, ll r) {
		return query(0, l, r, 0, size);
	}

	void set(ll &index, ll &value, ll root, ll left, ll right) {
		if ((right - left) == 1) {
			segtree[root] = value;
			return;
		}
		ll mid = left + (right - left) / 2;
		if (index < mid) {
			set(index, value, 2 * root + 1, left, mid);
		} else {
			set(index, value, 2 * root + 2, mid, right);
		}
		segtree[root] = max(segtree[2 * root + 1], segtree[2 * root + 2]);
	}

	void set(ll index, ll value) {
		set(index, value, 0, 0, size);
	}
};
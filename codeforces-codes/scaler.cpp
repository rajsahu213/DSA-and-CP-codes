#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
const ll mod = (1ll << 32);
inline ll mul(ll a, ll b) { return (a * 1ll * b) % mod; }
inline ll sub(ll a, ll b) { ll c = a - b; if (c < 0) c += mod; return c; }
inline ll add(ll a, ll b) { ll c = a + b; if (c >= mod) c -= mod; return c; }
inline ll max(ll a, ll b) {return a > b ? a : b;}
inline ll min(ll a, ll b) {return a < b ? a : b;}
inline ll ceil(ll a, ll b) {return (a % b == 0) ? (a / b) : (a / b + 1);}
const int MAXM = 300001, MAXN = 300001;
int n, q, TIME = 0, l;
const int bs = 950;
vector<int> tree[MAXN], up[MAXN];
ll w[MAXN], from[MAXN];
int p[MAXN], startTime[MAXN], endTime[MAXN], level[MAXN], id[MAXN << 1];
short occ[MAXN];
ll curr[MAXN];
int value[MAXN][2];

struct query {
	int id, l, r, lc;
} Q[MAXM];

bool cmp(query a, query b) {
	if (a.l / bs != b.l / bs)
		return a.l / bs < b.l / bs;
	return a.l / bs % 2 ? a.r < b.r : a.r > b.r;
}

void dfs(int &s, int &prev, ll &temp, int lev) {
	startTime[s] = ++TIME;
	id[TIME] = s;
	up[s][0] = prev;
	from[s] = add(mul(w[s], w[s]), temp);
	p[s] = prev;
	level[s] = lev;
	for (ll i = 1; i <= l; ++i)
		up[s][i] = up[up[s][i - 1]][i - 1];

	for (int x : tree[s]) {
		if (x != prev)
			dfs(x, s, from[s], lev + 1);
	}
	endTime[s] = ++TIME;
	id[TIME] = s;
}

inline bool is(int u, int v) {
	return startTime[u] <= startTime[v] && endTime[u] >= endTime[v];
}

inline int lca(int u, int v) {
	if (is(u, v))
		return u;
	if (is(v, u))
		return v;
	for (int i = l; i >= 0; --i) {
		if (!is(up[u][i], v))
			u = up[u][i];
	}
	return up[u][0];
}

void adding(int &node, ll &res, int &u, int &v) {
	if (occ[node] == 1) {
		if (value[level[node]][0] != -1 && value[level[node]][1] != -1) {
			if (mul(w[value[level[node]][0]], w[value[level[node]][1]]) == curr[level[node]]) {
				res = sub(res, curr[level[node]]);
				curr[level[node]] = 0;
			}
		}
	}
	occ[node] ^= 1;
	if (occ[node] == 1) {
		if (is(node, u)) {
			if (value[level[node]][0] != -1 && value[level[node]][1] != -1) {
				if (mul(w[value[level[node]][0]], w[value[level[node]][1]]) == curr[level[node]]) {
					res = sub(res, curr[level[node]]);
					curr[level[node]] = 0;
				}
				if (is(value[level[node]][1], v)) {
					curr[level[node]] = mul(w[node], w[value[level[node]][1]]);
					res = add(res, curr[level[node]]);
				}
			} else if (value[level[node]][1] != -1) {
				if (is(value[level[node]][1], v)) {
					curr[level[node]] = mul(w[node], w[value[level[node]][1]]);
					res = add(res, curr[level[node]]);
				}
			}
			value[level[node]][0] = node;
		} else if (is(node, v)) {
			if (value[level[node]][0] != -1 && value[level[node]][1] != -1) {
				if (mul(w[value[level[node]][0]], w[value[level[node]][1]]) == curr[level[node]]) {
					res = sub(res, curr[level[node]]);
					curr[level[node]] = 0;
				}
				if (is(value[level[node]][0], u)) {
					curr[level[node]] = mul(w[value[level[node]][0]], w[node]);
					res = add(res, curr[level[node]]);
				}
			} else if (value[level[node]][0] != -1) {
				if (is(value[level[node]][0], u)) {
					curr[level[node]] = mul(w[node], w[value[level[node]][0]]);
					res = add(res, curr[level[node]]);
				}
			}
			value[level[node]][1] = node;
		}
	}
	return;
}

void compute() {
	int curL = Q[0].l, curR = Q[0].l - 1;
	ll res = 0;
	vl ans(q);
	for (int i = 0; i < q; i++) {
		if (id[Q[i].l] == id[Q[i].r]) {
			ans[Q[i].id] = from[Q[i].lc];
			continue;
		} else {
			int u = id[Q[i].l], v = id[Q[i].r];
			while (curL < Q[i].l) {
				adding(id[curL], res, u, v);
				curL++;
			}
			while (curL > Q[i].l) {
				curL--;
				adding(id[curL], res, u, v);
			}
			while (curR < Q[i].r) {
				curR++;
				adding(id[curR], res, u, v);
			}
			while (curR > Q[i].r) {
				adding(id[curR], res, u, v);
				curR--;
			}
			ans[Q[i].id] = res;
			ans[Q[i].id] = add(ans[Q[i].id], from[Q[i].lc]);
		}
	}
	for (int i = 0; i < q; i++) printf("%lld\n", ans[i]);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d %d", &n, &q);
	l = ceil(log2(n));
	f(n)up[i].resize(l + 1);
	f(n)scanf("%lld", &w[i]);
	f(n - 1) {
		int u, v;
		scanf("%d %d", &u, &v);
		u--; v--;
		tree[u].pb(v);
		tree[v].pb(u);
	}
	int temp = 0; ll temp1 = 0;
	dfs(temp, temp, temp1, temp);
	memset(value, -1, sizeof(value));
	memset(curr, 0, sizeof(curr));
	for (int i = 0; i < q; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		u--; v--;
		Q[i].lc = lca(u, v);
		if (startTime[u] > startTime[v]) swap(u, v);
		if (Q[i].lc == u) Q[i].l = startTime[u], Q[i].r = startTime[v];
		else Q[i].l = endTime[u], Q[i].r = startTime[v];
		Q[i].id = i;
	}
	sort(Q, Q + q, cmp);
	compute();
}
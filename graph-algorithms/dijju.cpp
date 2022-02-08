#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll inf = 1e18;
vector<vector<pair<ll, ll>>> graph;
ll n, m;
void dijju1(ll s, vector<ll> &d, vector<ll> &p) {
	d.assign(n, inf);
	p.assign(n, -1);
	d[s] = 0;
	vector<bool> vis(n, false);
	for (ll t = 0; t < n; t++) {
		ll u = -1;
		for (ll i = 0; i < n; i++) {
			if (!vis[i] && (u == -1 || d[i] < d[u])) {
				u = i;
			}
		}
		if (d[u] == inf)break;
		vis[u] = true;
		for (auto x : graph[u]) {
			ll v = x.first, w = x.second;
			if (d[v] > d[u] + w) {
				d[v] = d[u] + w;
				p[v] = u;
			}
		}
	}
}

void dijju2(ll s, vector<ll> &d, vector<ll> &p) {
	d.assign(n, inf);
	p.assign(n, -1);
	d[s] = 0;
	set<pair<ll, ll>> q;
	q.insert({d[s], s});
	while (!q.empty()) {
		ll u = q.begin()->second;
		q.erase(q.begin());
		for (auto x : graph[u]) {
			ll v = x.first, w = x.second;
			if (d[v] > d[u] + w) {
				q.erase({d[v], v});
				d[v] = d[u] + w;
				p[v] = u;
				q.insert({d[v], v});
			}
		}
	}
}

void dijju3(ll s, vector<ll> &d, vector<ll> &p) {
	d.assign(n, inf);
	p.assign(n, -1);
	using pll = pair<ll, ll>;
	priority_queue<pll, vector<pll>, greater<pll>> q;
	d[s] = 0; q.push({d[s], s});
	while (!q.empty()) {
		pll temp = q.top(); q.pop();
		ll u = temp.second, du = temp.first;
		if (du != d[u])continue;
		for (pll x : graph[u]) {
			ll v = x.first, w = x.second;
			if (d[v] > d[u] + w) {
				d[v] = d[u] + w;
				p[v] = u;
				q.push({d[v], v});
			}
		}
	}
}
void Dijkstra(ll s, vector<ll> &d, vector<ll> &p) {
	vector<bool> vis(n, false);
	d[s] = 0;
	set<pair<ll, ll>> q; q.insert({d[s], s});
	while (!q.empty()) {
		ll u = q.begin()->second;
		q.erase(q.begin());
		for (pair<ll, ll> x : graph[u]) {
			ll v = x.first, w = x.second;
			if (d[v] > d[u] + w) {
				q.erase({d[v], v});
				d[v] = d[u] + w;
				p[v] = u;
				q.insert({d[v], v});
			}
		}
	}
}
void printPath(ll d, vector<ll> &p) {
	vector<ll> path;
	for (ll x = d; x != -1; x = p[x]) {
		path.push_back(x);
	}
	reverse(path.begin(), path.end());
	for (ll x : path) {
		cout << x + 1 << " ";
	} cout << endl;
}
int main() {
	cin >> n >> m;
	graph.resize(n);
	for (ll i = 0; i < m; i++) {
		ll u, v, w; cin >> u >> v >> w;
		u--; v--;
		graph[u].push_back({v, w});
		graph[v].push_back({u, w});
	}
	ll s = 0;
	vector<ll> d(n, inf), p(n, -1);
	dijju2(s, d, p);
	ll t = n - 1;
	if (d[t] != inf)printPath(t, p);
	else cout << "-1" << endl;
}

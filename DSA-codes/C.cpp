#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll maxn = 1e4 + 5;
vector<ll> graph[maxn];
ll p[maxn], color[maxn], height[maxn];
ll has[maxn][2];
ll u, v, n;
void dfs(ll s, ll h) {
	color[s] = 1;
	height[s] = h;
	if (s == u) {
		has[s][0] = true;
	}
	if (s == v) {
		has[s][1] = true;
	}
	for (ll x : graph[s]) {
		if (color[x] == 0) {
			dfs(x, h + 1);
		}
		has[s][0] = has[s][0] || has[x][0];
		has[s][1] = has[s][1] || has[x][1];
	}
}

int main() {
	cin >> n;
	cin >> u >> v;
	u--; v--; memset(p, -1, sizeof(p));
	for (ll i = 0; i < n; i++) {
		ll x, y; cin >> x >> y;
		x--; y--;
		p[y] = x;
		graph[x].push_back(y);
	}
	memset(color, 0, sizeof(color));
	memset(has, false, sizeof(has));
	for (ll i = 0; i < n; i++) {
		if (p[i] == -1) {
			dfs(i, 0);
		}
	}
	ll ans = -1, h = -1;
	for (ll i = 0; i < n; i++) {
		if (has[i][0] && has[i][1]) {
			if (height[i] > h) {
				h = height[i];
				ans = i + 1;
			}
		}
	}
	cout << ans << endl;
}
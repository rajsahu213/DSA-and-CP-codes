#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
bool OK(ll n, ll l, ll r) {
	return n >= l && n <= r;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif
	ll n, m; cin >> n >> m;
	if (!OK(n, 2, 1000) || !OK(m, 2, 1000)) {
		cout << "Error in N or M" << endl;
		return 0;
	}
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= m; j++) {
			ll a; cin >> a;
			if (i == 1 && j == 1 && a != 0) {
				cout << "6th block is not sanitized" << endl;
				return 0;
			}
			if (!OK(a, 0, 1000000000)) {
				cout << "Error in value of A" << endl;
				return 0;
			}
		}
	}
}

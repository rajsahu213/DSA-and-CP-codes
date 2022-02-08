#include<bits/stdc++.h>
using namespace std;

int main() {
	using ll = long long int;
	ll n; cin >> n;
	vector<ll> a(n);
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}
	ll ans = 0;
	for (ll i = 0; i < n; i++) {
		ans += a[i];
	}
	cout << ans << endl;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int fun(string &a) {
	int ans = 0;
	for (char x : a) {
		ans += (x - 'a') + 1;
	}
	return ans;
}
int fun1(vector<pair<int, string>> &a, int l, int r) {
	int n = r - l;
	int mean;
	if (n & 1) {
		mean = a[l + n / 2].first;
	} else {
		mean = (a[l + n / 2].first + a[l + n / 2 - 1].first) / 2;
	}
	int ans = 0;
	for (int i = l; i < r; i++) {
		ans += abs(a[i].first - mean);
	}
	return ans;
}
int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<pair<int, string>> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i].second;
			a[i].first = fun(a[i].second);
		}
		sort(a.begin(), a.end());
		if (fun1(a, 0, n - 1) > fun1(a, 1, n)) {
			cout << a[0].second << "\n";
		} else {
			cout << a[n - 1].second << "\n";
		}
	}
}
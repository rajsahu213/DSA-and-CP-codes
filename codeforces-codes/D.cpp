#include<bits/stdc++.h>
using namespace std;

const int maxn = 10002, mod = 1e9 + 7;

int dp[maxn];

int rec(string &s, int low, int high) {
	if (low >= high) {
		return 1;
	} else if (dp[low] != -1) {
		return dp[low];
	} else {
		long long ans = rec(s, low + 1, high);
		int temp = s[low] - '0';
		temp = temp * 10 + s[low + 1] - '0';
		if (temp <= 25 && s[low] != '0') {
			ans = (ans % mod + rec(s, low + 2, high) % mod) % mod;
		}
		return dp[low] = ans;
	}
}

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		string s; cin >> s;
		memset(dp, -1, sizeof(dp));
		cout << rec(s, 0, n - 1) << "\n";
	}
}
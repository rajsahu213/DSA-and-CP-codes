#include<bits/stdc++.h>
using namespace std;

int dp[maxn];
int rec(vector<int> &a, int low, int high, int k) {
	if (low == high) {
		return a[high];
	} else if (dp[low] != -1) {
		return dp[low
		         ];
	}
	else {
		int ans =  a[low] + rec(a, low + 1, high, k);
		for (int i = low + 2; i <= min(high, low + k); i++) {
			ans = max(ans, a[low] + rec(a, i, high, k));
		}
		return dp[low] = ans;
	}
}

int main() {
	int n, k; cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	memset(dp, sum + 1, sizeof(dp));
	int ans = 0;
	for (int i = 1; i <= min(k, n - 1); i++) {
		ans = max(ans, a[0] + rec(a, i, n - 1, k));
	}
	cout << ans << endl;
}

pair<int, int> fun(string &a) {
	pair<int, int> ans;
	string temp = "";
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == ' ') {
			ans.first = stoi(temp);
			temp = "";
		} else {
			temp.push_back(a[i]);
		}
	}
	ans.second = stoi(temp);
	return ans;
}

long countMax(vector<string> input) {
	int n = input.size();
	long r = INT_MAX, c = INT_MAX;
	for (int i = 0; i < n; i++) {
		pair<int, int> temp = fun(input[i]);
		r = min(r, temp.first);
		c = min(c, temp.second);
	}
	return r * c;
}
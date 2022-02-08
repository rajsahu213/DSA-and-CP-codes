#include<bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, d; cin >> n >> d;
	vector<vector<pair<int, int>>> a(d, vector<pair<int, int>>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < d; j++) {
			cin >> a[j][i].first >> a[j][i].second;
		}
	}
	for (int day = 0; day < d; day++) {
		map<int, int> mp;
		priority_queue<int, vector<int>, greater<int>> q2;
		for (int i = 0; i < n; i++) {
			if (a[day][i].first > a[day][i].second) {
				mp[(a[day][i].first - a[day][i].second)]++;
			} else if (a[day][i].first < a[day][i].second) {
				q2.push(a[day][i].second - a[day][i].first);
			}
		}
		int ans = 0;
		while (!q2.empty()) {
			int want = q2.top(); q2.pop();
			int have;
			if (mp.lower_bound(want) != mp.end()) {
				auto i = mp.lower_bound(want);
				int have = i->first;
				if (i->second > 0) {
					i->second--;
				} else {
					mp.erase(have);
				}
			} else {
				auto i = mp.rend();
				int have = i->first;
				if (i->second > 0) {
					i->second--;
				} else {
					mp.erase(have);
				}
			}
			if (have > want) {
				mp[have - want]++;
			}
			ans++;
		}
		cout << ans << endl;
	}
}
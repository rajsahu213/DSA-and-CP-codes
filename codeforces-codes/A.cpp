#include<bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> a, vector<vector<int>> q) {
	int currId = 1;
	vector<int> ans(q.size()), ids(a.size(), 0);
	for (int times = 0; times < q.size(); times++) {
		if (q[times][0] == 0) {
			int x = q[times][1];
			int last = 0, index = -1;
			for (int i = 0; i < a.size(); i++) {
				if (a[i] == 0) {
					last++;
				} else {
					last = 0;
				}
				if (last == x) {
					index = i - x + 1;
					break;
				}
			}
			if (index == -1) {
				ans[times] = -1;
			} else {
				ans[times] = index;
				for (int i = 0; i < x; i++) {
					a[index + i] = 1;
					ids[index + i] = currId;
				}
			}
			currId++;
		} else {
			int id = q[times][1], s = 0;
			for (int i = 0; i < a.size(); i++) {
				if (ids[i] == id && a[i] == 1) {
					a[i] = 0;
					s++;
				}
			}
			ans[times] = ((s == 0) ? -1 : s);
		}
	}
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector<int> a = {0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0};
	vector<vector<int>> q = {{0, 2}, {0, 1}, {0, 1}, {1, 2}, {1, 4}, {0, 4}};
	vector<int> ans = solution(a, q);
	for (int x : ans) {
		cout << x << endl;
	}
}
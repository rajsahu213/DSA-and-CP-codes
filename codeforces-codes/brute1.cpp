#include<bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	long long int mod = 1e9 + 7;
	while (t--) {
		int n;
		cin >> n;
		vector<long long int> arr(n + 1);
		int p = 0;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}
		vector<long long int> pre(n + 1);
		pre[0] = 0;
		pre[1] = arr[1];
		long long int temp = 0;
		if (arr[1] != 1) {
			for (int i = 2; i <= n; i++) {
				if (arr[i - 1] != 1 && arr[i - 1] % 2 != 0) {
					pre[i] = (((pre[i - 1] % mod) - (1 % mod)) % mod + arr[i] % mod) % mod;
				}
				else if (arr[i - 1] % 2 == 0) {
					pre[i] = (pre[i - 1] % mod + arr[i] % mod) % mod;
				}
				else if (arr[i - 1] == 1) {
					if (arr[i - 2] % 2 != 0) {
						pre[i] = (pre[i - 2] % mod + arr[i] % mod) % mod;
					}
					else {
						pre[i] = (((pre[i - 2] % mod) - (1 % mod)) % mod + arr[i] % mod) % mod;
					}
				}
			}
			if (arr[n] % 2 == 0) {
				temp++;
			}
		}
		int q;
		cin >> q;
		while (q--) {
			long long int r;
			cin >> r;
			if (arr[1] == 1) {
				long long int x = ceil((float)r / n);
				if (r % n == 1 && r != 1)
					x = ((x % mod) - (1 % mod)) % mod;
				cout << x % mod << "\n";
			}
			else {
				long long int ans = 0;
				long long int x = r / n;
				long long int y = r % n;
				if (temp != 1) {
					ans = ((x % mod) * (pre[n] % mod)) % mod;
					ans = ((ans % mod) + (pre[y] % mod)) % mod;
				}
				else {
					long long int z = x;
					if (y == 0)
						z--;
					ans = ((ans % mod) + ((((pre[n] % mod) - (1 % mod)) % mod) * (z % mod)) % mod) % mod;
					if (y == 0) {
						y = n;
					}
					ans = ((ans % mod) + (pre[y] % mod)) % mod;
				}
				cout << ans % mod << "\n";
			}
		}
	}
}

#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n, ans = 0;
int a[N];
map<int, int> m;
vector<int> v;

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		m[a[i]]++;
	}
	for(auto &it:m)
	{
		if(it.second > 1)
			ans = max(ans, it.first);
		v.push_back(it.first);
	}
	reverse(v.begin(), v.end());
	for(int i = 0; i < v.size(); i++)
	{
		for(int j = i + 1; j < v.size() && j < i + 100; j++)
		{
			int cur = v[i] * v[j] / __gcd(v[i], v[j]);
			ans = max(ans, cur);
		}
	}
	cout << ans;
	return 0;
}
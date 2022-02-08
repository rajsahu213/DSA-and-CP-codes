//snigdh_op
#include<bits/stdc++.h>
using namespace std;
#define fio ios_base::sync_with_stdio(false)

struct tnode {
	tnode *ptr[26] = {NULL};
	bool isWord = false;
};
typedef tnode* TTPTR;
void add(TTPTR &T, string &s, int i)
{
	int k = int(s[i]) - 97;
	if (i == s.length() - 1)
	{
		if (T->ptr[k])
			T->ptr[k]->isWord = true;

		else
		{
			T->ptr[k] = new tnode;
			T->ptr[k]->isWord = true;
		}
		return ;
	}
	else
	{	i++;
		if (!T->ptr[k])
			T->ptr[k] = new tnode;
		add(T->ptr[k], s, i);
	}
}
int fill(TTPTR &T, unordered_map<int, int>&mp)
{
	if (!T)return 0;
	int ans = 0;
	if (T->isWord)ans++;
	for (int i = 0; i < 26; i++)ans += fill(T->ptr[i], mp);
	mp[ans]++;
	return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fio;
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<string> inp(n);
	for (int i = 0; i < n; i++)cin >> inp[i];
	int m;
	cin >> m;
	TTPTR T = new tnode;

	for (int i = 0; i < n; i++)
	{
		add(T, inp[i], 0);
	}
	unordered_map<int, int>mp;
	int res = fill(T, mp);
	for (int i = n - 1; i >= 1; i--)mp[i] += mp[i + 1];
	while (m--)
	{
		int k;
		cin >> k;
		cout << mp[k] - 1 << "\n";
	}
	return 0;
}
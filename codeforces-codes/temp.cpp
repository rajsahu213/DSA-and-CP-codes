vector<int> binary(int a) {
	vector<int> ans;
	while (a) {
		ans.push_back(a % 2);
		a = a / 2;
	}
	return ans;
}
void fun(map<string, vector<int>> &d) {
	map<string, vector<int>> diff;
	for (auto i : d) {
		vector<int> a = i.second;
		int last = 0;
		for (int i = 0; i < a.size(); i++) {
			diff[i.first].push_back(a[i] - last);
			last = a[i];
		}
	}
	map<string, vector<int>> f;
	for (auto i : diff) {
		for (int x : i.second) {
			vector<int> num = binary(x);
			vector<int> range = binary(num.size());
			reverse(range.begin(), range.end());
			range.pop_back();
			reverse(range.begin(), range.end());
			for (int x1 : range) {
				f[i.first].push_back(x1);
			}
			for (int x1 : num) {
				f[i.first].push_back(x1);
			}
		}
	}
}
#include<bits/stdc++.h>
using namespace std;
double min_conf;
bool join_step(vector<string> &a, vector<string> &b, int common) {
	int k = 0;
	while (k < a.size() && k < b.size() && a[k] == b[k])k++;
	return k == common;
}

bool prune(vector<vector<string>> &l, vector<string> &c) {
	int k = c.size() - 1;
	for (int i = 0; i < c.size(); i++) {
		vector<string> temp;
		for (int j = 0; j < c.size(); j++) {
			if (i != j) {
				temp.push_back(c[j]);
			}
		}
		if (find(l.begin(), l.end(), temp) == l.end()) {
			return false;
		}
	}
	return true;
}

int support(set<string> &i, vector<set<string>> &a) {
	int cnt = 0;
	for (int j = 0; j < a.size(); j++) {
		int count = 0;
		for (string x : a[j]) {
			if (i.find(x) != i.end()) {
				count++;
			}
		}
		if (count == (int)i.size()) {
			cnt++;
		}
	}
	return cnt;
}

void print(set<string> &a) {
	cout << "{ ";
	for (auto i : a)cout << i << " ";
	cout << "}";
}

void association(vector<string> &a, vector<set<string>> &inp) {
	int n = a.size();
	set<string> temp(a.begin(), a.end());
	int sup_xy = support(temp, inp);
	for (int bit = 1; bit < (1 << n) - 1; bit++) {
		set<string> x, y;
		for (int i = 0; i < n; i++) {
			if (bit & (1 << i)) {
				x.insert(a[i]);
			} else {
				y.insert(a[i]);
			}
		}
		int sup_x = support(x, inp);
		int sup_y = support(y, inp);
		double confidence = (double)sup_xy / sup_x;
		if (confidence >= min_conf) {
			// cout << "confidence " << (double)sup_xy / sup_x << endl;
			print(x);
			cout << " - > ";
			print(y);
			cout << endl;
		}
	}
}

int main() {
	freopen("input1.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int num; cin >> num; //number of transactions
	vector<set<string>> a(num);
	for (int i = 0; i < num; i++) {
		int n; cin >> n; //number of items;
		for (int j = 0; j < n; j++) {
			string item; cin >> item;
			a[i].insert(item);
		}
	}
	int min_sup; cin >> min_sup; //minimum support count
	cin >> min_conf;
	map<string, int> mp;
	for (int i = 0; i < num; i++) {
		for (string x : a[i]) {
			mp[x]++;
		}
	}
	set<set<string>> l;
	cout << "1th item set" << endl;
	for (auto i : mp) {
		set<string> t;
		if (i.second >= min_sup) {
			cout << "{ " << i.first << " }" << endl;
			t.insert(i.first);
			l.insert(t);
		}
	}
	int common = 0;
	while (l.size() > 0) {
		cout << common + 2 << "th item set" << endl;
		vector<vector<string>> temp;
		for (auto i : l) {
			vector<string> c(i.begin(), i.end());
			temp.push_back(c);
		}
		l.clear();
		for (int i = 0; i < temp.size() - 1; i++) {
			for (int j = i + 1; j < temp.size(); j++) {
				if (join_step(temp[i], temp[j], common)) {
					set<string> new_c;
					for (int k = 0; k < temp[i].size(); k++) {
						new_c.insert(temp[i][k]);
					}
					for (int k = 0; k < temp[j].size(); k++) {
						if (new_c.find(temp[j][k]) == new_c.end()) {
							new_c.insert(temp[j][k]);
						}
					}
					vector<string> temp1(new_c.begin(), new_c.end());
					if (prune(temp, temp1)) {
						l.insert(new_c);
					}
				}
			}
		}
		set<set<string>> new_l;
		for (auto i : l) {
			if (support(i, a) >= min_sup) {
				new_l.insert(i);
			}
		}
		l = new_l;
		for (auto i : l) {
			cout << "{ ";
			for (string x : i) {
				cout << x << " ";
			}
			cout << "}" << endl;
		}
		cout << "Association of " << common + 2 << " size item set are " << endl;
		for (auto i : l) {
			vector<string> temp(i.begin(), i.end());
			association(temp, a);
		}
		common++;
	}
}
#include <bits/stdc++.h>
#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>
using namespace std;

long long int rand(long long int a, long long int b) {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution<long long int>(a, b)(rng);
}

int main() {
	freopen("input1.txt", "w", stdout);
	int n = rand(3, 10);
	int d = rand(1, 10);
	cout << n << " " << d << endl;
	for (int i = 1; i <= n; i++) {
		int sum1 = 0, sum2 = 0;
		vector<int> supply, demand;
		do {
			supply.clear();
			demand.clear();
			sum1 = 0, sum2 = 0;
			for (int j = 0; j < d; j++) {
				int x = rand(1, 100), y = rand(1, 100);
				sum1 += x;
				sum2 += y;
				supply.push_back(x);
				demand.push_back(y);
			}
		} while (sum1 < sum2);
		assert()
		for (int j = 0; j < d; j++) {
			cout << supply[j] << " " << demand[j] << endl;
		}

	}
	cout << endl;
}
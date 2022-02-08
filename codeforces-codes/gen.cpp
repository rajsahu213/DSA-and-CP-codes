#include <bits/stdc++.h>

using namespace std;
int rand(int a, int b) {
	return a + rand() % (b - a + 1);
}

int main() {
	freopen("input1.txt", "w", stdout);
	srand(time(0));
	int t = rand() % 100 + 1;
	cout << t << endl;
	while (t--) {
		int w = rand() % 1000 + 1;
		long long n = rand() % 1000 + 1;
		cout << w << " " << n << endl;
		for (int i = 0; i < w; i++) {
			cout << rand() % n + 1 << " ";
		}
		cout << endl;
	}
}
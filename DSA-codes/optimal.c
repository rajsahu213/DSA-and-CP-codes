#include<stdio.h>

int fun(int sz, int * arr, int val) {
	for (int i = 0; i < sz; i++) {
		if (arr[i] == val)
			return 1;
	}
	return 0;
}

int closestIndex(int sz, int currL, int * arr,  int val, int dir) {
	int i = currL;
	if (dir == -1) {
		for (i--; i >= 0; i--) {
			if (arr[i] == val)
				return i;
		}
		return i;
	}
	else {
		for (i++; i < sz; i++) {
			if (arr[i] == val) {
				return i;
			}
		}
		return i;
	}
}

int extreme(int sz, int * arr, int type) {
	int extreme = 0;
	if (type == 1) { //max
		int i = 0;
		int max = arr[0];
		for (i++; i < sz; i++) {
			if (arr[i] > max) {
				max = arr[i];
				extreme = i;
			}
		}
		return extreme;
	}
	else {
		int i = 0;
		int min = arr[0];
		for (i++; i < sz; i++) {
			if (arr[i] < min) {
				min = arr[i];
				extreme = i;
			}
		}
		return extreme;
	}
}
int main() {
	int n, m, i;
	printf("Enter the number of page requests: ");
	scanf("%d", &n);
	printf("Enter the number of pages: ");
	scanf("%d", &m);
	int curr[m], requests[n], nextIndex[m];
	printf("Enter the page requests separated by space: \n");
	for (i = 0; i < n; i++) scanf("%d", &requests[i]);
	int faults = 0, index = -1;
	for (i = 0; i < m; i++) curr[i] = -1;
	int filledBlocks = 0;
	faults = 0;
	index = -1;
	for (i = 0; i < n; i++) {
		if (fun(filledBlocks, curr, requests[i])) continue;
		else {
			if (filledBlocks == m) {
				int j = 0;
				for (; j < m; j++) {
					nextIndex[j] = 	closestIndex(n, i, requests , curr[j], 1);
				}
				int farest = extreme(m, nextIndex, 1);
				curr[farest] = requests[i];
			}
			else {
				curr[(++index) % m] = requests[i];
				filledBlocks++;
			}
			faults++;
		}
	}
	printf("\nOptimal: \n");
	printf("\tPage faults : %d\n", faults);
	printf("\t       Hits : %d\n", n - faults);
	printf("\t  Hit Ratio : %.2f%%\n", (n - faults) * 100.0 / n);

}
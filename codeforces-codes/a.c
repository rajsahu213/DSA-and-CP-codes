#include <stdio.h>
#include <stdlib.h>
#define ll long long int

int comp (const void * elem1, const void * elem2) {
	ll f = *((ll*)elem1);
	ll s = *((ll*)elem2);
	if (f > s) return  1;
	if (f < s) return -1;
	return 0;
}

ll lowerBound(ll a[], ll n, ll x) {
	ll low = 0, high = n - 1;
	while (low < high) {
		ll mid = low + (high - low) / 2;
		if (a[mid] >= x) {
			high = mid;
		} else {
			low = mid + 1;
		}
	}
	return low;
}

ll upperBound(ll a[], ll n, ll x) {
	ll low = 0, high = n;
	while (low < high) {
		ll mid = low + (high - low) / 2;
		if (a[mid] <= x) {
			low = mid + 1;
		} else {
			high = mid;
		}
	}
	return low;
}

int main() {
	ll n, k;
	scanf("%lld %lld", &n, &k);
	ll a[n];
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
	}
	ll x; scanf("%lld", &x);
	ll sums[n - k + 1], sum = 0, len = 0;
	for (int i = 0; i < k; i++) {
		sum += a[i];
	}
	sums[len++] = sum;
	for (int i = k; i < n; i++) {
		sum += a[i];
		sum -= a[i - k];
		sums[len++] = sum;
	}
	ll temp1[len], temp2[len];
	for (ll i = 0; i < len; i++) {
		temp1[i] = sums[i] * k;
		temp2[i] = sums[i] * k;
	}
	qsort (temp1, sizeof(temp1) / sizeof(*temp1), sizeof(*temp1), comp);
	qsort (temp2, sizeof(temp2) / sizeof(*temp2), sizeof(*temp2), comp);
	ll ans = 0;
	for (ll i = 0; i < len; i++) {
		ll curr = temp1[i];
		ll target = x - curr;
		ll t1 = lowerBound(temp2, len, target), t2 = upperBound(temp2, len, target);
		ans += t2 - t1;
	}
	printf("%lld\n", ans);
}
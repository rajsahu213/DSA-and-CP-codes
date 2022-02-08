#include <bits/stdc++.h>
using namespace std;

#define fio 					ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define watch(x) 				cout << (#x) << " is " << (x) << endl
#define f(t) 					for(ll i=0;i<t;i++)
#define ll 						long long int
#define ld 						long double
#define umpl 					unordered_map<ll,ll>
#define vl 						vector<ll>
#define vld 					vector<ld>
#define vvl 					vector<vl>
#define pb 						push_back
#define pll 					pair<ll,ll>
#define inf 					1e18
#define pcout(x,p) 				cout<<fixed<<setprecision(p)<<x
#define all(a) 					a.begin(),a.end()
#define sz(a) 					(ll)a.size()
#define endl 					"\n"


const ll mod = 1e9 + 7;
inline ll mul(ll a, ll b) { ll c = (a * 1ll * b) % mod; if (c < 0) c += mod; return c; }
inline ll sub(ll a, ll b) { ll c = a - b; if (c < 0) c += mod; return c; }
inline ll add(ll a, ll b) { ll c = a + b; if (c >= mod) c -= mod; return c; }
inline ll max(ll a, ll b) {return a > b ? a : b;}
inline ll min(ll a, ll b) {return a < b ? a : b;}
inline ll ceil(ll a, ll b) {return (a % b == 0) ? (a / b) : (a / b + 1);}

template<class T> ostream& operator<<(ostream &os, vector<T> V) {
	for (auto v : V) os << v << " ";
	return os;
}
template<class T> ostream& operator<<(ostream &os, set<T> S) {
	os << "{ ";
	for (auto s : S) os << s << " ";
	return os << "}";
}
template<class L, class R> ostream& operator<<(ostream &os, pair<L, R> P) {
	return os << "(" << P.first << "," << P.second << ")";
}
template<class L, class R> ostream& operator<<(ostream &os, map<L, R> M) {
	os << "{ ";
	for (auto m : M) os << "(" << m.first << ":" << m.second << ") ";
	return os << "}";
}

const ll maxn = 300005;
const int MAXA = maxn;
const int MAXN = maxn;
const int MAXQ = maxn;

int a[MAXN];
typedef tuple<int, int, int, int> Query;
Query query[MAXQ];

inline void moAlgorithm(const int n, const int a[], const int q, tuple<int, int, int, int> query[])
{
	const int blockSize = (int)sqrt((long double)n);

	const auto getLeft = [](const Query & q) {return get<0>(q); };
	const auto getRight = [](const Query & q) {return get<1>(q); };
	const auto getBlockIndex = [ = ](const Query & q) {return getLeft(q) / blockSize; };

	sort(query, query + q, [ = ](const Query & a, const Query & b) {
		return
		    getBlockIndex(a) < getBlockIndex(b) ||
		    getBlockIndex(a) == getBlockIndex(b) && getRight(a) > getRight(b);
	});

	static int count[MAXA + 1];
	memset(count, 0, sizeof(count));
	static int numberOfValuesWithCount[MAXN + 1];
	memset(numberOfValuesWithCount, 0, sizeof(*numberOfValuesWithCount) * (n + 1));
	int maxCount = 0;

	const auto remove = [&](const int index) {
		--numberOfValuesWithCount[count[a[index]]];
		if (count[a[index]] == maxCount && numberOfValuesWithCount[count[a[index]]] == 0)
		{
			--maxCount;
		}
		--count[a[index]];
		++numberOfValuesWithCount[count[a[index]]];

	};
	const auto add = [&](const int index) {
		--numberOfValuesWithCount[count[a[index]]];
		if (count[a[index]] == maxCount)
		{
			++maxCount;
		}
		++count[a[index]];
		++numberOfValuesWithCount[count[a[index]]];
	};

	int left = 0, right = -1;

	for (int i = 0; i < q; ++i)
	{
		for (; left < getLeft(query[i]); ++left)
		{
			remove(left);
		}
		for (; left > getLeft(query[i]); )
		{
			add(--left);
		}
		for (; right < getRight(query[i]); )
		{
			add(++right);
		}
		for (; right > getRight(query[i]); --right)
		{
			remove(right);
		}
		get<3>(query[i]) = maxCount;
	}

	sort(query, query + q, [ = ](const Query & a, const Query & b) {
		return get<2>(a) < get<2>(b);
	});
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fio;
	int n, q; cin >> n >> q;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int k = 0; k < q; ++k) {
		int l, r;
		cin >> l >> r;
		l--; r--;
		get<0>(query[k]) = l; get<1>(query[k]) = r;
		get<2>(query[k]) = k;
	}
	moAlgorithm(n, a, q, query);
	for (int k = 0; k < q; ++k) {
		ll x = get<3>(query[k]);
	}
}

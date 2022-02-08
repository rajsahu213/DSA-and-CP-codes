/*█▀▀▄░░░░░░░░░░░▄▀▀█
░█░░░▀▄░▄▄▄▄▄░▄▀░░░█
░░▀▄░░░▀░░░░░▀░░░▄▀
░░░░▌░▄▄░░░▄▄░▐▀▀
░░░▐░░█▄░░░▄█░░▌▄▄▀▀▀▀█
░░░▌▄▄▀▀░▄░▀▀▄▄▐░░░░░░█
▄▀▀▐▀▀░▄▄▄▄▄░▀▀▌▄▄▄░░░█
█░░░▀▄░█░░░█░▄▀░░░░█▀▀▀
░▀▄░░▀░░▀▀▀░░▀░░░▄█▀
░░░█░░░░░░░░░░░▄▀▄░▀▄
░░░█░░░░░░░░░▄▀█░░█░░█
░░░█░░░░░░░░░░░█▄█░░▄▀
░░░█░░░░░░░░░░░████▀
░░░▀█▄▄▄▀▀▀▀▄▄▄█▀*/

#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
using namespace std;

#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define watch(x) cout << (#x) << " is " << (x) << endl
#define f(t) for(ll i =0;i<t;i++)
#define bs(a,x) binary_search(a.begin(),a.end(),x)
#define ll long long int
#define ul unsigned long int
#define ld long double
#define umpi unordered_map<int,int>
#define umpl unordered_map<ll,ll>
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define mod 1000000007
#define N 10000000
#define all(a) a.begin(),a.end()
#define point pair<int,int>
const int inf = 1000000007;
const ll linf = 1ll * inf * inf;
const ll MAXIMUM = 1e5 + 4;

inline ll mul(ll a, ll b) { return (a * 1ll * b) % mod; }
inline ll sub(ll a, ll b) { ll c = a - b; if (c < 0) c += mod; return c; }
inline ll add(ll a, ll b) { ll c = a + b; if (c > mod) c -= mod; return c; }

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1> {}(p.first);
        auto hash2 = hash<T2> {}(p.second);
        return hash1 ^ hash2;
    }
};

ll spf[N];
const ll nax = N;

void sieve() {
    spf[1] = 1;
    for (ll i = 2; i < nax; i++) spf[i] = i;
    for (ll i = 4; i < nax; i += 2) spf[i] = 2;
    for (ll i = 3; i * i < nax; i++) {
        if (spf[i] == i) {
            for (ll j = i * i; j < nax; j += i)
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}


unordered_map<ll, ll> f;

ll fib(ll n) {
    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return (f[n] = 1);
    if (f.find(n) != f.end())
        return f[n];
    ll k = (n & 1) ? (n + 1) / 2 : n / 2;
    if (n & 1) {
        f[n] = add(mul(fib(k), fib(k)), mul(fib(k - 1), fib(k - 1)));
    } else {
        f[n] = mul(add(mul(2, fib(k - 1)), fib(k)), fib(k));
    }
    return f[n];
}

ll nextPowerOf2(ll n)
{
    n >>= 1;
    ll count = 0;

    if (n && !(n & (n - 1)))
        return n;

    while ( n != 0)
    {
        n >>= 1;
        count += 1;
    }

    return 1 << count;
}

ll binomialCoeff(ll n, ll k)
{
    ll C[k + 1];
    memset(C, 0, sizeof(C));
    C[0] = 1;

    for (ll i = 1; i <= n; i++)
    {
        for (ll j = min(i, k); j > 0; j--)
            C[j] = C[j] + C[j - 1];
    }
    return C[k];
}

bool isPrime(ll n)
{

    if (n <= 1)
        return false;
    if (n <= 3)
        return true;

    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (ll i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}

ll power(ll x, ll y, ll p)
{
    ll res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

ll modInverse(ll n, ll p)
{
    return power(n, p - 2, p);
}

ll modFact(ll n, ll p)
{
    if (n >= p)return 0;
    ll result = 1;
    for (ll i = 1; i <= n; i++)
        result = ((result % mod) * (i % mod)) % p;

    return result;
}

string to_str(char a)
{
    string s(1, a);
    return s;
}

vector<vector<pair<longint, longint>>> factors(MAXIMUM);

ll power_for_factors(ll n, ll m)
{
    ll count = 0;
    while (n % m == 0)
    {
        n /= m;
        count++;
    }
    return count;
}

void prime_factors()
{
    for (auto i = 2; i < MAXIMUM; i++)
    {
        if (!factors[i].size())
        {
            for (auto j = i; j < MAXIMUM; j += i)factors[j].pb({i, power_for_factors(j, i)});
        }
    }
}

void primeFactors(ll n, set<ll> &div)
{
    while (n % 2 == 0)
    {
        div.insert(2);
        n = n / 2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            div.insert(i);
            n = n / i;
        }
    }
    if (n > 2)
        div.insert(n);
}

ll binary_search(vector<ll> &a, ll x)
{
    ll low = 0, high = a.size() - 1;
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        if (a[mid] == x)return mid;
        else if (a[mid] > x)high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}

vl dectobinary(ll n)
{
    vl binaryNum(64, 0);
    ll i = 0;
    while (n > 0)
    {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
    return binaryNum;
}

ll sqrt_of_integer(ll n)
{
    if (n <= 1)return n;
    ll low = 0, high = n - 1;
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        if (mid * mid == n)return mid;
        else if (mid * mid < n)low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

//INDEX OF FIRST ELEMENT GREATER THAN OR EQUAL TO X OR -1

ll binary_search(vector<ll> &a, ll x)
{
    ll low = 0, high = a.size() - 1;
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        if (a[mid] == x)return mid;
        else if (a[mid] > x)high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}

ll sqrt_of_integer(ll n)
{
    if (n <= 1)return n;
    ll low = 0, high = n - 1;
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        if (mid * mid == n)return mid;
        else if (mid * mid < n)low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

ll lower_bound(vl &a, ll x)
{
    ll low = 0, high = a.size() - 1;
    ll ans = -1;
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        if (a[mid] < x)low = mid + 1;
        else
        {
            ans = mid;
            high = mid - 1;
        }
    }
    return ans;
}

ll upper_bound(vl &a, ll x)
{
    ll low = 0, high = a.size() - 1;
    ll ans = -1;
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        if (a[mid] <= x)low = mid + 1;
        else
        {
            ans = mid;
            high = mid - 1;
        }
    }
    return ans;
}

ll find_min(vector<ll>& a)
{
    ll low = 0, high = a.size() - 1;
    ll ans = INT_MAX;
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        if (a[mid] > a[high])low = mid + 1;
        else
        {
            ans = min(ans, a[mid]);
            high = mid - 1;
        }
    }
    return ans;
}

ll max(ll a, ll b) {return a > b ? a : b;}
ll min(ll a, ll b) {return a < b ? a : b;}

ll find_peek(vl &a)
{
    ll low = 0, high = a.size() - 1, ans = -1;
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        if (mid == 0 || a[mid] > a[mid - 1])
        {
            ans = max(ans, a[mid]);
            low = mid + 1;
        }
        else high = mid - 1;
    }
    return ans;
}

ld squart(ld n)
{
    ld low = 0, high = n;
    ld pre = 0.000000000001;
    while (high - low > pre)
    {
        ld mid = low + (high - low) / 2;
        if (mid * mid > n)high = mid;
        else low = mid;
    }
    return low + (high - low) / 2;
}

ll lower_bound(vl &a, ll x)
{
    ll low = 0, high = a.size() - 1;
    ll ans = -1;
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        if (a[mid] < x)low = mid + 1;
        else
        {
            ans = mid;
            high = mid - 1;
        }
    }
    return ans;
}

//INDEX OF FIRST ELEMENT STRICTLY GREATER THAN X OR -1

ll upper_bound(vl &a, ll x)
{
    ll low = 0, high = a.size() - 1;
    ll ans = -1;
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        if (a[mid] <= x)low = mid + 1;
        else
        {
            ans = mid;
            high = mid - 1;
        }
    }
    return ans;
}

//******************SEGMENT TREE************************


#include <bits/stdc++.h>
using namespace std;

#define fio                     ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define watch(x)                cout << (#x) << " is " << (x) << endl
#define f(t)                    for(ll i=0;i<t;i++)
#define ll                      long long int
#define ld                      long double
#define umpl                    unordered_map<ll,ll>
#define vl                      vector<ll>
#define vld                     vector<ld>
#define vvl                     vector<vl>
#define pb                      push_back
#define pll                     pair<ll,ll>
#define inf                     1e18
#define pcout(x,p)              cout<<fixed<<setprecision(p)<<x
#define all(a)                  a.begin(),a.end()
#define endl                    "\n"


const ll mod = 1e9 + 7;
inline ll mul(ll a, ll b) { ll c = (a * 1ll * b) % mod; if (c < 0) c += mod; return c; }
inline ll sub(ll a, ll b) { ll c = a - b; if (c < 0) c += mod; return c; }
inline ll add(ll a, ll b) { ll c = a + b; if (c >= mod) c -= mod; return c; }
inline ll max(ll a, ll b) {return a > b ? a : b;}
inline ll min(ll a, ll b) {return a < b ? a : b;}
inline ll ceil(ll a, ll b) {return (a % b == 0) ? (a / b) : (a / b + 1);}

class intervalTree
{
    ll* tree;
    ll* lazy;
    ll n;

    void build_tree(const vector<ll>& v, ll node, ll a, ll b)
    {
        if (a > b) return;

        if (a == b) { tree[node] = v[a]; return; }

        build_tree(v, node * 2, a, (a + b) / 2);
        build_tree(v, node * 2 + 1, 1 + (a + b) / 2, b);
        tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
    }

    void update_lazy(ll node, ll a, ll b)
    {
        tree[node] += lazy[node];

        if (a != b)
        {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }

        lazy[node] = 0;
    }

    void update_tree(ll node, ll a, ll b, ll i, ll j, ll value)
    {
        if (lazy[node] != 0) update_lazy(node, a, b);

        if (a > b || a > j || b < i) return;

        if (a >= i && b <= j)
        {
            tree[node] += value;
            if (a != b)
            {
                lazy[node * 2] += value;
                lazy[node * 2 + 1] += value;
            }
            return;
        }

        update_tree(node * 2, a, (a + b) / 2, i, j, value);
        update_tree(1 + node * 2, 1 + (a + b) / 2, b, i, j, value);

        tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
    }

    ll query_tree(ll node, ll a, ll b, ll i, ll j)
    {
        if (a > b || a > j || b < i) return 2100000000;

        if (lazy[node] != 0) update_lazy(node, a, b);

        if (a >= i && b <= j) return tree[node];

        ll q1 = query_tree(node * 2, a, (a + b) / 2, i, j);
        ll q2 = query_tree(1 + node * 2, 1 + (a + b) / 2, b, i, j);

        return min(q1, q2);
    }

public:
    intervalTree(const vector<ll>& v) {
        n = v.size();
        ll s = 2 * pow(2, ceil(log2(v.size())));
        tree = new ll[s];
        lazy = new ll[s];
        memset(lazy, 0, sizeof lazy);
        build_tree(v, 1, 0, n - 1);
    }

    void update(ll idx1, ll idx2, ll add) {
        update_tree(1, 0, n - 1, idx1, idx2, add);
    }

    ll query(ll idx1, ll idx2) {
        return query_tree(1, 0, n - 1, idx1, idx2);
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input1.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fio;
    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        ll q; cin >> q;
        const vl a(n, 1);
        intervalTree tree(a);
        while (q--) {
            ll l, r; cin >> l >> r;
            ll mi = tree.query(l, r);
            mi = mi % mod;
            tree.update(l, r, mi);
        }
        cout << tree.query(0, n - 1) % mod << endl;
    }
}


class SegmentTree {
private:
    ll size;
    vl segtree;
public:
    void init(ll n) {
        size = 1;
        while (size < n)size *= 2;
        segtree.resize(2 * size, 0);
    }

    void build(vl &a, ll root, ll left, ll right) {
        if ((right - left) == 1) {
            if (left < (ll)a.size()) {
                segtree[root] = a[left];
            }
            return;
        }
        ll mid = left + (right - left) / 2;
        build(a, 2 * root + 1, left, mid);
        build(a, 2 * root + 2, mid, right);
        segtree[root] = segtree[2 * root + 1] + segtree[2 * root + 2];
    }

    void build(vl &a) {
        build(a, 0, 0, size);
    }

    void set(ll &index, ll &value, ll root, ll left, ll right) {
        if ((right - left) == 1) {
            segtree[root] = value;
            return;
        }
        ll mid = left + (right - left) / 2;
        if (index < mid) {
            set(index, value, 2 * root + 1, left, mid);
        } else {
            set(index, value, 2 * root + 2, mid, right);
        }
        segtree[root] = segtree[2 * root + 1] + segtree[2 * root + 2];
    }

    void set(ll index, ll value) {
        set(index, value, 0, 0, size);
    }

    ll query(ll &l, ll &r, ll root, ll left, ll right) {
        if (l >= right || r <= left)return 0;
        if (right <= r && left >= l)return segtree[root];
        ll mid = left + (right - left) / 2;
        ll sum1 = query(l, r, 2 * root + 1, left, mid);
        ll sum2 = query(l, r, 2 * root + 2, mid, right);
        return sum1 + sum2;
    }

    ll query(ll l, ll r) {
        return query(l, r, 0, 0, size);
    }
};


ll a[300000][30];
ll segtree[1000000][30];

void build(ll node, ll start, ll end, ll g)
{
    if (start == end)
    {
        segtree[node][g] = a[start][g];
    }
    else
    {
        ll mid = (start + end) / 2;
        build(2 * node, start, mid, g);
        build(2 * node + 1, mid + 1, end, g);
        segtree[node][g] = segtree[2 * node][g] + segtree[2 * node + 1][g];
    }
}


ll query(ll node, ll start, ll end, ll l, ll r, ll g)
{

    if (start > r || end < l)return 0;
    if (start >= l && end <= r)return segtree[node][g];
    ll mid = (start + end) / 2;
    ll left = query(node * 2, start, mid, l, r, g);
    ll right = query(node * 2 + 1, mid + 1, end, l, r, g);
    return (left + right);
}




void update(ll node, ll start, ll end, ll ind, ll value, ll g)
{
    if (start == end)
    {
        segtree[node][g] = segtree[node][g] + value;
        a[ind][g] = a[ind][g] + value;
    }
    else
    {
        ll mid = (start + end) / 2;
        if (ind <= mid)
        {
            update(2 * node, start, mid, ind, value, g);
        }
        else
        {
            update(2 * node + 1, mid + 1, end, ind, value, g);
        }
        segtree[node][g] = segtree[2 * node][g] + segtree[2 * node + 1][g];
    }
}

ll a[300000];
ll segtree[1000000];

void build(ll node, ll start, ll end)
{
    if (start == end)
    {
        segtree[node][g] = a[start];
    }
    else
    {
        ll mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        segtree[node] = segtree[2 * node] + segtree[2 * node + 1];
    }
}


ll query(ll node, ll start, ll end, ll l, ll r)
{
    if (start > r || end < l)return 0;
    if (start >= l && end <= r)return segtree[node];
    ll mid = (start + end) / 2;
    ll left = query(node * 2, start, mid, l, r);
    ll right = query(node * 2 + 1, mid + 1, end, l, r);
    return (left + right);
}

void update(ll node, ll start, ll end, ll ind, ll value)
{
    if (start == end)
    {
        segtree[node] = segtree[node] + value;
        a[ind] = a[ind] + value;
    }
    else
    {
        ll mid = (start + end) / 2;
        if (ind <= mid)
        {
            update(2 * node, start, mid, ind, value);
        }
        else
        {
            update(2 * node + 1, mid + 1, end, ind, value);
        }
        segtree[node] = segtree[2 * node] + segtree[2 * node + 1];
    }
}

map<int, int>vis;
vector<int>adj[100];

void bfs(int s)
{
    queue<int>q;
    q.push(s);
    vis[s] = 1;

    cout << s << " ";

    while (!q.empty())
    {
        for (int i = 0; i < adj[s].size(); i++)
        {
            if (!vis[adj[s][i]])
            {
                cout << adj[s][i] << " ";

                vis[adj[s][i]] = 1;
                q.push(adj[s][i]);
            }
        }

        q.pop();
        s = q.front();

    }
}

map<int, int>vis;
vector<int>adj[100];

void dfs(int s)
{
    vis[s] = 1;
    cout << s << " ";

    for (int i = 0; i < adj[s].size(); i++)
    {
        if (!vis[adj[s][i]])
        {
            dfs(adj[s][i]);
        }
    }
}

//*********************************************************************

int main()
{
    fio;
    ll t; cin >> t;
    while (t--)
    {

    }
}



​g++ -DLOCAL - std = c++17 - Wshadow - Wall - o "h" "h.cpp" - fsanitize = address - fsanitize = undefined - D_GLIBCXX_DEBUG - g (in directory: / home / kamil / youtube / atcoder - dp)
                       numlockx on

                       Prefix / Suffix in O(n):
                       https://leetcode.com/problems/house-robber/ 
                       https://leetcode.com/problems/house-robber-ii/
                       https://leetcode.com/problems/maximum-subarray/ 
                       https://leetcode.com/problems/maximum-product-subarray/
                       https://leetcode.com/problems/longest-turbulent-subarray/
                       https://leetcode.com/problems/longest-valid-parentheses/
                       https://leetcode.com/problems/climbing-stairs/
                       https://leetcode.com/problems/decode-ways/
                       https://leetcode.com/problems/decode-ways-ii/
                       https://leetcode.com/problems/integer-break/
                       https://leetcode.com/problems/arithmetic-slices/
                       https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/

                           Prefix / Suffix in O(n ^ 2):
                       https://leetcode.com/problems/longest-increasing-subsequence/
                       https://leetcode.com/problems/longest-arithmetic-sequence/
                       https://leetcode.com/problems/word-break/
                       https://leetcode.com/problems/word-break-ii/
                       https://leetcode.com/problems/stone-game-iii/
                       https://leetcode.com/problems/palindrome-partitioning-ii/
                       https://leetcode.com/problems/wiggle-subsequence/
                       https://leetcode.com/problems/odd-even-jump/

                       2D DP:

                           Row - wise filling in O(n ^ 2)
                       https://leetcode.com/problems/target-sum/
                       https://leetcode.com/problems/partition-equal-subset-sum/
                       https://leetcode.com/problems/last-stone-weight-ii/

                       https://www.spoj.com/problems/KNAPSACK/ 
                       https://www.hackerrank.com/challenges/unbounded-knapsack/problem 
                       https://www.interviewbit.com/problems/tushars-birthday-party/ 
                       https://www.interviewbit.com/problems/n-digit-numbers-with-digit-sum-s-/ 

                       https://leetcode.com/problems/edit-distance/ 
                       https://leetcode.com/problems/distinct-subsequences/
                       https://leetcode.com/problems/longest-common-subsequence/
                       https://leetcode.com/problems/distinct-subsequences-ii/

                       https://leetcode.com/problems/frog-jump/

                           Length DP in O(n ^ 2):
                       https://leetcode.com/problems/stone-game/
                       https://leetcode.com/problems/longest-palindromic-subsequence/ 
                       https://leetcode.com/problems/longest-palindromic-substring/ 

                           O(n ^ 3):
                       https://leetcode.com/problems/stone-game-ii/
                       https://leetcode.com/problems/largest-sum-of-averages/ 
                       https://leetcode.com/problems/burst-balloons/ 



                       Matrix DP:
                       https://leetcode.com/problems/minimum-path-sum/
                       https://leetcode.com/problems/count-square-submatrices-with-all-ones/
                       https://www.interviewbit.com/problems/min-sum-path-in-matrix/ 
                       https://www.interviewbit.com/problems/dungeon-princess/     
                       https://www.interviewbit.com/problems/unique-paths-in-a-grid/ 
                       https://www.interviewbit.com/problems/kingdom-war/ 
                       https://leetcode.com/problems/cherry-pickup/
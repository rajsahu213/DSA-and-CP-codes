#include <bits/stdc++.h>
using namespace std;
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define watch(x) cout << (#x) << " is " << (x) << endl
#define f(t) for(ll i=0;i<t;i++)
#define ll long long int
#define ld long double
#define umpl unordered_map<ll,ll>
#define vl vector<ll>
#define vld vector<ld>
#define vvl vector<vl>
#define pb push_back
#define pll pair<ll,ll>
#define inf 1e18
#define pcout(x,p) cout<<fixed<<setprecision(p)<<x
#define all(a) a.begin(),a.end()
#define endl "\n"
const ll mod = 1e9 + 7;
inline ll mul(ll a, ll b) { return (a * 1ll * b) % mod; }
inline ll sub(ll a, ll b) { ll c = a - b; if (c < 0) c += mod; return c; }
inline ll add(ll a, ll b) { ll c = a + b; if (c >= mod) c -= mod; return c; }
inline ll max(ll a, ll b) {return a > b ? a : b;}
inline ll min(ll a, ll b) {return a < b ? a : b;}
inline ll ceil(ll a, ll b) {return (a % b == 0) ? (a / b) : (a / b + 1);}


const ll maxn = 5001;
ll more[maxn][maxn];
vl dp_before, dp_curr;
ll cost(ll i, ll j) {
    return more[j][j] - more[i - 1][j] - more[j][i - 1] + more[i - 1][i - 1];
}
void compute(ll l, ll r, ll low, ll high) {
    if (l > r)return;
    ll mid = (l + r) / 2;
    pll best = {inf, -1};
    for (ll k = low; k <= min(mid, high); k++) {
        best = min(best, {dp_before[k - 1] + cost(k, mid), k});
    }
    dp_curr[mid] = best.first;
    ll now = best.second;
    compute(l, mid - 1, low, now);
    compute(mid + 1, r, now, high);
}

int main() {
    fio;
    ll t; cin >> t;
    while (t--) {
        ll n, k; cin >> n >> k;
        vl a(n + 1);
        for (ll i = 1; i <= n; i++)cin >> a[i];
        memset(more, 0, sizeof(more));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                if (a[j] > a[i]) {
                    more[i][j] = a[j];
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                more[i][j] = more[i - 1][j] + more[i][j - 1] - more[i - 1][j - 1] + more[i][j];
            }
        }
        dp_before.resize(n + 1), dp_curr.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            dp_before[i] = cost(1, i);
        }
        for (ll i = 2; i <= k; i++) {
            compute(i, n, i, n);
            dp_before = dp_curr;
        }
        cout << dp_before[n] << endl;
    }
}
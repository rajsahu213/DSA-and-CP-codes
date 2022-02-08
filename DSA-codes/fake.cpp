#include<bits/stdc++.h>
using namespace std;
 
#define loop(i,a,b) for(ll i=a;i<b;i++)
#define all(v) v.begin(), v.end() 
 
#define print(stuff) cout << stuff << endl
#define printc(stuff) for(auto x: stuff) cout << x << " "; cout << endl;
#define printPrec(stuff) cout << fixed << setprecision(15) << stuff << endl;
#define len length
#define ret0 return 0
#define ret return 
 
// #define int long long 
#define ll long long 
#define ld long double
#define fi first
#define endl '\n'
#define se second
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define fill(ar, x) memset(ar, x, sizeof ar)
 
#define vl vector<ll> 
#define sl set<ll>
#define pll pair<ll, ll>
#define mll map<ll, ll> 
#define pq priority_queue<ll>
 
// typedef tree<ll,null_type,less<ll>,rb_tree_tag,
// tree_order_statistics_node_update> indexed_set;
 
#define inf (long long int) 1e18
#define eps 0.000001
#define mod 1000000007
#define mod1 998244353
#define MAXN (ll)1e5+5
#define N (1ll<<10)
#define nax (ll)1e6+5
#define nax2 (ll)4e5+5

ll block = 448;
const ll LG = 20;
ll curTime = 1;
ll value = 1;
ll st[MAXN], en[MAXN], a[MAXN], lvl[MAXN], P[MAXN][LG], mo[MAXN], final[nax];
ll spf[nax], powerCount[MAXN][27], sumPower[MAXN][27][LG], posInPrimes[101];
ll modInv[nax2];
bool vis[MAXN];
vl adj[MAXN], primes, bigPrime[MAXN];

void sieve() { 
    spf[1] = 1; 
    for (ll i=2; i<nax; i++) spf[i] = i; 
    for (ll i=4; i<nax; i+=2) spf[i] = 2; 
    for (ll i=3; i*i<nax; i++) { 
        if (spf[i] == i) { 
            for (ll j=i*i; j<nax; j+=i) 
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
}

ll modexp(ll a, ll b, ll m){
    if (b==0)
        return 1;
    ll temp = modexp(a,b/2,m);
    temp = (temp*temp)%m;
    if (b&1)
        return (temp*(a%m))%m; // if b is odd a^b = a^(b/2)*a^(b/2)*a
    return temp;
}

void getFactorization(ll x, ll idx) { 
    while (x != 1) { 
        if(spf[x] < 100) powerCount[idx][posInPrimes[spf[x]]]++;
        else bigPrime[idx].pb(spf[x]);
        x = x / spf[x]; 
    }
}  

void dfs(ll s, ll e){
    lvl[s] = 1 + lvl[e];
    P[s][0] = e;
    loop(i,0,27){
        sumPower[s][i][0] = powerCount[e][i];
    }
    st[s] = curTime++;
    for(auto x: adj[s]){
        if(x != e){
            dfs(x, s);
        }
    }
    en[s] = curTime++;
}

ll lca(ll u, ll v){
    ll i, lg;
    if(lvl[u] < lvl[v]) swap(u, v);
    for(lg = 0; (1ll<<lg) <= lvl[u]; lg++);
    lg--;
    for(i = lg; i >= 0; i--){
        if(lvl[u] - (1ll<<i) >= lvl[v]){
            u = P[u][i];
        }
    }
    if(u == v) return u;
    for(i = lg; i >= 0; i--){
        if(P[u][i] != -1 and P[u][i] != P[v][i]){
            u = P[u][i], v = P[v][i];
        }
    }
    return P[u][0];
}

void preprocess(ll n){
    block = sqrt(2*n);
    loop(i,0,nax) final[i] = 0;
    curTime = 1;
    value = 1;
    loop(i,1,n+1){
        adj[i].clear();
        st[i] = en[i] = a[i] = lvl[i] = 0;
        vis[i] = 0;
        bigPrime[i].clear();
        loop(j,0,LG) {
            P[i][j] = -1;
            loop(k,0,27) sumPower[i][k][j] = 0;
        }
        loop(j,0,27) powerCount[i][j] = 0;

    }
    loop(i,1,2*n+1) mo[i] = 0;
}
ll findCount(ll u, ll l, ll x){
    ll dis = lvl[u] - lvl[l];
    ll result = powerCount[u][x], cur = u;
    for(ll j=0; j<LG; j++){
        if(dis&(1ll<<j)){
            result += sumPower[cur][x][j];
            cur = P[cur][j];
        }
    }
    return result;
}

bool cmp(pair<pll, pll> a, pair<pll, pll> b){
    if(a.fi.fi / block == b.fi.fi/block) return a.fi.se < b.fi.se;
    else return a.fi.fi / block < b.fi.fi / block;
}

void addSimple(vector<ll> v){
    for(auto x: v){
        value = (value * modInv[final[x]+1])%mod;
        final[x]++;
        value = (value * (final[x]+1))%mod;
    }
}



void solve(){
    ll n;
    cin>>n;

    preprocess(n);

    // loop(i,0,n-1){
    //     ll x, y;
    //     cin>>x>>y;
    //     adj[x].pb(y), adj[y].pb(x);
    // }
    // loop(i,1,n+1) cin>>a[i];
    loop(i,1,n+1){
        getFactorization(a[i], i);
    }

    lvl[0] = -1;

    dfs(1, 0);

    for(ll i=1; i<LG; i++){
        for(ll j = 1; j <= n; j++){
            if(P[j][i-1] != -1){
                P[j][i] = P[P[j][i-1]][i-1];
            }
        }
    }

    for(ll i=0; i<27; i++){
        for(ll j=1; j<LG; j++){
            for(ll k=1; k<=n; k++){
                if(P[k][j-1])
                    sumPower[k][i][j] = sumPower[k][i][j-1] + sumPower[P[k][j-1]][i][j-1];
            }
        }
    }
    
    ll q;
    cin>>q;
    pair<ll, ll> queries[q];
    pair<pair<ll, ll>, pair<ll, ll>> modQueries[q];
    ll ans[q];
    loop(i,0,q) ans[i] = 1;
    loop(i,0,q){
        cin>>queries[i].fi>>queries[i].se;
        ll u = queries[i].fi, v = queries[i].se;
        ll l = lca(u, v);
        if(l == u){
            modQueries[i].fi.fi = st[u];
            modQueries[i].fi.se = st[v];
            modQueries[i].se.fi = 0;
        }
        else {
            modQueries[i].fi.fi = en[u];
            modQueries[i].fi.se = st[v];
            modQueries[i].se.fi = l;
        }
        modQueries[i].se.se = i;
        for(ll j = 0; j<27; j++){
            ll xx = findCount(u, l, j) + findCount(v, l, j) - powerCount[l][j];
            ans[i] = (ans[i] * (xx+1))%mod;
        }
    }

    // for(ll i=1; i<=n; i++){
    //     mo[st[i]] = i, mo[en[i]] = i;
    // }
    
    // sort(modQueries, modQueries+q, cmp);

    // ll curL = 1, curR = 1;
    // addSimple(bigPrime[mo[1]]);
    // vis[1] = 1;

    // for(ll i=0; i<q; i++){
    //     ll left = modQueries[i].fi.fi;
    //     ll right = modQueries[i].fi.se;
    //     while(curL > left) {
    //         curL--;
    //         ll node = mo[curL];
    //         if(vis[node]){
    //             for(auto x: bigPrime[node]){
    //                 value = (value * modInv[final[x]+1])%mod;
    //                 final[x]--;
    //                 value = (value * (final[x]+1))%mod;
    //             }
    //             vis[node] = false;
    //         }
    //         else {
    //             for(auto x: bigPrime[node]){
    //                 value = (value * modInv[final[x]+1])%mod;
    //                 final[x]++;
    //                 value = (value * (final[x]+1))%mod;
    //             }
    //             vis[node] = true;
    //         }
    //     }
    //     while(curR < right) {
    //         curR++;
    //         ll node = mo[curR];
    //         if(vis[node]){
    //             for(auto x: bigPrime[node]){
    //                 value = (value * modInv[final[x]+1])%mod;
    //                 final[x]--;
    //                 value = (value * (final[x]+1))%mod;
    //             }
    //             vis[node] = false;
    //         }
    //         else {
    //             for(auto x: bigPrime[node]){
    //                 value = (value * modInv[final[x]+1])%mod;
    //                 final[x]++;
    //                 value = (value * (final[x]+1))%mod;
    //             }
    //             vis[node] = true;
    //         }
    //     }
    //     while(curL < left) {
    //         ll node = mo[curL];
    //         if(vis[node]){
    //             for(auto x: bigPrime[node]){
    //                 value = (value * modInv[final[x]+1])%mod;
    //                 final[x]--;
    //                 value = (value * (final[x]+1))%mod;
    //             }
    //             vis[node] = false;
    //         }
    //         else{
    //             for(auto x: bigPrime[node]){
    //                 value = (value * modInv[final[x]+1])%mod;
    //                 final[x]++;
    //                 value = (value * (final[x]+1))%mod;
    //             }
    //             vis[node] = true;
    //         }
    //         curL++;
    //     }
    //     while(curR > right) {
    //         ll node = mo[curR];
    //         if(vis[node]){
    //             for(auto x: bigPrime[node]){
    //                 value = (value * modInv[final[x]+1])%mod;
    //                 final[x]--;
    //                 value = (value * (final[x]+1))%mod;
    //             }
    //             vis[node] = false;
    //         }
    //         else{
    //             for(auto x: bigPrime[node]){
    //                 value = (value * modInv[final[x]+1])%mod;
    //                 final[x]++;
    //                 value = (value * (final[x]+1))%mod;
    //             }
    //             vis[node] = true;
    //         }
    //         curR--;
    //     }

    //     if(modQueries[i].se.fi != 0){
    //         for(auto x: bigPrime[modQueries[i].se.fi]){
    //             value = (value * modInv[final[x]+1])%mod;
    //             final[x]++;
    //             value = (value * (final[x]+1))%mod;
    //         }
            
    //     }
    //     ans[modQueries[i].se.se] = (ans[modQueries[i].se.se] * value)%mod;
    //     if(modQueries[i].se.fi != 0){
    //         for(auto x: bigPrime[modQueries[i].se.fi]){
    //             value = (value * modInv[final[x]+1])%mod;
    //             final[x]--;
    //             value = (value * (final[x]+1))%mod;
    //         }
    //     }

    // }
    // loop(i,0,q){
    //     print(ans[i]);
    // }
}
 
int main(){
 
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll t = 1;
    cin>>t;
    sieve();
    for(ll i=2; i<=100; i++){
        if(spf[i] == i) primes.pb(i);
    }
    for(ll i=0; i<primes.size(); i++){
        posInPrimes[primes[i]] = i;
    }
    for(ll i=1; i<nax2; i++){
        modInv[i] = modexp(i, mod-2, mod);
    }
    while(t--){
        solve();
    }
        
}

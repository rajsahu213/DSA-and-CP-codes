// AUTHOR RAJ SAHU

#include <bits/stdc++.h>

using namespace std;

#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
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
#define fill(a,p) memset(a,p,sizeof(a))
#define pb push_back
#define mod 1000000007
#define N 100005
#define LOG 20
#define MAXN (ll)1e6+5
#define MAXN2 (ll)4e5+5
#define all(a) a.begin(),a.end()
#define point pair<ll,ll>
#define block 448

const int inf = 1000000007;
const ll linf = 1ll * inf * inf;
const ll MAXIMUM =1000005;

inline ll mul(ll a, ll b){ return (a * 1ll * b) % mod; }
inline ll sub(ll a, ll b){ ll c = a - b; if(c < 0) c += mod; return c; }
inline ll add(ll a, ll b){ ll c = a + b; if(c >= mod) c -= mod; return c; }
inline ll max(ll a, ll b){return a>b?a:b;}
inline ll minim(ll a, ll b){return a<b?a:b;}

struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
};

ll power(ll x, ll y,ll p) 
{ 
    ll res = 1;      
     x = x % p;    
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % p; 
            y = y>>1;  
            x = (x*x) % p;   
    } 
    return res; 
}

ll modInverse[MAXN2];
vl prime_numbers;
ll positionOfPrime[101];
ll spf[N],sumOfPowers[N][27][LOG],powercount[N][27];
ll MO[N],final[MAXN];
bool visited[N];
vl bigPrime[N];
vl graph[N];
ll parent[N][LOG],level[N],startTime[N],endTime[N],currTime,value;


void sieve() { 
    spf[1] = 1; 
    for (ll i=2; i<N; i++) spf[i] = i; 
    for (ll i=4; i<N; i+=2) spf[i] = 2; 
    for (ll i=3; i*i<N; i++) { 
        if (spf[i] == i) { 
            for (ll j=i*i; j<N; j+=i) 
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
}

void make_graph(ll n){
    f(n-1){
        ll x,y;cin>>x>>y;
        graph[x].pb(y);
        graph[y].pb(x);
    }
}

void DFS(ll curr, ll prev){ 
    parent[curr][0] = prev;
    startTime[curr]=currTime++;
    f(27){
        sumOfPowers[curr][i][0] = powercount[prev][i];
    }
    level[curr]=1+level[prev];
    for(ll i=0;i<graph[curr].size();i++){
        if(graph[curr][i]!=prev){
            DFS(graph[curr][i],curr);
        }
    }
    endTime[curr]=currTime++;
}

ll lca(ll u,ll v) 
{ 
    ll i, lg;
    if(level[u] < level[v]) swap(u, v);
    for(lg = 0; (1ll<<lg) <= level[u]; lg++);
    lg--;
    for(i = lg; i >= 0; i--){
        if(level[u] - (1ll<<i) >= level[v]){
            u = parent[u][i];
        }
    }
    if(u == v) return u;
    for(i = lg; i >= 0; i--){
        if(parent[u][i] != -1 and parent[u][i] != parent[v][i]){
            u = parent[u][i], v = parent[v][i];
        }
    }
    return parent[u][0]; 
}


bool comp(pair<point, point> a, pair<point,point> b){
    if(a.first.first / block == b.first.first/block) return a.first.second < b.first.second;
    else return a.first.first / block < b.first.first / block;
}

void add(vector<ll> v){
    for(ll x: v){
        value=mul(value,modInverse[final[x]+1]);
        final[x]++;
        value=mul(value,add(final[x],1));
    }
}

void Factorization(ll index, ll element) { 
    while (element != 1) { 
        if(spf[element] < 100) powercount[index][positionOfPrime[spf[element]]]++;
        else bigPrime[index].pb(spf[element]);
        element = element / spf[element]; 
    }
} 

ll  Count(ll u, ll l, ll x){
    ll dis = level[u] - level[l];
    ll result = powercount[u][x], cur = u;
    for(ll j=0; j<LOG; j++){
        if(dis&(1ll<<j)){
            result += sumOfPowers[cur][x][j];
            cur = parent[cur][j];
        }
    }
    return result;
}

int main()
{
    fio;
    sieve();
    for(ll i=2; i<=100; i++){
        if(spf[i] == i) prime_numbers.pb(i);
    }
    for(ll i=0; i<prime_numbers.size(); i++){
        positionOfPrime[prime_numbers[i]] = i;
    }
    for(ll i=1; i<MAXN2; i++){
        modInverse[i] = power(i, mod-2, mod);
    }    
    ll t;cin>>t;
    while(t--)
    {
        ll n;cin>>n;
        make_graph(n);
        vl a(n+1);
        for(ll i=1;i<=n;i++)cin>>a[i];
        for(ll i=1;i<=n;i++){
            graph[i].clear();
            bigPrime[i].clear();
        }
        fill(startTime,0);
        fill(endTime,0);
        fill(parent,-1);
        fill(level,0);level[0]=-1;
        currTime=1,value=1;
        fill(powercount,0);
        fill(sumOfPowers,0);

        for(ll i=1;i<=n;i++){
            Factorization(i,a[i]);
        }

        DFS(1, 0);

        for(ll i=1; i<LOG; i++){
            for(ll j = 1; j <= n; j++){
                if(parent[j][i-1] != -1){
                    parent[j][i] = parent[parent[j][i-1]][i-1];
                }
            }
        }

        for(ll i=0; i<27; i++){
            for(ll j=1; j<LOG; j++){
                for(ll k=1; k<=n; k++){
                    if(parent[k][j-1])
                        sumOfPowers[k][i][j] = sumOfPowers[k][i][j-1] + sumOfPowers[parent[k][j-1]][i][j-1];
                }
            }
        }

        ll q;
        cin>>q;
        ll ans[q];
        for(ll i=0;i<q;i++)ans[i]=1;
        pair<pair<ll, ll>, pair<ll, ll>> queries[q];
        f(q){

            ll u,v;cin>>u>>v;
            ll lc=lca(u, v);

            for(ll j = 0; j<27; j++){
                ll xx = Count(u, lc, j) + Count(v, lc, j) - powercount[lc][j];
                ans[i] = (ans[i] * (xx+1))%mod;
            }

            if(lc == u){
                queries[i].first.first = startTime[u];
                queries[i].first.second = startTime[v];
                queries[i].second.first = 0;
            }
            else {
                queries[i].first.first = endTime[u];
                queries[i].first.second = startTime[v];
                queries[i].second.first = lc;
            }
            queries[i].second.second = i;

        }

        // MO's Algorithm for finding answers for big prime factors

        fill(visited,false);
        fill(final,0);
        fill(MO,0);
        ll currLeft = 1, currRight = 1;

        sort(queries,queries+q,comp);
        
        for(ll i=1;i<=n;i++){
            MO[startTime[i]]=i;
            MO[endTime[i]]=i;
        }
        
        visited[1] = true;
        add(bigPrime[MO[1]]);

        for(ll i=0; i<q; i++){
            ll left = queries[i].first.first;
            ll right = queries[i].first.second;
            while(currLeft > left) {
                currLeft--;
                ll currentNode = MO[currLeft];
                if(visited[currentNode]){
                    for(ll x: bigPrime[currentNode]){
                        value=mul(value,modInverse[final[x]+1]);
                        final[x]--;
                        value=mul(value,add(final[x],1));
                    }
                    visited[currentNode] = false;
                }
                else {
                    for(ll x: bigPrime[currentNode]){
                        value=mul(value,modInverse[final[x]+1]);
                        final[x]++;
                        value=mul(value,add(final[x],1));
                    }
                    visited[currentNode] = true;
                }
            }
            while(currRight < right) {
                currRight++;
                ll currentNode = MO[currRight];
                if(visited[currentNode]){
                    for(ll x: bigPrime[currentNode]){
                        value=mul(value,modInverse[final[x]+1]);
                        final[x]--;
                        value=mul(value,add(final[x],1));
                    }
                    visited[currentNode] = false;
                }
                else {
                    for(ll x: bigPrime[currentNode]){
                        value=mul(value,modInverse[final[x]+1]);
                        final[x]++;
                        value=mul(value,add(final[x],1));
                    }
                    visited[currentNode] = true;
                }
            }
            while(currLeft < left) {
                ll currentNode = MO[currLeft];
                if(visited[currentNode]){
                    for(ll x: bigPrime[currentNode]){
                        value=mul(value,modInverse[final[x]+1]);
                        final[x]--;
                        value=mul(value,add(final[x],1));
                    }
                    visited[currentNode] = false;
                }
                else{
                    for(ll x: bigPrime[currentNode]){
                        value=mul(value,modInverse[final[x]+1]);
                        final[x]++;
                        value=mul(value,add(final[x],1));
                    }
                    visited[currentNode] = true;
                }
                currLeft++;
            }
            while(currRight > right) {
                ll currentNode = MO[currRight];
                if(visited[currentNode]){
                    for(ll x: bigPrime[currentNode]){
                        value=mul(value,modInverse[final[x]+1]);
                        final[x]--;
                        value=mul(value,add(final[x],1));
                    }
                    visited[currentNode] = false;
                }
                else{
                    for(ll x: bigPrime[currentNode]){
                        value=mul(value,modInverse[final[x]+1]);
                        final[x]++;
                        value=mul(value,add(final[x],1));
                    }
                    visited[currentNode] = true;
                }
                currRight--;
            }

            if(queries[i].second.first != 0){
                for(ll x: bigPrime[queries[i].second.first]){
                    value=mul(value,modInverse[final[x]+1]);
                    final[x]++;
                    value=mul(value,add(final[x],1));
                }
                
            }
            ans[queries[i].second.second] = mul(ans[queries[i].second.second],value);
            if(queries[i].second.first != 0){
                for(ll x: bigPrime[queries[i].second.first]){
                    value=mul(value,modInverse[final[x]+1]);
                    final[x]--;
                    value=mul(value,add(final[x],1));
                }
            }
        }

        for(ll i=0;i<q;i++){
            cout<<ans[i]<<'\n';
        }
    }
    return 0;
}
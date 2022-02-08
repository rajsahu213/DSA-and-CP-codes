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
#define BLOCK 450
#define all(a) a.begin(),a.end()
#define point pair<ll,ll>

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

vl graph[N],largePrimes[N];
ll spf[N],last[N],parent[N][LOG],sumOfPowers[N][26][LOG],powercount[N][26];
ll prime_numbers[]={1,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
ll positionOfPrime[100];
ll prime_count=26,box,Time,value;
bool visited[N];

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

void Factorization(ll index, ll element) { 
    while (element != 1) { 
        if(spf[element] < 100) powercount[index][positionOfPrime[spf[element]]]++;
        else largePrimes[index].pb(spf[element]);
        element = element / spf[element]; 
    }
} 

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

ll modInverse(ll n,ll p) 
{ 
    return power(n, p-2, p); 
}

void initialize(){
    box = sqrt(2*n),Time=1,value=1;
    fill(sumOfPowers,0);
    fill(last,0);
    fill(master,0);
    fill(start,0);
    fill(end,0);
    fill(level,0);level[0]=-1;
    fill(powercount,0);
    fill(visited,false);
    fill(parent,-1);
}

void ending(ll n)
{
    f(n+1){
        graph[i].clear();
        largePrimes[i].clear();
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
    start[curr]=Time++;
    f(26){
        sumOfPowers[curr][i][0] = powercount[prev][i];
    }
    level[curr]=1+level[prev];
    for(ll i=0;i<graph[curr].size();i++){
        if(graph[curr][i]!=prev){
            DFS(graph[curr][i],curr);
        }
    }
    end[curr]=Time++;
}

int main()
{
    fio;
    sieve();
    for(ll i=0;i<prime_count;i++)positionOfPrime[prime_numbers[i]]=i;
    ll t;cin>>t;
    while(t--)
    {
        ll n;cin>>n;
        initialize();
        make_graph(n);
        vl a(n+1);
        for(ll i=1;i<=n;i++)cin>>a[i];
        for(ll i=1;i<=n;i++){
            Factorization(i,a[i]);
        }
        DFS(1, 0);




        ending(n);
    }
}




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
#define all(a) a.begin(),a.end()
#define point pair<ll,ll>

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

vector<vector<pair<ll,ll>>> factors(MAXIMUM);

ll power_for_factors(ll n,ll m)
{
    ll count=0;
    while(n%m==0)
    {
        n/=m;
        count++;
    }
    return count;
}

void prime_factors()
{
    for(auto i=2;i<MAXIMUM;i++)
    {
        if(!factors[i].size()) 
        {
            for(auto j=i;j<MAXIMUM;j+=i)
                factors[j].pb({i,power_for_factors(j,i)});
        }
    }
}

ll power(ll x, ll y) 
{ 
    ll res = 1;      
     x = x ;    
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) ;
            y = y>>1;  
            x = (x*x) ;   
    } 
    return res; 
}

vector<pair<ll,ll>> updateChild(vector<pair<ll,ll>> &childs_data,vector<pair<ll,ll>> &parents_data)
{
    unordered_map<ll,ll> mp;
    for(ll i=0;i<childs_data.size();i++){
        mp[childs_data[i].first]=add(mp[childs_data[i].first],childs_data[i].second);
    }
    for(ll i=0;i<parents_data.size();i++){
        mp[parents_data[i].first]=add(mp[parents_data[i].first],parents_data[i].second);
    }
    vector<pair<ll,ll>> new_data;
    for(auto i=mp.begin();i!=mp.end();i++){
        new_data.push_back({i->first,i->second});
    }
    return new_data;
}

void BFS(vector<ll> graph[],ll root,vector<vector<pair<ll,ll>>> &node_data,ll n)
{
    queue<ll> q;
    vector<bool> vis(n+1);
    vector<ll> p(n+1);
    q.push(root);
    vis[root]=true;
    p[root]=-1;
    while(!q.empty())
    {
        ll temp=q.front();q.pop();
        ll child=temp;
        ll parent=p[temp];
        if(parent!=-1)
        {
            vector<pair<ll,ll>> new_data=
            updateChild(node_data[child],node_data[parent]);
            node_data[child]=new_data;
        }
        for(ll u:graph[child])
        {
            if(!vis[u]){
                vis[u]=true;
                q.push(u);
                p[u]=temp;
            }
        }
    }
}

int memo[100005][50];
int lev[N];

void dfs(int u, int p, int log, vector<ll> g[]) 
{  
    memo[u][0] = p; 
    for (int i = 1; i <= log; i++) 
        memo[u][i] = memo[memo[u][i - 1]][i - 1]; 
    for (int v : g[u]) 
    { 
        if (v != p) 
        { 
            lev[v] = lev[u] + 1; 
            dfs(v, u, log, g); 
        } 
    } 
} 
  
int lca(int u, int v, int log) 
{ 
    if (lev[u] < lev[v]) 
        swap(u, v); 
    for (int i = log; i >= 0; i--) 
        if ((lev[u] - (1ll<<i)) >= lev[v]) 
            u = memo[u][i]; 
    if (u == v) 
        return u; 
    for (int i = log; i >= 0; i--) 
    { 
        if (memo[u][i] != memo[v][i]) 
        { 
            u = memo[u][i]; 
            v = memo[v][i]; 
        } 
    } 
    return memo[u][0]; 
} 

void addEdge(vl adj[],ll u,ll v) 
{ 
    adj[u].push_back(v); 
    adj[v].push_back(u); 
} 

int main()
{
    fio;
    prime_factors();
    ll t;cin>>t;
    while(t--)
    {
        ll n;cin>>n;
        vl adj[n+1];
        int log = (int)ceil(log2(n)); 
        fill(memo,-1);
        f(n-1){
            ll x,y;
            cin>>x>>y;
            addEdge(adj,x,y);
        }
        vl a(n);
        for(ll i=1;i<=n;i++){
            cin>>a[i];
        }
        dfs(1, 1, log, adj); 
        vector<vector<pair<ll,ll>>> node_data(n+1);
        
        for(ll i=1;i<=n;i++){
            node_data[i]=factors[a[i]];
        }

        BFS(adj,1,node_data,n);

        ll q;cin>>q;
        while(q--){
            ll u,v;cin>>u>>v;
            ll lc=lca(u, v, log);
            vector<pair<ll,ll>> factu,factv,factlc;
            factu=node_data[u];
            factv=node_data[v];
            factlc=node_data[lc];
            unordered_map<ll,ll> mp;
            for(ll i=0;i<factu.size();i++){
                mp[factu[i].first]=add(mp[factu[i].first],factu[i].second);
            }
            for(ll i=0;i<factv.size();i++){
                mp[factv[i].first]=add(mp[factv[i].first],factv[i].second);
            }
            for(ll i=0;i<factlc.size();i++){
                mp[factlc[i].first]=sub(mp[factlc[i].first],mul(2,factlc[i].second));
            } 
            for(ll i=0;i<factors[a[lc]].size();i++){
                mp[factors[a[lc]][i].first]=add(mp[factors[a[lc]][i].first],factors[a[lc]][i].second);
            }                       
            ll ans=1;
            for(auto i=mp.begin();i!=mp.end();i++){
                ans=mul(ans,add(i->second,1));
            }
            cout<<ans<<"\n";
        }
    }
}
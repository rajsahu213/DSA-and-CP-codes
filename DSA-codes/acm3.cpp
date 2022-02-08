#include <bits/stdc++.h>

using namespace std;

#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define watch(x) cout << (#x) << " is " << (x) << endl
#define f(t) for(ll i=0;i<t;i++)
#define bs(a,x) binary_search(a.begin(),a.end(),x)
#define ll long long int
#define ul unsigned long int
#define ld long double
#define umpi unordered_map<int,int> 
#define umpl unordered_map<ll,ll> 
#define vi vector<int>
#define vvl vector<vector<ll>>
#define vl vector<ll>
#define pb push_back
#define mod 1000000007 
#define N 10000000
#define all(a) a.begin(),a.end()
#define point pair<int,int>
const int inf = 1000000007;
const ll linf = 1ll * inf * inf;
const ll MAXIMUM=1000005;

inline ll mul(ll a, ll b){ return (a * 1ll * b) % mod; }
inline ll sub(ll a, ll b){ ll c = a - b; if(c < 0) c += mod; return c; }
inline ll add(ll a, ll b){ ll c = a + b; if(c >= mod) c -= mod; return c; }
inline ll max(ll a, ll b){return a>b?a:b;}
inline ll min(ll a, ll b){return a<b?a:b;}

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
            for(auto j=i;j<MAXIMUM;j+=i)factors[j].pb({i,power_for_factors(j,i)});
        }
    }
}

const int sz = 1e3+5; 
vector<ll> tree[sz]; 
bool vis[sz]; 
vector<ll> path[sz][sz]; 
void addEdge(ll a,ll b) 
{ 
    tree[a].push_back(b); 
    tree[b].push_back(a); 
} 
void bfs(ll node) 
{ 
    ll root=node;
    queue<pair<ll,ll> > qu; 
    qu.push({ node, -1 }); 
    vis[node] = true; 
    while (!qu.empty()) { 
        pair<ll, ll> p = qu.front(); 
        qu.pop(); 
        vis[p.first] = true; 
        for (int child : tree[p.first]) { 
            if (!vis[child]) { 
                qu.push({ child, p.first });  
                path[root][child] = path[root][p.first]; 
                path[root][child].push_back(p.first); 
            } 
        } 
    } 
} 

const ll sz=1e3+5;
unordered_map<ll,ll> dp[sz][sz];

void fill(vl &a,vl graph[],ll n,ll node)
{
    bool vis[n+1];memset(vis,false,sizeof(vis));
    queue<pair<ll,ll>> q;
    q.push({node,-1});
    while(!q.empty())
    {
        pair<ll,ll> curr=q.front();q.pop();
        vis[curr.first]=true;
        if(curr.second!=-1 && dp[node][curr.first].size()==0){
            ll child=curr.first;
            ll parent=curr.second;
            dp[node][child]=dp[node][parent];
            ll value=a[child];
            for(ll i=0;i<factors[value].size();i++){
                dp[node][child][factors[value][i].first]+=factors[value][i].second;
            }
            dp[child][parent]=dp[parent][child];
        }
        ll child=curr.first;
        for(ll i=0;i<graph[child].size();i++){
            if(!vis[graph[child][i]]){
                q.push({graph[child][i],child});
            }
        }
    }
}   


int main()
{
    fio;
    prime_factors();
    ll t;cin>>t;
    while(t--)
    {
        ll n;cin>>n;
        f(n-1){
            ll x,y;
            cin>>x>>y;
            addEdge(x,y);
        }
        vl a(n+1);
        for(ll i=1;i<=n;i++){
            cin>>a[i];
        }
        for(ll i=1;i<=n;i++){
            memset(vis,false,sizeof(vis));
            bfs(i);
        }
        ll q;cin>>q;
        while(q--){
            ll u,v;cin>>u>>v;
            unordered_map<ll,ll> mp;
            for(ll i=0;i<path[u][v].size();i++){
                ll value=a[path[u][v][i]];
                for(ll j=0;j<factors[value].size();j++){
                    mp[factors[value][j].first]+=factors[value][j].second;
                }
            }
            for(ll j=0;j<factors[a[v]].size();j++){
                mp[factors[a[v]][j].first]+=factors[a[v]][j].second;
            }
            ll ans=1;
            for(auto i=mp.begin();i!=mp.end();i++){
                ans=mul(ans,add(i->second,1));
            }
            cout<<ans<<"\n";
        }
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
            for(auto j=i;j<MAXIMUM;j+=i)factors[j].pb({i,power_for_factors(j,i)});
        }
    }
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
    queue<pair<ll,ll>> q;
    bool vis[n+1];memset(vis,false,sizeof(vis));
    q.push({root,-1});
    while(!q.empty())
    {
        pair<ll,ll> temp=q.front();q.pop();
        ll child=temp.first;
        ll parent=temp.second;
        vis[child]=true;
        if(parent!=-1)
        {
            vector<pair<ll,ll>> parents_data=node_data[parent];
            vector<pair<ll,ll>> childs_data=node_data[child];
            vector<pair<ll,ll>> new_data=updateChild(childs_data,parents_data);
            node_data[child]=new_data;
        }
        for(ll i=0;i<graph[child].size();i++)
        {
            if(!vis[graph[child][i]]){
                q.push({graph[child][i],child});
            }
        }
    }
}

#define level 18

vector <ll> tree[N]; 
ll depth[N]; 
ll parent[N][level]; 
// ll level=100;

void dfs(ll cur,ll prev) 
{ 
    depth[cur] = depth[prev] + 1; 
    parent[cur][0] = prev; 
    for (ll i=0; i<tree[cur].size(); i++) 
    { 
        if (tree[cur][i] != prev) 
            dfs(tree[cur][i], cur); 
    } 
} 
void precomputeSparseMatrix(ll n) 
{ 
    for (ll i=1; i<level; i++) 
    { 
        for (ll node = 1; node <= n; node++) 
        { 
            if (parent[node][i-1] != -1) 
                parent[node][i] = 
                    parent[parent[node][i-1]][i-1]; 
        } 
    } 
} 
 
ll lca(ll u,ll v) 
{ 
    if (depth[v] < depth[u]) 
        swap(u, v); 
  
    ll diff = depth[v] - depth[u]; 
    for (ll i=0; i<level; i++) 
        if ((diff>>i)&1) 
            v = parent[v][i];  
    if (u == v) 
        return u; 
    for (ll i=level-1; i>=0; i--) 
        if (parent[u][i] != parent[v][i]) 
        { 
            u = parent[u][i]; 
            v = parent[v][i]; 
        }  
    return parent[u][0]; 
} 
  
void addEdge(ll u,ll v) 
{ 
    tree[u].push_back(v); 
    tree[v].push_back(u); 
} 

int main()
{
    fio;
    prime_factors();
    ll t;cin>>t;
    while(t--)
    {
        ll n;cin>>n;
        // vector<ll> graph[n+1],stack;
        memset(parent,-1,sizeof(parent));
        f(n-1){
            ll x,y;
            cin>>x>>y;
            addEdge(x,y);
        }
        vl a(n+1);
        for(ll i=1;i<=n;i++){
            cin>>a[i];
        }

        depth[0]=0;

        dfs(1,0);

        precomputeSparseMatrix(n); 

        vector<vector<pair<ll,ll>>> node_data(n+1);
        for(ll i=1;i<=n;i++){
            node_data[i]=factors[a[i]];
        }

        BFS(tree,1,node_data,n);

        ll q;cin>>q;
        while(q--){
            ll u,v;cin>>u>>v;
            ll lc=lca(u,v);
            if(lc==-1)lc=1;
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
            // cout<<lc<<endl;
        }
    }
}
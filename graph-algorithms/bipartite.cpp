#include <bits/stdc++.h>
using namespace std;
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define watch(x) cout << (#x) << " is " << (x) << endl
#define f(t) for(ll i =0;i<t;i++)
#define ll long long int
#define ul unsigned long int
#define ld long double
#define umpi unordered_map<int,int> 
#define umpl unordered_map<ll,ll> 
#define vi vector<int>
#define vl vector<ll>
#define vvl vector<vl>
#define fill(a,p) memset(a,p,sizeof(a))
#define pb push_back
#define mod 1000000007
#define N 100005
#define all(a) a.begin(),a.end()
#define point pair<ll,ll>
#define endl "\n"

const int inf = 1000000007;
const ll linf = 1ll * inf * inf;
const ll MAXIMUM =2005;

inline ll mul(ll a, ll b){ return (a * 1ll * b) % mod; }
inline ll sub(ll a, ll b){ ll c = a - b; if(c < 0) c += mod; return c; }
inline ll add(ll a, ll b){ ll c = a + b; if(c >= mod) c -= mod; return c; }
inline ll max(ll a, ll b){return a>b?a:b;}
inline ll min(ll a, ll b){return a<b?a:b;}
inline ll ceil(ll a,ll b){if(a%b==0)return a/b;else return a/b+1;}
inline ll mo(ll a,ll b){if(b<0){b=abs(b)%mod;b=a-b;return (b<0)?b+mod:b;}else{return (a+b)%mod;}}
inline ll pow(ll a,ll b){if(b==0){return 1;}else{if(b%2==0){ll temp=pow(a,b/2);return temp*temp;}
else{return a*pow(a,b-1);}}}

struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
};
vvl graph;
vl color;
ll n,e;

void init(){
	graph.clear();graph.resize(n);
	color.clear();color.resize(n,0);
	ll u,v;
	for(ll i=0;i<e;i++){
		cin>>u>>v;
		u--;v--;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
}

bool dfs(ll s,ll col){
    color[s]=col;
    for(ll x:graph[s]){
        if(color[x]==col)
            return false;
        if(color[x]==0){
            if(!dfs(x,(col^(1))))
                return false;
        }
    }
    return true;
}

bool isBipartite() {
    bool ans=true;
    for(ll i=0;i<n;i++){
        if(color[i]==0){
            ans=ans&dfs(i,2);
        }
    }
    return ans;
}

int main()
{
	ll t;cin>>t;
	ll cases=1;
	while(t--){
		cin>>n>>e;
		init();
		bool ans=isBipartite();
		cout<<"Scenario #"<<cases<<":"<<endl;
		if(ans){
			cout<<"No suspicious bugs found!"<<endl;
		}else {
			cout<<"Suspicious bugs found!"<<endl;
		}
		cases++;
	}
}



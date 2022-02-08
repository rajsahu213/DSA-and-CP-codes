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
#define pb push_back
#define mod 1000000007 
#define N 10000000
#define all(a) a.begin(),a.end()
#define point pair<ll,ll>

const int inf = 1000000007;
const ll linf = 1ll * inf * inf;
const ll MAXIMUM =100005;

inline ll mul(ll a, ll b){ return (a * 1ll * b) % mod; }
inline ll sub(ll a, ll b){ ll c = a - b; if(c < 0) c += mod; return c; }
inline ll add(ll a, ll b){ ll c = a + b; if(c > mod) c -= mod; return c; }
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

ll dp[MAXIMUM];

ll longest_path(vector<vl> & graph,ll vertex)
{
	if(graph[vertex].size()==0)return 0;
	else if(dp[vertex]!=-1)return dp[vertex];
	else
	{
		ll ans=-1;
		for(ll i=0;i<graph[vertex].size();i++)
		{
			ans=max(ans,1+longest_path(graph,graph[vertex][i]));
		}
		dp[vertex]=ans;
		return ans;
	}
}

int main()
{
	fio;
	ll n,m;cin>>n>>m;
	vector<vl> graph(n);
	f(m)
	{
		ll x,y;cin>>x>>y;
		graph[x-1].pb(y-1);
	}	
	ll ans =LLONG_MIN;
	memset(dp,-1,sizeof(dp));
	for(ll i=0;i<n;i++)
	{
		ans=max(ans,longest_path(graph,i));
	}
	cout<<ans<<"\n";
}
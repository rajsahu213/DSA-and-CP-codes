#include <bits/stdc++.h>

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

inline ll mul(ll a, ll b){ return (a * 1ll * b) % mod; }
inline ll sub(ll a, ll b){ ll c = a - b; if(c < 0) c += mod; return c; }
inline ll add(ll a, ll b){ ll c = a + b; if(c > mod) c -= mod; return c; }

struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
};

string to_string(char x)
{
	string s(1,x);
	return s;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif	
	fio;
	ll t;t=1;
	while(t--)
	{
		string s1,s2;
		cin>>s1>>s2;
		ll dp[s1.length()+1][s2.length()+1];
		memset(dp,0,sizeof(dp));
		for(ll i=1;i<=s1.length();i++)
		{
			for(ll j=1;j<=s2.length();j++)
			{
				if(s1[i-1]==s2[j-1])
				{
					dp[i][j]=max(dp[i][j],1+dp[i-1][j-1]);
				}
				dp[i][j]=max(dp[i][j],dp[i-1][j]);
				dp[i][j]=max(dp[i][j],dp[i][j-1]);
			}
		}
		string ans="";int n=dp[s1.length()][s2.length()];
		ll i=s1.length(),j=s2.length();
		while(i>0 && j>0)
		{
			if(s1[i-1]==s2[j-1])
			{
				ans.append(to_string(s1[i-1]));
				i--;j--;
			}
			else if(dp[i-1][j]>dp[i][j-1])i--;
			else j--;
		}
		reverse(all(ans));
		cout<<ans<<"\n";
	}
}

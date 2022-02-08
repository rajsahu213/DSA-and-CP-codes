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
#define vv(a) vector<vector<a>> 
#define pll pair<ll,ll>
#define pb push_back
#define mod 1000000007 
#define N 10000000
#define all(a) a.begin(),a.end()
#define point pair<int,int>
const int inf = 1000000007;
const ll linf = 1ll * inf * inf;
const ll MAXIMUM=20;

inline ll mul(ll a, ll b){ return (a * 1ll * b) % mod; }
inline ll sub(ll a, ll b){ ll c = a - b; if(c < 0) c += mod; return c; }
inline ll add(ll a, ll b){ ll c = a + b; if(c > mod) c -= mod; return c; }


ll power(ll x,ll y,ll p) 
{ 
    ll res = 1;
    x=x%p;  
    while (y>0) 
    { 
        if (y & 1) 
            res = ((res%p)*(x%p))%p; 
        y = y>>1; 
        x = ((x%p)*(x%p))%p; 
    } 
    return res; 
} 

ll modInverse(ll n,ll p) 
{ 
    return power(n, p-2, p); 
}

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,sum=0;cin>>n;
        string s;cin>>s;
        ll a[n];
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                a[i]=1;
            }
            else if(s[i]==')')
            {
                a[i]=-1;
            }
            else
            {
                a[i]=0;
            }
        }
        ll cnt[n];
        memset(cnt,0,sizeof(cnt));
        umpl ind;
        // ind[0]=1;
        ll nh=0;
        f(n)
        {
          if(a[i]==-1)
          {
            cnt[i]+=n-i;
            if(i>0&&a[i-1]==-1)
            {
                cnt[i]+=(ind[sum]-1)*(n-i);
            }
            cnt[i]+=(nh/2)*(n-i);
            // if(nh/2>0)
            // {
            //     cnt[i]+=(ind[sum-nh])*(n-i);
            // }
            nh++;
 
          } 
          else
          {
            nh=0;
          }
            sum+=a[i];  
          ind[sum]++;
          cout<<cnt[i]<<" ";
        }
        cout<<endl;
        ll tc=0;
        f(n)tc+=cnt[i];                    
        ll ans=1;
        ll ans1 = (n*(n+1))/2;
        ans1=power(ans1,mod-2,mod);
        ans = mul(tc,ans1);
        cout<<ans<<"\n";
    }
}
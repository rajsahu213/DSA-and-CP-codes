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

// struct hash_pair { 
//     template <class T1, class T2> 
//     size_t operator()(const pair<T1, T2>& p) const
//     { 
//         auto hash1 = hash<T1>{}(p.first); 
//         auto hash2 = hash<T2>{}(p.second); 
//         return hash1 ^ hash2; 
//     } 
// };

bool check(int a,int b,int c)
{
    int dis0=(a-b)*(a-b);
    int dis1=a*a+c*c;
    int dis2=b*b+c*c;
    if((dis2+dis1)==(dis0) || (dis0+dis2)==(dis1) || (dis0+dis1)==(dis2))return true;
    return false;
} 

int main()
{
    fio;
    int t;cin>>t;
    while(t--)
    {
        int n,m;cin>>n>>m;
        vector<int> x(n),y(m);
        f(n)cin>>x[i];
        f(m)cin>>y[i];
        sort(all(x));
        sort(all(y));
        vector<int> x1,x2,y1,y2;
        bool flag1=false,flag2=false;
        f(n)
        {
            if(x[i]<0)x1.pb(x[i]);
            else if(x[i]==0)
            {
                flag1=true;
            }
            else x2.pb(x[i]);
        }
        f(m)
        {
            if(y[i]>0)y1.pb(y[i]);
            else if(y[i]==0)flag2=true;
            else y2.pb(y[i]);
        }
        ll ans=0;
        if(flag1 || flag2)
        {
            ans+=(x1.size()+x2.size())*(y1.size()+y2.size());
        }
        for(int i=0;i<x1.size();i++)
        {
            for(int j=x2.size()-1;j>=0;j--)
            {
                for(int k=0;k<y1.size();k++)
                {
                    if(check(x1[i],x2[j],y1[k])){ans++;break;}
                }
                for(int k=0;k<y2.size();k++)
                {
                    if(check(x1[i],x2[j],y2[k])){ans++;break;}                  
                }                
            }
        }
        for(int i=0;i<y1.size();i++)
        {
            for(int j=y2.size()-1;j>=0;j--)
            {
                for(int k=0;k<x1.size();k++)
                {
                    if(check(y1[i],y2[j],x1[k])){ans++;break;}
                }
                for(int k=0;k<x2.size();k++)
                {
                    if(check(y1[i],y2[j],x2[k])){ans++;break;}                  
                }                
            }
        }        
        cout<<ans<<"\n";
    }
}

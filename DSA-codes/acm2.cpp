#include <bits/stdc++.h>

using namespace std;

#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define watch(x) cout << (#x) << " is " << (x) << endl
#define f(t) for(ll i =0;i<t;i++)
#define bs(a,x) binary_search(a.begin(),a.end(),x)
#define ll int
#define ul unsigned long int
#define ld long double
#define umpi unordered_map<int,int> 
#define umpl unordered_map<ll,ll> 
#define vi vector<int>
#define vl vector<ll>
#define fill(a,p) memset(a,p,sizeof(a))
#define pb push_back
#define mod 998244353
#define N 10000000
#define all(a) a.begin(),a.end()
#define point pair<ll,ll>

const int inf = 1000000007;
// const ll linf = 1ll * inf * inf;
const ll MAXIMUM =2005;

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
 

int main()
{
    fio;
    ll t;cin>>t;
    while(t--)
    {
        srand(time(0));
        int n,m,k;
        cin>>n>>m>>k;
        int a[n][k];
        f(n){
            for(ll j=0;j<k;j++)
            {
                cin>>a[i][j];
            }
        }
        vl best;
        ll ans=-1;
        for(ll i=0;i<570;i++){
            vl temp(n);
            for(ll j=0;j<n;j++){
                temp[j]=rand()%m+1;
            }
            ll temp1=n;
            for(ll j=0;j<k;j++){
                ll count=0;
                for(ll h=0;h<n;h++){
                    if(a[h][j]==temp[h]){
                        count++;
                    }
                }
                if(count<temp1){
                    temp1=count;
                }
            }
            if(temp1>ans){
                ans=temp1;
                best=temp;
            }
        }
        for(int &value:best){
            cout<<value<<" ";
        }
        cout<<"\n";
    }
}



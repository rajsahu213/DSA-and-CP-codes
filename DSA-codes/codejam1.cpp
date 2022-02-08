// #include <bits/stdc++.h>
// using namespace std;
// #define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
// #define watch(x) cout << (#x) << " is " << (x) << endl
// #define f(t) for(ll i=0;i<t;i++)
// #define ll long long int
// #define ld long double
// #define umpl unordered_map<ll,ll> 
// #define vl vector<ll>
// #define vld vector<ld>
// #define vvl vector<vl>
// #define pll pair<ll,ll>
// #define pb push_back
// #define mod 998244353
// #define inf 1e18
// #define pcout(x,p) cout<<fixed<<setprecision(p)<<x
// #define all(a) a.begin(),a.end()
// #define endl "\n"

// inline ll mul(ll a, ll b){ return (a * 1ll * b) % mod; }
// inline ll sub(ll a, ll b){ ll c = a - b; if(c < 0) c += mod; return c; }
// inline ll add(ll a, ll b){ ll c = a + b; if(c >= mod) c -= mod; return c; }
// inline ll max(ll a, ll b){return a>b?a:b;}
// inline ll min(ll a, ll b){return a<b?a:b;}
// inline ll ceil(ll a,ll b){if(a%b==0)return a/b;else return a/b+1;}

// struct comp { 
//     template<class T1,class T2,class T3,class T4>
//     bool operator()(const pair<T1,T2> &p1,const pair<T3,T4> &p2){
//         return p1.first<p2.first;
//     }
// }; 
// struct edge{
//     ll u,v,w;
//     edge(ll u,ll v,ll w){
//         this->u=u,this->v=v,this->w=w;
//     }
// };
// ll n,m;
// bool bellman(vector<ll> &d,vector<ll> &p,vector<edge> &a){
//     d.assign(n,inf);p.assign(n,-1);
//     ll x;
//     for(ll i=0;i<n;i++){
//         x=-1;
//         for(ll j=0;j<m;j++){
//             if(d[a[j].v]>d[a[j].u]+a[j].w){
//                 d[a[j].v]=d[a[j].u]+a[j].w;
//                 p[a[j].v]=a[j].u;
//                 x=a[j].v;
//             }
//         }
//     }
//     if(x==-1)return false;
//     else{
//         ll y=x;
//         for(ll i=0;i<n;i++)y=p[y];
//         vector<ll> path;
//         for(ll curr=y;;curr=p[curr]){
//             path.push_back(curr+1);
//             if(curr==y && path.size()>1)break;
//         }
//         cout<<"YES"<<endl;
//         reverse(all(path));
//         for(ll x:path)cout<<x<<" ";
//         cout<<endl;
//         return true;
//     }
// }

// int main(){
//     cin>>n>>m;
//     vector<edge> a;
//     for(ll i=0;i<m;i++){
//         ll u,v,w;cin>>u>>v>>w;
//         u--;v--;
//         a.push_back(edge(u,v,w));
//     }
//     vector<ll> d,p;
//     bool cycle=bellman(d,p,a);
//     if(!cycle)cout<<"NO"<<endl;
// }
#include <bits/stdc++.h>
using namespace std;
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define watch(x) cout << (#x) << " is " << (x) << endl
#define f(t) for(ll i=0;i<t;i++)
#define ll long long int
#define ld long double
#define umpl unordered_map<ll,ll> 
#define vl vector<ll>
#define vld vector<ld>
#define vvl vector<vl>
#define pb push_back
#define mod 998244353
#define inf 1e18
#define pcout(x,p) cout<<fixed<<setprecision(p)<<x
#define all(a) a.begin(),a.end()
#define endl "\n"

inline ll mul(ll a, ll b){ return (a * 1ll * b) % mod; }
inline ll sub(ll a, ll b){ ll c = a - b; if(c < 0) c += mod; return c; }
inline ll add(ll a, ll b){ ll c = a + b; if(c >= mod) c -= mod; return c; }
inline ll max(ll a, ll b){return a>b?a:b;}
inline ll min(ll a, ll b){return a<b?a:b;}
inline ll ceil(ll a,ll b){if(a%b==0)return a/b;else return a/b+1;}
inline ll mo(ll a,ll b){if(b<0){b=abs(b)%mod;b=a-b;return (b<0)?b+mod:b;}else{return (a+b)%mod;}}
inline ll pow(ll a,ll b){if(b==0){return 1;}else{if(b%2==0){ll temp=pow(a,b/2);return temp*temp;}
else{return a*pow(a,b-1);}}}

struct comp { 
    template<class T1,class T2,class T3,class T4>
    bool operator()(const pair<T1,T2> &p1,const pair<T3,T4> &p2){
        return p1.first<p2.first;
    }
}; 
void solve(){
    ll n;cin>>n;
    using pll=pair<ll,ll>;
    vector<pll> input;
    vl p(n),h(n);
    f(n){
        ll a,b;cin>>a>>b;
        input.pb({a,b});
    }
    sort(all(input));
    f(n){
        p[i]=input[i].first,h[i]=input[i].second;
    }
    unordered_map<ll,ll> pos[2];
    vvl dp(n,vl(2,0));
    dp[0][0]=h[0];pos[p[0]][0]=h[0];
    dp[0][1]=0;pos[p[0]][1]=0;pos[p[0]+h[0]][0]=h[0];
    ll ans=-inf;
    for(ll i=1;i<n;i++){
        ll back=p[i]-h[i];
        for(ll j=0;j<i;j++){
            if(back<p[j]){
                dp[i][0]=max(dp[i][0],h[i]);
            }else if(back>p[j]){
                if((p[j]+h[j]+h[i])==p[i]){
                    dp[i][0]=max(dp[i][0],dp[j][1]+h[i]+h[j]);
                }else{
                    dp[i][0]=max(dp[i][0],h[i]);
                }
            }else{
                dp[i][0]=max(dp[i][0],dp[j][0]+h[i]);
            }
            if((p[j]+h[j])==p[i]){
                dp[i][1]=max(dp[i][1],h[j]+dp[j][1]);
            }else{
                dp[i][1]=max(dp[i][1],0);
            }
        }
    }
    for(ll i=0;i<n;i++){
        ans=max(ans,dp[i][0]);
        ans=max(ans,dp[i][1]+h[i]);
    }
    cout<<ans<<endl;
}

int main(){
    #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w", stdout); 
    #endif 
    ll t;cin>>t;
    for(ll i=1;i<=t;i++){
        cout<<"Case #"<<i<<": ";
        solve();
    }
}
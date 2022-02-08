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
#define point pair<int,int>
const int inf = 1000000007;
const ll linf = 1ll * inf * inf;
const ll MAXIMUM =1000005;

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

ll a[300000][105];
ll segtree[1000000][105];

void build(ll node,ll start,ll end,ll g)
{
    if(start==end)
    {
        segtree[node][g]=a[start][g];
    }
    else
    {
        ll mid=(start+end)/2;
        build(2*node,start,mid,g);
        build(2*node+1,mid+1,end,g);
        segtree[node][g]=segtree[2*node][g]+segtree[2*node+1][g];
    }
}


ll query(ll node,ll start,ll end,ll l,ll r,ll g)
{
    if(start>r || end<l)return 0;
    if(start>=l && end<=r)return segtree[node][g];
    ll mid=(start+end)/2;
    ll left=query(node*2,start,mid,l,r,g);
    ll right=query(node*2+1,mid+1,end,l,r,g);
    return (left+right);
}

void update(ll node,ll start,ll end,ll ind,ll value,ll g)
{
    if(start==end)
    {
        segtree[node][g]=segtree[node][g]+value;
        a[ind][g]=a[ind][g]+value;
    }
    else
    {
        ll mid=(start+end)/2;
        if(ind<=mid)
        {
            update(2*node,start,mid,ind,value,g);
        }
        else
        {
             update(2*node+1,mid+1,end,ind,value,g);
        }
        segtree[node][g]=segtree[2*node][g] + segtree[2*node+1][g];
    } 
}

ll power_for_factors(ll &n,ll m)
{
    ll count=0;
    while(n%m==0)
    {
        n/=m;
        count++;
    }
    return count;
}

vl fill(ll n)
{
    vl a(101);
    for(ll i=2;i<=100;i++)
    {
        a[i]=power_for_factors(n,i);
    }
    return a;
}

ll max(ll a,ll b){return a>b?a:b;}

int main()
{
    fio;
    ll t=1;
    while(t--)
    {
        ll n;cin>>n;
        vl a1(n);
        f(n)cin>>a1[i];
        f(n)
        {
            vl temp=fill(a1[i]);
            for(ll j=2;j<=100;j++)
            {
                a[i][j]=temp[j];
            }
        }
        for(ll i=2;i<=100;i++)
        {
            build(1,0,n-1,i);
        }
        ll q;cin>>q;
        while(q--)
        {
            ll k,l,r;
            cin>>k>>l>>r;
            if(k==1)
            {
                l--;r--;
                vector<ll> sum(101,0);
                for(ll i=2;i<=100;i++)
                {
                    sum[i]=query(1,0,n-1,l,r,i);
                }bool flag=false;
                for(ll i=2;i<=100;i++)
                {
                    if(sum[i]&1){flag=true;break;}
                }
                if(flag)cout<<"NO\n";
                else cout<<"YES\n";
            }
            else
            {
                l--;
                if(r!=1)
                {
                    vl temp=fill(r);
                    for(ll i=2;i<=100;i++)
                    {
                        update(1,0,n-1,l,temp[i],i);
                    }
                }
            }
        }
    } 
}
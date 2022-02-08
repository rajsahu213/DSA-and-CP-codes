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

bool is_there(vector<int> &v,int x)
{
    f(v.size())
    {
        if(v[i]==x)return true;
    }
    return false;
}

void rec(unordered_map<int,vector<int>> &mp,int m,vector<int> v1,vector<int> v2,ll &ans)
{
    if(v1.size()==4 && v2.size()==4)
    {
        int price[]={100,75,50,25};
        int b=0;        
        ll ans1=0;
        vector<int> x;
        for(int i=0;i<4;i++)
        {
            int max=0,temp=-1;
            for(int j=0;j<4;j++)
            {
                if(mp[v1[j]][v2[j]]>max && !is_there(x,j)){max=mp[v1[j]][v2[j]];temp=j;}
            }
            if(max==0)
            {
                ans1=ans1-100;
            }
            else
            {
                ans1+=max*price[b++];
            }
            if(temp!=-1)x.push_back(temp);
        }
        if(ans1>ans)ans=ans1;
    }
    else
    {
        for(int i=1;i<13;i++)
        {
            if(i%3==0)
            {
                if(!is_there(v1,i) && !is_there(v2,m))
                {
                    v1.pb(i);
                    v2.pb(m);
                    rec(mp,m+1,v1,v2,ans);
                    v1.pop_back();
                    v2.pop_back();
                }
            }
        }
    }
}

int main()
{
    fio;
    int t;cin>>t;
    ll final_ans=0;
    while(t--)
    {
        int n;cin>>n;
        unordered_map<int,vector<int>> mp;
        for(int i=1;i<13;i++)
        {
            if(i%3==0)
            {
                vector<int> temp(4,0);
                mp[i]=temp;
            }
        }
        f(n)
        {
            char m;
            int t;
            cin>>m>>t;
            mp[t][m-'A']++;
        }
        ll ans=LLONG_MIN;
        vector<int> v1,v2;
        rec(mp,0,v1,v2,ans);
        // unordered_map<pair<int,int>,bool,hash_pair> vis;
        // int price[]={100,75,50,25};
        // int b=0;
        // bool vis_movie[4]={false};
        // bool vis_time[13]={false};
        // for(int k=0;k<4;k++)
        // {
        //     pair<int,int> max_pair;
        //     int max=0;
        //     for(int i=1;i<13;i++)
        //     {
        //         if(i%3==0)
        //         {
        //             for(int j=0;j<4;j++)
        //             {
        //                 if(!vis[{i,j}] && !vis_time[i] && !vis_movie[j])
        //                 {
        //                     if(mp[i][j]>max)
        //                     {
        //                         max=mp[i][j];
        //                         max_pair.first=i;
        //                         max_pair.second=j;
        //                     }
        //                 }
        //             }
        //         }
        //     }
        //     if(max==0)
        //     {
        //         ans=ans-100;
        //     }
        //     else
        //     {
        //         ans=ans+price[b++]*max;
        //         vis[max_pair]=true;
        //         vis_time[max_pair.first]=true;
        //         vis_movie[max_pair.second]=true;
        //     }
        // }
        final_ans+=ans;
        cout<<ans<<"\n";
    }
    cout<<final_ans<<"\n";
}

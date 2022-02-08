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
#define mod 998244353
#define N 10000000
#define all(a) a.begin(),a.end()
#define point pair<ll,ll>

const int inf = 1000000007;
const ll linf = 1ll * inf * inf;
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

ll power(ll x, ll y,ll p) 
{ 
    ll res = 1;      
     x = x % p;    
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % p; 
            y = y>>1;  
            x = (x*x) % p;   
    } 
    return res; 
}

ll modInverse(ll n,ll p) 
{ 
    return power(n, p-2, p); 
} 

pair<ll,ll> operate(pair<ll,ll> &n1,char ch,pair<ll,ll> &n2){
    switch(ch){
        case '&':{
            pair<ll,ll> temp;
            temp.first=add(mul(n2.first,add(n1.first,n1.second)),mul(n2.second,n1.first));
            temp.second=mul(n2.second,n1.second);
            return temp;
        }
        case '|':{
            pair<ll,ll> temp;
            temp.first=mul(n2.first,n1.first);
            temp.second=add(mul(n2.second,add(n1.first,n1.second)),mul(n2.first,n1.second));
            return temp;
        }
        case '^':{
            pair<ll,ll> temp;
            temp.first=add(mul(n2.first,n1.first),mul(n2.second,n1.second));
            temp.second=add(mul(n2.second,n1.first),mul(n2.first,n1.second));
            return temp;
        }                
    }
}

pair<ll,ll> solve(string s,ll low,ll high)
{
    stack<pair<pair<ll,ll>,char>> st;
    for(ll i=low;i<=high;i++){
        if(s[i]=='#'){
            st.push({{2,2},'@'});
        }else if(s[i]=='('){
            pair<ll,ll> temp=solve(s,i+1,high);
            st.push({temp,'@'});
            stack<char> s1;s1.push('(');i++;
            while(!s1.empty()){
                if(s[i]=='(')s1.push(s[i]);
                else if(s[i]==')')s1.pop();
                i++;
            }
            i--;
        }else if(s[i]==')'){
            break;
        }else{
            st.push({{-1,-1},s[i]});
        }
    }
    while(st.size()>2){
        pair<ll,ll> n1=st.top().first;st.pop();
        char opr=st.top().second;st.pop();
        pair<ll,ll> n2=st.top().first;st.pop();
        pair<ll,ll> temp=operate(n2,opr,n1);
        st.push({{temp},'@'});
    }
    // cout<<st.top().first.first<<" "<<st.top().first.second<<endl;
    return st.top().first;
}

int main()
{
    fio;
    ll t;cin>>t;
    while(t--)
    {
        string s;cin>>s;
        // string s="(";s.append(inp);s.append(")");
        pair<ll,ll> ans=solve(s,0,s.length()-1);
        ll count=0;
        for(ll i=0;i<s.length();i++){
            if(s[i]=='#')count++;
        }
        ll qu=power(4,count,mod);
        ll ans1,ans2,ans3,ans4;
        ll zero=mul(ans.first,modInverse(qu,mod));
        ll one=mul(ans.second,modInverse(qu,mod));
        ans1=mul(zero,zero);
        ans2=mul(one,one);
        ans3=mul(zero,one);
        ans4=mul(one,zero);
        cout<<ans1<<" "<<ans2<<" "<<ans3<<" "<<ans4<<"\n";
    }
}



#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
using namespace std;

using l =long int;
using ll =long long int;
#define imax INT_MAX
#define lmax LLONG_MAX
#define pb push_back
#define ld long double
#define pii pair<l,l> 
#define pll pair<ll,ll>
#define v vector
#define vl vector<l>
#define vll vector<ll>
#define vvl vector<vector<l>>
#define vvll vector<vector<ll>>
#define vv(a) vector<vector<a>> 
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define mini(a,i,j) *min_element((a).begin()+i,(a).begin()+j)
#define maxi(a,i,j) *max_element((a).begin()+i,(a).begin()+j)
#define sum_vec(a) accumulate(all(a),0)
#define trans_lower(s) transform(all(s),s.begin(),::tolower)
#define trans_upper(s) transform(all(s),s.begin(),::toupper)
#define f first
#define se second
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
#define rep(i, begin, end) \
        for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define tc l t=0;cin>>t;while(t--)
#define tc_1 l t=1;while(t--)

const ll inf = 1e9+7;
const ll maxn=1e5+1;
ll n,m;
vv(pll) fact(maxn);

l power(ll n,ll m){
    l count=0;
    while(n%m==0){
        n/=m;
        count++;
    }
    return count;
}

void factor(){
    // fact[0].pb(0);
    // fact[1].pb(1);
    for(auto i=2;i<maxn;i++){
        if(!fact[i].size()) {
            for(auto j=i;j<maxn;j+=i)fact[j].pb({i,power(j,i)});
        }
    }
}

vll solve(vll x){
    vll ret;
    vll a,b;
    for(auto i:x){
        if(i>0)a.pb(i);
        else if(i<0)b.pb(-i);
    }
    map<vll,vll> mp;
    ll index=0;
    for(auto& i:a){
        v<pll> ft=fact[i];
        vll ft_vec;
        for(auto it=ft.begin();it!=ft.end();it++) if(it->se&1)ft_vec.pb(it->f);
        sort(all(ft_vec));
        mp[ft_vec].pb(index);
        index++;
    }
    index=0;
    for(auto i:b){

        v<pll> ft=fact[i];
        vll ft_vec;
        for(auto it=ft.begin();it!=ft.end();it++) if(it->se&1) ft_vec.pb(it->f);
        sort(all(ft_vec));
        if(mp[ft_vec].size()){
            for(auto j:mp[ft_vec]){
                ll q=sqrt(a[j]*i);
                ret.pb(q);ret.pb(-q);
            }
        }
        index++;
    }
    return ret;
}

int main()
{
    fast;
#ifndef ONLINE_JUDGE
    file;
#endif

    factor();
    tc{
        cin>>n>>m;
        vll a(n);cin>>a;
        vll b(m);cin>>b;
        ll ans=0;
        if(find(all(a),0)!=a.end()){
            a.erase(find(all(a),0));
            ans+=((m)*(n-1));
        }
        else if(find(all(b),0)!=b.end()){
            b.erase(find(all(b),0));
            ans+=((m-1)*(n));
        }
        vll ret_a(solve(a));
        vll ret_b(solve(b));
        // debug(ret_a);
        // debug(ret_b);
        map<ll,ll> mp;
        for(auto i:ret_a)mp[i]++;
        for(auto i:b)ans+=mp[i];
        mp.clear();
        for(auto i:ret_b)mp[i]++;
        for(auto i:a)ans+=mp[i];
        cout<<ans<<endl;
    }

#ifndef ONLINE_JUDGE
    cerr << "Time elapsed: " << 1000.0 * clock() / CLOCKS_PER_SEC << " ms.\n";
#endif
    return 0;
}
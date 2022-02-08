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
#define pll pair<ll,ll>
#define inf 1e18
#define pcout(x,p) cout<<fixed<<setprecision(p)<<x
#define all(a) a.begin(),a.end()
#define endl "\n"
const ll mod=1e9+7;
inline ll mul(ll a, ll b){ return (a * 1ll * b) % mod; }
inline ll sub(ll a, ll b){ ll c = a - b; if(c < 0) c += mod; return c; }
inline ll add(ll a, ll b){ ll c = a + b; if(c >= mod) c -= mod; return c; }
inline ll max(ll a, ll b){return a>b?a:b;}
inline ll min(ll a, ll b){return a<b?a:b;}
inline ll ceil(ll a,ll b){return (a%b==0)?(a/b):(a/b+1);}
template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    for(auto v : V) os << v << " ";
    return os;
}
template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ ";
    for(auto s:S) os<<s<<" ";
    return os<<"}";
}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.first << "," << P.second << ")";
}
template<class L, class R> ostream& operator<<(ostream &os, map<L,R> M) {
    os << "{ ";
    for(auto m:M) os<<"("<<m.first<<":"<<m.second<<") ";
    return os<<"}";
}
struct comp { 
    template<class T1,class T2,class T3,class T4>
    bool operator()(const pair<T1,T2> &p1,const pair<T3,T4> &p2){
        return p1.first<p2.first;
    }
};

class SegmentTree{
private:
	ll size;
	vector<pll> segtree;
public:
	void init(ll n){
		size=1;
		while(size<n)size=size*2;
		segtree.resize(2*size,{inf,1});
	}

	void build(vl &a,ll root,ll left,ll right){
		if((right-left)==1){
			if(left<(ll)a.size()){
				segtree[root]={a[left],1};
			}
			return;
		}
		ll mid=left+(right-left)/2;
		build(a,2*root+1,left,mid);
		build(a,2*root+2,mid,right);
		pll temp1=segtree[2*root+1];
		pll temp2=segtree[2*root+2];
		if(temp1.first<temp2.first){
			segtree[root]=temp1;
		}else if(temp2.first<temp1.first){
			segtree[root]=temp2;
		}else{
			segtree[root]={temp1.first,temp1.second+temp2.second};
		}
	}

	void build(vl &a){
		build(a,0,0,size);
	}

	void set(ll &index,ll &value,ll root,ll left,ll right){
		if((right-left)==1){
			segtree[root].first=value;
			return;
		}
		ll mid=left+(right-left)/2;
		if(index<mid){
			set(index,value,2*root+1,left,mid);
		}else{
			set(index,value,2*root+2,mid,right);
		}
		pll temp1=segtree[2*root+1];
		pll temp2=segtree[2*root+2];
		if(temp1.first<temp2.first){
			segtree[root]=temp1;
		}else if(temp2.first<temp1.first){
			segtree[root]=temp2;
		}else{
			segtree[root]={temp1.first,temp1.second+temp2.second};
		}
	}

	void set(ll index,ll value){
		set(index,value,0,0,size);
	}

	pll query(ll &l,ll &r,ll root,ll left,ll right){
		if(l>=right||r<=left)return {inf,1};
		if(left>=l && right<=r)return segtree[root];
		ll mid=left+(right-left)/2;
		pll m1=query(l,r,2*root+1,left,mid);
		pll m2=query(l,r,2*root+2,mid,right);
		if(m1.first<m2.first){
			return m1;
		}else if(m2.first<m1.first){
			return m2;
		}else{
			return {m1.first,m1.second+m2.second};
		}
	}

	pll query(ll l,ll r){
		return query(l,r,0,0,size);
	}
};


int main(){
	ll n,m;cin>>n>>m;
	vl a(n);
	f(n)cin>>a[i];
	SegmentTree tree;
	tree.init(n);
	tree.build(a);
	while(m--){
		ll op;cin>>op;
		if(op==1){
			ll index,value;cin>>index>>value;
			tree.set(index,value);
		}else{
			ll l,r;cin>>l>>r;
			pll temp=tree.query(l,r);
			cout<<temp.first<<" "<<temp.second<<endl;
		}
	}
}
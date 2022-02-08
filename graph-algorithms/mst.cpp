// using krushkal's algorithm
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
struct Edge{
    ll u,v,weight;  
    Edge(ll a,ll b,ll c){
    	u=a,v=b,weight=c;
    }
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }    
};
vector<Edge> edges,ans;
ll n,m;

class disjointSet{
	private:
		ll n;
		vector<ll> parent,size;
	public:
		disjointSet(ll nn){
			n=nn;
			parent.resize(n);size.resize(n);
		}
		void make_set(ll a){
			parent[a]=a;
			size[a]=1;
		}
		ll find_set(ll a){
			if(parent[a]==a)
				return a;
			return parent[a]=find_set(parent[a]);
		}
		void union_set(ll a,ll b){
			a=find_set(a);
			b=find_set(b);
			if(a!=b){
				if(size[a]<size[b])
					swap(a,b);
				parent[b]=a;
				size[a]+=size[b];
			}
		}
};

void MST(){
	sort(edges.begin(),edges.end());
	disjointSet set(n);
	for(ll i=0;i<n;i++){
		set.make_set(i);
	}
	ll i=0,totalCost=0;
	while(ans.size()<(n-1)){
		ll u=edges[i].u,v=edges[i].v,w=edges[i].weight;
		ll a,b;
		a=set.find_set(u);
		b=set.find_set(v);
		if(a!=b){
			ans.push_back(edges[i]);
			totalCost+=w;
			set.union_set(a,b);
		}
		i++;
	}
	cout<<totalCost<<"\n";
	// ans contains all the edges included
	return;
}
void solve(){
	cin>>n>>m;
	if((m)<(n-1))return;
	edges.clear();ans.clear();
	for(ll i=0;i<m;i++){
		ll u,v,w;cin>>u>>v>>w;// u and v should be 0 indexing
		Edge edge(u,v,w);
		edges.push_back(edge);
	}
	MST();
	return;
}
int main(){
	ll t;cin>>t;
	while(t--){
		solve();
	}
}
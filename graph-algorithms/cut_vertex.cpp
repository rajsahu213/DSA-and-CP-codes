#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<vector<ll>> graph;
vector<ll> color,startTime,lowTime;
set<ll> cut;
ll n,m,TIME=0;
void init(){
	graph.clear();graph.resize(n);
	color.clear();color.assign(n,0);
	startTime.clear();startTime.resize(n);
	lowTime.clear(),lowTime.resize(n);
	cut.clear();
	TIME=0;
}
void dfs(ll s,ll par){
	color[s]=1;
	startTime[s]=lowTime[s]=TIME++;
	ll subtree=0;
	for(ll x:graph[s]){
		if(x==par)continue;
		if(color[x]==1){
			lowTime[s]=min(lowTime[s],startTime[x]);
		}else{
			dfs(x,s);
			if(par!=-1 && lowTime[x]>=startTime[s]){
				cut.insert(s);
			}
			lowTime[s]=min(lowTime[s],lowTime[x]);
			subtree++;
		}
	}
	if(par==-1 && subtree>1){
		cut.insert(s);
	}
}

void solve(){
	cin>>n>>m;
	init();
	for(ll i=0;i<m;i++){
		ll u,v;cin>>u>>v;
		u--;v--;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for(ll i=0;i<n;i++){
		if(color[i]==0){
			dfs(i,-1);
		}
	}
	cout<<cut.size()<<"\n";
}

int main(){
	ll t;cin>>t;
	while(t--){
		solve();
	}
}

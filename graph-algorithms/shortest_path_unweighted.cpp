#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll inf=1e18;

void BFS(ll s,vector<vector<ll>> &graph,ll n,vector<ll> &ans){
	queue<pair<ll,ll>> q;
	vector<bool> vis(n,false);
	vis[s]=true;
	q.push({s,0});
	while(!q.empty()){
		pair<ll,ll> node=q.front();q.pop();
		ans[node.first]=min(ans[node.first],node.second);
		for(ll x:graph[node.first]){
			if(!vis[x]){
				vis[x]=true;
				q.push({x,node.second+1});
			}
		}
	}
}

int main(){
	ll n;cin>>n;
	vector<vector<ll>> graph(n);
	ll e;cin>>e;
	for(ll i=0;i<e;i++){
		ll u,v;cin>>u>>v;
		u--;v--;
		graph[u].push_back(v);
	}
	ll s;cin>>s;s--;
	vector<ll> distanceFromS(n,inf);
	BFS(s,graph,n,distanceFromS);
	for(ll dis:distanceFromS){
		cout<<dis<<" ";
	}
	cout<<"\n";
}
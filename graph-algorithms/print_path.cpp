//printing all paths between two given nodes in a graph

#include<bits/stdc++.h>
using namespace std;
#define vvl vector<vector<ll>>
#define ll long long int 

void DFS(ll s,ll &d,vector<ll> &temp,vvl &graph,vector<bool> &vis){
	if(s==d){
		for(ll x:temp){
			cout<<x+1<<" ";
		}
		cout<<endl;
		return;
	}else{
		for(ll node:graph[s]){
			if(!vis[node]){
				vis[node]=true;
				temp.push_back(node);
				DFS(node,d,temp,graph,vis);
				vis[node]=false;
				temp.pop_back();
			}
		}
	}
}

int main(){
	ll n;cin>>n;
	ll e;cin>>e;
	vvl graph(n);
	for(ll i=0;i<e;i++){
		ll u,v;cin>>u>>v;
		u--;v--;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	cout<<"source: ";
	ll s;cin>>s;s--;
	cout<<"destination: ";
	ll d;cin>>d;d--;
	vector<ll> temp;
	vector<bool> vis(n,false);
	temp.push_back(s);vis[s]=true;
	DFS(s,d,temp,graph,vis);
	temp.pop_back();
	return 0;
}
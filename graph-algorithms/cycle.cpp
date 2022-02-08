//we use color to detect cycle in directed graph
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long int
// #define vl vector<ll> 
// #define vvl vector<vl> 

// vvl graph;
// vl color;
// ll n,e;

// bool DFS(ll s){
// 	color[s]=1;
// 	for(ll x:graph[s]){
// 		if(color[x]==1){
// 			return true;
// 		}
// 		if(color[x]==0){
// 			if(DFS(x))
// 				return true;
// 		}
// 	}
// 	color[s]=2;
// 	return false;
// }

// int main(){
// 	cin>>n;
// 	graph.resize(n);
// 	color.resize(n,0);
// 	cin>>e;
// 	for(ll i=0;i<e;i++){
// 		ll u,v;cin>>u>>v;
// 		u--;v--;
// 		graph[u].push_back(v);
// 	}
// 	bool ans=false;
// 	for(ll i=0;i<n;i++){
// 		if(color[i]==0){
// 			bool flag=DFS(i);
// 			if(flag){
// 				ans=true;
// 			}
// 		}
// 	}
// 	cout<<((ans)?"has cycle\n":"dont have a cycle\n");
// }

// to detect cycle in undirected graph we just need a vis array

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vl vector<ll> 
#define vvl vector<vl> 

vvl graph;
vector<bool> vis;
ll n,e;

bool DFS(ll s,ll par){
	vis[s]=true;
	for(ll x:graph[s]){
		if(x!=par){
			if(vis[x])
				return true;
			if(!vis[x]){
				if(DFS(x,s))
					return true;
			}
		}
	}
	return false;
}

int main(){
	cin>>n;
	cin>>e;
	graph.resize(n);
	vis.resize(n,false);
	for(ll i=0;i<e;i++){
		ll u,v;cin>>u>>v;
		u--;v--;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	bool ans=false;
	for(ll i=0;i<n;i++){
		if(!vis[i]){
			ans=ans|DFS(i,-1);
		}
	}
	cout<<((ans)?"has cycle\n":"dont have a cycle\n");
}
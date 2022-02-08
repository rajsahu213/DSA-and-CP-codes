#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define vl vector<ll>
#define vvl vector<vl>

vvl graph;
vl startTime,endTime,color;
ll n,e,TIME;

void DFS(ll s){
	color[s]=1;
	startTime[s]=TIME++;
	for(ll x:graph[s]){
		if(color[x]==0){
			DFS(x);
		}
	}
	endTime[s]=TIME++;
	color[s]=2;
}

int main(){
	cin>>n;
	cin>>e;
	graph.resize(n);
	for(ll i=0;i<e;i++){
		ll u,v;cin>>u>>v;
		u--;v--;
		graph[u].push_back(v);
	}
	startTime.resize(n),endTime.resize(n);
	color.resize(n,0);TIME=0;
	for(ll i=0;i<n;i++){
		if(color[i]==0){
			DFS(i);
		}
	}
}

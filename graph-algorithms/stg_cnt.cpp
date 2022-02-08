/*
STRONGLY CONNECTED COMPONENTS
it is defined only for directed graphs
for undirected graphs all the connected components are
strongly connected 
a strongly connected component is defined as the component
in which we can reach any vertex from any given vertex
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vl vector<ll> 
#define vvl vector<vl>

vvl graph,Tgraph;
vl color,topo;
stack<ll> st;
ll n,e;

void init(){
	graph.clear();Tgraph.clear();
	graph.resize(n);Tgraph.resize(n);
	color.clear(),topo.clear();
	color.resize(n,0);topo.resize(n);
}

void DFS(ll s){
	color[s]=1;
	for(ll x:graph[s]){
		if(color[x]==0){
			DFS(x);
		}
	}
	color[s]=2;
	st.push(s);
}

void topoSort(){
	ll k=0;
	while(!st.empty()){
		topo[k++]=st.top();st.pop();
	}
}

void takeTranspose(){
	for(ll i=0;i<n;i++){
		for(ll x:graph[i]){
			Tgraph[x].push_back(i);
		}
	}
}

void DFS_util(ll s){
	char ch=s+'A';
	cout<<ch<<" ";
	color[s]=1;
	for(ll x:Tgraph[s]){
		if(color[x]==0){
			DFS_util(x);
		}
	}
}

int main(){
	ll t;cin>>t;
	while(t--)
	{
		cin>>n;
		cin>>e;
		init();
		for(ll i=0;i<e;i++){
			ll u,v;cin>>u>>v;
			u--;v--;
			graph[u].push_back(v);
		}
		for(ll i=0;i<n;i++){
			if(color[i]==0){
				DFS(i);
			}
		}
		topoSort();
		takeTranspose();
		fill(color.begin(),color.end(),0);
		for(ll i=0;i<n;i++){
			ll s=topo[i];
			if(color[s]==0){
				DFS_util(s);
				cout<<"\n";
			}
		}
	}
}
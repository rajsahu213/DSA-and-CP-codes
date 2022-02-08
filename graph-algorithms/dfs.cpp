/*
WRITING A CODE FOR DFS IN 
1)undirected - unweighted graph
2)undirected - weighted graph
3)directed - unweighted graph
4)directed - weighted graph

TREE IS NOTHING BUT A DIRECTED ACYCLIC GRAPH(DAG)
1)dfs for a unweighted tree
2)dfs for a weighted tree
*/

/*
APPLICATIONS OF DEPTH FIRST SEARCH
1) printing paths from a given source vertex to all other reacheable vertex
2) calculating the arival and departure time for every vertex
3) check if a vertex is an ancestor of other vertex in a tree
4) topological sorting of vertices of the given graph
5) check if there is cycle in undirected and directed graphs
6) finding the strongly connected components in a directed graph
7) finding bridges in undirected graphs
*/

// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long int
// #define vvll vector<vector<ll>>
// #define vvpll vector<vector<pair<ll,ll>>>

// //undirected unweighted 
// void DFS(ll s,vvll &graph,vector<bool> &vis){
// 	char ch=s+'a';
// 	cout<<ch<<" ";
// 	vis[s]=true;
// 	for(ll x:graph[s]){
// 		if(!vis[x]){
// 			DFS(x,graph,vis);
// 		}
// 	}
// }

// int main(){
// 	ll n;cin>>n;
// 	ll e;cin>>e;
// 	vvll graph(n);
// 	for(ll i=0;i<e;i++){
// 		ll u,v;cin>>u>>v;
// 		u--;v--;
// 		graph[u].push_back(v);
// 		graph[v].push_back(u);
// 	}
// 	vector<bool> vis(n,false);
// 	for(ll i=0;i<n;i++){
// 		if(!vis[i]){
// 			DFS(i,graph,vis);
// 			cout<<endl;
// 		}
// 	}
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long int
// #define vvll vector<vector<ll>>
// #define vvpll vector<vector<pair<ll,ll>>>

// // undirected graph with weighted edges
// void DFS(ll s,vvpll &graph,vector<bool> &vis){
// 	cout<<s<<" ";
// 	vis[s]=true;
// 	for(auto x:graph[s]){
// 		if(!vis[x.first]){
// 			DFS(x.first,graph,vis);
// 		}
// 	}
// }

// int main(){
// 	ll n;cin>>n;
// 	ll e;cin>>e;
// 	vvpll graph(n);
// 	for(ll i=0;i<e;i++){
// 		ll u,v,w;
// 		cin>>u>>v>>w;
// 		graph[u].push_back({v,w});
// 		graph[v].push_back({u,w});
// 	}
// 	vector<bool> vis(n,false);
// 	for(ll i=0;i<n;i++){
// 		if(!vis[i]){
// 			DFS(i,graph,vis);
// 			cout<<endl;
// 		}
// 	}
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long int
// #define vvll vector<vector<ll>>
// #define vvpll vector<vector<pair<ll,ll>>>

// // directed graph with unweighted edges
// void DFS(ll s,vvll &graph,vector<bool> &vis){
// 	cout<<s+1<<" ";
// 	vis[s]=true;
// 	for(ll x:graph[s]){
// 		if(!vis[x]){
// 			DFS(x,graph,vis);
// 		}
// 	}
// }

// int main(){
// 	ll n;cin>>n;
// 	ll e;cin>>e;
// 	vvll graph(n);
// 	for(ll i=0;i<e;i++){
// 		ll u,v;cin>>u>>v;u--;v--;
// 		graph[u].push_back(v);
// 	}
// 	vector<bool> vis(n,false);
// 	for(ll i=0;i<n;i++){
// 		if(!vis[i]){
// 			DFS(i,graph,vis);
// 			cout<<endl;
// 		}
// 	}
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long int
// #define vvll vector<vector<ll>>
// #define vvpll vector<vector<pair<ll,ll>>>

// //directed graph with weighted edges
// void DFS(ll s,vvpll &graph,vector<bool> &vis){
// 	cout<<s+1<<" ";
// 	vis[s]=true;
// 	for(auto x:graph[s]){
// 		if(!vis[x.first]){
// 			DFS(x.first,graph,vis);
// 		}
// 	}
// }

// int main(){
// 	ll n;cin>>n;
// 	ll e;cin>>e;
// 	vvpll graph(n);
// 	for(ll i=0;i<e;i++){
// 		ll u,v,w;cin>>u>>v>>w;
// 		u--;v--;
// 		graph[u].push_back({v,w});
// 	}
// 	vector<bool> vis(n,false);
// 	for(ll i=0;i<n;i++){
// 		if(!vis[i]){
// 			DFS(i,graph,vis);
// 			cout<<endl;
// 		}
// 	}
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long int
// #define vvll vector<vector<ll>>
// #define vvpll vector<vector<pair<ll,ll>>>

// // undirected unweighted tree
// void DFS(ll root,ll par,vvll &tree){
// 	cout<<root<<" ";
// 	for(ll node:tree[root]){
// 		if(node!=par){
// 			DFS(node,root,tree);
// 		}
// 	}
// }

// int main(){
// 	ll n;cin>>n;
// 	vvll tree(n);
// 	for(ll i=0;i<n-1;i++){
// 		ll u,v;cin>>u>>v;
// 		tree[u].push_back(v);
// 		tree[v].push_back(u);
// 	}
// 	DFS(0,-1,tree);
// 	cout<<endl;
// }
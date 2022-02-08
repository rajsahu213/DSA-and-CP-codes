/*
	ONLY POSSIBLE FOR DAG!!
there are two ways to do topological
sorting
1) kahn's algorithm for indegree
2) using dfs
note:
	using priority queue in kahn's
	algorithm we can find lexicographically
	first topological ordering or vertices
it can also be used to detect cycle in
directed graphs
*/
// topo sort using kahn's algo
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long int
// #define vl vector<ll>
// #define vvl vector<vl>

// vvl graph;
// vl order,indegree;
// ll n,e;
void topologicalSorting() {
	queue<ll> q;// use priority queue to get
	// laxicographically first ordering
	for (ll i = 0; i < n; i++) {
		if (indegree[i] == 0)
			q.push(i);
	}
	while (!q.empty()) {
		ll u = q.front(); q.pop();
		order.push_back(u);
		for (ll v : graph[u]) {
			indegree[v]--;
			if (indegree[v] == 0)
				q.push(v);
		}
	}
	/*
	if order.size()!=n
		then the graph contains cycle
	else the graph is a DAG!
	*/
}

// int main(){
// 	cin>>n>>e;
// 	graph.resize(n);
// 	indegree.assign(n,0);
// 	for(ll i=0;i<e;i++){
// 		ll u,v;cin>>u>>v;
// 		u--;v--;
// 		graph[u].push_back(v);
// 		indegree[v]++;
// 	}
// 	topologicalSorting();
// 	cout<<"topological ordering of vertices are\n";
// 	for(ll x:order){
// 		cout<<x+1<<" ";
// 	}cout<<"\n";
// }

// topo sort using dfs
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long int
// #define vl vector<ll>
// #define vvl vector<vl>

// vvl graph;
// vl order,color;
// ll n,e;
// bool dfs(ll s){
// 	color[s]=1;
// 	for(ll x:graph[x]){
// 		if(color[x]==1)
// 			return true;
// 		if(color[x]==0 && dfs(x))
// 			return true;
// 	}
// 	color[s]=2;
// 	order.push_back(s);
// 	return false;
// }

// int main(){
// 	cin>>n>>e;
// 	graph.resize(n);
// 	color.assign(n,0);
// 	for(ll i=0;i<e;i++){
// 		ll u,v;cin>>u>>v;
// 		u--;v--;
// 		graph[u].push_back(v);
// 	}
// 	bool cycle=false;
// 	for(ll i=0;i<n;i++){
// 		if(color[i]==0){
// 			cycle=cycle|dfs(i);
// 		}
// 	}
// 	if(cycle){
// 		cout<<"graph contains cycle!!\n";
// 	}else{
// 		cout<<"the required ordering is: ";
// 		reverse(order.begin(),order.end());
// 		for(ll x:order){
// 			cout<<x+1<<" ";
// 		}cout<<"\n";
// 	}
// }
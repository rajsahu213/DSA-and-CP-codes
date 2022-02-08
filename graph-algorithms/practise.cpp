// //  TOPOLOGICAL SORTING IS DEFINED ONLY FOR DAG!
// // dfs in a unweighted graph
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long int
// #define vl vector<ll>
// #define vvl vector<vl>

// vvl graph;
// vl color,startTime,endTime,topo;
// ll n,e,TIME=0;
// void dfs(ll s){
// 	cout<<s+1<<" ";
// 	color[s]=1;
// 	startTime[s]=TIME++;
// 	for(ll x:graph[s]){
// 		if(color[x]==0){
// 			dfs(x);
// 		}
// 	}
// 	color[s]=2;
// 	endTime[s]=TIME++;
// 	topo.push_back(s);
// }
// int main(){
// 	cin>>n>>e;
// 	graph.resize(n);startTime.resize(n);
// 	color.assign(n,0);endTime.resize(n);
// 	for(ll i=0;i<e;i++){
// 		ll u,v;cin>>u>>v;
// 		u--;v--;
// 		graph[u].push_back(v);
// 	}
// 	cout<<"dfs of the enterered graph is\n";
// 	for(ll i=0;i<n;i++){
// 		if(color[i]==0){
// 			dfs(i);
// 			cout<<"\n";
// 		}
// 	}
// 	reverse(topo.begin(),topo.end());
// 	for(ll x:topo){
// 		cout<<x+1<<" ";
// 	}cout<<endl;
// }
//dfs for weighted graphs
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long int
// #define pll pair<ll,ll>
// #define vl vector<ll>
// #define vvpll vector<vector<pll>>
// #define vvl vector<vl>

// vvpll graph;
// vl color,startTime,endTime,topo;
// ll n,e,TIME=0;
// void dfs(ll s){
// 	cout<<s+1<<" ";
// 	color[s]=1;
// 	startTime[s]=TIME++;
// 	for(pll x:graph[s]){
// 		if(color[x.first]==0)
// 			dfs(x.first);
// 	}
// 	endTime[s]=TIME++;
// 	topo.push_back(s);
// 	color[s]=2;
// }

// int main(){
// 	cin>>n>>e;
// 	graph.resize(n);startTime.resize(n);
// 	endTime.resize(n);color.resize(n,0);
// 	for(ll i=0;i<e;i++){
// 		ll u,v,w;cin>>u>>v>>w;
// 		u--;v--;
// 		graph[u].push_back({v,w});
// 	}
// 	cout<<"dfs for the enterered graph is\n";
// 	for(ll i=0;i<n;i++){
// 		if(color[i]==0){
// 			dfs(i);
// 			cout<<endl;
// 		}
// 	}
// 	reverse(topo.begin(),topo.end());
// 	for(ll x:topo){
// 		cout<<x+1<<" ";
// 	}cout<<endl;
// }

// to print all the ancectors of a given node
// and to print the lowest common ancestor
// of two given node

// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long int
// #define vl vector<ll>
// #define vvl vector<vl>

// vvl tree;
// vl startTime,endTime;
// ll n,m,TIME=0,root;
// void dfs(ll node,ll par){
// 	startTime[node]=TIME++;
// 	for(ll x:tree[node]){
// 		if(x!=par)
// 			dfs(x,node);
// 	}
// 	endTime[node]=TIME++;
// }
// void printAncestors(ll node){
// 	for(ll i=0;i<n;i++){
// 		if(startTime[i]<=startTime[node] && 
// 			endTime[node]<=endTime[i])
// 			cout<<i+1<<" ";
// 	}
// 	cout<<endl;
// }

// int lca(ll u,ll v){
// 	vl ancu,ancv;
// 	for(ll i=0;i<n;i++){
// 		if(startTime[i]<=startTime[u] &&
// 			endTime[u]<=endTime[i]){
// 			ancu.push_back(i);
// 		}
// 		if(startTime[i]<=startTime[v] &&
// 			endTime[v]<=endTime[i]){
// 			ancv.push_back(i);
// 		}		
// 	}
// 	sort(ancu.begin(),ancu.end());
// 	sort(ancv.begin(),ancv.end());
// 	ll ans,time=-1;
// 	ll i=0,j=0;
// 	while(i<ancu.size() && j<ancv.size()){
// 		if(ancu[i]==ancv[j]){
// 			ll node=ancu[i];
// 			if(startTime[node]>time){
// 				ans=node;time=startTime[node];
// 			}
// 			i++;j++;
// 		}else if(ancu[i]>ancv[j]){
// 			j++;
// 		}else{
// 			i++;
// 		}
// 	}
// 	return ans+1;
// }

// int main(){
// 	cin>>n;
// 	cin>>m;
// 	tree.resize(n);
// 	startTime.resize(n);endTime.resize(n);
// 	for(ll i=0;i<m;i++){
// 		ll u,v;cin>>u>>v;
// 		u--;v--;
// 		tree[u].push_back(v);
// 		tree[v].push_back(u);
// 	}
// 	cout<<"enter the root node: ";
// 	cin>>root;root--;
// 	dfs(root,-1);
// 	cout<<"enter the node: ";
// 	ll node;cin>>node;node--;
// 	printAncestors(node);
// 	cout<<"enter two nodes: ";
// 	ll u,v;cin>>u>>v;
// 	u--;v--;
// 	cout<<lca(u,v)<<endl;
// }

// to detect cycle in  undirected and directed
// graph
// to detect a cycle in directed graph
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long int
// #define vl vector<ll>
// #define vvl vector<vl>

// vvl graph;
// vl color;
// ll n,e;
// bool dfs(ll s){
// 	color[s]=1;
// 	for(ll x:graph[s]){
// 		if(color[x]==1)
// 			return true;
// 		if(color[x]==0){
// 			if(dfs(x))
// 				return true;
// 		}
// 	}
// 	color[s]=2;
// 	return false;
// }

// int main(){
// 	cin>>n>>e;
// 	graph.resize(n);color.assign(n,0);
// 	for(ll i=0;i<e;i++){
// 		ll u,v;cin>>u>>v;
// 		u--;v--;
// 		graph[u].push_back(v);
// 	}
// 	bool ans=false;
// 	for(ll i=0;i<n;i++){
// 		if(color[i]==0){
// 			ans=ans|dfs(i);
// 		}
// 	}
// 	cout<<((ans)?"has cycle\n":"no cycle found\n");
// }

// to detect cycle in undirected graph
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long int
// #define vl vector<ll>
// #define vvl vector<vl>

// vvl graph;
// vector<bool> vis;
// ll n,e;
// bool dfs(ll s,ll prev){
// 	vis[s]=true;
// 	for(ll x:graph[s]){
// 		if(x!=prev){
// 			if(vis[x])
// 				return true;
// 			else{
// 				if(dfs(x,s))
// 					return true;
// 			}
// 		}
// 	}
// 	return false;
// }

// int main(){
// 	cin>>n>>e;
// 	graph.resize(n);
// 	vis.assign(n,false);
// 	for(ll i=0;i<e;i++){
// 		ll u,v;cin>>u>>v;
// 		u--;v--;
// 		graph[u].push_back(v);
// 		graph[v].push_back(u);
// 	}
// 	bool ans=false;
// 	for(ll i=0;i<n;i++){
// 		if(!vis[i]){
// 			ans=ans|dfs(i,-1);
// 		}
// 	}
// 	cout<<((ans)?"has cycle\n":"no cycle\n");
// }

// to find the strongly connected components
// for a directed graph
// for undirected graphs all connected 
// components are strongly connected
//take topo sort make transpose run dfs
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long int
// #define vl vector<ll>
// #define vvl vector<vl>

// vvl graph,Tgraph;
// vl topo,color;
// ll n,e;
// void dfs(ll s){
// 	color[s]=1;
// 	for(ll x:graph[s]){
// 		if(color[x]==0)
// 			dfs(x);
// 	}
// 	color[s]=2;
// 	topo.push_back(s);
// }
// void takeTranspose(){
// 	Tgraph.resize(n);
// 	for(ll i=0;i<n;i++){
// 		for(ll x:graph[i]){
// 			Tgraph[x].push_back(i);
// 		}
// 	}
// }
// void dfs_util(ll s){
// 	color[s]=1;
// 	cout<<s+1<<" ";
// 	for(ll x:Tgraph[s]){
// 		if(color[x]==0)
// 			dfs_util(x);
// 	}
// 	color[s]=2;
// }

// int main(){
// 	cin>>n>>e;
// 	graph.resize(n),color.assign(n,0);
// 	for(ll i=0;i<e;i++){
// 		ll u,v;cin>>u>>v;
// 		u--;v--;
// 		graph[u].push_back(v);
// 	}
// 	for(ll i=0;i<n;i++){
// 		if(color[i]==0){
// 			dfs(i);
// 		}
// 	}
// 	reverse(topo.begin(),topo.end());
// 	takeTranspose();
// 	cout<<"the strongly connected components are\n";
// 	fill(color.begin(),color.end(),0);
// 	for(ll i=0;i<n;i++){
// 		ll s=topo[i];
// 		if(color[s]==0){
// 			dfs_util(s);
// 			cout<<endl;
// 		}
// 	}
// }

// bfs of a graph as well as calculating shortest
// path in an unweighted graph
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long int
// #define vl vector<ll>
// #define vvl vector<vl>
// const ll inf=1e18;
// vvl graph;
// vl d,p;
// vector<bool> vis;
// ll n,e;
// void bfs(ll s){
// 	vis.assign(n,false);
// 	d.resize(n);p.resize(n);	
// 	queue<ll> q;q.push(s);
// 	d[s]=0;p[s]=-1;
// 	vis[s]=true;
// 	while(!q.empty()){
// 		ll temp=q.front();q.pop();
// 		for(ll x:graph[temp]){
// 			if(!vis[x]){
// 				vis[x]=true;
// 				d[x]=d[temp]+1;
// 				p[x]=temp;
// 				q.push(x);
// 			}
// 		}
// 	}
// }

// void printShortestPath(ll s,ll t){
// 	if(!vis[t]){
// 		cout<<"no path!\n";
// 		return;
// 	}
// 	vl path;
// 	for(ll i=t;i!=-1;i=p[i])
// 		path.push_back(i);
// 	reverse(path.begin(),path.end());
// 	cout<<"path: ";
// 	for(ll x:path)
// 		cout<<x<<" ";
// 	cout<<endl;
// }

// int main(){
// 	cin>>n>>e;
// 	graph.resize(n);
// 	for(ll i=0;i<e;i++){
// 		ll u,v;cin>>u>>v;
// 		// u--;v--;
// 		graph[u].push_back(v);
// 		graph[v].push_back(u);
// 	}
// 	cout<<"enter the source vertex: ";
// 	ll s;cin>>s;
// 	bfs(s);
// 	cout<<"enter the destination: ";
// 	ll t;cin>>t;
// 	printShortestPath(s,t);
// }




/*
queries to check weather edge (u,v) lies in
the shortest path form vertex (a to b) 
note 
1) to find the edge
da[u]+db[v]+1==da[b]
2) to find vertex
da[v]+db[v]==da[b]
*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long int
// #define vl vector<ll>
// #define vvl vector<vl>

// vvl graph;
// vl da,db;
// vector<bool> vis;
// ll n,m;
// void bfs(ll s,vl &d){
// 	queue<ll> q;
// 	d[s]=0;vis[s]=true;
// 	q.push(s);
// 	while(!q.empty()){
// 		ll temp=q.front();q.pop();
// 		for(ll x:graph[temp]){
// 			if(!vis[x]){
// 				d[x]=d[temp]+1;
// 				vis[x]=true;
// 				q.push(x);
// 			}
// 		}
// 	}
// }

// int main(){
// 	cin>>n>>m;
// 	graph.resize(n);
// 	for(ll i=0;i<m;i++){
// 		ll u,v;cin>>u>>v;
// 		u--;v--;
// 		graph[u].push_back(v);
// 		graph[v].push_back(u);
// 	}
// 	ll a,b;cin>>a>>b;
// 	a--;b--;
// 	da.resize(n);
// 	vis.assign(n,false);
// 	bfs(a,da);
// 	if(!vis[b]){
// 		cout<<"no path!!\n";
// 		return 0;
// 	}
// 	db.resize(n);
// 	vis.assign(n,false);
// 	bfs(b,db);
// 	ll q;cin>>q;
// 	while(q--){
// 		ll u,v;cin>>u>>v;
// 		u--;v--;
// 		if((da[u]+db[v]+1)==da[b]){
// 			cout<<"Yes\n";
// 		}else{
// 			cout<<"No\n";
// 		}
// 	}
// }

// finding the connected components in a graph
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long int
// #define vl vector<ll>
// #define vvl vector<vl>

// vvl graph;
// vl color;
// ll n,m;
// void dfs(ll s){
// 	char ch=s+'a';
// 	cout<<ch<<" ";
// 	color[s]=1;
// 	for(ll x:graph[s]){
// 		if(color[x]==0){
// 			dfs(x);
// 		}
// 	}
// }

// int main(){
// 	cin>>n>>m;
// 	graph.resize(n);
// 	color.assign(n,0);
// 	for(ll i=0;i<m;i++){
// 		ll u,v;cin>>u>>v;
// 		u--;v--;
// 		graph[u].push_back(v);
// 		graph[v].push_back(u);
// 	}
// 	for(ll i=0;i<n;i++){
// 		if(color[i]==0){
// 			cout<<"comp: ";
// 			dfs(i);
// 			cout<<endl;
// 		}
// 	}
// }

// topological sorting using khan's algorithm
//  priority queue can be used to find 
// lexicographically first topo sort
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long int
// #define vl vector<ll> 
// #define vvl vector<vl>

// vvl graph;
// vl topo,indegree;
// vector<bool> vis;
// ll n,e;

// void topoSort(){
// 	priority_queue<ll,vl,greater<ll>> q;
// 	for(ll i=0;i<n;i++){
// 		if(indegree[i]==0){
// 			q.push(i);
// 		}
// 	}
// 	while(!q.empty()){
// 		ll temp=q.top();q.pop();
// 		topo.push_back(temp);
// 		for(ll x:graph[temp]){
// 			indegree[x]--;
// 			if(indegree[x]==0){
// 				q.push(x);
// 			}
// 		}
// 	}
// }

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
// 	topoSort();
// 	cout<<"the topological ordering is: ";
// 	for(ll x:topo){
// 		cout<<x+1<<" ";
// 	}cout<<endl;
// }

// // topological sort is possible for
// // directed acyclic graph
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long int
// #define vl vector<ll>
// #define vvl vector<vl>

// vvl graph;
// vl color,topo;
// stack<ll> stk;
// ll n,e;

// bool DFS(ll s){
// 	color[s]=1;
// 	for(ll x:graph[s]){
// 		if(color[x]==1)
// 			return true;
// 		if(color[x]==0){
// 			if(DFS(x))
// 				return true;
// 		}
// 	}
// 	stk.push(s);
// 	color[s]=2;
// 	return false;
// }

// bool cyclic(){
// 	for(ll i=0;i<n;i++){
// 		if(color[i]==0){
// 			bool flag=DFS(i);
// 			if(flag)return true;
// 		}
// 	}
// 	return false;
// }

// void topoSort(){
// 	topo.resize(n);ll k=0;
// 	while(!stk.empty()){
// 		topo[k++]=stk.top();
// 		stk.pop();
// 	}
// }

// int main(){
// 	cin>>n;
// 	cin>>e;
// 	graph.resize(n);color.resize(n,0);
// 	for(ll i=0;i<e;i++){
// 		ll u,v;cin>>u>>v;
// 		u--;v--;
// 		graph[u].push_back(v);
// 	}
// 	if(cyclic()){
// 		cout<<"oops! the graph is not a DAG!!\n";
// 	}else{
// 		topoSort();
// 		cout<<"the topological ordering is\n";
// 		for(ll i=0;i<n;i++){
// 			char xh=topo[i]+'A';
// 			cout<<xh<<" ";
// 		}cout<<"\n";
// 	}
// }


// #include<bits/stdc++.h>
// using namespace std;

// vector<vector<int>> graph,Tgraph;
// vector<int> color,order;
// int n,m;
// void dfs(int &s){
// 	color[s]=1;
// 	for(int x:graph[s])
// 		if(color[x]==0)
// 			dfs(x);
// 	color[s]=2;
// 	order.push_back(s);
// }
// void takeTranspose(){
// 	Tgraph.resize(n);
// 	for(int i=0;i<n;i++){
// 		for(int x:graph[i]){
// 			Tgraph[x].push_back(i);
// 		}
// 	}
// }
// void dfs_util(int &s){
// 	color[s]=1;
// 	// char ch=s+'a';
// 	cout<<s<<" ";
// 	for(int x:Tgraph[s]){
// 		if(color[x]==0)
// 			dfs_util(x);
// 	}
// 	color[s]=2;
// }

// int main(){
// 	cin>>n>>m;
// 	graph.resize(n);
// 	for(int i=0;i<m;i++){
// 		int u,v;cin>>u>>v;
// 		//u--;v--;
// 		graph[u].push_back(v);
// 	}
// 	color.assign(n,0);
// 	for(int i=0;i<n;i++){
// 		if(color[i]==0){
// 			dfs(i);
// 		}
// 	}
// 	reverse(order.begin(),order.end());
// 	takeTranspose();
// 	fill(color.begin(),color.end(),0);
// 	cout<<"the strongly connected components are\n";
// 	for(int i=0;i<n;i++){
// 		int s=order[i];
// 		if(color[s]==0){
// 			cout<<"component: ";
// 			dfs_util(s);
// 			cout<<"\n";
// 		}
// 	}
// }


// finding bridges in undirected graph
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long int

// vector<vector<ll>> graph;
// vector<ll> color,startTime,lowTime;
// set<pair<ll,ll>> bridge;
// ll n,m,TIME=0;
// void init(){
// 	graph.clear();graph.resize(n);
// 	color.clear();color.assign(n,0);
// 	startTime.clear();startTime.resize(n);
// 	lowTime.clear(),lowTime.resize(n);
// 	bridge.clear();
// 	TIME=0;
// }
// void dfs(ll s,ll par){
// 	color[s]=1;
// 	startTime[s]=lowTime[s]=TIME++;
// 	for(ll x:graph[s]){
// 		if(x==par)continue;
// 		if(color[x]==1){
// 			lowTime[s]=min(lowTime[s],startTime[x]);
// 		}else{
// 			dfs(x,s);
// 			if(lowTime[x]>startTime[s]){
// 				bridge.insert({min(s,x)+1,max(s,x)+1});
// 			}
// 			lowTime[s]=min(lowTime[s],lowTime[x]);
// 		}
// 	}
// }
// void solve(){
// 	cin>>n>>m;
// 	init();
// 	for(ll i=0;i<m;i++){
// 		ll u,v;cin>>u>>v;
// 		u--;v--;
// 		graph[u].push_back(v);
// 		graph[v].push_back(u);
// 	}
// 	for(ll i=0;i<n;i++){
// 		if(color[i]==0){
// 			dfs(i,-1);
// 		}
// 	}
// 	if(bridge.size()==0){
// 		cout<<"No bridge found!!\n";
// 	}else{
// 		cout<<bridge.size()<<"\n";
// 		for(auto i:bridge){
// 			cout<<i.first<<" "<<i.second<<"\n";
// 		}
// 	}
// }

// int main(){
// 	ll t;cin>>t;
// 	while(t--){
// 		solve();
// 	}
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long int
// if the given directed graph has
// a cycle then print any cycle and print the 
// strongly connected components in the graph
// else print the topological ordering of the graph

// find the bridges in an undirected graph

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

vector<vector<ll>> graph;
vector<ll> color,startTime,lowTime;
set<pair<ll,ll>> bridge;
ll n,m,TIME=0;
// void dfs(ll s,ll par){
// 	color[s]=1;
// 	startTime[s]=lowTime[s]=TIME++;
// 	for(ll x:graph[s]){
// 		if(x==par)continue;
// 		if(color[x]==1){
// 			lowTime[s]=min(lowTime[s],startTime[x]);
// 		}else{
// 			dfs(x,s);
// 			if(lowTime[x]>startTime[s]){
// 				bridge.insert({min(s,x)+1,max(s,x)+1});
// 			}
// 			lowTime[s]=min(lowTime[s],lowTime[x]);
// 		}
// 	}
// }

// int main(){
// 	cin>>n>>m;
// 	graph.resize(n);
// 	for(ll i=0;i<m;i++){
// 		ll u,v;cin>>u>>v;
// 		u--;v--;
// 		graph[u].push_back(v);
// 		graph[v].push_back(u);
// 	}
// 	color.assign(n,0);
// 	startTime.resize(n),lowTime.resize(n);
// 	for(ll i=0;i<n;i++){
// 		if(color[i]==0){
// 			dfs(i,-1);
// 		}
// 	}
// }
// find the articulation point in a undirected graph
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

vector<vector<ll>> graph;
vector<ll> color,startTime,lowTime;
set<ll> cut;
ll n,m,TIME=0;
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
			if(lowTime[x]>=startTime[s] && par!=-1){
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

int main(){
	cin>>n>>m;
	graph.resize(n);
	for(ll i=0;i<m;i++){
		ll u,v;cin>>u>>v;
		u--;v--;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	color.assign(n,0);
	startTime.resize(n),lowTime.resize(n);
	for(ll i=0;i<n;i++){
		if(color[i]==0){
			dfs(i,-1);
		}
	}
}

// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long int

// vector<vector<ll>> graph;
// vector<ll> color,startTime,endTime;
// ll n,m,TIME=0;
// void dfs(ll s){
// 	startTime[s]=TIME++;
// 	color[s]=1;
// 	for(ll x:graph[s]){
// 		if(color[x]==0){
// 			dfs(x);
// 		}
// 	}
// 	color[s]=2;
// 	endTime[s]=TIME++;
// }
// ll lca(ll u,ll v){
// 	vector<ll> ancu,ancv;
// 	for(ll i=0;i<n;i++){
// 		if(startTime[i]<=startTime[u] && endTime[u]<=endTime[i]){
// 			ancu.push_back(i);
// 		}
// 		if(startTime[i]<=startTime[v] && endTime[v]<=endTime[i]){
// 			ancv.push_back(i);
// 		}
// 	}
// 	sort(ancu.begin(),ancu.end());
// 	sort(ancv.begin(),ancv.end());
// 	ll i=0,j=0;vector<ll> temp;
// 	while(i<ancu.size() && j<ancv.size()){
// 		if(ancu[i]==ancv[j]){
// 			temp.push_back(ancu[i]);i++;j++;
// 		}else if(ancu[i]<ancv[j])i++;
// 		else j++;
// 	}
// 	if(temp.size()<1)return -1;
// 	sort(temp.begin(),temp.end(),[&](const ll &a,const ll &b){
// 		return startTime[a]>startTime[b];	
// 	});
// 	return temp[0];
// }

// int main(){
// 	cin>>n>>m;
// 	graph.resize(n);
// 	color.assign(n,0);
// 	startTime.resize(n);
// 	endTime.resize(n);
// 	for(ll i=0;i<m;i++){
// 		ll u,v;cin>>u>>v;
// 		u--;v--;
// 		graph[u].push_back(v);
// 		graph[v].push_back(u);
// 	}
// 	cout<<"enter the root: ";
// 	ll root;cin>>root;root--;
// 	dfs(root);
// 	ll q;cin>>q;
// 	while(q--){
// 		ll u,v;cin>>u>>v;
// 		u--;v--;
// 		// if(startTime[u]<=startTime[v] && endTime[v]<=endTime[u]){
// 		// 	cout<<"Yes\n";
// 		// }else{
// 		// 	cout<<"No\n";
// 		// }
// 		cout<<lca(u,v)<<"\n";
// 	}
// }

/*
there are two ways to find the topological 
ordering
1) kahn's algorithm
2) using dfs coloring
*/
// using dfs coloring
// for topo ordering the graph should be a
// Acyclic direcred graph
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long int 

// vector<vector<ll>> graph;
// vector<ll> color,order;
// ll n,m;
// bool dfs(ll s){
// 	color[s]=1;
// 	for(ll x:graph[s]){
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
// 	cin>>n>>m;
// 	graph.resize(n);
// 	for(ll i=0;i<m;i++){
// 		ll u,v;cin>>u>>v;
// 		u--;v--;
// 		graph[u].push_back(v);
// 	}
// 	color.assign(n,0);
// 	bool cycle=false;
// 	for(ll i=0;i<n;i++){
// 		if(color[i]==0){
// 			cycle=cycle|dfs(i);
// 		}
// 	}
// 	if(cycle){
// 		cout<<"the entered graph is not a DAG!!\n";
// 	}else{
// 		cout<<"the topological ordering is \n";
// 		reverse(order.begin(),order.end());
// 		for(ll x:order){
// 			cout<<x<<" ";
// 		}cout<<"\n";
// 	}
// }

/*
using kahn's algorithm
use priority queue to 
get lexicographically smallest ordering
*/

// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long int 

// vector<vector<ll>> graph;
// vector<ll> indegree,order;
// ll n,m;
// void topologicalSort(){
// 	queue<ll> q;
// 	for(ll i=0;i<n;i++){
// 		if(indegree[i]==0)
// 			q.push(i);
// 	}
// 	while(!q.empty()){
// 		ll temp=q.front();q.pop();
// 		order.push_back(temp);
// 		for(ll x:graph[temp]){
// 			indegree[x]--;
// 			if(indegree[x]==0){
// 				q.push(x);
// 			}
// 		}
// 	}
// 	if(order.size()<n){
// 		cout<<"topological ordering is not possible\n";
// 	}else{
// 		for(ll x:order){
// 			cout<<x<<" ";
// 		}cout<<"\n";
// 	}
// }

// int main(){
// 	cin>>n>>m;
// 	graph.resize(n);indegree.assign(n,0);
// 	for(ll i=0;i<m;i++){
// 		ll u,v;cin>>u>>v;
// 		u--;v--;
// 		graph[u].push_back(v);
// 		indegree[v]++;
// 	}
// 	topologicalSort();
// }

/*
detecting cycles in directed graph
*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long int 

// vector<vector<ll>> graph;
// vector<ll> color;
// ll n,m;
// bool dfs(ll s){
// 	color[s]=1;
// 	for(ll x:graph[s]){
// 		if(color[x]==1)
// 			return true;
// 		if(color[x]==0 && dfs(x))
// 			return true;
// 	}
// 	color[s]=2;
// 	return false;
// }

// int main(){
// 	cin>>n>>m;
// 	graph.resize(n);color.assign(n,0);
// 	for(ll i=0;i<m;i++){
// 		ll u,v;cin>>u>>v;
// 		u--;v--;
// 		graph[u].push_back(v);
// 	}
// 	bool cycle = false;
// 	for(ll i=0;i<n;i++){
// 		if(order[i]==0){
// 			cycle=cycle|dfs(i);
// 		}
// 	}
// 	cout<<((cycle)?"has cycle\n":"cycle not found\n");
// }

/*
to detect cycle in undirected graph
*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long int 

// vector<vector<ll>> graph;
// vector<bool> vis;
// ll n,m;
// bool dfs(ll s,ll par){
// 	vis[s]=true;
// 	for(ll x:graph[s]){
// 		if(x==par)continue;
// 		if(vis[x])return true;
// 		if(!vis[x] && dfs(x,s))return true;
// 	}
// 	return false;
// }

// int main(){
// 	cin>>n>>m;
// 	graph.resize(n);vis.assign(n,false);
// 	for(ll i=0;i<m;i++){
// 		ll u,v;cin>>u>>v;
// 		u--;v--;
// 		graph[u].push_back(v);
// 		graph[v].push_back(u);
// 	}
// 	bool cycle = false;
// 	for(ll i=0;i<n;i++){
// 		if(!vis[i]){
// 			cycle=cycle|dfs(i,-1);
// 		}
// 	}
// 	cout<<((cycle)?"has cycle\n":"cycle not found\n");
// }
/*
to find the strongly connected components
in a directed graph
using kosaraju's algorithm
*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long int 

// vector<vector<ll>> graph,Tgraph;
// vector<ll> color,order;
// ll n,m;
// void dfs(ll s){
// 	color[s]=1;
// 	for(ll x:graph[s]){
// 		if(color[x]==0){
// 			dfs(x);
// 		}
// 	}
// 	order.push_back(s);
// 	color[s]=2;
// }
// void dfs_util(ll s){
// 	color[s]=1;
// 	// cout<<s+1<<" ";
// 	for(ll x:Tgraph[s]){
// 		if(color[x]==0)
// 			dfs_util(x);
// 	}
// 	color[s]=2;
// }

// void solve(){
// 	cin>>n;
// 	graph.clear();Tgraph.clear();
// 	graph.resize(n);Tgraph.resize(n);
// 	string data;
// 	for(ll i=0;i<n;i++){
// 		cin>>data;
// 		for(ll j=0;j<data.length();j++){
// 			if(data[j]=='Y'){
// 				graph[i].push_back(j);
// 				Tgraph[j].push_back(i);
// 			}
// 		}
// 	}
// 	color.clear();
// 	order.clear();
// 	color.assign(n,0);
// 	for(ll i=0;i<n;i++){
// 		if(color[i]==0){
// 			dfs(i);
// 		}
// 	}
// 	ll ans=0;
// 	reverse(order.begin(),order.end());
// 	fill(color.begin(),color.end(),0);
// 	//cout<<"the strongly connected components are\n";
// 	for(ll i=0;i<n;i++){
// 		ll s=order[i];
// 		if(color[s]==0){
// 			//cout<<"comp: ";
// 			dfs_util(s);
// 			ans++;
// 		}
// 	}
// 	cout<<ans<<"\n";
// }

// int main(){
// 	ll t;cin>>t;
// 	while(t--){
// 		solve();
// 	}
// 	return 0;
// }

/*
finding bridges in undirected graph
*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long int 

// vector<vector<ll>> graph;
// vector<ll> color,startTime,lowTime;
// set<pair<ll,ll>> bridge;
// ll n,m,TIME;
// void init(){
// 	graph.clear();graph.resize(n);
// 	color.clear();color.assign(n,0);
// 	startTime.clear();startTime.resize(n);
// 	lowTime.clear();lowTime.resize(n);
// 	bridge.clear();
// 	TIME=0;
// }
// void dfs(ll s,ll par){
// 	startTime[s]=lowTime[s]=TIME++;
// 	color[s]=1;
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
// 		cout<<"No bridge found\n";
// 	}else{
// 		cout<<bridge.size()<<"\n";
// 		for(auto x:bridge){
// 			cout<<x.first<<" "<<x.second<<"\n";
// 		}
// 	}
// }

// int main(){
// 	ll t;cin>>t;
// 	ll cases=1;
// 	while(t--){
// 		cout<<"Case #"<<cases<<"\n";
// 		solve();
// 		cases++;
// 	}
// }

//finding articulation point in a graph
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long int

// vector<vector<ll>> graph;
// vector<ll> color,startTime,lowTime;
// set<ll> cut;
// ll n,m,TIME;
// void init(){
// 	graph.clear();graph.resize(n);
// 	color.clear();color.assign(n,0);
// 	startTime.clear();startTime.resize(n);
// 	lowTime.clear();lowTime.resize(n);
// 	cut.clear();
// 	TIME=0;
// }
// void dfs(ll s,ll par=-1){
// 	color[s]=1;
// 	startTime[s]=lowTime[s]=TIME++;
// 	ll subtree=0;
// 	for(ll x:graph[s]){
// 		if(x==par)continue;
// 		if(color[x]==1){
// 			lowTime[s]=min(lowTime[s],startTime[x]);
// 		}else{
// 			dfs(x,s);
// 			if(par!=-1 && lowTime[x]>=startTime[s]){
// 				cut.insert(s);
// 			}
// 			lowTime[s]=min(lowTime[s],lowTime[x]);
// 			subtree++;
// 		}
// 	}
// 	if(par==-1 && subtree>1){
// 		cut.insert(s);
// 	}
// }

// void solve(){
// 	cin>>n>>m;
// 	if(n==0 && m==0)return;
// 	init();
// 	for(ll i=0;i<m;i++){
// 		ll u,v;cin>>u>>v;
// 		u--;v--;
// 		graph[u].push_back(v);
// 		graph[v].push_back(u);
// 	}
// 	for(ll i=0;i<n;i++){
// 		if(color[i]==0){
// 			dfs(i);
// 		}
// 	}
// 	cout<<cut.size()<<"\n";
// }

// int main(){
// 	while(true){
// 		solve();
// 		if(m==0 && n==0)break;
// 	}
// }

/*
BFS and it's applications
*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long int 
// const ll inf=1e18;
// vector<vector<ll>> graph;
// vector<ll> d,p;
// ll n,m;
// void bfs(ll s){
// 	d.assign(n,inf);
// 	p.assign(n,-1);
// 	vector<bool> vis(n,false);
// 	queue<ll> q;
// 	vis[s]=true;q.push(s);d[s]=0;
// 	while(!q.empty()){
// 		ll temp=q.front();q.pop();
// 		cout<<temp<<" ";
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
// void printPath(ll t){
// 	if(d[t]==inf){
// 		cout<<"No path\n";
// 	}else{
// 		vector<ll> path;
// 		while(t!=-1){
// 			path.push_back(t);
// 			t=p[t];
// 		}
// 		reverse(path.begin(),path.end());
// 		for(ll x:path){
// 			cout<<x<<" ";
// 		}cout<<"\n";
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
// 	cout<<"enter the source: ";
// 	ll s;cin>>s;s--;
// 	bfs(s);
// 	cout<<"enter the destination: ";
// 	ll t;cin>>t;t--;
// 	printPath(t);
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long int

// vector<vector<ll>> graph;
// vector<bool> vis;
// ll n,m;
// void bfs(ll s){
// 	vector<ll> d(n),p(n);
// 	vis.assign(n,false);
// 	queue<ll> q;
// 	q.push(s);vis[s]=true;
// 	d[s]=0;p[s]=-1;
// 	while(!q.empty()){
// 		ll temp=q.front();q.pop();
// 		for(ll x:graph[temp]){
// 			if(!vis[x]){
// 				vis[x]=true;
// 				p[x]=s;
// 				d[x]=d[temp]+1;
// 				q.push(x);
// 			}
// 		}
// 	}
// }
// void printPath(ll t){
// 	if(!vis[t]){
// 		cout<<"No path!\n";
// 	}else{
// 		vector<ll> path;
// 		while(t!=-1){
// 			path.push_back(t);
// 			t=p[t];
// 		}
// 		reverse(path.begin(),path.end());
// 		cout<<"path: ";
// 		for(ll x:path){
// 			cout<<x<<" ";
// 		}cout<<"\n";
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
// 	cout<<"enter the source: ";
// 	ll s;cin>>s;s--;
// 	bfs(s);
// 	cout<<"enter the destination: ";
// 	ll t;cin>>t;t--;
// 	printPath(t);
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long 

// int main(){
// 	ll n,k,d;cin>>n>>k>>d;
// 	set<ll> startion;
// 	for(ll i=0;i<k;i++){
// 		ll data;cin>>data;data--;
// 		startion.insert(data);
// 	}
// 	vector<vector<ll>> graph(n);
// 	map<pair<ll,ll>,ll> mp;
// 	for(ll i=0;i<n-1;i++){
// 		ll u,v;cin>>u>>v;
// 		u--;v--;
// 		mp[{min(u,v)+1,max(u,v)+1}]=i+1;
// 		graph[u].push_back(v);
// 		graph[v].push_back(u);
// 	}
// 	vector<bool> vis(n,false);
// 	set<pair<ll,ll>> ans;
// 	queue<pair<ll,ll>> q;
// 	vector<ll> p(n);
// 	for(ll u:startion){
// 		vis[u]=true;
// 		p[u]=-1;
// 		q.push({u,0});
// 	}
// 	while(!q.empty()){
// 		pair<ll,ll> temp=q.front();q.pop();
// 		// if(temp.second==d)continue;
// 		for(ll u:graph[temp.first]){
// 			if(!vis[u] && temp.second<d){
// 				p[u]=temp.first;
// 				q.push({u,temp.second+1});
// 				vis[u]=true;
// 			}else if(u!=p[temp.first]){
// 				ans.insert({min(u,temp.first)+1,max(u,temp.first)+1});
// 			}
// 		}
// 	}
// 	cout<<ans.size()<<"\n";
// 	for(auto i:ans){
// 		cout<<mp[i]<<" ";
// 	}cout<<"\n";
// }
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long int

// vector<vector<ll>> graph;
// vector<ll> color,startTime,endTime;
// ll n,m,TIME=0;
// void dfs(ll s){
// 	color[s]=1;
// 	startTime[s]=TIME++;
// 	for(ll x:graph[s]){
// 		if(color[x]==0){
// 			dfs(x);
// 		}
// 	}
// 	endTime[s]=TIME++;
// 	color[s]=2;
// }

// int main(){
// 	ll n,m;cin>>n>>m;
// 	graph.resize(n);
// 	for(ll i=0;i<m;i++){
// 		ll u,v;cin>>u>>v;
// 		u--;v--;
// 		graph[u].push_back(v);
// 		graph[v].push_back(u);
// 	}
// 	color.resize(n,0);
// 	startTime.resize(n);
// 	endTime.resize(n);
// 	for(ll i=0;i<n;i++){
// 		if(color[i]==0){
// 			dfs(i);
// 		}
// 	}
// }

/*
given a tree ( directed acyclic graph )
check wheather given node u is an ancestor of node j
solve it for q queries
*/

// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long int 

// vector<vector<ll>> tree;
// vector<ll> startTime,endTime;
// ll n,TIME=0;
// void dfs(ll s=0,ll p=-1){
// 	startTime[s]=TIME++;
// 	for(ll x:tree[s]){
// 		if(x==p)continue;
// 		dfs(x,s);
// 	}
// 	endTime[s]=TIME++;
// }

// int main(){
// 	ll n,q;cin>>n>>q;
// 	tree.resize(n);
// 	for(ll i=0;i<n-1;i++){
// 		ll u,v;cin>>u>>v;
// 		u--;v--;
// 		tree[u].push_back(v);
// 		tree[v].push_back(u);
// 	}
// 	startTime.resize(n);
// 	endTime.resize(n);
// 	dfs();
// 	while(q--){
// 		ll u,v;cin>>u>>v;
// 		u--;v--;
// 		for(ll i=0;i<n;i++){
// 			if(startTime[i]<=startTime[u] && endTime[i]>=endTime[u]
// 				&& startTime[i]<=startTime[v] && endTime[i]>=endTime[v]){
// 				cout<<i+1<<" ";
// 			}
// 		}
// 		cout<<endl;
// 	}
// }

// find the strongly connected components in 
// Directed graph

// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long int

// vector<vector<ll>> graph,Tgraph;
// vector<ll> topo,color;
// ll n,m;
// void dfs(ll s){
// 	color[s]=1;
// 	for(ll x:graph[s]){
// 		if(color[x]==0){
// 			dfs(x);
// 		}
// 	}
// 	topo.push_back(s);
// }
// void dfs_util(ll s){
// 	char ch='A'+s;
// 	cout<<ch<<" ";
// 	color[s]=1;
// 	for(ll x:Tgraph[s]){
// 		if(color[x]==0){
// 			dfs_util(x);
// 		}
// 	}
// }

// int main(){
// 	ll n,m;cin>>n>>m;
// 	graph.resize(n);Tgraph.resize(n);
// 	for(ll i=0;i<m;i++){
// 		ll u,v;cin>>u>>v;
// 		u--;v--;
// 		graph[u].push_back(v);
// 		Tgraph[v].push_back(u);
// 	}
// 	color.resize(n,0);
// 	for(ll i=0;i<n;i++){
// 		if(color[i]==0){
// 			dfs(i);
// 		}
// 	}
// 	reverse(topo.begin(),topo.end());
// 	cout<<"the strongly connected components are : "<<endl;
// 	fill(color.begin(),color.end(),0);
// 	for(ll i=0;i<n;i++){
// 		ll s=topo[i];
// 		if(color[s]==0){
// 			dfs_util(s);
// 			cout<<endl;
// 		}
// 	}
// }
// #include<bits/sdtc++.h>
// using namespace std;
// #define ll long long int

// vector<vector<ll>> graph;
// vector<ll> d,p,used;
// ll n,m;
// void bfs(ll s){
// 	d.resize(n,0);p.resize(n,-1);used.resize(n,0);
// 	queue<ll> q;
// 	q.push(s);
// 	used[s]=1;
// 	while(!q.empty()){
// 		ll temp=q.front();q.pop();
// 		for(ll x:graph[temp]){
// 			if(!used[x]){
// 				d[x]=d[temp]+1;
// 				used[x]=1;
// 				p[x]=temp;
// 				q.push(x);
// 			}
// 		}
// 	}
// }
// void printPath(ll t){
// 	if(!used[t]){
// 		cout<<"No path!!\n";
// 	}
// 	else{
// 		vector<ll> path;
// 		for(ll i=t;i!=-1;i=p[i]){
// 			path.push_back(i);
// 		}
// 		reverse(path.begin(),path.end());
// 		cout<<"Path: ";
// 		for(ll x:path){
// 			cout<<x<<" ";
// 		}
// 		cout<<endl;
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
// 	cout<<"source: ";
// 	ll s;cin>>s;s--;
// 	bfs(s);
// 	cout<<"destination: ";
// 	ll t;cin>>t;t--;
// 	printPath(t);
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long int

// int main(){
// 	ll t;cin>>t;
// 	while(t--){
// 		ll n,m;cin>>n>>m;
// 		vector<vector<char>> grid(n,vector<char>(m));
// 		for(ll i=0;i<n;i++){
// 			for(ll j=0;j<m;j++){
// 				cin>>grid[i][j];
// 			}
// 		} 
// 		vector<int> di={0,0,-1,1},dj={-1,1,0,0};
// 		vector<vector<bool>> vis(n,vector<bool>(m,false));
// 		vector<vector<ll>> d(n,vector<ll>(m,LLONG_MAX));
// 		deque<pair<ll,ll>> q;
// 		q.push_front({0,0});
// 		d[0][0]=0;
// 		vis[0][0]=true;
// 		while(!q.empty()){
// 			pair<ll,ll> temp=q.front();q.pop_front();
// 			ll i=temp.first,j=temp.second;
// 			for(ll d1=0;d1<4;d1++){
// 				ll r=di[d1]+i,c=dj[d1]+j;
// 				if((r>=0 && r<n && c>=0 && c<m)){
// 					if(grid[i][j]==grid[r][c]){
// 						if(d[r][c]>d[i][j]){
// 							d[r][c]=d[i][j];
// 							q.push_front({r,c});
// 						}
// 					}else{
// 						if(d[r][c]>1+d[i][j]){
// 							d[r][c]=1+d[i][j];
// 							q.push_back({r,c});
// 						}
// 					}
// 				}
// 			}
// 		}
// 		cout<<d[n-1][m-1]<<"\n";
// 	}
// }
/*
queries to check whether edge(u,v) lies
on the shortest path from a to b
*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long int
// void bfs(ll s,vector<vector<ll>> &graph,vector<ll> &d,ll &n){
// 	vector<bool> vis(n,false);
// 	d[s]=0;vis[s]=true;
// 	queue<ll> q;q.push(s);
// 	while(!q.empty()){
// 		ll temp=q.front();q.pop();
// 		for(ll x:graph[temp]){
// 			if(!vis[x]){
// 				vis[x]=true;
// 				d[x]=d[temp]+1;
// 				q.push(x);
// 			}
// 		}
// 	}
// }

// int main(){
// 	ll t;cin>>t;
// 	while(t--){
// 		ll n,m;cin>>n>>m;
// 		ll a,b;cin>>a>>b;a--;b--;
// 		vector<vector<ll>> graph(n);
// 		for(ll i=0;i<m;i++){
// 			ll u,v;cin>>u>>v;
// 			u--;v--;
// 			graph[u].push_back(v);
// 			graph[v].push_back(u);
// 		}
// 		vector<ll> da(n,LLONG_MAX),db(n,LLONG_MAX);
// 		bfs(a,graph,da,n);
// 		bfs(b,graph,db,n);
// 		ll q;cin>>q;
// 		while(q--){
// 			ll u,v;cin>>u>>v;
// 			u--;v--;
// 			if(da[u]!=LLONG_MAX && db[v]!=LLONG_MAX && (da[u]+1+db[v])==da[b]){
// 				cout<<"Yes\n";
// 			}else{
// 				cout<<"No\n";
// 			}
// 		}
// 	}
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long int
// vector<vector<ll>> graph;
// vector<pair<ll,ll>> bridge;
// vector<ll> color,startTime,lowTime;
// ll TIME;
// void dfs(ll s,ll p=-1){
// 	color[s]=1;
// 	lowTime[s]=startTime[s]=TIME++;
// 	for(ll x:graph[s]){
// 		if(x==p)continue;
// 		if(color[x]==1){
// 			lowTime[s]=min(lowTime[s],startTime[x]);
// 		}else{
// 			dfs(x,s);
// 			if(lowTime[x]>startTime[s]){
// 				bridge.push_back({min(s+1,x+1),max(s+1,x+1)});
// 			}
// 			lowTime[s]=min(lowTime[s],lowTime[x]);
// 		}
// 	}
// }

// void solve(){
// 	ll n,m;cin>>n>>m;
// 	graph.clear();graph.resize(n);
// 	for(ll i=0;i<m;i++){
// 		ll u,v;cin>>u>>v;
// 		u--;v--;
// 		graph[u].push_back(v);
// 		graph[v].push_back(u);
// 	}
// 	color.clear();color.resize(n,0);
// 	startTime.clear();startTime.resize(n);
// 	lowTime.clear();lowTime.resize(n);
// 	bridge.clear();
// 	TIME=0;
// 	dfs(0);
// 	if(bridge.size()==0){
// 		cout<<"Sin bloqueos\n";
// 	}else{
// 		cout<<bridge.size()<<"\n";
// 		sort(bridge.begin(),bridge.end());
// 		for(pair<ll,ll> x:bridge){
// 			cout<<x.first<<" "<<x.second<<"\n";
// 		}
// 	}
// }

// int main(){
// 	ll t;cin>>t;
// 	for(ll i=1;i<=t;i++){
// 		cout<<"Caso #"<<i<<"\n";
// 		solve();
// 	}
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long int 
// vector<vector<ll>> graph;
// vector<ll> color,startTime,lowTime;
// set<ll> cut;
// ll n,m,Time;
// void dfs(ll s,ll p=-1){
// 	color[s]=1;
// 	startTime[s]=lowTime[s]=Time++;
// 	ll comp=0;
// 	for(ll x:graph[s]){
// 		if(x==p)continue;
// 		if(color[x]==1){
// 			lowTime[s]=min(lowTime[s],startTime[x]);
// 		}else{
// 			dfs(x,s);
// 			if(p!=-1 && lowTime[x]>=startTime[s]){
// 				cut.insert(s);
// 			}
// 			lowTime[s]=min(lowTime[s],lowTime[x]);
// 			comp++;
// 		}
// 	}
// 	if(p==-1 && comp>1){
// 		cut.insert(s);
// 	}
// }

// void solve(){
// 	graph.clear();graph.resize(n);
// 	for(ll i=0;i<m;i++){
// 		ll u,v;cin>>u>>v;
// 		u--;v--;
// 		graph[u].push_back(v);
// 		graph[v].push_back(u);
// 	}
// 	color.clear();color.resize(n,0);
// 	startTime.clear();startTime.resize(n);
// 	lowTime.clear();lowTime.resize(n);
// 	cut.clear();Time=0;
// 	for(ll i=0;i<n;i++){
// 		if(color[i]==0){
// 			dfs(i);
// 		}
// 	}
// 	cout<<cut.size()<<"\n";
// }

// int main(){
// 	while(true){
// 		cin>>n>>m;
// 		if(n==0 && m==0)break;
// 		solve();
// 	}
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long int 
// vector<vector<ll>> graph,Tgraph;
// vector<ll> color,topo;
// ll n,m;
// void dfs(ll s){
// 	color[s]=1;
// 	for(ll x:graph[s]){
// 		if(color[x]==0){
// 			dfs(x);
// 		}
// 	}
// 	topo.push_back(s);
// }
// void dfs_util(ll s){
// 	color[s]=1;
// 	for(ll x:Tgraph[s]){
// 		if(color[x]==0){
// 			dfs_util(x);
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
// 		Tgraph[v].push_back(u);
// 	}
// 	color.resize(n,0);
// 	for(ll i=0;i<n;i++){
// 		if(color[i]==0){
// 			dfs(i);
// 		}
// 	}
// 	reverse(topo.begin(),topo.end());
// 	fill(color.begin(),color.end(),0);
// 	for(ll i=0;i<n;i++){
// 		ll s=topo[i];
// 		if(color[s]==0){
// 			dfs_util(s);
// 		}
// 	}
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long int 
// vector<vector<ll>> g,tg;
// vector<ll> topo,color;
// ll n;
// void dfs(ll s){
// 	color[s]=1;
// 	for(ll x:g[s]){
// 		if(color[x]==0){
// 			dfs(x);
// 		}
// 	}
// 	topo.push_back(s);
// }
// void dfs_util(ll s){
// 	color[s]=1;
// 	for(ll x:tg[s]){
// 		if(color[x]==0){
// 			dfs_util(x);
// 		}
// 	}
// }
// int main(){
// 	ll t;cin>>t;
// 	while(t--){
// 		cin>>n;char x;
// 		g.clear();g.resize(n);
// 		tg.clear();tg.resize(n);
// 		for(ll i=0;i<n;i++){
// 			for(ll j=0;j<n;j++){
// 				cin>>x;
// 				if(x=='Y'){
// 					g[i].push_back(j);
// 					tg[j].push_back(i);
// 				}
// 			}
// 		}
// 		topo.clear();
// 		color.clear();color.resize(n,0);
// 		for(ll i=0;i<n;i++){
// 			if(color[i]==0){
// 				dfs(i);
// 			}
// 		}
// 		ll ans=0;
// 		reverse(topo.begin(),topo.end());
// 		fill(color.begin(),color.end(),0);
// 		for(ll i=0;i<n;i++){
// 			ll s=topo[i];
// 			if(color[s]==0){
// 				ans++;
// 				dfs_util(s);
// 			}
// 		}
// 		cout<<ans<<endl;
// 	}
// }

// Dijkstra on dense graph
// O(n^2+m)
// directed weighted graph with non negative edge weight
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long int 
// #define pll pair<ll,ll>
// const ll inf=1e18;
// vector<vector<pll>> g;
// vector<ll> d,p;
// ll n,m;
// void Dijkstra(ll s){
// 	d.resize(n,inf);p.resize(n,-1);
// 	vector<bool> vis(n,false);
// 	d[s]=0;
// 	for(ll i=0;i<n;i++){
// 		ll mx=inf,u;
// 		for(ll j=0;j<n;j++){
// 			if(!vis[j] && d[j]<mx){
// 				mx=d[j];u=j;
// 			}
// 		}
// 		if(d[u]==inf)break;
// 		vis[u]=true;
// 		for(pll x:g[u]){
// 			if(d[x.first]>d[u]+x.second){
// 				p[x.first]=u;
// 				d[x.first]=d[u]+x.second;
// 			}
// 		}
// 	}
// }
// int main(){
// 	n,m;cin>>n>>m;
// 	for(ll i=0;i<m;i++){
// 		ll u,v,w;cin>>u>>v>>w;
// 		u--;v--;
// 		g[u].push_back({v,w});
// 	}
// 	cout<<"enter a source vertex: ";
// 	ll s;cin>>s;s--;
// 	Dijkstra(s);
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long int
// const ll inf=1e18;
// vector<vector<pair<ll,ll>>> graph;
// ll n,m;
// void Dijkstra(ll s,vector<ll> &d,vector<ll> &p){
// 	vector<bool> vis(n,false);
// 	d[s]=0;
// 	set<pair<ll,ll>> q;q.insert({d[s],s});
// 	while(!q.empty()){
// 		ll u=q.begin()->second;
// 		q.erase(q.begin());
// 		for(pair<ll,ll> x:graph[u]){
// 			ll v=x.first,w=x.second;
// 			if(d[v]>d[u]+w){
// 				q.erase({d[v],v});
// 				d[v]=d[u]+w;
// 				p[v]=u;
// 				q.insert({d[v],v});
// 			}
// 		}
// 	}
// }
// void printPath(ll d,vector<ll> &p){
// 	vector<ll> path;
// 	for(ll x=d;x!=-1;x=p[x]){
// 		path.push_back(x);
// 	}
// 	reverse(path.begin(),path.end());
// 	for(ll x:path){
// 		cout<<x+1<<" ";
// 	}cout<<endl;
// }
// int main(){
// 	cin>>n>>m;
// 	graph.resize(n);
// 	for(ll i=0;i<m;i++){
// 		ll u,v,w;cin>>u>>v>>w;
// 		u--;v--;
// 		graph[u].push_back({v,w});
// 		graph[v].push_back({u,w});
// 	}
// 	ll s=0;
// 	vector<ll> d(n,inf),p(n,-1);
// 	Dijkstra(s,d,p);
// 	ll t=n-1;
// 	if(d[t]!=inf)printPath(t,p);
// 	else cout<<"-1"<<endl;
// }

// void dijju1(ll s,vector<ll> &d,vector<ll> &p){
// 	d.assign(n,inf);
// 	p.assign(n,-1);
// 	d[s]=0;
// 	vector<bool> vis(n,false);
// 	for(ll t=0;t<n;t++){
// 		ll u=-1;
// 		for(ll i=0;i<n;i++){
// 			if(!vis[i] && (u==-1 || d[i]<d[u])){
// 				u=i;
// 			}
// 		}
// 		if(d[u]==inf)break;
// 		vis[u]=true;
// 		for(auto x:graph[u]){
// 			ll v=x.first,w=x.second;
// 			if(d[v]>d[u]+w){
// 				d[v]=d[u]+w;
// 				p[v]=u;
// 			}
// 		}
// 	}
// }

// void dijju2(ll s,vector<ll> &d,vector<ll> &p){
// 	d.assign(n,inf);
// 	p.assign(n,-1);
// 	d[s]=0;
// 	set<pair<ll,ll>> q;
// 	q.insert({d[s],s});
// 	while(!q.empty()){
// 		ll u=q.begin()->second;
// 		q.erase(q.begin());
// 		for(auto x:graph[u]){
// 			ll v=x.first,w=x.second;
// 			if(d[v]>d[u]+w){
// 				q.erase({d[v],v});
// 				d[v]=d[u]+w;
// 				p[v]=u;
// 				q.insert({d[v],v});
// 			}
// 		}
// 	}
// }

// void dijju3(ll s,vector<ll> &d,vector<ll> &p){
// 	d.assign(n,inf);
// 	p.assign(n,-1);
// 	using pll=pair<ll,ll>;
// 	priority_queue<pll,vector<pll>,greater<pll>> q;
// 	d[s]=0;q.push({d[s],s});
// 	while(!q.empty()){
// 		pll temp=q.top();q.pop();
// 		ll u=temp.second,du=temp.first;
// 		if(du!=d[u])continue;
// 		for(pll x:graph[u]){
// 			ll v=x.first,w=x.second;
// 			if(d[v]>d[u]+w){
// 				d[v]=d[u]+w;
// 				p[v]=u;
// 				q.push({d[v],v});
// 			}
// 		}
// 	}
// }
// void printpath(ll d,vector<ll> &p){
// 	vector<ll> path;
// 	for(ll x=d;x!=-1;x=p[x])path.push_back(x);
// 	reverse(path.begin(),path.end());
// 	for(ll x:path)cout<<x+1<<" ";
// 	cout<<endl;
// }

// void dijju1(ll s,vector<ll> &d,vector<ll> &p){
// 	d.assign(n,inf);
// 	p.assign(n,-1);
// 	d[s]=0;
// 	vector<bool> vis(n,false);
// 	for(int t=0;t<n;t++){
// 		ll u=-1;
// 		for(ll i=0;i<n;i++){
// 			if(!vis[i] && (u==-1 || d[i]<d[u])){
// 				u=i;
// 			}
// 		}
// 		if(d[u]==inf)break;
// 		vis[u]=true;
// 		for(pll x:graph[u]){
// 			ll v=x.first,w=x.second;
// 			if(d[v]>d[u]+w){
// 				p[v]=u;
// 				d[v]=d[u]+w;
// 			}
// 		}
// 	}
// }

// void dijju2(ll s,vector<ll> &d,vector<ll> &p){
// 	d.assign(n,inf);
// 	p.assign(n,-1);
// 	d[s]=0;
// 	using pll=pair<ll,ll>;
// 	set<pll> q;
// 	q.insert({d[s],s});
// 	while(!q.empty()){
// 		ll u=q.begin()->second;
// 		q.erase(q.begin());
// 		for(pll x:graph[u]){
// 			ll v=x.first,w=x.second;
// 			if(d[v]>d[u]+w){
// 				q.erase({d[v],v});
// 				d[v]=d[u]+w;
// 				p[v]=u;
// 				q.insert({d[v],v});
// 			}
// 		}
// 	}
// }

// void dijju3(ll s,vector<ll> &d,vector<ll> &p){
// 	d.assign(n,inf);
// 	p.assign(n,-1);
// 	using pll=pair<ll,ll>;
// 	priority_queue<pll,vector<pll>,greater<pll>> q;
// 	d[s]=0;q.push({d[s],s});
// 	while(!q.empty()){
// 		pll temp=q.top();q.pop();
// 		ll u=temp.second,du=temp.first;
// 		if(du!=d[u])continue;
// 		for(pll x:graph[u]){
// 			ll v=x.first,w=x.second;
// 			if(d[v]>d[u]+w){
// 				d[v]=d[u]+w;
// 				p[v]=u;
// 				q.push({d[v],v});
// 			}
// 		}
// 	}
// }

// voh sab algo graph with non negative edge weight
// pe kam karte hai

// bellman ford assuming no negative cycle

// void bellman(ll s,vector<ll> &d,vector<ll> &p,vector<edge> &a){
// 	d.assign(n,inf);
// 	p.assign(n,-1);
// 	d[s]=0;
// 	while(true){
// 		bool any=false;
// 		for(ll i=0;i<a.size();i++){
// 			if(d[a[i].u]<inf){
// 				if(d[a[i].v]>d[a[i].u]+a[i].w){
// 					d[a[i].v]=d[a[i].u]+a[i].w;
// 					p[a[i].v]=a[i].u;
// 					any=true;
// 				}
// 			}
// 		}
// 		if(!any)break;
// 	}
// 	if(d[t]==inf){
// 		cout<<"No path!!"<<endl;
// 	}else{
// 		vector<ll> path;
// 		for(ll x=t;x!=-1;x=p[x]){
// 			path.push_back(x);
// 		}
// 		cout<<"shortest path is: ";
// 		for(ll i=path.size()-1;i>=0;i--){
// 			cout<<path[i]+1<<" ";
// 		}
// 		cout<<endl;
// 	}
// }

// void dijju1(ll s,vector<ll> &d,vector<ll> &p){
// 	d.assign(n,inf);
// 	p.assign(n,-1);
// 	vector<bool> vis(n,false);
// 	d[s]=0;
// 	for(ll t=0;t<n;t++){
// 		ll u=-1;
// 		for(ll i=0;i<n;i++){
// 			if(!vis[i] && (u==-1||d[i]<d[u]))u=i;
// 		}
// 		if(d[u]==inf)break;
// 		vis[u]=true;
// 		for(auto x:graph[u]){
// 			ll v=x.first,w=x.second;
// 			if(d[v]>d[u]+w){
// 				d[v]=d[u]+w;
// 				p[v]=u;
// 			}
// 		}
// 	}
// }

// void dijju2(ll s,vector<ll> &d,vector<ll> &p){
// 	d.assign(n,inf);
// 	p.assign(n,-1);
// 	d[s]=0;
// 	using pll=pair<ll,ll>;
// 	set<pll> q;
// 	q.insert({d[s],s});
// 	while(!q.empty()){
// 		ll u=q.begin()->second;
// 		q.erase(q.begin());
// 		for(pll x:graph[u]){
// 			ll v=x.first,w=x.second;
// 			if(d[v]>d[u]+w){
// 				q.erase({d[v],v});
// 				d[v]=d[u]+w;
// 				p[v]=u;
// 				q.insert({d[v],v});
// 			}
// 		}
// 	}
// }

// void dijju3(ll s,vector<ll> &d,vector<ll> &p){
// 	d.assign(n,inf);
// 	p.assign(n,-1);
// 	d[s]=0;
// 	using pll=pair<ll,ll>;
// 	priority_queue<pll,vector<pll>,greater<pll>> q;
// 	q.push({d[s],s});
// 	while(!q.empty()){
// 		pll temp=q.top();q.pop();
// 		ll u=temp.second,du=temp.first;
// 		if(du!=d[u])continue;
// 		for(pll x:graph[u]){
// 			ll v=x.first,w=x.second;
// 			if(d[v]>d[u]+w){
// 				d[v]=d[u]+w;
// 				p[v]=u;
// 				q.push({d[v],v});
// 			}
// 		}
// 	}
// }

// void printPath(ll d,vector<ll> &p){
// 	vector<ll> path;
// 	for(ll x=d;x!=-1;x=p[x])path.push_back(x);
// 	reverse(path.begin(),path.end());
// 	for(ll x:path)cout<<x+1<<" ";
// 	cout<<endl;
// }


// bellman ford assuming no negative edge weight
// void bellman(ll s,vector<ll> &d,vector<ll> &p,vector<edge> &a){
// 	d.assign(n,inf);
// 	p.assign(n,-1);
// 	d[s]=0;
// 	while(true){
// 		bool any=false;
// 		for(ll i=0;i<a.size();i++){
// 			if(d[a[i].u]<inf){
// 				if(d[a[i].v]>d[a[i].u]+a[i].w){
// 					d[a[i].v]=d[a[i].u]+a[i].w;
// 					p[a[i].v]=a[i].u;
// 					any=true;
// 				}
// 			}
// 		}
// 		if(!any)break;
// 	}
// 	if(d[t]==inf){
// 		cout<<"Not reachable form "<<s+1<<endl;
// 	}else{
// 		printPath(t,p);
// 	}
// }
// bellman ford with negative cycle 
void bellman(ll s,vector<ll> &d,vector<ll> &p,vector<edge> &a){
	d.assign(n,inf);
	p.assign(n,-1);
	d[s]=0;
	ll x;
	for(ll i=0;i<n;i++){
		x=-1;
		for(ll j=0;j<a.size();j++){
			if(d[a[j].u]<inf){
				if(d[a[j].v]>d[a[j].u]+a[j].w){
					d[a[j].v]=d[a[j].u]+a[j].w;
					p[a[j].v]=a[j].u;
					x=a[j].v;
				}
			}
		}
	}
	if(x==-1){
		cout<<"there is no negative cycle reachable from "<<s+1<<endl;
	}else{
		ll y=x;
		for(ll i=0;i<n;i++)y=p[y];
		vector<ll> cycle;
		for(ll curr=y;;curr=p[curr]){
			cycle.push_back(curr);
			if(curr==y && cycle.size()>1)break;
		}
		cout<<"negative cycle is: ";
		for(ll x:cycle)cout<<x+1<<" ";
		cout<<endl;
	}
}
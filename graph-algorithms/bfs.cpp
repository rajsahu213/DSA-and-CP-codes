/*
1)
implement bfs for 
1)undirected unweighted graphs
2)undirected weighted graphs
3)directed unweighted graphs
4)directed weighted graphs
*/
/*
applictions of dfs
1)print the shortest path for given two vertices
in an undirected graph
2)finding the shortest cycle in unweighted graphs
3)Find all the edges that lie on any shortest 
path between a given pair of vertices (a,b).
4)Find all the vertices on any shortest
 path between a given pair of vertices (a,b)
5)Find the shortest path of even length from a
source vertex s to a target vertex t in 
an unweighted graph:
*/
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

// void BFS(ll s){
// 	queue<ll> q;
// 	q.push(s);
// 	p[s]=-1;d[s]=0;vis[s]=true;
// 	while(!q.empty()){
// 		ll u=q.front();q.pop();
// 		char ch=u+'a';
// 		cout<<ch<<" ";
// 		for(ll v:graph[u]){
// 			if(!vis[v]){
// 				d[v]=d[u]+1;
// 				vis[v]=true;
// 				p[v]=u;
// 				q.push(v);
// 			}
// 		}
// 	}
// 	cout<<endl;
// }

// void printPath(ll t){
// 	if(!vis[t]){
// 		cout<<"no path!\n";
// 	}else{
// 		vl path;
// 		while(p[t]!=-1){
// 			path.push_back(t);
// 			t=p[t];
// 		}path.push_back(t);
// 		reverse(path.begin(),path.end());
// 		for(ll x:path){
// 			char ch=x+'a';
// 			cout<<ch<<" ";
// 		}
// 		cout<<endl;
// 	}
// }

// int main(){
// 	cin>>n;
// 	cin>>e;
// 	graph.resize(n);
// 	d.resize(n,inf),p.resize(n,-2);
// 	vis.resize(n,false);	
// 	for(ll i=0;i<e;i++){
// 		ll u,v;cin>>u>>v;
// 		u--;v--;
// 		graph[u].push_back(v);
// 		graph[v].push_back(u);
// 	}
// 	cout<<"enter the starting vertex: ";
// 	ll s;cin>>s;s--;
// 	BFS(s);
// 	cout<<"enter the second vertex: ";
// 	ll t;cin>>t;t--;
// 	printPath(t);
// }

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pll pair<ll,ll>
#define vl vector<ll>
#define vvl vector<vl>
#define vpll vector<pll>
#define vvpll vector<vpll>
const ll inf=1e18;

vvpll graph;
vl d,p;
vector<bool> vis;
ll n,e,s,t;
void dijju(){
	ll v,w;
	vis.resize(n,false),d.resize(n,inf);
	p.resize(n);
	priority_queue<pll,vpll,greater<pll>> q;
	q.push({0,s});d[s]=0;p[s]=-1;
	vis[s]=true;
	while(!q.empty()){
		pll temp=q.top();q.pop();
		ll du=temp.first,u=temp.second;
		for(pll x:graph[u]){
			v=x.first;w=x.second;
			if(d[v]>d[u]+w){
				d[v]=d[u]+w;
				p[v]=u;
			}
			if(!vis[v]){
				vis[v]=true;
				q.push({d[v],v});
			}
		}
	}
}

void printPath(){
	if(!vis[t]){
		cout<<"no path!\n";
		return;
	}
	vl path;
	while(t!=-1){
		path.push_back(t+1);
		t=p[t];
	}
	reverse(path.begin(), path.end());
	for(ll x:path){
		cout<<x<<" ";
	}
	cout<<endl;
}

int main(){
	cin>>n;
	cin>>e;
	graph.resize(n);
	for(ll i=0;i<e;i++){
		ll u,v,w;cin>>u>>v>>w;
		u--;v--;
		graph[u].push_back({v,w});
	}
	cout<<"enter the source: ";
	cin>>s;s--;
	// cout<<"enter the destination: ";
	// cin>>t;t--;
	dijju();
	// printPath();
	for(ll i=0;i<n;i++){
		cout<<d[i]<<" ";
	}
	cout<<endl;
}
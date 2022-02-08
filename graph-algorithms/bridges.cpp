// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long int
// vector<vector<ll>> graph;
// vector<ll> color,startTime,lowTime;
// set<pair<ll,ll>> bridge;
// ll n,m,TIME;
// void init(){
// 	graph.clear();graph.resize(n);
// 	color.clear(),color.assign(n,0);
// 	startTime.clear(),startTime.resize(n);
// 	lowTime.clear(),lowTime.resize(n);
// 	bridge.clear();
// 	TIME=0;
// }
// void dfs(ll &s,ll par){
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
// 		cout<<"No bridges found!!\n";
// 	}else{
// 		cout<<bridge.size()<<"\n";
// 		for(auto i:bridge){
// 			cout<<i.first<<" "<<i.second<<"\n";
// 		}
// 	}
// }

// int main(){
// 	ll t;cin>>t;
// 	for(ll i=1;i<=t;i++){
// 		solve();
// 	}
// }

class Solution {
public:
    vector<vector<int>> graph,bridge;
    vector<int> startTime,lowTime,color;
    int Time;
    void dfs(int s,int p=-1){
        color[s]=1;
        startTime[s]=lowTime[s]=Time++;
        for(int x:graph[s]){
            if(x==p)continue;
            if(color[x]==1){
                lowTime[s]=min(lowTime[s],startTime[x]);
            }else{
                dfs(x,s);
                if(lowTime[x]>startTime[s]){
                    bridge.push_back({s,x});
                }
                lowTime[s]=min(lowTime[s],lowTime[x]);
            }
        }
    }    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& edge) {
        graph.clear();graph.resize(n);
        for(int i=0;i<edge.size();i++){
            graph[edge[i][0]].push_back(edge[i][1]);
            graph[edge[i][1]].push_back(edge[i][0]);
        }
        color.clear();color.resize(n,0);
        startTime.clear();startTime.resize(n);
        lowTime.clear();lowTime.resize(n);
        Time=0;bridge.clear();
        dfs(0);
        return bridge;
    }
};
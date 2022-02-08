#include<bits/stdc++.h>
using namespace std;

struct weight
{
    int data;
    int wei;
};

typedef vector<weight> graph;

void print_adjlist_wei(vector<weight> adj_list[],int v)
{
    cout<<"the adjacency list is\n";
    for(int i=0;i<v;i++)
    {
        cout<<i;
        for(int j=0;j<adj_list[i].size();j++)
        {
            cout<<"-> "<<adj_list[i][j].data<<" "<<adj_list[i][j].wei;
        }
        cout<<endl;
    }
}

void adjlist_dir_weight(int e,int v,vector<weight> adj_list[])
{
    for(int i=0;i<v;i++)
    {
        // cout<<"enter the adjacent vertex of "<<i<<" and its weight( -1 to stop )\n";
        while(1)
        {
            struct weight a;
            cin>>a.data>>a.wei;
            if(a.data==-1)break;
            adj_list[i].push_back(a);
            int temp=a.data;a.data=i;
            adj_list[temp].push_back(a);
        }
    }
}

int index(graph v[],int d,int n)
{
  for(int i=0;i<v[d].size();i++)
  {
    if(v[d][i].data==n)return i;
  }
}

void shortest_path(int s,int d,vector<weight> adj[], bool vis[],int dis[],int N,int &flag)
{
    if(flag==2)return;
    queue<int> q;
    q.push(s);
    int prev[N];
    for(int i=0;i<N;i++)vis[i]=false;
    for(int i=0;i<N;i++)dis[i]=INT_MAX;
    dis[s]=0;
    while(!q.empty())
    {
        int t1=q.front();
        q.pop();
        if(vis[t1]==false)
        {
        	for(int i=0;i<adj[t1].size();i++)
        	{
        		if(dis[t1]+adj[t1][i].wei<dis[adj[t1][i].data])
        		{
        			dis[adj[t1][i].data]=dis[t1]+adj[t1][i].wei;
        			prev[adj[t1][i].data]=t1;
        		}
        	}
        	vis[t1]=true;
            for(int i=0;i<adj[t1].size();i++)
        	{
            	if(!vis[adj[t1][i].data])q.push(adj[t1][i].data);
        	}
        }
    }
    int s1=s,d1=d;
    while(1)
    {
    	cout<<d<<" ";
      if(flag==0){
      int i=index(adj,d,prev[d]);
      adj[d].erase(adj[d].begin()+i);}
    	d=prev[d];
    	if(d==s)break;
    }
    cout<<s<<endl;
    shortest_path(d1,s1,adj,vis,dis,N,++flag);
}

int main()
{
  cout<<"enter v: ";
  int v;cin>>v;
  graph adj_list[v];
  cout<<"enter e: ";
  int e;cin>>e;
  adjlist_dir_weight(e,v,adj_list);
  print_adjlist_wei(adj_list,v);
  bool vis[v];
  int dis[v],prev[v];
  cout<<"enter the starting index: ";
  int s;cin>>s;
  cout<<"enter the destination index: ";
  int d;cin>>d;
  cout<<"the shortest path in reverse order is\n";int i=0;
  shortest_path(s,d,adj_list,vis,dis,v,i);
  print_adjlist_wei(adj_list,v);
}

// 1 2 2 4 3 1 -1 -1
// 3 3 4 10 -1 -1
// 3 2 5 5 -1 -1
// 4 2 5 8 6 4 -1 -1
// 6 6 -1 -1
// 6 1 -1 -1
// -1 -1
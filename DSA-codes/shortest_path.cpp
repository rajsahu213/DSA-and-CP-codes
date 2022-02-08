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
        }
    }
}

void shortest_path(int s,int d,vector<weight> adj[], bool vis[],int dis[],int prev[],int N)
{
    queue<int> q;
    q.push(s);
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
    int temp=d;
    int a[N],j=0;
    while(1)
    {
    	 a[j++]=d;
    	 int k=d;
	     d=prev[d];
	     if(d==s)break;
    }
    a[j++]=s;
    for(int k=j-1;k>=0;k--)
    {
    	cout<<a[k]<<" ";
    }
    cout<<endl;
    cout<<"the shortest distance is: "<<dis[temp]<<endl;
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
  int dis[v],prev[v];
  cout<<"enter the starting index: ";
  int s;cin>>s;
  cout<<"enter the destination index: ";
  int d;cin>>d;
  cout<<"the shortest path is\n";
  bool vis[v]={false};
  shortest_path(s,d,adj_list,vis,dis,prev,v);
}

// 1 2 2 4 3 1 -1 -1
// 0 2 3 3 4 10 -1 -1
// 0 4 3 2 5 5 -1 -1
// 0 1 1 3 2 2 4 2 5 8 6 4 -1 -1
// 1 10 3 7 6 6 -1 -1
// 2 5 3 8 6 1 -1 -1 
// 3 4 4 6 5 1 -1 -1
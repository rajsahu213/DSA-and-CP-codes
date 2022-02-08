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

void adjlist_undir_weight(int e,int v,vector<weight> adj_list[])
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
            struct weight b;
            b.data=i;b.wei=a.wei;
            adj_list[a.data].push_back(b);
        }
    }
}

void shortest_path(int s,vector<weight> adj[], bool vis[],int dis[],int prev[],int N)
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
        	vis[t1]=true;
          for(int i=0;i<adj[t1].size();i++)
        	{
              if(dis[t1]+adj[t1][i].wei<dis[adj[t1][i].data])
              {
                dis[adj[t1][i].data]=dis[t1]+adj[t1][i].wei;
                prev[adj[t1][i].data]=t1;
              }        
            	if(!vis[adj[t1][i].data])q.push(adj[t1][i].data);
        	}
        }
    }
    for(int i=1;i<N;i++)
    {
        int a[N],j=0;
        int d=i;
        while(1)
        {
        	 a[j++]=d;
    	     d=prev[d];
    	     if(d==s)break;
        }
        a[j++]=s;
        for(int k=j-1;k>=0;k--)cout<<a[k]<<" ";
        cout<<endl;
    }
}



int main()
{
  cout<<"enter v: ";
  int v;cin>>v;
  graph adj_list[v];
  cout<<"enter e: ";
  int e;cin>>e;
  adjlist_undir_weight(e,v,adj_list);
  print_adjlist_wei(adj_list,v);
  bool vis[v];
  int dis[v],prev[v];
  cout<<"enter the starting index: ";
  int s;cin>>s;
  cout<<"the shortest path is\n";
  shortest_path(s,adj_list,vis,dis,prev,v);
}

// 1 10 4 10 5 15 -1 -1
// 2 10 3 15 -1 -1
// 4 10 -1 -1
// 4 15 -1 -1
// 6 10 7 10 -1 -1
// 6 10 7 10 -1 -1
// -1 -1
// -1 -1
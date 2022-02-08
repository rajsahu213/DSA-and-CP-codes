#include<bits/stdc++.h>
using namespace std;
struct ver
{
  int dis;
  int data;
};

void bfs(int s, vector<int> adj[], bool vis[], int N)
{
    queue<int> q;
    q.push(s);
    for(int i=0;i<N;i++)vis[i]=false;
    while(!q.empty())
    {
        int t1=q.front();
        q.pop();
        if(!vis[t1])cout<<t1<<" ";
        vis[t1]=true;
        for(int i=0;i<adj[t1].size();i++)
        {
            if(!vis[adj[t1][i]])q.push(adj[t1][i]);
        }
    }
    cout<<endl;
}

void diju(int s,int d,vector<ver> adj[], bool vis[],int dis[],int prev[],int N)
{
    int count=0;
    queue<int> q;
    q.push(s);
    for(int i=0;i<N;i++)vis[i]=false;
    while(!q.empty())
    {
        int t1=q.front();
        q.pop();
        if(!vis[t1])
        {
          cout<<t1<<" ";
        }
        vis[t1]=true;
        for(int i=0;i<adj[t1].size();i++)
        {
            dis[adj[t1][i].data]=adj[t1][i].dis;
            prev[adj[t1][i].data]=t1;
            if(!vis[adj[t1][i].data])q.push(adj[t1][i].data);
        }
    }
    cout<<endl;
}

void dfs(int s, vector<int> g[], bool vis[])
{
    if(!vis[s])
    {
        cout<<s<<" ";
        vis[s]=true;
        for(int i=0;i<g[s].size();i++)
        {
            dfs(g[s][i],g,vis);
        }
    }
}
struct ver
{
  int dis;
  int data;
};

int main()
{
  cout<<"enter v: ";
  int v;cin>>v;
  vector<ver> adj_list[v];
  cout<<"enter e: ";
  int e;cin>>e;
  cout<<"enter the edge set\n";
  for(int i=0;i<e;i++)
  {
    int u,v,w;
    cin>>u>>v>>w;
    ver s;s.dis=w;
    s.data=v;
    adj_list[u].push_back(s);
    // adj_list[v].push_back(u);
  }
  cout<<"the adjacency list is\n";
  for(int i=0;i<v;i++)
  {
      cout<<i;
      for(int j=0;j<adj_list[i].size();j++)
      {
          cout<<"-> "<<adj_list[i][j].data<<" "<<adj_list[i][j].dis;
      }
      cout<<endl;
  }
  bool vis[v];
  cout<<"enter the starting index for bsf: ";
  int s;cin>>s;
  cout<<"enter the destination index for bsf: ";
  int d;cin>>d;
  cout<<"the breath first traversal is\n";
  // bfs(s,adj_list,vis,v);
  int dis[v]={INT_MAX};
  int prev[v];
  diju(s,d,adj_list,vis,dis,prev,v);
  // for(int i=0;i<v;i++)vis[i]=false;
  // cout<<"the deapth first traversal is\n";
  // dfs(s,adj_list,vis);
  // cout<<endl;
  cin.get();
  cin.get();
  return 0;
}

#include<bits/stdc++.h>
using namespace std;

typedef vector<int> graph;

void adjlist_dir(int e,int v,graph adj_list[],int wei[])
{
    for(int i=0;i<v;i++)
    {
        // cout<<"enter the adjacent vertex of "<<i<<" ( -1 to stop )\n";
        while(1)
        {
            int n;cin>>n;
            if(n==-1)break;
            adj_list[i].push_back(n);
        }
        // cout<<"enter the weight of vertex "<<i<<" : ";
        cin>>wei[i];
    }
}

void print_adjlist_unw(graph adj_list[],int v,int wei[])
{
  cout<<"the adjacency list is\n";
  for(int i=0;i<v;i++)
  {
      cout<<i<<" "<<wei[i];
      for(int j=0;j<adj_list[i].size();j++)
      {
          cout<<"-> "<<adj_list[i][j];
      }
      cout<<endl;
  }
}

void shortest_path(int s,int d,graph adj[], bool vis[],int dis[],int prev[],int wei[],int N)
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
            if(wei[t1]+wei[adj[t1][i]]+dis[t1]<dis[adj[t1][i]])
            {
              dis[adj[t1][i]]=wei[t1]+wei[adj[t1][i]]+dis[t1];
              prev[adj[t1][i]]=t1;
              cout<<prev[adj[t1][i]]<<endl;
            }
          }
          vis[t1]=true;
          for(int i=0;i<adj[t1].size();i++)
          {
              if(!vis[adj[t1][i]])q.push(adj[t1][i]);
          }
        }
    }
    while(1)
    {
      cout<<d<<" ";
      d=prev[d];
      if(d==s)break;
    }
    cout<<s<<endl;
}

int main()
{
  cout<<"enter v: ";
  int v;cin>>v;
  graph adj_list[v];
  cout<<"enter e: ";
  int e;cin>>e;
  int wei[v];
  adjlist_dir(e,v,adj_list,wei);
  print_adjlist_unw(adj_list,v,wei);
  bool vis[v];
  int dis[v],prev[v];
  cout<<"enter the starting index: ";
  int s;cin>>s;
  cout<<"enter the destination index: ";
  int d;cin>>d;
  cout<<"the shortest path in reverse order is\n";
  shortest_path(s,d,adj_list,vis,dis,prev,wei,v);
}

// 1 3 -1
// 5
// 3 4 -1
// 8
// 0 5 -1
// 3
// 2 4 5 6 -1
// 2
// 6 -1
// 9
// -1
// 10
// 5 -1
// 6
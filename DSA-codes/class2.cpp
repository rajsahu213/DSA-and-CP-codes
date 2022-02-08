#include<bits/stdc++.h>
using namespace std;

typedef vector<int> graph;

void adjlist_undir(int e,int v,graph adj_list[])
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
    }
}

void dfs_unweighted(int s, vector<int> g[], bool vis[],int arr[],int dep[],int &m)
{
    if(!vis[s])
    {
        vis[s]=true;
        arr[s]=m++;
        for(int i=0;i<g[s].size();i++)
        {
            dfs_unweighted(g[s][i],g,vis,arr,dep,m);
        }
        dep[s]=m++;
    }
}

void print_adjlist_unw(graph adj_list[],int v)
{
  cout<<"the adjacency list is\n";
  for(int i=0;i<v;i++)
  {
      cout<<i;
      for(int j=0;j<adj_list[i].size();j++)
      {
          cout<<"-> "<<adj_list[i][j];
      }
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
  adjlist_undir(e,v,adj_list);
  print_adjlist_unw(adj_list,v);
  bool vis[v]={false};
  int arr[v],dep[v],m=0; 
  for(int i=0;i<v;i++)
  {
    if(!vis[i])dfs_unweighted(i,adj_list,vis,arr,dep,m);
  }
  int n=m;
  cout<<"arriving time and departure time is given by\n";
  for(int i=0;i<v;i++)
  {
    cout<<arr[i]<<" "<<dep[i]<<endl;
  }
  cout<<"the topological sort is given by\n";
  int top[n];
  for(int i=0;i<n;i++)top[i]=-1;
  for(int i=0;i<v;i++)
  {
    top[dep[i]]=i;
  }
  for(int i=n-1;i>=0;i--)
  {
    if(top[i]!=-1)cout<<top[i]<<" ";
  }
  cout<<endl;
}
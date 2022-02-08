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
            adj_list[n].push_back(i);
        }
    }
}

void dfs_unweighted(int s, vector<int> g[], bool vis[],int m,int gt,int k)
{
    if(!vis[s])
    {
        if(k==0&&s>=gt)
        {
          cout<<"( "<<m<<", "<<s<<" ) ";
        }
        vis[s]=true;
        for(int i=0;i<g[s].size();i++)
        {
            dfs_unweighted(g[s][i],g,vis,m,gt,k-1);
        }
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
  cout<<"enter the value of k: ";
  int k;cin>>k;
  for(int i=0;i<v;i++)
  {
    bool vis[v]={false};
    dfs_unweighted(i,adj_list,vis,i,i,k);
  }
  cout<<endl;
}
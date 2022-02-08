#include<bits/stdc++.h>
using namespace std;

typedef vector<int> graph;

void adjlist_undir(int e,int v,graph adj_list[])
{
    for(int i=0;i<v;i++)
    {
        cout<<"enter the adjacent vertex of "<<i<<" ( -1 to stop )\n";
        while(1)
        {
            int n;cin>>n;
            if(n==-1)break;
            adj_list[i].push_back(n);
            adj_list[n].push_back(i);
        }
    }
}

void dfs_unweighted(int s, vector<int> g[], bool vis[])
{
    if(!vis[s])
    {
        cout<<s<<" ";
        vis[s]=true;
        for(int i=0;i<g[s].size();i++)
        {
            dfs_unweighted(g[s][i],g,vis);
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

struct weight
{
    int data;
    int dis;
};

void print_adjlist_wei(vector<weight> adj_list[],int v)
{
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
}

void adjlist_dir_weight(int e,int v,vector<weight> adj_list[])
{
    for(int i=0;i<v;i++)
    {
        cout<<"enter the adjacent vertex of "<<i<<" and its weight( -1 to stop )\n";
        while(1)
        {
            struct weight a;
            cin>>a.data>>a.dis;
            if(a.data==-1)break;
            adj_list[i].push_back(a);
        }
    }
}

void dfs_weight(int s, vector<weight> g[], bool vis[])
{
    if(!vis[s])
    {
        cout<<s<<" ";
        vis[s]=true;
        for(int i=0;i<g[s].size();i++)
        {
            dfs_weight(g[s][i].data,g,vis);
        }
    }
}

int main()
{
  cout<<"enter v: ";
  int v;cin>>v;
  graph adj_list[v];
  // vector<weight> adj_list[v];
  cout<<"enter e: ";
  int e;cin>>e;
  adjlist_undir(e,v,adj_list);
  print_adjlist_unw(adj_list,v);
  bool vis[v]={false};
  cout<<"enter the starting index for dsf: ";
  int s;cin>>s;
  cout<<"the deapth first traversal is\n";
  dfs_unweighted(s,adj_list,vis);
  cout<<endl;
}
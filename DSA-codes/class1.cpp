#include<bits/stdc++.h>
using namespace std;

typedef vector<int> graph;

void adjlist_dir(int v,graph adj_list[])
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

void dfs1(int s, vector<int> g[], bool vis[],stack<int> &st)
{
    if(!vis[s])
    {
        vis[s]=true;
        for(int i=0;i<g[s].size();i++)
        {
            dfs1(g[s][i],g,vis,st);
        }
        st.push(s);
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
  adjlist_dir(v,adj_list);
  print_adjlist_unw(adj_list,v);
  bool vis[v]={false};
  // int arr[v],dep[v],m=0; 
  // for(int i=0;i<v;i++)
  // {
  //   if(!vis[i])dfs_unweighted(i,adj_list,vis,arr,dep,m);
  // }
  stack<int> s;
  for(int i=0;i<v;i++)
  {
    if(!vis[i])dfs1(i,adj_list,vis,s);
  }
  vector<int> g[v];
  for(int i=0;i<v;i++)
  {
    for(int j=0;j<adj_list[i].size();j++)
    {
        g[adj_list[i][j]].push_back(i);
    }
  }
  // map<int,int> mp;
  // for(int i=0;i<v;i++)
  // {
  //   mp[dep[i]]=i;
  // } 
  bool vis1[v]={false};
  cout<<"the strongly connected components of the given graph are\n";
  // for(auto i=mp.rbegin();i!=mp.rend();++i)
  // {
  //   if(!vis1[i->second])
  //   {
  //     dfs(i->second,g,vis1);
  //     cout<<endl;
  //   }
  // }
  while(!s.empty())
  {
    int i=s.top();
    s.pop();
    if(!vis1[i])
    {
      dfs(i,g,vis1);
      cout<<endl;
    }      
  }
}




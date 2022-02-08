#include<bits/stdc++.h>
using namespace std;
typedef vector<int> graph;

void adjlist_undir(int e,int v,vector<int> adj_list[])
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

bool dfs_unweighted(int s, vector<int> g[], bool vis[],stack<int> st,int v)
{
    if(st.size()==v)
    {
        for(int i=0;i<v;i++)
        {
            if(vis[v]==false)return false;
        }
        return true;
    }
    if(!vis[s])
    {
        st.push(s);
        vis[s]=true;
        for(int i=0;i<g[s].size();i++)
        {
            dfs_unweighted(g[s][i],g,vis,st,v);
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
    vector<int> adj_list[v];
    cout<<"enter e: ";
    int e;cin>>e;
    adjlist_undir(e,v,adj_list);
    print_adjlist_unw(adj_list,v);
    cout<<"enter the starting index for dsf: ";
    int s;cin>>s;
    bool vis[v]={false};
    stack<int> st;
    cout<<dfs_unweighted(s,adj_list,vis,st,v)<<endl;
    cout<<endl;    
}
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
int index(graph v[],int d,int n)
{
  for(int i=0;i<v[d].size();i++)
  {
    if(v[d][i]==n)return i;
  }
}
void eulere_path(int s, vector<int> g[],bool vis[],int v,int st)
{
    cout<<s<<" ";
    for(int i=0;i<g[s].size();i++)
    {
        int temp=g[s][i];
        int m1=index(g,g[s][i],s); 
        g[g[s][i]].erase(g[g[s][i]].begin()+m1);
        g[s].erase(g[s].begin()+i);  
        for(int k=0;k<g[s].size();k++)
        {
            int m=index(g,g[s][k],s); 
            g[g[s][k]].erase(g[g[s][k]].begin()+m);
            g[g[s][k]].push_back(s);
        }  
        for(int k=0;k<g[st].size();k++)
        {
            int m=index(g,g[st][k],st); 
            g[g[st][k]].erase(g[g[st][k]].begin()+m);
            g[g[st][k]].push_back(st);
        }        
        eulere_path(temp,g,vis,v,st);
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
    eulere_path(s,adj_list,vis,v,s);
    cout<<endl;    
}
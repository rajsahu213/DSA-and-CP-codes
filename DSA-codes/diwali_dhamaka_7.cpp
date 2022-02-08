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
            adj_list[n].push_back(i);
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
      cout<<i<<" ";
      for(int j=0;j<adj_list[i].size();j++)
      {
          cout<<"-> "<<adj_list[i][j];
      }
      cout<<endl;
  }
}

void dfs_unweighted(int s, vector<int> g[], bool vis[],int wei[],int &sum,int l)
{
    if(!vis[s])
    {
        vis[s]=true;
        for(int i=0;i<g[s].size();i++)
        {
            dfs_unweighted(g[s][i],g,vis,wei,sum,l+wei[g[s][i]]);
        }
        if(l>sum)sum=l;
    }
}

void dfs_unweighted_print(int s, vector<int> g[], bool vis[],int wei[],int k,int l,int a[],int j)
{
    if(!vis[s])
    {
        a[j++]=s;
        vis[s]=true;
        for(int i=0;i<g[s].size();i++)
        {
            dfs_unweighted_print(g[s][i],g,vis,wei,k,l+wei[g[s][i]],a,j);
        }
        if(l==k)
        { 
          for(int i=0;i<j;i++)
          {
            cout<<a[i]<<" ";
          }
          cout<<endl;
        }
    }
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
  int sum=INT_MIN,max=INT_MIN;
  for(int i=0;i<v;i++)
  {
    bool vis[v]={false};
    dfs_unweighted(i,adj_list,vis,wei,sum,wei[i]);
    if(sum>max)max=sum;
  }
  cout<<"the maximum path sum is given by: "<<max<<endl;
  cout<<"enter k: ";
  int k;cin>>k;
  for(int i=0;i<v;i++)
  {
    bool vis[v]={false};
    int a[v];int l=0;
    dfs_unweighted_print(i,adj_list,vis,wei,k,wei[i],a,l);
  }  
}

// 1 2 3 4 -1
// 5
// 5 6 7 -1
// 8
// 8 9 -1
// -10
// 10 11 -1
// 12
// 12 13 14 -1
// 13
// -1
// -6
// -1
// 9
// -1
// 4
// -1
// 3
// -1
// 5
// 15 -1
// -18
// -1
// 1
// 16 -1
// 2
// -1
// -8
// -1
// 1
// -1
// 19
// 17 -1
// 3
// -1
// 4


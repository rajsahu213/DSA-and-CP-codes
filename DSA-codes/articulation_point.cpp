#include<bits/stdc++.h>
using namespace std;

typedef vector<int> graph;

void adjlist_undir(int v,vector<int> adj_list[])
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
int mini(int a,int b)
{
    if(a<b)return a;
    else return b;
}

int min(int s,graph g[],bool vis[],int num[],int prev)
{
    int mi=num[s];
    for(int i=0;i<g[s].size();i++)
    {
        if(vis[g[s][i]]&&g[s][i]!=prev)
        {
            int temp=mini(num[s],num[g[s][i]]);
            if(temp<mi)mi=temp;
        }
    }
    return mi;
}

void dfs_unweighted(int s,int prev,vector<int> g[],bool vis[],int num[],int low[],int &m,int root,int &count,set<int,greater<int>> &S)
{
    if(!vis[s])
    {
        vis[s]=true;
        num[s]=m++;
        low[s]=min(s,g,vis,num,prev);
        for(int i=0;i<g[s].size();i++)
        {
            dfs_unweighted(g[s][i],s,g,vis,num,low,m,root,count,S);  
        }
        if(prev==root)count++;
        if(low[s]>=num[prev]&&prev!=root&&prev!=-1)
        {
            S.insert(prev);
        }   
        if(low[s]>num[prev])
        {
            cout<<prev<<"   "<<s<<endl;
        }         
        low[prev]=mini(low[prev],low[s]);      
    }
}

int main()
{
    cout<<"enter v: ";
    int v;cin>>v;
    vector<int> adj_list[v];
    adjlist_undir(v,adj_list);
    print_adjlist_unw(adj_list,v);
    bool vis[v]={false};
    int m=1,low[v],num[v],prev=-1,count=0; 
    for(int i=0;i<v;i++)num[i]=INT_MAX;
    cout<<"enter the starting index: ";
    int s;cin>>s;
    set <int, greater <int> > S;
    cout<<"the bridges are\n";
    dfs_unweighted(s,prev,adj_list,vis,num,low,m,s,count,S);
    if(count>1)S.insert(s);
    cout<<"the articulation points are\n";    
    for(auto i=S.begin();i!=S.end();i++)
    {
        cout<<*i<<" ";
    }
    cout<<endl;
}
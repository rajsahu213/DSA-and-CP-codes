#include<bits/stdc++.h>
using namespace std;

void adjlist_undir(int e,int v,vector<int> adj_list[])
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

void adjlist_dir(int e,int v,vector<int> adj_list[])
{
    for(int i=0;i<v;i++)
    {
        cout<<"enter the adjacent vertex of "<<i<<" ( -1 to stop )\n";
        while(1)
        {
            int n;cin>>n;
            if(n==-1)break;
            adj_list[i].push_back(n);
        }
    }
}

struct weight
{
    int data;
    int dis;
};

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

void adjlist_undir_weight(int e,int v,vector<weight> adj_list[])
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
            struct weight b;
            b.data=i;b.dis=a.dis;
            adj_list[a.data].push_back(b);
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

void print_adjlist_wei(graph adj_list[],int v)
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

int main()
{
    cout<<"enter v: ";
    int v;cin>>v;
    // vector<int> adj_list[v];
    vector<weight> adj_list[v];
    cout<<"enter e: ";
    int e;cin>>e;
    adjlist_undir_weight(e,v,adj_list);
    print_adjlist_wei(adj_list,v);
}

#include<bits/stdc++.h>
using namespace std;
typedef vector<int> graph;

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

bool found(graph adj_list[],int s,int x)
{
    for(int i=0;i<adj_list[s].size();i++)
    {
        if(adj_list[s][i]==x)return true;
    }
    return false;
}

void no_of_triangles(int s,graph adj_list[],int flag,int &count,int x)
{
    if(flag==2)
    {
        if(found(adj_list,s,x))count++;
        return;
    }
    else
    {
        for(int i=0;i<adj_list[s].size();i++)
        {
            if(adj_list[s][i]!=x)no_of_triangles(adj_list[s][i],adj_list,flag+1,count,x);
        }
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
    int count,flag;
    int sum=0;
    for(int i=0;i<v;i++)
    {
        count=0;flag=0;
        no_of_triangles(i,adj_list,flag,count,i);
        sum+=count;
    }
    cout<<"number of triangles in the given graph is: "<<sum/6<<endl;
}
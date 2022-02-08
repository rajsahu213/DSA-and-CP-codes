#include<iostream>
using namespace std;

void adjmtx_undirected(int &v,int &e,int g[][100])
{
  cout<<"enter the edge set\n";
  for(int i=0;i<e;i++)
  {
    int u,v;
    cin>>u>>v;
    g[u][v]=1;
    g[v][u]=1;
  }
}

int degree(int g[][100],int v,int v1)
{
  int count=0;
  for(int i=1;i<=v;i++)
  {
    if(g[v1][i])count++;
  }
  return count;
}

int no_of_edges(int g[][100],int v)
{
  int count=0;
  for(int i=1;i<=v;i++)
  {
    for(int j=1;j<=i;j++)
    {
      if(g[i][j])count++;
    }
  }
  return count;
}

int main()
{
  cout<<"enter v: ";
  int v;cin>>v;
  int g[100][100];
  g[v+1][v+1]={0};
  cout<<"enter e: ";
  int e;cin>>e;
  adjmtx_undirected(v,e,g);
  cout<<"enter the vertex to know its degree: ";
  int v1;cin>>v1;
  cout<<"the ans is "<<degree(g,v,v1)<<endl;
  cout<<"no of edges in the graph is: "<<no_of_edges(g,v)<<endl;
  cin.get();
  cin.get();
}

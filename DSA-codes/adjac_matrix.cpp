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

void adjmtx_directed(int &v,int &e,int g[][100])
{
  cout<<"enter the edge set\n";
  for(int i=0;i<e;i++)
  {
    int u,v;
    cin>>u>>v;
    g[u][v]=1;
  }
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
  cout<<"the required matrix is\n";
  for(int i=1;i<=v;i++)
  {
    for(int j=1;j<=v;j++)
    {
      cout<<g[i][j]<<" ";
    }
    cout<<endl;
  }
  cin.get();
  cin.get();
}

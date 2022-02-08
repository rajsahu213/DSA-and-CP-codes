#include<iostream>
#define v 7
using namespace std;

void adjmtx_undir(int &e,int g[][v])
{
  cout<<"enter the edge set\n";
  for(int i=0;i<e;i++)
  {
    int n,m;
    cin>>n>>m;
    g[n][m]=1;
    g[m][n]=1;
  }
}

void adjmtx_undir_weight(int &e,int g[][v])
{
  cout<<"enter the edge set and its weight\n";
  for(int i=0;i<e;i++)
  {
    int n,m,w;
    cin>>n>>m>>w;
    g[n][m]=w;
    g[m][n]=w;
  }
}

void adjmtx_dir(int &e,int g[][v])
{
  cout<<"enter the edge set\n";
  for(int i=0;i<e;i++)
  {
    int n,m;
    cin>>n>>m;
    g[n][m]=1;
  }
}

void adjmtx_dir_weight(int &e,int g[][v])
{
  cout<<"enter the edge set and its weight\n";
  for(int i=0;i<e;i++)
  {
    int n,m,w;
    cin>>n>>m>>w;
    g[n][m]=w;
  }
}

int main()
{
  int g[v][v]={0};
  cout<<"enter e: ";
  int e;cin>>e;
  adjmtx_dir_weight(e,g);
  cout<<"the required matrix is\n";
  for(int i=0;i<v;i++)
  {
    for(int j=0;j<v;j++)
    {
      cout<<g[i][j]<<" ";
    }
    cout<<endl;
  }
}

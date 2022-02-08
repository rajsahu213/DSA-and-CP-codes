#include<iostream>
using namespace std;

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

int indegree(int g[][100],int v,int v1)
{
  int count=0;
  for(int i=1;i<=v;i++)
  {
    if(g[i][v1])count++;
  }
  return count;
}

int outdegree(int g[][100],int v,int v1)
{
  int count=0;
  for(int i=1;i<=v;i++)
  {
    if(g[v1][i])count++;
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
  adjmtx_directed(v,e,g);
  cout<<"enter the vertex to know its degree: ";
  int v1;cin>>v1;
  cout<<"the indegree is: "<<indegree(g,v,v1)<<endl;
  cout<<"the outdegree is: "<<outdegree(g,v,v1)<<endl;
  cout<<"the degree is: "<<indegree(g,v,v1)+outdegree(g,v,v1)<<endl;
  cin.get();
  cin.get();
}

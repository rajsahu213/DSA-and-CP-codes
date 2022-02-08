#include<iostream>
using namespace std;

int main()
{
  cout<<"enter v: ";
  int v;cin>>v;
  int g[v+1][v+1]={0};
  cout<<"enter e: ";
  int e;cin>>e;
  int ind[v+1]={0};
  cout<<"enter the edge set\n";
  for(int i=0;i<e;i++)
  {
    int u,v;
    cin>>u>>v;
    ind[v]++;
    g[u][v]=1;
  }
  int t=v;
  while(t--)
  {
    for(int i=1;i<=v;i++)
    {
      if(ind[i]==0)
      {
        cout<<i<<" ";
        ind[i]--;
        for(int j=1;j<=v;j++)
        {
          if(g[i][j]==1)
          {
            ind[j]--;
          }
        }
        break;
      }
    }
  }
  cin.get();
  cin.get();
}

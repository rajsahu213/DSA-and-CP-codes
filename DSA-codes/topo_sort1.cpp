#include<iostream>
#include<vector>
using namespace std;

typedef vector<int> graph;

void adjlist_dir(int e,int v,vector<int> adj_list[],int ind[])
{
    for(int i=0;i<v;i++)
    {
        // cout<<"enter the adjacent vertex of "<<i<<" ( -1 to stop )\n";
        while(1)
        {
            int n;cin>>n;
            if(n==-1)break;
            ind[n]++;
            adj_list[i].push_back(n);
        }
    }
}

// void topo_sort(graph adj_list[],int ind[],int v)
// {
//   int t=v;
//   while(t--)
//   {
//     for(int i=0;i<v;i++)
//     {
//       if(ind[i]==0)
//       {
//         cout<<i<<" ";
//         ind[i]--;
//         if(adj_list[i].size()>=1)ind[adj_list[i][0]]--;
//         break;
//       }
//     } 
//   }
// }

bool check(vector<int> &v,int a)
{
  for(int i=0;i<v.size();i++)
  {
    if(v[i]==a)return true;
  }
  return false;
}

void topo_sort(graph adj_list[],vector<int> v,int ind[],int n,int &count)
{
    if(v.size()==n)
    {
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i]<<" ";
        }
        cout<<endl;
        return;
    }
    else
    {
      for(int i=0;i<n;i++)
      {
        if(!check(v,i))
        {
          if(ind[i]==0)
          {
              v.push_back(i);
              for(int k=0;k<adj_list[i].size();k++)
              {
                if(adj_list[i].size()>=1)ind[adj_list[i][k]]--;
              }
              topo_sort(adj_list,v,ind,n,count);
              v.pop_back();
              for(int k=0;k<adj_list[i].size();k++)
              {
                if(adj_list[i].size()>=1)ind[adj_list[i][k]]++;
              }
          }
        }
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
  int ind[v]={0};
  adjlist_dir(e,v,adj_list,ind);int i=0;
  vector<int> ve;
  // for(int i=0;i<v;i++)cout<<ind[i]<<" ";
  // cout<<endl;
  topo_sort(adj_list,ve,ind,v,i);
  cout<<endl;
}


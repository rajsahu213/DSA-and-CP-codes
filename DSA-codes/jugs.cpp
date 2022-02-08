#include<bits/stdc++.h>
using namespace std;

struct state
{
  int j1;
  int j2;
};

typedef vector<state> graph;

bool is_there(graph v,int n,int m)
{
  for(int i=0;i<v.size();i++)
  {
    if(v[i].j1==n&&v[i].j2==m)return true;
  }
  return false;
}

void fill_jug(graph &v,int s1,int s2,int n,int m,int k)
{
  if(s1>n||s2>m)return;
  if(is_there(v,s1,s2))return;
  else{
    struct state a;a.j1=s1;a.j2=s2;
    v.push_back(a);
  }
  if(s1==k||s2==k)return;
  if(s1==0)fill_jug(v,n,s2,n,m,k);
  else if(s1==n)
  {
    fill_jug(v,0,s2,n,m,k);
    if(s2==0)fill_jug(v,s1,m,n,m,k);
    int a=m-s2;
    fill_jug(v,s1-a,s2+a,n,m,k);
  }
  if(s2==0)
  {
    fill_jug(v,s1,m,n,m,k);
    if(s1<=m)fill_jug(v,0,s1,n,m,k);
  }
  else if(s2==m)
  {
    fill_jug(v,s1,0,n,m,k);
    if(s1==0)fill_jug(v,n,s2,n,m,k);
    int b=n-s1;
    if(b<=m)fill_jug(v,s1+b,s2-b,n,m,k);
    else fill_jug(v,s2,0,n,m,k);
  }
}

int main()
{
  cout<<"enter the capacity of jug 1: ";
  int n;cin>>n;
  cout<<"enter the capacity of jug 2: ";
  int m;cin>>m;
  cout<<"enter k: ";
  int k;cin>>k;
  graph v;
  fill_jug(v,0,0,n,m,k);
  for(int i=0;i<v.size();i++)
  {
    cout<<" ( "<<v[i].j1<<" , "<<v[i].j2<<" )   ";
  }
  cout<<endl;
}

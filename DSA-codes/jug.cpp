#include<bits/stdc++.h>
using namespace std;

struct state
{
  int j1;
  int j2;
};

bool is_there(state v[],int l,int n,int m)
{
  for(int i=0;i<l;i++)
  {
    if(v[i].j1==n&&v[i].j2==m)return true;
  }
  return false;
}

void fill_jug(state v[],int s1,int s2,int n,int m,int k,int &i)
{
  if(s1>n||s2>m)return;
  if(is_there(v,i,s1,s2))return;
  else{v[i].j1=s1;v[i].j2=s2;i++;}
  if(s1==k||s2==k)return;
  if(s1==0)fill_jug(v,n,s2,n,m,k,i);
  else if(s1==n)
  {
    fill_jug(v,0,s2,n,m,k,i);
    if(s2==0)fill_jug(v,s1,m,n,m,k,i);
    int a=m-s2;
    fill_jug(v,s1-a,s2+a,n,m,k,i);
  }
  if(s2==0)
  {
    fill_jug(v,s1,m,n,m,k,i);
    if(s1<=m)fill_jug(v,0,s1,n,m,k,i);
  }
  else if(s2==m)
  {
    fill_jug(v,s1,0,n,m,k,i);
    if(s1==0)fill_jug(v,n,s2,n,m,k,i);
    int b=n-s1;
    if(b<=m)fill_jug(v,s1+b,s2-b,n,m,k,i);
    else fill_jug(v,s2,0,n,m,k,i);
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
  state v[100];int l=0;
  fill_jug(v,l,l,n,m,k,l);
  for(int i=0;i<l;i++)
  {
    cout<<" ( "<<v[i].j1<<" , "<<v[i].j2<<" ) ,";
  }
  cout<<endl;

}

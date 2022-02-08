#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;

ld distance(ld x1,ld y1,ld x2,ld y2) 
{ 
  ld d1=pow(x2 - x1, 2) * 1.0;
  ld d2=pow(y2 - y1, 2) * 1.0;
  ld d3=d1+d2;
  return sqrtl(d3); 
}

int main() 
{
  ll t;cin>>t;
  while(t--)
  {
    ld x,y;
    cin>>x>>y;
    ll n,m,k;
    cin>>n>>m>>k;
    ld a[n],b[n],c[m],d[m],e[k],f[k];
    for(ll i=0;i<n;i++)
    {
      cin>>a[i]>>b[i];
    }
    for(ll i=0;i<m;i++)
    {
      cin>>c[i]>>d[i];
    }
    for(ll i=0;i<k;i++)
    {
      cin>>e[i]>>f[i];
    }
    ld min_dis=LDBL_MAX;
    for(ll i=0;i<n;i++)
    {
        ld d1=distance(x,y,a[i],b[i]);
        for(ll j=0;j<m;j++)
        {
            ld d2=distance(a[i],b[i],c[j],d[j]);
            for(ll l=0;l<k;l++)
            {
                ld d3=distance(c[j],d[j],e[l],f[l]);
                if((d1+d2+d3)<min_dis){min_dis=d1+d2+d3;}
            }
        }
    }
    for(ll i=0;i<m;i++)
    {
        ld d1=distance(x,y,c[i],d[i]);
        for(ll j=0;j<n;j++)
        {
            ld d2=distance(c[i],d[i],a[j],b[j]);
            for(ll l=0;l<k;l++)
            {
                ld d3=distance(a[j],b[j],e[l],f[l]);
                if((d1+d2+d3)<min_dis){min_dis=d1+d2+d3;}
            }
        }
    }
    cout<<setprecision(11)<<min_dis<<endl;
  }
  return 0;
}
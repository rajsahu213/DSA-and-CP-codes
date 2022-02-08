#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
	ll t;cin>>t;
	while(t--)
	{
	    ll n,m;
	    cin>>n>>m;
	    ll a[n+1];
	    memset(a, 0, sizeof(a));
	    for(ll i=0;i<m;i++)
	    {
	        ll u,v;
	        cin>>u>>v;
	        a[u]++;
	        a[v]++;
	    }
	    if(m%2==0)
	    {
	        cout<<1<<endl;
	        for(ll i=1;i<=n;i++)
	        {
	            cout<<1<<" ";
	        }
	        cout<<endl;
	    }
	    else
	    {
	        ll flag=0,temp;
            for(ll i=1;i<=n;i++)
            {
                if(a[i]%2!=0)
                {
                    temp=i;
                    flag=1;
                    break;
                }
            }
            if(flag==1)
            {
                cout<<2<<endl;
                for(ll i=1;i<=n;i++)
                {
                    if(i==temp||a[i]==0)
                    {
                        cout<<2<<" ";
                    }
                    else
                    {
                        cout<<1<<" ";
                    }
                }
                cout<<endl;
            }
            else
            {
               cout<<3<<endl;
               for(ll i=1;i<=n;i++)
               {
                   if(i==1)
                   {
                       cout<<3<<" ";
                   }
                   else if(i==2||a[i]==0)
                   {
                       cout<<2<<" ";
                   }
                   else cout<<1<<" ";
               }
               cout<<endl;
            }
	    }
	}
	return 0;
}















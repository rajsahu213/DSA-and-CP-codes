#include <iostream>
using namespace std;
typedef unsigned long long int ll;

int mod(int a,int b)
{
    if(a>b)return a-b;
    else return b-a;
}

int main() {
	ll t;
	cin>>t;
	while(t--)
    {
        ll Q,n;
        cin>>n>>Q;
        ll b[n];
        for(int i=1;i<n;i++)
        {
            cin>>b[i];
        }
        while(Q--)
        {
            ll p,q;
            cin>>p>>q;
            if(p<q){int temp=p;p=q;q=temp;}     
                if((p-q)%2!=0)
                {
                    ll flag=1,ans=0;
                    for(ll i=q;i<p;i++)
                    {
                        ans+=flag*b[i];
                        flag=flag*(-1);
                    }
                    cout<<ans<<endl;
                }
                else
                {
                    cout<<"UNKNOWN"<<endl;
                }
            
            // else if(q-p>0)
            // {
            //     if((q-p)%2!=0)
            //     {
            //         ll flag1=1,ans1=0;
            //         for(ll i=p;i<q;i++)
            //         {
            //             ans1+=flag1*b[i];
            //             flag1=flag1*(-1);
            //         }
            //         cout<<ans1<<endl;
            //     }
            //     else
            //     {
            //         cout<<"UNKNOWN"<<endl;
            //     }
            // }
        }
        
    }
    return 0;
}





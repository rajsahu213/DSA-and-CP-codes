#include <iostream>
using namespace std;

int main() {
    int t;cin>>t;
    while(t--)
    {
        int n,k,flag;
        cin>>n>>k;
        int a[n+1];
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        int flag1=0;
        if(a[1]==-1)
        {
            if(a[2]!=-1)
            {
            for(int j=1;j<=k;j++)
            {
                if(a[2]!=j)
                {
                    a[1]=j;
                    break;
                }
            }
            }
            if(a[2]==-1)flag1=1;
        }      
        for(int i=2;i<n;i++)
        {
            if(a[i]==-1)
            {
                for(int j=1;j<=k;j++)
                {
                    int x=a[i-1],y=a[i+1];
                    if(j!=x&&j!=y)
                    {
                        a[i]=j;
                    }
                }
            }
        }
        if(flag1==1)
        {
            for(int j=1;j<=k;j++)
            {
                if(a[2]!=j)
                {
                    a[1]=j;
                    break;
                }
            }            
        }
        if(a[n]==-1)
        {
            for(int j=1;j<=k;j++)
            {
                if(a[n-1]!=j)
                {
                    a[n]=j;
                    break;
                }
            }
        }          
        flag=1;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==-1){flag=0;}
            if(i<n){
            if(a[i]==a[i+1]){flag=0;}
            }
        }
        
        if(flag==1)
        {
            cout<<"YES\n";
            for(int i=1;i<=n;i++)
            {
                cout<<a[i]<<" ";
            }
            cout<<endl;
        }
        else 
        {
            cout<<"NO\n";
        }
    }
    return 0;
}
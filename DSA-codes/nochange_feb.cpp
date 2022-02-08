#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NUlong long int)
    int t;cin>>t;
    while(t--)
    {
        long long int n,p;cin>>n>>p;
        vector<long long int> d(n);
        for(long int i=0;i<n;i++)cin>>d[i];
        bool flg=false;
        for(long int i=0;i<n;i++)
        {
            if(p%d[i]!=0){flg=true;break;}
        }
        if(!flg)
        {
            sort(d.begin(),d.end());
            bool flg1=false;
            vector<long long int> ans;
            for(int i=n-1;i>=0;i--)
            {
                if(p%d[i]==0)
                {
                    ans.push_back(p/d[i]-1);
                    p=d[i];
                }
                else
                {
                    ans.push_back(p/d[i]+1);
                    flg1=true;
                    break;
                }
            }
            if(flg1)
            {
                cout<<"YES ";
                for(int i=0;i<(n-ans.size());i++)cout<<0<<" ";
                for(int i=ans.size()-1;i>=0;i--)
                {
                    cout<<ans[i]<<" ";
                }
                cout<<"\n";
            }
            else
            {
                cout<<"NO\n";
            }
        }
        else
        {
            long long int valu,ind;
            f(n)
            {
                if(p%d[i]!=0)
                {
                    valu=d[i];
                    ind=i;
                    break;
                }
            }
            cout<<"YES ";
            valu=p/valu+1;
            f(n)
            {
                if(i==ind)
                {
                    cout<<valu<<" ";
                }
                else cout<<0<<" ";
            }
            cout<<"\n";
        }
    }
}

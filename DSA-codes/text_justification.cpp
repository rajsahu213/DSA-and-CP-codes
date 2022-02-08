#include<bits/stdc++.h>

using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define mod 1000000007 
#define N 10000000

typedef long long int ll;
typedef long double ld;
typedef long int li;

int sqr(int a){return a*a;}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin>>n;
    string s[n];
    for(int i=0;i<n;i++)cin>>s[i];
    int t;cin>>t;
    int dp[n+1][n+1];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++)
    {
        dp[i][i]=sqr(t-s[i].length());
    }
    int th[n];
    th[0]=s[0].length();
    for(int i=1;i<n;i++)
    {
        th[i]=1+th[i-1]+s[i].length();
    }
    for(int k=1;k<n;k++)
    {
        for(int i=0;i+k<n;i++)
        {
            int j=i+k;
            if(i==0)
            {
                if(th[j]<=t)dp[i][j]=sqr(t-th[j]);
                else dp[i][j]=100000;
            }
            else
            {
                if((th[j]-th[i-1]-1)<=t)dp[i][j]=sqr(t-th[j]+1+th[i-1]);
                else dp[i][j]=100000;
            }
        }
    }
    ll temp1[n],temp2[n];
    temp1[n-1]=dp[n-1][n-1];temp2[n-1]=n;
    for(int i=n-1;i>=0;i--)
    {
        ll ans=INT_MAX;
        for(int j=n-1;j>=i;j--)
        {
            if((dp[i][j]+dp[j+1][n-1])<ans)
            {
                ans=dp[i][j]+dp[j+1][n-1];
                temp2[i]=j+1;
            }
        }
        temp1[i]=ans;
    }  
    for(int i=0;i<n;i++)
    {
        cout<<temp1[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<temp2[i]<<" ";
    }
    cout<<endl;
    return 0;
}           
#include<bits/stdc++.h>

using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl

typedef long long int ll;
typedef long double ld;
typedef long int li;

int main()
{
    // clock_t tStart = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;cin>>t;
    while(t--)
    {
        ll n;cin>>n;
        vector<string> s;
        string temp;
        for(ll i=0;i<n;i++)
        {
            cin>>temp;
            s.push_back(temp);
        }
        if(n==1){cout<<0<<"\n";continue;}
        ll ans=0;
        sort(s.begin(),s.end());
        vector<string> a;
        ll len=0;
        for(ll i=0;i<n;i++)
        {
            if((i+1)<n&&s[i]==s[i+1]){ans+=s[i].length()*s[i].length();i=i+1;}
            else a.push_back(s[i]);
        }     
        while(a.size()>1)
        {
            ll p1=0,p2=0,max=0;
            for(ll i=0;i<a.size();i++)
            {
                for(ll j=0;j<a.size();j++)
                {
                    if(i!=j)
                    {
                        ll k=0;
                        while(k<a[i].length() && k< a[j].length() && a[i][k]==a[j][k])
                        {
                            k++;
                        }
                        ll i1=a[i].length()-1,i2=a[j].length()-1,t=0;
                        while(i1>=0 &&  i2>=0  && a[i][i1]==a[j][i2])
                        {
                            t++;i1--;i2--;
                        }
                        if(t>=k)
                        {
                            if(k>=max)
                            {
                                max=k;
                                p1=i;
                                p2=j;
                            }
                        }
                        else if(k>t)
                        {
                            if(t>=max)
                            {
                                max=t;
                                p1=i;
                                p2=j;
                            }
                        }
                    }
                }
            }
            ans+=max*max;
            if(p1>p2)
            {
                a.erase(a.begin()+p1);
                a.erase(a.begin()+p2);
            }
            else
            {
                a.erase(a.begin()+p2);
                a.erase(a.begin()+p1);
            }   
            p1=0;p2=0;max=0;         
        }
        cout<<ans<<"\n";
    }
    // prllf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
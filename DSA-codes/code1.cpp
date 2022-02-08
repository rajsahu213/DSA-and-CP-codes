#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long int li;

int main()
{
    ll t;cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        ll sum=0;
        for(ll i=0;i<s.length();i++)
        {
            if(s[i]=='a'||s[i]=='d'||s[i]=='g'||s[i]=='j'||s[i]=='m'||s[i]=='p'||s[i]=='t'||s[i]=='w')
            {
                sum+=1;
            }
            else if(s[i]=='b'||s[i]=='e'||s[i]=='h'||s[i]=='k'||s[i]=='n'||s[i]=='q'||s[i]=='u'||s[i]=='x')
            {
                sum+=2;
            }
            else if(s[i]=='c'||s[i]=='f'||s[i]=='i'||s[i]=='l'||s[i]=='o'||s[i]=='r'||s[i]=='v'||s[i]=='y')
            {
                sum+=3;
            }       
            else if(s[i]=='s'||s[i]=='z')
            {
                sum+=4;
            }               
        }
        cout<<sum<<endl;
    }
    return 0;
}


#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long int li;

int main()
{
    ll t;cin>>t;
    while(t--)
    {
        ll n;cin>>n;
        ll ans=0; 
        for (ll i=1;i<=n;i++)
        { 
            ll count=0; 
            for(ll j=1;j<=i/2;j++) 
            {    
                if(i%j==0)
                { 
                    ++count; 
                } 
            } 
            if(count%2) 
            { 
                ++ans; 
            } 
        }
        cout<<ans<<endl;
        fflush(stdout);
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long int li;

int main()
{
    ll n,k;
    cin>>n>>k;
    ull a[n];
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(ll i=0;i<k-1;i++)
    {
        cout<<0<<" ";
    }
    for(ll i=k-1;i<n;i++)
    {
        sort(a,a+i+1);
        cout<<a[k-1]<<" ";
    }
    cout<<endl;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long int li;
bool isPrime(ll n) 
{  
    if(n<=1)return false; 
    if(n<=3)return true; 
    if(n%2==0||n%3==0)return false; 
    for (ll i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
    return true; 
}
ll count(ll n) 
{ 
    ll cnt = 0; 
    for (ll i=2;i<=sqrtl(n);i++)
    { 
        if (n%i==0){  
            if(n/i==i) 
                cnt++; 
            else cnt=cnt+2; 
        } 
    } 
    return cnt; 
}  

int main()
{
    ll n;cin>>n;
    ll q;cin>>q;
    while(q--)
    {
        ll l,r;
        cin>>l>>r;
        ll count2=0;
        for(ll i=l;i<=r;i++)
        {
            if(i>n)break;
            ll count1=count(i);
            if(isPrime(count1))
            {
                count2++;
            }
        }
        cout<<count2<<endl;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long int li;

int main()
{
    ll n,k;
    cin>>n>>k;
    ull a[n];
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(ll i=0;i<k-1;i++)
    {
        cout<<0<<" ";
    }
    sort(a,a+k);
    ll j=1;
    for(ll i=k-1;i<n;i++)
    {
        if(a[i]<a[k-1])
        {
            sort(a,a+k+j);
            j++;
            cout<<a[k-1]<<" ";
        }
        else
        {
            cout<<a[k-1]<<" ";
        }
    }
    cout<<endl;
    return 0;
}
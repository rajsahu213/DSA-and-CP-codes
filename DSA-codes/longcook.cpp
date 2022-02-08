#include <bits/stdc++.h>

using namespace std;

#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define watch(x) cout << (#x) << " is " << (x) << endl
#define f(t) for(ll i =0;i<t;i++)
#define bs(a,x) binary_search(a.begin(),a.end(),x)
#define ll long long int
#define ul unsigned long int
#define ld long double
#define umpi unordered_map<int,int> 
#define umpl unordered_map<ll,ll> 
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define mod 1000000007 
#define N 10000000
#define all(a) a.begin(),a.end()
#define point pair<int,int>
const int inf = 1000000007;
const ll linf = 1ll * inf * inf;

inline ll mul(ll a, ll b){ return (a * 1ll * b) % mod; }
inline ll sub(ll a, ll b){ ll c = a - b; if(c < 0) c += mod; return c; }
inline ll add(ll a, ll b){ ll c = a + b; if(c > mod) c -= mod; return c; }

struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
};

int day(int d,ll m,ll y)  
{  
    static int t[] = { 0, 3, 2, 5, 0, 3, 
                       5, 1, 4, 6, 2, 4 };  
    y -= m < 3;  
    return ( y + y / 4 - y / 100 +  
             y / 400 + t[m - 1] + d) % 7;  
}  

int numberOfDays (ll MN,ll year) 
{ 
    if (MN == 0)return (31); 
    if (MN == 1) 
    {  
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))return (29); 
        else return (28); 
    } 
    if (MN == 2)return (31); 
    if (MN == 3)return (30); 
    if (MN == 4)return (31); 
    if (MN == 5)return (30); 
    if (MN == 6)return (31); 
    if (MN == 7)return (31); 
    if (MN == 8)return (30); 
    if (MN == 9)return (31); 
    if (MN == 10)return (30); 
    if (MN == 11)return (31); 
} 

void fun(ll year1,ll year2,ll month1,ll month2,ll &ans)
{
    for(ll i=year1;i<=year2;i++)
    {
        if((i==year1 && month1<=2) || (i==year2 && month2>=2) || (i!=year1 && i!=year2))
        {
            int j=2;
            int fd=day(1,j,i);
            int temp=1;
            while(fd%7!=5){temp++;fd++;}
            int no=numberOfDays(j-1,i);
            int lsd=day(no,j,i);
            int second_sunday=no-lsd-7;
            if((second_sunday<(temp+10)) && second_sunday>=temp)
            {
                ans++;
            }
        }
    }
}

int main()
{
    fio;
    int t;cin>>t;
    while(t--)
    {
        ll month1,year1;
        cin>>month1>>year1;
        ll month2,year2;
        cin>>month2>>year2;
        ll ans=0;
        ll t2;
        if(year1%400==0)
        {
            int t1=year1-400;
            t2=(t1/400)*101;
            if(month1==1){year1=year1-1;month1=12;}
            else month1=month1-1;
            fun(t1+1,year1,1,month1,t2);
        }
        else
        {
            int t1=year1-year1%400;
            t2=(t1/400)*101;
            if(month1==1){year1=year1-1;month1=12;}
            else month1=month1-1;                
            fun(t1+1,year1,1,month1,t2);
        }
        if(year2%400==0)
        {
            int t1=year2-400;
            ll temp3=(t1/400)*101;
            fun(t1+1,year2,1,month2,temp3);
            ans+=temp3-t2;                
        }
        else
        {
            int t1=year2-year2%400;
            ll temp3=(t1/400)*101;
            fun(t1+1,year2,1,month2,temp3);
            ans+=temp3-t2;
        }
        cout<<ans<<"\n";
    }
}

#include<iostream>
#include<vector>
#include<ctime>
#include<algorithm>
#include<limits>
using namespace std;
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long int ll;

void fastscan(ll &number) 
{  
    bool negative = false; 
    register ll c; 
    number = 0;  
    c = getchar(); 
    if (c=='-') 
    {  
        negative = true; 
        c = getchar(); 
    } 
    for (; (c>47 && c<58); c=getchar()) 
        number = number *10 + c - 48; 
    if (negative) 
        number *= -1; 
} 

int main()
{
	// clock_t tStart = clock();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;fastscan(t);
	while(t--)
	{
	   ll a,b,n;
       cin>>a>>b>>n;
       if(n==1)
       {
            cout<<b<<"\n";
       }
       else
       {
            ll ans;
            for(ll i=1;i<n;i++)
            {
                ans=a^b;
                a=b;
                b=ans;
            }
            cout<<ans<<"\n";
       }
	}
	// printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	return 0;
}
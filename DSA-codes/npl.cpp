#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<string>
#include<queue>
using namespace std;

typedef long long int ll; 

void bfs(ll n,ll m,ll num,ll k,ll &count) 
{ 
    queue<ll> q; 
  
    q.push(num); 
  
    while (!q.empty()) 
    { 
        ll stepNum = q.front(); 
        q.pop();  
        if (stepNum <= m && stepNum >= n) 
            count++;
        if (num == 0 || stepNum > m) 
            continue; 
        ll lastDigit = stepNum % 10; 
        ll stepNumA = stepNum * 10 + (lastDigit- k); 
        ll stepNumB = stepNum * 10 + (lastDigit + k); 
        if (lastDigit == 0) 
            q.push(stepNumB); 
        else if (lastDigit == 9) 
            q.push(stepNumA); 
  
        else
        { 
            q.push(stepNumA); 
            q.push(stepNumB); 
        } 
    } 
} 

void displaySteppingNumbers(ll n,ll m,ll k,ll &count) 
{ 
    for (int i = 0 ; i <= 9 ; i++) 
        bfs(n, m, i,k,count); 
} 

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;cin>>t;
	while(t--)
	{
        ll l,r;
        ll k;
        cin>>l>>r>>k;
        ll count=0,i=0;
        for(i=l;i<=r;i++)
        {
            if(i<10)
            {
                count++;
            }
            else break;
        }
        if(i>l)l=i;
        for(ll i=0;i<=k;i++)
        {
            displaySteppingNumbers(l,r,k,count);
        }
        cout<<count<<endl;
	}
}
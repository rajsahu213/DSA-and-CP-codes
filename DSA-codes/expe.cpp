#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll power(ll x,ll y,ll p) 
{ 
    ll res = 1;
    x=x%p;  
    while (y>0) 
    { 
        if (y & 1) 
            res = ((res%p)*(x%p))%p; 
        y = y>>1; 
        x = ((x%p)*(x%p))%p; 
    } 
    return res; 
} 

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string s;
		int arr[n];
		cin>>s;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='('){
				arr[i]=1;
			}
			else if(s[i]==')'){
				arr[i]=-1;
			}
			else{
				arr[i]=0;
			}
		}
		int count[n] = {0};
		unordered_map<int ,int > index;
 
		index[0] = 1;
		int sum =0;
		int negeative_handler = 0;
		for(int i=0;i<n;i++)
		{
		  if(arr[i]==-1)
		  {
		  	count[i]+=n-i;
		  	count[i]+=index[sum]*(n-i);
 
		  	count[i]+=((negeative_handler+1)/2)*(n-i);
		  	if(negeative_handler/2>0)
		  	count[i]+=(index[sum-negeative_handler])*n-i;
		  	negeative_handler++;
 
		  }	
		  else
		  {
		  	negeative_handler = 0;
		  }
		  index[sum]++;
		  sum += arr[i];
		}
		int total_count =0;
		for(int i=0;i<n;i++)
		{
			total_count+=count[i];
		}                     
		long int ans = 1;
		long int q = n*(n+1);
		q=q/2;
		long int mod = 1000000007;
		q= power(q,mod-2,mod);
		ans = (total_count*q)%mod;
 		cout<<ans<<endl;
	}
}

// #include<bits/stdc++.h>
// using namespace std;
// long int power(long int x,  int y,  long int p) 
// { 
//     long int res = 1;      // Initialize result 
  
//     x = x % p;  // Update x if it is more than or 
//                 // equal to p 
  
//     while (y > 0) 
//     { 
//         // If y is odd, multiply x with result 
//         if (y & 1) 
//             res = (res*x) % p; 
  
//         // y must be even now 
//         y = y>>1; // y = y/2 
//         x = (x*x) % p; 
//     } 
//     return res; 
// } 
// int main(){
// 	int t;
// 	cin>>t;
// 	while(t--){
// 		int n;
// 		cin>>n;
// 		string s;
// 		int arr[n];
// 		cin>>s;
// 		for(int i=0;i<n;i++){
// 			if(s[i]=='('){
// 				arr[i]=1;
// 			}
// 			else if(s[i]==')'){
// 				arr[i]=-1;
// 			}
// 			else{
// 				arr[i]=0;
// 			}
// 		}
// 		int count[n] = {0};
// 		unordered_map<int ,int > index;
		
// 	//	index[0] = 1;
// 		int sum =0;
// 		int negeative_handler = 0;
// 		for(int i=0;i<n;i++){
// 		  if(arr[i]==-1){
// 		  	count[i]+=n-i;
// 		  	count[i]+=index[sum]*(n-i);
		  	
// 		  	count[i]+=((negeative_handler+1)/2)*(n-i);
// 		  //	if(negeative_handler/2>0)
// 		  //	count[i]+=(index[sum-negeative_handler])*n-i;
// 		  	negeative_handler++;
		  	
// 		  }	
// 		  else{
// 		  	negeative_handler = 0;
// 		  }
// 		  index[sum]++;
// 		  sum += arr[i];
// 		}int total_count =0;
// 		for(int i=0;i<n;i++){
// 		//	cout<<count[i]<<" ";
//             cout<<count[i]<<" ";
// 			total_count+=count[i];
// 		}
// 		//cout<<total_count<<endl;                      
// 		long int ans = 1;
// 		long int q = n*(n+1);
// 		q=q/2;
// 		//cout<<q<<endl;
// 		long int mod = 1000000007;
// 		q= power(q,mod-2,mod);
// 		ans = (total_count*q)%mod;
		
// 		cout<<ans<<endl;
		
		
// 	}
// }







    int t;cin>>t;
    while(t--)
    {
        ll n;cin>>n;
        string s;cin>>s;
        ll ans=0;
        vector<vector<pair<pair<ll,ll>,ll> > > dp(n,vector<pair<pair<ll,ll>,ll>>(n,{{0,0},0}));
        // memset(dp,-1,sizeof(dp));
        for(ll i=0;i<n;i++)
        {
            if(s[i]==')')dp[i][i]={{1,0},1};
            else if(s[i]=='(')dp[i][i]={{1,0},0};
            // cout<<i<<" "<<i<<endl;
            // cout<<dp[i][i].first.first<<" "<<dp[i][i].first.second<<" "<<dp[i][i].second<<endl;
        }
        for(ll k=1;k<n;k++)
        {
            for(ll i=0;i+k<n;i++)
            {
                ll j=i+k;
                pair<ll,ll> temp1=dp[i][j-1].first;
                ll temp2=dp[i][j-1].second;                
                if(s[j]=='(')
                {
                    dp[i][j]={{temp1.first+1,temp1.second},temp2};
                }
                else if(s[j]==')')
                {
                    if((temp1.second+1)>(temp1.first))
                    {
                        dp[i][j]={{temp1.first+1,temp1.second},temp2+1};
                    }
                    else
                    {
                        dp[i][j]={{temp1.first,temp1.second+1},temp2};
                    }
                }
                // cout<<i<<" "<<j<<endl;
                // cout<<dp[i][j].first.first<<" "<<dp[i][j].first.second<<" "<<dp[i][j].second<<endl;
            }
        }
        for(ll i=0;i<n;i++)
        {
            for(ll j=i;j<n;j++)
            {
                ans+=dp[i][j].second;
            }
        }
        // for(ll l=0;l<n;l++)
        // {
        //     for(ll r=l;r<n;r++)
        //     {
        //         ll nc=0,no=0;
        //         ll temp=0;
        //         if(dp[l][r]!=-1){ans+=dp[l][r];continue;}
        //         for(ll i=l;i<=r;i++)
        //         {
        //             if(s[i]=='*')continue;
        //             else if(s[i]=='(')no++;
        //             else if(s[i]==')')nc++;
        //             if(nc>no)
        //             {
        //                 ans++;
        //                 no++;
        //                 nc--;
        //                 temp++;
        //             }
        //         }
        //         dp[l][r]=temp;
        //     }
        // }
        ll ans1 = n*(n+1)/2;
        ans=mul(ans,modInverse(ans1,mod));
        cout<<ans<<endl;
    } 
#include<iostream>
using namespace std;

typedef long long int ll;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;cin>>t;
	while(t--)
	{
		int n;cin>>n;
		ll l[n],r[n],v[n];
		for(int i=0;i<n;i++)
		{
			cin>>l[i]>>r[i]>>v[i];
		}
		int count;
		for(int i=0;i<n-1;i++)
		{
			count=0;
			for(int j=i+1;j<n;j++)
			{
				if(l[j]<=l[i]&&r[j]>=l[i]||l[j]<=r[i]&&r[j]>=r[i]||l[j]>=l[i]||l[j]>=l[i]&&r[j]<=r[i]||l[j]<=l[i]&&r[j]>=r[i])
				{
					if(v[i]==v[j])count++;
				}
			}
			if(count==2)break;
		}
		if(count==2)cout<<"NO\n";
		else cout<<"YES\n";
	}
}
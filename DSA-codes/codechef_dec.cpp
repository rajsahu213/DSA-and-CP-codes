#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll add(string a,string b)
{
	ll count=0;
	bool flag=false;
	for(ll i=0;i<b.length();i++)
	{
		if(b[i]=='1'){flag=true;break;}
	}
	ll n;
	ll n1=a.length();
	ll n2=b.length();
	if(n1>n2)
	{
		b.insert(0,n1-n2,'0');
		n=n1;
	}
	else 
	{
		a.insert(0,n2-n1,'0');
		n=n2;
	}	
	while(flag)
	{
		flag=false;		
		for(ll i=0;i<n;i++)
		{
			char a1=a[i],b1=b[i];
			if(a[i]==b[i])a[i]='0';
			else a[i]='1';
			if(a1=='1'&&b1=='1'){b[i]='1';flag=true;}
			else b[i]='0';
		}
		b.append(1,'0');
		count++;
	}
	return count;
}

int main() 
{ 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;cin>>t;
	while(t--)
	{
		string a,b;cin>>a>>b;				
		cout<<add(a,b)<<endl;	
	}
	return 0;
}


// AGGVGBTABEBCDD
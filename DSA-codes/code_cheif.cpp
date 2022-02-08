#include <iostream>
#include<string>
using namespace std;
typedef long long int ll;

int main() 
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    while(t--)
    {
        ll n;cin>>n;
        string temp;
        for(ll i=0;i<n;i++)
        {
            string s;cin>>s;
            if(i!=0)
            {
                for(int j=0;j<10;j++)
                {
                	if(s[j]==temp[j])
                	{
                		temp[j]='1';
                	}
                	else
                	{
                		temp[j]='0';
                	}
                }
            }
            else temp=s;
        }
        int count=0;
        for(int i=0;i<10;i++)
        {
            if(temp[i]=='1')count++;
        }
        cout<<count<<endl;
    }
	return 0;
}

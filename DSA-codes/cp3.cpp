#include<iostream>
#include<vector>
#include<ctime>
#include<algorithm>
#include<limits>
using namespace std;
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long int ll;

bool check(vector<char> &v,char a)
{
    for(int i=0;i<v.size();i++)
    {
        if(v[i]==a)return true;
    }
    return false;
}

void permu(string s,vector<char> &v,int l)
{
    if(v.size()==s.length())
    {
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i];
        }
        cout<<endl;
    }
    else
    {
        for(int i=l;i<s.length();i++)
        {
            if(!check(v,s[l]))v.push_back(s[l]);
            permu(s,v,l+1);
            v.pop_back();
        }
    }
}


int main()
{
	clock_t tStart = clock();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;cin>>t;
	while(t--)
	{
		
	}
	printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	return 0;
}
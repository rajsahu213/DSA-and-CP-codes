#include<bits/stdc++.h>
using namespace std;

// void permu(string s,int l,int r)
// {
// 	if(l==r)
// 	{
// 		cout<<s<<endl;
// 	}
// 	else
// 	{
// 		for(int i=l;i<=r;i++)
// 		{
// 			swap(s[l],s[i]);
// 			permu(s,l+1,r);
// 			swap(s[l],s[i]);
// 		}
// 	}
// }

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
	cout<<"enter a string: ";
	string s;
	cin>>s;
	vector<char> v;
	permu(s,v,0);
}
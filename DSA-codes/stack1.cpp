#include<bits/stdc++.h>
using namespace std;

string reverse(string a)
{
	char temp;
	int j=a.length();
	j=j-1;
	int i=0;
	while(i<j)
	{
		temp=a[i];a[i]=a[j];a[j]=temp;
		i++;
		j--;
	}
	return a;
}

int main()
{
	cout<<"enter a string: ";
	string s;
	cin>>s;
	string a=reverse(s);
	if(a==s){cout<<"pali\n";}
	else{cout<<"not a pali\n";}
}
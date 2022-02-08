#include<bits/stdc++.h>
using namespace std;

int check(char a[])
{
	stack<char> s;
	int l=strlen(a);
	for(int i=0;i<l;i++)
	{
		if(a[i]=='['||a[i]=='('||a[i]=='{')
		{
			s.push(a[i]);
		}
		else if(a[i]==']'||a[i]==')'||a[i]=='}')
		{
			if(s.empty())
			{
				return 0;
			}
			else{
				s.pop();
			}
		}
	}
	if(s.empty()){return 1;}
	else{return 0;}
}

int main()
{
	cout<<"enter a string: ";
	char a[100];
	cin.getline(a,100);
	int flag=check(a);
	if(flag==0){cout<<"the string is not balanced\n";}
	else{
		cout<<"the string is balanced\n";
	}
}
#include<bits/stdc++.h>

using namespace std;

bool check2(char op,char cl)
{
    if(op=='['&&cl==']')return true;
    else if(op=='('&&cl==')')return true;
    else if(op=='{'&&cl=='}')return true;
    else return false;
}

int check(string a)
{
    stack<char> s;
    int l=a.length();
    for(int i=0;i<l;i++)
    {
        if(a[i]=='['||a[i]=='('||a[i]=='{')
        {
            s.push(a[i]);
        }
        else if(a[i]==']'||a[i]==')'||a[i]=='}')
        {
            if(s.empty()||!check2(s.top(),a[i]))
            {
                return 0;
            }
            else{
                s.pop();
            }
        }
    }
    if(s.empty())return 1;
    else return 0;
}

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
    string a;
    cin>>a;
	int flag=check(a);
	if(flag==0){cout<<"not balanced\n";}
	else {cout<<"balanced\n";}
    }
	return 0;
}
#include<bits/stdc++.h>
using namespace std;

int oper(int n1,char a,int n2)
{
    switch(a)
    {
        case '+':return n1+n2;
        case '-':return n1-n2;
        case '*':return n1*n2;
        case '/':return n1/n2;
    }
}

int check(queue<string> &q)
{
    int l=q.size(),flag=0;
    for(int i=0;i<l;i++)
    {
        string s=q.front();q.pop();
        if(s=="*"||s=="/")flag=1;
        q.push(s);
    }
    return flag;
}

int main()
{
    cout<<"enter the string: ";
    string s[20];
    int i=0;
    while(1)
    {
        cin>>s[i];
        if(s[i]=="break")break;
        i++;
    }
    queue<string> q;
    for(int j=0;j<i;j++)
    {
        q.push(s[j]);
    }
    string s1,s2,s3;
    int n1,n3;
    while(q.size()!=1)
    {
        s1=q.front();q.pop();
        //n1=stoi(s1);
        s2=q.front();q.pop();
        if(s2=="*"||s2=="/")
        {
            n1=stoi(s1);
            s3=q.front();q.pop();
            n3=stoi(s3);
            int result=oper(n1,s2[0],n3);
            string s4=to_string(result);
            q.push(s4);
        }
        else if(s2=="-"||s2=="+")
        {
            if(check(q))
            {
                q.push(s1);
                q.push(s2);
            }
            else
            {
                n1=stoi(s1);
                s3=q.front();q.pop();
                n3=stoi(s3);
                int result=oper(n1,s2[0],n3);
                string s5=to_string(result);
                q.push(s5);
            }
        }
        else
        {
            q.push(s1);
            q.push(s2);
        }
    }
    cout<<q.front()<<endl;
}
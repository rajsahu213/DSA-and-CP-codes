#include<bits/stdc++.h>
using namespace std;

struct x
{
    int a;
    int b;
    int c;
};

int main()
{
    cout<<"enter n: ";
    int n;cin>>n;
    cout<<"enter the numbers\n";
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    struct x t1,t2;
    t1.a=INT_MIN,t1.b=a[0],t1.c=INT_MAX;
    int i=1;
    queue<x> q;
    q.push(t1);
    while(i<n&&!q.empty())
    {
        t1=q.front();
        q.pop();
        if(a[i]>=t1.a&&a[i]<=t1.b)
        {
            t2.a=t1.a;
            t2.b=a[i];
            t2.c=t1.b-1;
            q.push(t2);
            i++;
        }
        if(i==n)break;
        if(a[i]>=t1.b&&a[i]<=t1.c)
        {
            t2.a=t1.b+1;
            t2.b=a[i];
            t2.c=t1.c;
            q.push(t2);
            i++;
        }
    }  
    if(i==n)cout<<"possible\n";
    else cout<<"not possible\n";   
}
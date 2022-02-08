#include<iostream>
#include<cstring>
#include<climits>
using namespace std;

struct stack
{
    int top;
    int element[50];
    int size;
};

void push(stack &s,int a)
{
    if(s.top==s.size-1)
    {
        cout<<"the stack is full\n";
    }
    else{
        s.top+=1;
        s.element[s.top]=a;
    }
}

int pop(stack &s)
{
    if(s.top==-1)
    {
        return -1;
    }
    else{
        return s.element[s.top--];
    }
}

int peek(stack &s)
{
    if(s.top==-1)
    {
        return -1;
    }
    else{
        return s.element[s.top];
    }
}

void sort(stack &s,int a[],int n)
{
    int temp,i=0;
    a[i++]=pop(s);
    while(i<n)
    {
        if(peek(s)<a[i-1]&&a[i]==-1)
        {
            a[i]=pop(s);
            i=1;
        }
        else if(peek(s)<a[i-1]&&a[i]!=-1)
        {
            i++;
        }
        else
        {
            temp=a[i-1];
            a[i-1]=pop(s);
            push(s,temp);
            i=1;
        }
    }   
    for(int i=0;i<n;i++)
    {
        push(s,a[i]);
    }
}

int main()
{
    struct stack s;
    s.top=-1;
    cout<<"enter the size of the stack( < 50 ) : ";
    cin>>s.size;
    cout<<"enter the numbers in the stack\n";
    int a[s.size];
    for(int i=0;i<s.size;i++)
    {
        int data;
        cin>>data;
        push(s,data);
        a[i]=-1;
    }
    sort(s,a,s.size);
    cout<<"the sorted stack is \n";
    while(s.top!=-1)
    {
        cout<<pop(s)<<endl;
    }
}
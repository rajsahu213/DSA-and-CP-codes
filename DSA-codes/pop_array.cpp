#include<iostream>
#include<cstring>
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

int main()
{
    struct stack s;
    s.top=-1;
    s.size=10;
    cout<<"enter the pop array \n";
    int a[6];
    for(int i=0;i<6;i++)
    {
        cin>>a[i];
    }
    int i=1;
    for(int j=0;j<6;j++)
    {
        if(a[j]>i)
        {
            while(i!=a[j])
            {
                push(s,i);
                i++;
            }
        }
        if(a[j]==i){
            push(s,i);
            cout<<pop(s)<<endl;
            i++;
        }
        else{
            cout<<pop(s)<<endl;
        }
    }
}
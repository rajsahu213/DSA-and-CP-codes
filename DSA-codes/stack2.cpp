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
    int a[6],temp[6];
    for(int i=0;i<6;i++)
    {
        cin>>a[i];
    }
    int i=1,j=0,k=0;
    while(j!=6)
    {
        if(a[j]>i)
        {
            push(s,i);
            i++;
        }
        else if(a[j]==i){
            push(s,i);
            temp[k++]=pop(s);
            i++;j++;
        }
        else{
            temp[k++]=pop(s);
            j++;
        }
    }
    int flag=1;
    for(int i=0;i<6;i++)
    {
        if(a[i]!=temp[i])
        {
            flag=0;
            break;
        }
    }
    if(flag==1)
    {
        cout<<"possible\n";
    }
    else{
        cout<<"not possible\n";
    }
}
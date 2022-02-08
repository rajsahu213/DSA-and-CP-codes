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

int oper(int a ,int b ,char c)
{
    switch(c)
    {
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
        case '/': return a/b;
        case '%': return a%b;
        default: break;
    }
}

int postfix(struct stack &s,char a[])
{
    int l=strlen(a);
    for(int i=0;i<l;i++)
    {
        int b=a[i];
        if(b<=57&&b>=48)
        {
            push(s,b-48);
        }
        else if(a[i]==' ')
        {
            push(s,-1);
        }
        else{
            int fact=1,n1=0;
            if(peek(s)==-1)pop(s);
            while(peek(s)!=-1)
            {
                n1=n1+fact*(pop(s));
                fact=fact*10;
            }
            pop(s);
            int fact1=1,n2=0;
            while(peek(s)!=-1)
            {
                n2=n2+fact1*(pop(s));
                fact1=fact1*10;
            }           
            int result=oper(n2,n1,a[i]);
            push(s,result);
        }
    }
    return peek(s);
}

int main()
{
    struct stack s;
    s.top=-1;
    s.size=40;
    cout<<"enter a string: ";
    char a[40];
    cin.getline(a,40);
    int result=postfix(s,a);
    cout<<"the result of the entered expresion is : "<<result<<endl;
}
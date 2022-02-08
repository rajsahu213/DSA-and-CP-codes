#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

union u
{
    int in;
    char ch; 
};

struct queue{
    int front;
    int rear;
    int size;
    int flag[50];
    union u element[50];  
};

void enqueue(queue &q,char x)
{
    if((q.rear+1)%q.size==q.front)
    {
        cout<<"the queue is full\n";
    }
    else{
        if(q.front==-1&&q.rear==-1)
        {
            q.front=q.rear=0;
        }
        else{
            q.rear=(q.rear+1)%q.size;
        }
        q.element[q.rear].ch=x;
    }
    q.flag[q.rear]=0;
}

void enqueue(queue &q,int x)
{
    if((q.rear+1)%q.size==q.front)
    {
        cout<<"the queue is full\n";
    }
    else{
        if(q.front==-1&&q.rear==-1)
        {
            q.front=q.rear=0;
        }
        else{
            q.rear=(q.rear+1)%q.size;
        }
        q.element[q.rear].in=x;
    }
    q.flag[q.rear]=1;
}

char dqueuechar(queue &q)
{
    q.flag[q.front]=-1;
    if(q.front==-1)
    {
        cout<<"the queue is empty\n";
    }
    else{
        char t=q.element[q.front].ch;
        if(q.front==q.rear)
        {
            q.front=q.rear=-1;
        }
        else{
            q.front=(q.front+1)%q.size;
        }
        return t;
    }
}

int dqueueint(queue &q)
{
    q.flag[q.front]=-1;
    if(q.front==-1)
    {
        cout<<"the queue is empty\n";
    }
    else{
        int t=q.element[q.front].in;
        if(q.front==q.rear)
        {
            q.front=q.rear=-1;
        }
        else{
            q.front=(q.front+1)%q.size;
        }
        return t;
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

int prefix(queue &q)
{
    char c;
    while(q.front!=q.rear)
    {
        if(q.flag[q.front]==0)
        {
            c=dqueuechar(q);
        }
        if(q.flag[q.front]==1&&q.flag[q.front+1]==1)
        {
            int n1=dqueueint(q);
            int n2=dqueueint(q);
            cout<<n1<<c<<n2<<endl;
            int result=oper(n1,n2,c);
            enqueue(q,result);
        }
        else if(q.flag[q.front]==1&&q.flag[q.front+1]==0&&c=='e')
        {
            enqueue(q,dqueueint(q));
        }
        else if(q.flag[q.front]==1&&q.flag[q.front+1]==0&&c!='e')
        {
            enqueue(q,c);
            enqueue(q,dqueueint(q));
        }
        else{
            enqueue(q,c);
        }
        c='e';
    }
    return dqueueint(q);
}

int main()
{
    queue q;
    q.front=q.rear=-1;
    q.size=40;
    cout<<"enter a string: ";
    char s[40];
    cin.getline(s,40);
    int l=strlen(s);
    for(int i=0;i<l;i++)
    {
        int b=s[i];
        if(b<=57&&b>=48)
        {
            enqueue(q,b-48);
        }
        else{
            enqueue(q,s[i]);
        }
    }
    int result=prefix(q);
    cout<<"the answer is: "<<result<<endl;
}
#include<iostream>
#include<cstring>
using namespace std;

struct queue{
    int size;
    char element[50];
    int front;
    int rear;
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
        q.element[q.rear]=x;
    }
}

char dqueue(queue &q)
{
    if(q.front==-1)
    {
        cout<<"the queue is empty\n";
    }
    else{
        char t=q.element[q.front];
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

void interleave(queue &q,int l)
{
    queue q1;
    q1.front=q1.rear=-1;
    q1.size=40;
    int mid;
    if(l%2==0)mid=l/2-1;
    else mid=l/2;
    for(int i=0;i<=mid;i++)
    {
        enqueue(q1,dqueue(q));
    }
    for(int i=0;i<l;i++)
    {
        if(i%2==0)
        {
            cout<<dqueue(q1);
        }
        else{
            cout<<dqueue(q);
        }
    }
    cout<<endl;
}

int main()
{
    struct queue q;
    q.front=q.rear=-1;
    q.size=40;
    string s;
    cout<<"Queue contents input: ";
    cin>>s;
    for(int i=0;i<s.length();i++)
    {
        enqueue(q,s[i]);
    }
    cout<<"Output: ";
    interleave(q,s.length());
}
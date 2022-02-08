#include<iostream>
#include<cstdlib>
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

struct queue{
    stack s1,s2;
    int front;
    int rear;
    int size;
};

void enqueue(queue &q,int x)
{
    if(q.rear==q.size-1)
    {
        cout<<"the queue is full\n";
    }
    else{
        if(q.front==-1)
        {
            q.front=q.rear=0;
        }
        else{
            q.rear++;
        }
        push(q.s1,x);
    }
}

int dqueue(queue &q)
{
    if(q.front==-1)
    {
        cout<<"the queue is empty\n";
    }
    else{
        for(int i=q.front;i<q.rear;i++)
        {
            push(q.s2,pop(q.s1));
        }
        int t=pop(q.s1);
        q.rear--;
        for(int i=q.front;i<=q.rear;i++)
        {
            push(q.s1,pop(q.s2));
        }
        return t;
    }
}

int main()
{
    int c;
    queue q;
    q.front=q.rear=-1;
    q.size=40;
    q.s1.top=q.s2.top=-1;
    q.s1.size=q.s2.size=40;
    do{
    cout<<"1: ENQUEUE\n";
    cout<<"2: DEQUEUE\n";
    cout<<"3: EXIT\n";
    cout<<"enter the choice: ";
    cin>>c;
    switch(c)
    {
        case 1: cout<<"enter a number: ";
                int data;cin>>data;
                enqueue(q,data);
                break;
        case 2: cout<<"the dequeued element is : "<<dqueue(q)<<endl;
                break;
        case 3: break;                          

    }

    }while(c!=3);
    cout<<"THANK YOU\n";
    return 0;
}

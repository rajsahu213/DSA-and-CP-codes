#include<iostream>
#include<cstring>
using namespace std;

struct queue{
    int size;
    int element[50];
    int front;
    int rear;
};

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
        q.element[q.rear]=x;
    }
}

int dqueue(queue &q)
{
    if(q.front==-1)
    {
        cout<<"the queue is empty\n";
    }
    else{
        int t=q.element[q.front];
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

struct stack
{
    queue q1,q2;
    int size;
    int top;
};

void push(stack &s,int a)
{
    if(s.top==s.size-1)
    {
        cout<<"the stack is full\n";
    }
    else{
        s.top++;
        enqueue(s.q1,a);
    }
}

int pop(stack &s)
{
    if(s.top==-1)
    {
        cout<<"the stack is empty\n";
        return -1;
    }
    else{
        for(int i=0;i<s.top;i++)
        {
            enqueue(s.q2,dqueue(s.q1));
        }
        int t=dqueue(s.q1);
        s.top--;
        for(int i=0;i<=s.top;i++)
        {
            enqueue(s.q1,dqueue(s.q2));
        }
        return t;
    }
}

int peek(stack &s)
{
    if(s.top==-1)
    {
        return -1;
    }
    else{
        for(int i=0;i<s.top;i++)
        {
            enqueue(s.q2,dqueue(s.q1));
        }
        int t=dqueue(s.q1);
        for(int i=0;i<s.top;i++)
        {
            enqueue(s.q1,dqueue(s.q2));
        }
        enqueue(s.q1,t);
        return t;
    }
}

int empty(stack &s)
{
    if(s.top==-1)
    {
        return 1;
    }
    else return 0;
}

int main()
{
    stack s;
    s.top=-1;
    s.size=40;
    s.q1.front=s.q1.rear=-1;
    s.q2.front=s.q2.rear=-1;
    s.q1.size=s.q2.size=40;
    int choice;
    do
    {
        cout<<"   ####STACK####    \n";
        cout<<"1: push\n";
        cout<<"2: pop\n";
        cout<<"3: top\n";
        cout<<"4: exit\n";
        cout<<"enter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1: cout<<"enter a number: ";
                    int data;cin>>data;
                    push(s,data);
                    break;
            case 2: cout<<"the poped out element is: "<<pop(s)<<endl;
                    break;
            case 3: cout<<"the top of the stack is : "<<peek(s)<<endl;
                    break;
            case 4: break;
            default: cout<<"wrong choice try again\n";              
        }

    }while(choice!=4);
    cout<<"THANK YOU\n";
    return 0;
}
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

int pali(queue &q,string s)
{
    int l=s.length();
    int mid=l/2;
    for(int i=0;i<mid;i++)
    {
        enqueue(q,s[i]);
    }
    int flag=1;
    if(l%2==0)
    {
        for(int i=l-1;i>=mid;i--)
        {
            if(s[i]!=dqueue(q))
            {
                flag=0;
                break;
            }
        }
    }
    else{
        for(int i=l-1;i>mid;i--)
        {
            if(s[i]!=dqueue(q))
            {
                flag=0;
                break;
            }
        }
    }
    return flag;
}

int main()
{
    struct queue q;
    q.front=q.rear=-1;
    q.size=40;
    string s;
    cout<<"enter a string: ";
    cin>>s;
    int flag=pali(q,s);
    if(flag==1)
    {
        cout<<"palindrome\n";
    }
    else cout<<"not a palindrome\n";
}
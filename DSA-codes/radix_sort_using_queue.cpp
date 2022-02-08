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

void radix_sort(queue q[],int a[],int n)
{
    int t=10,fact=1,k=0,y;
    while(t--)
    {
        k++;
        for(int i=0;i<n;i++)
        {
            int d=a[i],x;
            for(int j=0;j<k;j++)
            {
                x=d%10;
                d=d/10;
            }
            enqueue(q[x],a[i]);
        }
        y=0;
        for(int i=0;i<10;i++)
        {
            while(q[i].front!=-1)
            {
                a[y++]=dqueue(q[i]);
            }
        }
    }
}

int main()
{
    struct queue q[10];
    for(int i=0;i<10;i++)
    {
        q[i].front=q[i].rear=-1;
        q[i].size=40;
    }
    cout<<"enter the size of the array: ";
    int n;cin>>n;
    cout<<"enter the numbers\n";
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    radix_sort(q,a,n);
    cout<<"the sorted array is\n";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<endl;
    }
    return 0;
}
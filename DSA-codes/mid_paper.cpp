#include<bits/stdc++.h>
using namespace std;

struct btnode
{
	int data;
	btnode* lchild;
	btnode* rchild;
};

typedef struct btnode* btptr;

btptr creatnode(int a)
{
	if(a==-1)return NULL;
	btptr temp;
	temp=new btnode;
	temp->data=a;
	temp->lchild=temp->rchild=NULL;
	return temp;
}

btptr creat(btptr &t,int a[],int &i,int n)
{
	t=creatnode(a[i]);
	if(t==NULL||i>=n)return t;
	t->lchild=creat(t->lchild,a,++i,n);
	t->rchild=creat(t->rchild,a,++i,n);
	return t;
}

void level_order(btptr &t)
{
    queue<btptr> q;
    q.push(t);
    q.push(NULL);
    while(!q.empty())
    {
        if(q.front()==NULL)
        {
            cout<<endl;
            q.pop();
            if(q.empty())break;
            q.push(NULL);
        }
        btptr t1=q.front();
        cout<<t1->data<<" ";
        q.pop();
        if(t1->lchild!=NULL)q.push(t1->lchild);
        if(t1->rchild!=NULL)q.push(t1->rchild);
    }
}

//#QUESTION 1
// void level_order(btptr &t)
// {
//     queue<btptr> q;
//     queue<int> q1[30];
//     q.push(t);
//     q.push(NULL);
//     int i=0;
//     while(!q.empty())
//     {
//         if(q.front()==NULL)
//         {
//             cout<<endl;
//             i++;
//             q.pop();
//             if(q.empty())break;
//             q.push(NULL);
//         }
//         btptr t1=q.front();
//         q1[i].push(t1->data);
//         //cout<<t1->data<<" ";
//         q.pop();
//         if(t1->lchild!=NULL)q.push(t1->lchild);
//         if(t1->rchild!=NULL)q.push(t1->rchild);
//     }
//     int flag=0;
//     stack<int> s;
//     int k=i-1,j=0;
//     while(k>=j)
//     {
//         if(flag%2==0)
//         {
//             while(!q1[j].empty())
//             {
//                 cout<<q1[j].front()<<" ";
//                 q1[j].pop();
//             }
//             j++;
//         }
//         else
//         {
//             while(!q1[k].empty())
//             {
//                 s.push(q1[k].front());
//                 q1[k].pop();
//             }
//             while(!s.empty())
//             {
//                 cout<<s.top()<<" ";
//                 s.pop();
//             }
//             k--;
//         }
//         flag++;
//     }
// }

//#QUESTION 2
// bool search(btptr &t,int x)
// {
//     stack<btptr> s;
//     s.push(t);  
//     while(!s.empty())
//     {
//         btptr t1=s.top();
//         s.pop();
//         while(t1!=NULL)
//         {
//             if(t1->rchild!=NULL)s.push(t1->rchild);
//             if(t1->data==x)return true;
//             t1=t1->lchild;
//         }

//     }
//     return false;
// }

// void print(btptr &t,int x)
// {
//     while(t!=NULL)
//     {
//         if(search(t->lchild,x))
//         {
//             cout<<t->data<<" ";
//             t=t->lchild;
//         }
//         else if(search(t->rchild,x))
//         {
//             cout<<t->data<<" ";
//             t=t->rchild;
//         }
//         if(t->data==x)
//         {
//             break;
//         }
//     }
// }

struct node
{
    int data;
    node* next;
};
typedef struct node* lptr;

lptr insert(lptr &l,int n)
{
    if(l==NULL)
    {
        lptr temp;
        temp=new(node);
        temp->data=n;
        temp->next=NULL;
        l=temp;
    }
    else l->next=insert(l->next,n);
    return l;
}

int num(lptr &l,int n)
{
    lptr l1=l;
    for(int i=0;i<n;i++)
    {
        l1=l1->next;
    }
    return l1->data;
}

void creat(btptr &t,lptr &l,int i,int n)
{
    if(i>=n)return;
    else
    {
        t=creatnode(num(l,i));
        creat(t->lchild,l,2*i+1,n);
        creat(t->rchild,l,2*i+2,n);
    }
}

int main()
{
    // cout<<"enter n: ";
    // int n;cin>>n;
    // cout<<"enter the serialization: ";
    // int a[n];
    // for(int i=0;i<n;i++)cin>>a[i];
    btptr t=NULL;
    // int i=0;
    // creat(t,a,i,n);
    // // level_order(t);    
    // cout<<"enter x : ";
    // int x;cin>>x;
    // print(t,x);
    // cout<<endl;
    lptr l=NULL;
    while(1)
    {
        int data;
        cin>>data;
        if(data==-1)break;
        insert(l,data);
    }
    lptr l1=l;
    int n=0;
    while(l1!=NULL)
    {
        n++;
        l1=l1->next;
    }
    int i=0;
    creat(t,l,i,n);
    level_order(t);
}
#include<bits/stdc++.h>
using namespace std;
struct gtnode
{
	char data;
	int  cnt;
    bool visit;
	gtnode* cptr[50]; 
};
typedef struct gtnode* gtptr;
struct btnode{
    char data;
    btnode* lchild;
    btnode* rchild;
};
typedef struct btnode* btptr;
void level_order_bt(btptr &t)
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
gtptr creatnode(char a)
{
	if(a==')')return NULL;
	gtptr temp;
	temp=new gtnode;
	temp->data=a;
	temp->cnt=0;
    temp->visit=false;
	for(int i=0;i<50;i++){temp->cptr[i]=NULL;}
	return temp;
}
btptr creatnode_bt(char a)
{
    btptr temp;
    temp=new(btnode);
    temp->data=a;
    temp->lchild=temp->rchild=NULL;
    return temp;
}
gtptr creat(gtptr &t,int &i,string s)
{
	t=creatnode(s[i]);
	if(t==NULL||i>=s.length())return t;
	for(int j=0;j<30;j++)
	{
		t->cptr[j]=creat(t->cptr[j],++i,s);
		if(t->cptr[j]==NULL)break;
	}
	return t;
}
void level_order(gtptr &t)
{
    queue<gtptr> q;
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
        gtptr t1=q.front();
        cout<<t1->data<<" ";
        q.pop();
        for(int i=0;i<30;i++)
        {
        	if(t1->cptr[i]!=NULL)
        	{
        		t1->cnt++;
        		q.push(t1->cptr[i]);
        	}
        }
    }
}
void preorder(gtptr &t)
{
    if(t!=NULL)
    {
        cout<<t->data<<" ";
        for(int i=0;i<=t->cnt;i++)
        {
            preorder(t->cptr[i]);
        }
    }
}

bool search(btptr &t,char x)
{
    if(t==NULL)return false;
    if(t->data==x)return true;
    else return search(t->lchild,x)+search(t->rchild,x);
}
gtptr assign(gtptr &t,btptr &t1)
{
    if(t!=NULL)
    {
        t->cptr[0]=assign(t->cptr[0],t1);
        bool temp=false;
        temp=search(t1,t->data);
        if(!t->visit)t->visit=temp;
        for(int i=0;i<=t->cnt;i++)
        {
            t->cptr[i]=assign(t->cptr[i],t1);
        }
    }
    return t;
}
btptr creat_bt(gtptr &t,int &cn,btptr &root)
{
    if(t==NULL)return NULL;
    else if(t->cnt==0&&t->visit==false)
    {
        return creatnode_bt(t->data);
    }
    else if(t->cnt==0&&t->visit==true)
    {
        return NULL;
    }
    else
    {
        root=creatnode_bt(t->data);
        for(int i=0;i<t->cnt-1;i++)
        {
            if(root->lchild==NULL)root->lchild=creat_bt(t->cptr[i],cn,root->lchild);
            root->rchild=creat_bt(t->cptr[i+1],cn,root->rchild);
            if(root->lchild!=NULL&&root->rchild!=NULL)break;
        }
        if(root->lchild==NULL&&root->rchild==NULL)return NULL;
    }
    return root;
}

int main()
{
    cout<<"enter a string : ";//abf)g)z)y))ci)j)v))dhk)l)m))s)p))en)r)))
    string s;
    cin>>s;
    gtptr t=NULL;
    int i=0;
    creat(t,i,s);
    cout<<"the breadth first traversal is  \n";
    level_order(t);
    btptr bt[10];int it=0;
    while(1)
    {
        int k=0;
        bt[it]=creat_bt(t,k,bt[it]);
        if(bt[it]==NULL)break;
        t=assign(t,bt[it]);
        it++;
    }
    for(int i=0;i<it;i++)
    {
        level_order_bt(bt[i]);
    }
}
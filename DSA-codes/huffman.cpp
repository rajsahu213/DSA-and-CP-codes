#include<bits/stdc++.h>
using namespace std;

struct node
{
	int f;
	char ch;
	struct node* lchild;
	struct node* rchild;
};

typedef struct node* hptr;

hptr creatnode(int f,char c)
{
	hptr temp=new node;
	temp->f=f;
	temp->ch=c;
	temp->lchild=temp->rchild=NULL;
	return temp;
}

struct comp
{
	bool operator()(hptr lhs,hptr rhs)
	{
		return lhs->f>rhs->f;
	}
};

void encode(hptr &t,char x,string s)
{
	if(t!=NULL)
	{
		if(t->ch==x)
		{
			cout<<s<<endl;
		}
		encode(t->lchild,x,s+"0");
		encode(t->rchild,x,s+"1");
	}
}

void level_order(hptr &t)
{
    queue<hptr> q;
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
        hptr t1=q.front();
        cout<<t1->ch<<" "<<t1->f<<"\t";
        q.pop();
        if(t1->lchild!=NULL)q.push(t1->lchild);
        if(t1->rchild!=NULL)q.push(t1->rchild);
    }
}

void decode(hptr &t,string s,int &i)
{
	if(t!=NULL)
	{
		if(i==s.length())
		{
			cout<<t->ch<<" "<<t->f<<endl;
		}
		if(s[i]=='0')decode(t->lchild,s,++i);
		else decode(t->rchild,s,++i);
	}
}

int main()
{
	cout<<"enter n: ";
	int n;cin>>n;
	cout<<"character and frequency respectively\n";
	hptr t[n]={NULL};
	for(int i=0;i<n;i++)
	{
		char ch;int f;
		cin>>ch>>f;
		t[i]=creatnode(f,ch);
	}
	priority_queue<hptr,vector<hptr>,comp> pq;
	for(int i=0;i<n;i++)
	{
		pq.push(t[i]);
	}
	while(pq.size()!=1)
	{
		hptr t1=pq.top();
		pq.pop();
		hptr t2=pq.top();
		pq.pop();
		hptr t3=creatnode(t1->f+t2->f,'#');
		t3->lchild=t1;
		t3->rchild=t2;
		pq.push(t3);
	}
	hptr root=pq.top();
	pq.pop();
	level_order(root);
	cout<<"enter the character: ";
	char x;cin>>x;
	string s;
	encode(root,x,s);
	cout<<"enter the code: ";
	string cd;cin>>cd;int i=0;
	decode(root,cd,i);
}	
#include<bits/stdc++.h>
using namespace std;

struct gtnode
{
	char data;
	int hd;
	int  cnt;
	int ht;
	gtnode* cptr[50]; 
};

typedef struct gtnode* gtptr;

gtptr creatnode(char a)
{
	if(a==')')return NULL;
	gtptr temp;
	temp=new gtnode;
	temp->data=a;
	temp->cnt=0;
	for(int i=0;i<50;i++){temp->cptr[i]=NULL;}
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

void level_order(gtptr &t,int &ht)
{
    queue<gtptr> q;
    q.push(t);
    q.push(NULL);
    while(!q.empty())
    {
        if(q.front()==NULL)
        {
        	ht++;
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

int height(gtptr &t,int &ht)
{
    queue<gtptr> q;
    q.push(t);
    q.push(NULL);
    while(!q.empty())
    {
        if(q.front()==NULL)
        {
        	ht++;
            cout<<endl;
            q.pop();
            if(q.empty())break;
            q.push(NULL);
        }
        gtptr t1=q.front();
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
    return ht-1;
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

void creat_level(gtptr &t)
{
	queue<gtptr> q;
	char a;
	cin>>a;
	t=creatnode(a);
	q.push(t);
	gtptr t1;
	while(!q.empty())
	{
		t1=q.front();
		q.pop();
		int n;cin>>n;
		for(int i=0;i<n;i++)
		{
			char data;
			cin>>data;
			t1->cptr[i]=creatnode(data);
			q.push(t1->cptr[i]);
		}
	}
}

void inorder(gtptr &t)
{
	if(t!=NULL)
	{
		inorder(t->cptr[0]);
		cout<<t->data<<" ";
		for(int i=1;i<=t->cnt;i++)
		{
			inorder(t->cptr[i]);
		}
	}
}

void postorder(gtptr &t)
{
	if(t!=NULL)
	{
		for(int i=0;i<=t->cnt;i++)
		{
			postorder(t->cptr[i]);
		}
		cout<<t->data<<" ";
	}
}

void set_hd(gtptr &t,int &hd)
{
	if(t!=NULL)
	{
		set_hd(t->cptr[0],hd);
		t->hd=hd++;
		for(int i=1;i<=t->cnt;i++)
		{
			set_hd(t->cptr[i],hd);
		}
	}
}

void print_gt(gtptr &t)
{
    queue<gtptr> q;
    q.push(t);
    q.push(NULL);
    int start=0;
    while(!q.empty())
    {
        if(q.front()==NULL)
        {
            cout<<endl;
            q.pop();
            if(q.empty())break;
            q.push(NULL);
            start=0;
        }
        gtptr t1=q.front();
        for(int i=start;i<t1->hd;i++)cout<<" ";
        cout<<t1->data;
    	start=t1->hd+1;
        q.pop();
        for(int i=0;i<=t1->cnt;i++)
        {
        	if(t1->cptr[i]!=NULL)
        	{
        		q.push(t1->cptr[i]);
        	}
        }
    }
}

void print_kth(gtptr &t,int k)
{
	if(t!=NULL)
	{
		if(k==0)
		{
			cout<<t->data<<" ";
		}
		for(int i=0;i<=t->cnt;i++)
		{
			print_kth(t->cptr[i],k-1);
		}
	}
}

int main()
{
	cout<<"enter a string : ";
	string s;
	cin>>s;
	gtptr t=NULL;
	int i=0;
	creat(t,i,s);
	//creat_level(t);
	cout<<"the breadth first traversal is  \n";
	int ht=0;
	level_order(t,ht);
	cout<<"the depth first traversal is \n";
	preorder(t);
	cout<<endl
	int hd=0;
	inorder(t);
	cout<<endl;
	set_hd(t,hd);
	print_gt(t);
	cout<<endl;
	//KTH NODE FROM ROOT
	cout<<"enter k: ";
	int k;cin>>k;
	print_kth(t,k);
	int l=0;
	cout<<endl;
}
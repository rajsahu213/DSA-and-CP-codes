#include<bits/stdc++.h>
using namespace std;

struct gtnode
{
	char data;
	int num;
	gtnode* cptr[27]; 
};

typedef struct gtnode* gtptr;

gtptr creatnode(char a)
{
	gtptr temp;
	temp=new gtnode;
	temp->data=a;
	for(int i=0;i<27;i++){temp->cptr[i]=NULL;}
	return temp;
}
gtptr creatnode1(int a)
{
	gtptr temp;
	temp=new gtnode;
	temp->num=a;
	temp->data='$';
	for(int i=0;i<27;i++){temp->cptr[i]=NULL;}
	return temp;
}

gtptr creat_trie(gtptr &t,int &i,string s,int num)
{
	if(t==NULL&&i<s.length())
	{
		t=creatnode(s[i++]);
	}
	if(t->cptr[27]==NULL&&i==s.length())
	{
		t->cptr[27]=creatnode1(num);
	}
	for(int j=0;j<26;j++)
	{
		if(j==(s[i]-'a'))
		{
			if(t->cptr[j]!=NULL)i++;
			t->cptr[j]=creat_trie(t->cptr[j],i,s,num);
			break;
		}
	}
	return t;
}

void print(char a[],int nu,int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<nu;
	cout<<endl;
}
bool is_leaf(gtptr &t)
{
	for(int i=0;i<27;i++)
	{
		if(t->cptr[i]!=NULL)
		{
			return false;
		}
	}
	return true;
}
void print_path(gtptr &t,char a[],int i)
{
	if(t!=NULL)
	{
		if(t->cptr[27]!=NULL)
		{
			int nu=t->num;
			a[i++]=t->data;
			print(a,nu,i);
		}
		else a[i++]=t->data;
		for(int j=0;j<26;j++)
		{
			print_path(t->cptr[j],a,i);
		}
	}
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
        if(t1->data=='$')cout<<t1->num<<" ";
        else cout<<t1->data<<" ";
        q.pop();
        for(int i=0;i<27;i++)
        {
        	if(t1->cptr[i]!=NULL)
        	{
        		q.push(t1->cptr[i]);
        	}
        }
    }
}

int main()
{
	cout<<"enter n: ";
	int n;cin>>n;
	string s[n];
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>s[i]>>a[i];
	}
	gtptr t=NULL;
	t=creatnode('#');
	for(int i=0;i<n;i++)
	{
		int k=0;
		t=creat_trie(t,k,s[i],a[i]);
	}
	level_order(t);
	char b[30];
	int i=0;
	print_path(t,b,i);
}
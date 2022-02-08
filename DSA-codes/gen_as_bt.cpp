#include<bits/stdc++.h>
using namespace std;

struct gtnode
{
	char data;
	gtnode *fc;
	gtnode *ns;
};

typedef struct gtnode* gtptr;

gtptr creatnode(char a)
{
	if(a==')')return NULL;
	gtptr temp;
	temp=new gtnode;
	temp->data=a;
	temp->fc=temp->ns=NULL;
	return temp;
}

void creat(gtptr &t)
{
	char data;cin>>data;
	t=creatnode(data);
	//cout<<"do "<<t->data<<" have a first child?(y/n) : ";
	char fst;cin>>fst;
	if(fst=='y')
	{
		creat(t->fc);
	}
	//cout<<"do "<<t->data<<" have a next sibiling?(y/n) : ";
	char a;cin>>a;
	if(a=='y')
	{
		creat(t->ns);
	}
}

void print(gtptr &t)
{
	if(t!=NULL)
	{
		cout<<t->data<<" ";
		print(t->fc);
		print(t->ns);
	}
}

void print1(gtptr &t,int i)
{
	if(t!=NULL)
	{
		for(int k=0;k<i;k++)cout<<" ";
		cout<<t->data<<endl;
		print1(t->fc,i+1);
		print1(t->ns,i);
	}
}

void print2(gtptr &t)
{
	while(t!=NULL)
	{
		cout<<t->data<<" ";
		t=t->ns;
	}
}

void print_siblings(gtptr &t,char x)
{
	static stack<gtptr> s;
	if(t!=NULL)
	{
		if(t->data==x){
			if(!s.empty()){
			gtptr t1=s.top();
			print2(t1);
			return;}
			else cout<<t->data<<" ";
		}
		if(t->fc!=NULL)s.push(t->fc);
		print_siblings(t->fc,x);
		if(t->ns==NULL)s.pop();
		print_siblings(t->ns,x);
	}
}

int main()
{
	cout<<"GENERAL TREE AS BINARY TREE\n";
	cout<<"enter the data\n";
	gtptr t=NULL;
	creat(t);
	print(t);
	cout<<endl;
	int i=0;
	//print1(t,i);
	cout<<"enter data: ";
	char data;cin>>data;
	print_siblings(t,data);
	cout<<endl;
}
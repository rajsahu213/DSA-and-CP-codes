#include<bits/stdc++.h>
using namespace std;

struct dlnode{
	int data;
	dlnode *left;
	dlnode *right;
};

typedef struct dlnode* dptr;

void insert_at_end(dptr &d,int data)
{
	dptr t;
	t=new(dlnode);
	t->data=data;
	t->right=NULL;
	if(d==NULL)
	{
		t->left=d;
		d=t;
	}
	else{
		dptr t1=d;
		while(t1->right!=NULL)
		{
			t1=t1->right;
		}
		t->left=t1;
		t1->right=t;
	}
}

void display(dptr &d)
{
	if(d==NULL)
	{
		cout<<"the list is empty\n";
	}
	else{
		dptr t=d;
		cout<<"the list is: ";
		while(t!=NULL)
		{
			cout<<t->data<<" ";
			t=t->right;
		}
		cout<<endl;
	}
}

void creat(dptr &d,int k)
{
	int max=INT_MIN,a;
	dptr t=d,t1=d;
	while(t1->right!=NULL)
	{
		a=k;
		while((a--)&&t1!=NULL)
		{
			if(t1->data>max){max=t1->data;}
			t1=t1->right;
		}
		cout<<max<<" ";
		if(t1==NULL){break;}
		t=t->right;
		t1=t;
		max=t->data;
	}
}

int main()
{
	dptr d=NULL;
	cout<<"enter the numbers(-1 to stop): ";
	while(1)
	{
		int data;cin>>data;
		if(data==-1)break;
		insert_at_end(d,data);
	}
	cout<<"enter k: ";
	int k;cin>>k;
	creat(d,k);	
	cout<<endl;
}
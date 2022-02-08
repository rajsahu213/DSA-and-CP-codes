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

void insert_at_big(dptr &d,int data)
{
	dptr t;
	t=new(dlnode);
	t->data=data;
	t->left=NULL;
	if(d==NULL)
	{
		t->left=d;
		d=t;
	}
	else{
		t->right=d;
		d->left=t;
		d=t;
	}

}

void add(dptr &d1,dptr &d2,dptr &d3)
{
	dptr t1=d1,t2=d2;
	while(t1->right!=NULL)
	{
		t1=t1->right;
	}
	while(t2->right!=NULL)
	{
		t2=t2->right;
	}
	int sum,carry=0;
	while(t1!=NULL&&t2!=NULL)
	{
		sum=t1->data+t2->data;
		if(sum>=10)
		{
			insert_at_big(d3,sum-10+carry);
			carry=1;
		}
		else{
			insert_at_big(d3,sum+carry);
			carry=0;
		}
		t1=t1->left;
		t2=t2->left;
	}
	while(t1!=NULL)
	{
		sum=t1->data+carry;
		if(sum>=10)
		{
			insert_at_big(d3,sum-10+carry);
			carry=1;
		}
		else{
			insert_at_big(d3,sum+carry);
			carry=0;
		}
		t1=t1->left;
	}
	while(t2!=NULL)
	{
		sum=t2->data+carry;
		if(sum>=10)
		{
			insert_at_big(d3,sum-10+carry);
			carry=1;
		}
		else{
			insert_at_big(d3,sum+carry);
			carry=0;
		}
		t2=t2->left;
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

int main()
{
	dptr d1=NULL,d2=NULL,d3=NULL;
	cout<<"enter the first number(-1 to stop): ";
	while(1)
	{
		int data;cin>>data;
		if(data==-1)break;
		insert_at_end(d1,data);
	}
	cout<<"enter the second number: ";
	while(1)
	{
		int data;cin>>data;
		if(data==-1)break;
		insert_at_end(d2,data);
	}
	add(d1,d2,d3);
	display(d3);	
}
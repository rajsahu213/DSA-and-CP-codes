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
	t= new(dlnode);
	t->data=data;
	t->right=NULL;
	t->left=NULL;
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
	t= new(dlnode);
	t->data=data;
	t->left=NULL;
	if(d==NULL)
	{
		t->left=d;
		d=t;
	}
	else{
		d->left=t;
		t->right=d;
		d=t;
	}
}

void rev_print(dptr &d)
{
	static dptr t=d;
	if(d->right!=NULL)
	{
		t=t->right;
		rev_print(d->right);
	}
	cout<<t->data<<" ";
	t=t->left;
}

void insertion_after(dptr &d,int data)
{
	cout<<"enter the element: ";
	int x;cin>>x;
	dptr t;
	t= new(dlnode );
	t->data=data;
	t->left=NULL;
	t->right=NULL;
	if(d->data==x)
	{
		t->left=d;
		t->right=d->right;
		d->right=t;
	}
	else{
		dptr t1=d;
		while(t1!=NULL)
		{
			if(t1->data==x)
			{
				t->left=t1;
				t->right=t1->right;
				t1->right=t;
				break;
			}
			else{
				t1=t1->right;
			}
		}
	}
}

void insertion_before(dptr &d,int data)
{
	cout<<"enter the element: ";
	int x;cin>>x;
	dptr t;
	t= new(dlnode );
	t->data=data;
	t->left=NULL;
	t->right=NULL;
	if(d->data==x)
	{
		d->left=t;
		t->right=d;
		d=t;
	}
	else{
		dptr t1=d;
		while(t1->right!=NULL)
		{
			if(t1->right->data==x)
			{
				t->left=t1;
				t->right=t1->right;
				t1->right=t;
				break;
			}
			else{
				t1=t1->right;
			}
		}
	}
}

void deletion(dptr &d,int x)
{
	dptr t1=d,t2=d->right;
	if(d->data==x)
	{
		d=d->right;
		d->left=NULL;
		free(t1);
	}
	else{
		while(t2!=NULL)
		{
			if(t2->data==x)
			{
				if(t2->right==NULL)
				{
					t1->right=NULL;
					t2->left=NULL;
					free(t2);
					break;
				}
				else{
					t2->right->left=t1;
					t1->right=t2->right;
					free(t2);
					break;
				}
			}
			else{
				t1=t1->right;
				t2=t2->right;
			}
		}
	}
}

void deletion_before(dptr &d,int x)
{
	dptr t1=d,t2=d->right;
	if(d->right==NULL)return;
	if(d->right->data==x)
	{
		d=d->right;
		d->left=NULL;
		free(t1);
	}
	else{
		while(t2->right!=NULL)
		{
			if(t2->right->data==x)
			{
				t2->right->left=t1;
				t1->right=t2->right;
				free(t2);
				break;
			}
			else{
				t1=t1->right;
				t2=t2->right;
			}
		}
	}
}

void deletion_after(dptr &d,int x)
{
	dptr t1=d,t2=d->right;
	if(d->right==NULL)return;
	if(d->data==x&&t2->right!=NULL)
	{
		t2->right->left=d;
		d->right=t2->right;
		free(t2);
	}
	else{
		while(t2->right!=NULL)
		{
			if(t1->right->data==x)
			{
				t2->right->left=t1;
				t1->right=t2->right;
				free(t2);
				break;
			}
			else{
				t1=t1->right;
				t2=t2->right;
			}
		}
	}
}

void reverse(dptr &d)
{
	dptr prev=d,next=d->right->right,curr=d->right;
	prev->left=curr;
	curr->right=prev;
	prev->right=NULL;
	prev=curr;
	curr=next;
	while(curr->right!=NULL)
	{
		next=curr->right;
		prev->left=curr;
		curr->right=prev;
		prev=curr;
		curr=next;
	}
	prev->left=curr;
	curr->right=prev;
	curr->left=d;
	d=curr;
}

void display_reverse(dptr &d)
{
	if(d->right!=NULL)
	{
		display_reverse(d->right);
	}
	cout<<d->data<<" ";
}

void display(dptr &d)
{
	if(d==NULL)
	{
		cout<<"the list is empty\n";
	}
	else{
		dptr t=d;
		cout<<"the list is : ";
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
	dptr d=NULL;
	cout<<"enter the data ( or -1 to stop )\n";
	while(1)
	{
		cout<<"enter a number: ";
		int data;cin>>data;
		if(data==-1)break;
		insert_at_end(d,data);
	}
	// for(int i=0;i<3;i++)
	// {
	// 	cout<<"enter a num: ";
	// 	int n;cin>>n;
	// 	deletion_after(d,n);
	// 	display(d);
	// }
	rev(d);
	rev_print(d);
	cout<<endl;
}
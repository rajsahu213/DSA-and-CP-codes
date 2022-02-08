#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node* next;
};

typedef struct node* lptr;

lptr creatnode(int data)
{
	lptr temp;
	temp=new node;
	temp->data=data;temp->next=NULL;
	return temp;
}

lptr insert_at_end(lptr &l,int data)
{
	if(l==NULL)l=creatnode(data);
	else l->next=insert_at_end(l->next,data);
	return l;
}

void insert_at_big(lptr &l,int data)
{
	lptr temp=creatnode(data);
	temp->next=l;
	l=temp;
}

lptr delete_ll(lptr &l,int x)
{
	if(l->data==x)return l->next;
	else l->next=delete_ll(l->next,x);
	return l;
}

void display(lptr &l)
{
	if(l!=NULL)
	{
		cout<<l->data<<" ";
		display(l->next);
	}
}

bool pres(int a[],int n,int x)
{
	for(int i=0;i<n;i++)
	{
		if(a[i]==x)
		{
			return true;
		}
	}
	return false;
}

void remove_dupli(lptr &l)
{
	lptr l1=l;
	int a[50],i=0;
	while(l1!=NULL)
	{
		if(pres(a,i,l1->data))
		{
			int temp=l1->data;
			l1=l1->next;
			l=delete_ll(l,temp);
		}
		else
		{
			a[i++]=l1->data;
			l1=l1->next;
		}
	}
}

lptr merge(lptr l,lptr l1,lptr l2)
{
	if(l1==NULL&&l2==NULL)return NULL;
	if(l2==NULL)
	{
		l=creatnode(l1->data);
		l->next=merge(l->next,l1->next,l2);
	}	
	else if(l1==NULL)
	{
		l=creatnode(l2->data);
		l->next=merge(l->next,l1,l2->next);
	}	
	else if(l1->data<l2->data)
	{
		l=creatnode(l1->data);
		l->next=merge(l->next,l1->next,l2);
	}
	else if(l2->data<l1->data)
	{
		l=creatnode(l2->data);
		l->next=merge(l->next,l1,l2->next);
	}	
	else
	{
		l=creatnode(l1->data);
		l->next=merge(l->next,l1->next,l2->next);
	}
	return l;
}

lptr reverse(lptr prev,lptr curr,lptr nex)
{
	if(curr==NULL)return prev;
	curr->next=prev;
	if(nex!=nullptr)reverse(curr,nex,nex->next);
	else reverse(curr,nex,nex);
}

int main()
{
	lptr l=NULL;
	int n1=0,n2=0;
	while(1)
	{
		int data;cin>>data;
		if(data==-1)break;
		l=insert_at_end(l,data);
		n1++;
	}
	display(l);
	cout<<endl;
	// lptr l2=NULL;
	// while(1)
	// {
	// 	int data;cin>>data;
	// 	if(data==-1)break;
	// 	l2=insert_at_end(l2,data);
	// 	n2++;
	// }
	// display(l2);
	// cout<<endl;	
	// lptr l=NULL;
	// l=merge(l,l1,l2);
	// display(l);cout<<endl;
	// l=reverse(NULL,l,l->next);
	// display(l);cout<<endl;
}
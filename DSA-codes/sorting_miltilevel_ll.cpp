#include <iostream>
using namespace std;
struct mlnode{
	int data;
	struct mlnode *dlink;
	struct mlnode *next; 
};
typedef struct mlnode *LPTR;
void add_down(LPTR &h,int num)
{
	if(num==0)
		return;
	else
	{
		h=new struct mlnode;
		cin>>h->data;
		h->next=NULL;
		h->dlink=NULL;
		add_down(h->dlink,num-1);
	}
}
void add(LPTR &l,int x)
{
	if(x==0)
		return;
	else
	{
		l=new struct mlnode;
		char ch;
		cin>>l->data;
		cout<<"y for want a downlink n for not:";
		cin>>ch;
		if(ch=='n')
		{
			l->dlink=NULL;
			l->next=NULL;
			add(l->next,x-1);
		}
		else if(ch=='y')
		{
			int n;
			cout<<"no of elements in downlink:";
			cin>>n;
			l->next=NULL;
			l->dlink=NULL;
			add_down(l->dlink,n);
			add(l->next,x-1);
		}
	}
}
void flatten_end(LPTR &h,LPTR temp)
{
	if(h->dlink==NULL)
	{
		h->dlink=temp;
	}
	else
	{
		flatten_end(h->dlink,temp);
	}
}
void final(LPTR &l)
{
	if(l==NULL)
		return;
	else
	{
		if(l->dlink!=NULL)
		{
			LPTR tmp=l->next;
			l->next=NULL;
			flatten_end(l->dlink,tmp);
			final(tmp);
		}
		else
		{
			//  cout<<l->data<<endl;
			final(l->next);
		}
	}
}

void print(LPTR &l)
{
	if(l==NULL)
		return;
	else
	{
		if(l->dlink!=NULL)
		{
			cout<<l->data<<" ";
			print(l->dlink);
		}
		else
		{
			cout<<l->data<<" ";
			print(l->next);
		}
	}
}

void swap(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}

void sort2(LPTR &l)
{
	if(l==NULL || l->dlink==NULL) return;
	else
	{
		if(l->data>l->dlink->data)
		swap(l->data,l->dlink->data);
		sort2(l->dlink);
	}
}
void sort(LPTR &m)
{
	if(m==NULL || m->next==NULL) return;
	else{
		LPTR h=m;
		LPTR temp=h->next;
		while(h->dlink!=NULL){
			if(h->dlink->data>=temp->data){
				swap(h->dlink->data,temp->data);
				h=h->dlink;
			}
			else break;
		}
		sort2(m);
		sort(m->next);
	}
}
int main()
{
	int z;
	cin>>z;
	LPTR l=NULL;
	add(l,z);
	sort(l);
	final(l);
	print(l);
}
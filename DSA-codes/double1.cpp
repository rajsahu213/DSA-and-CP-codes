#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node *next;
	node *pre;
};

node *start=NULL;

void insert_node_at_end()
{
	node *temp,*t;
	temp=(node*)new(node);
	cout<<"enter a number: ";
	cin>>temp->data;
	temp->next=NULL;
	if(start==NULL)
	{
		temp->pre=start;
		start=temp;
	}
	else{
		t=start;
		while(t->next!=NULL)
		{
			t=t->next;
		}
		temp->pre=t;
		t->next=temp;
	}

}

void insert()
{
	cout<<"enter a number: ";
	node *temp,*t;
	temp=(node*)new(node);
	cin>>temp->data;
	cout<<"enter element: ";
	int x;cin>>x;
	t=start;
	while(t!=NULL)
	{
		if(t->data==x)
		{
			temp->pre=t;
			temp->next=t->next;
			t->next=temp;
			t->next->pre=temp;
			break;
		}
		else{
			t=t->next;
		}
	}
}

void insert_node_at_big()
{
	node *temp;
	temp=(node*)new(node);
	cout<<"enter a number: ";
	cin>>temp->data;
	temp->pre=NULL;
	temp->next=start;
	start=temp;
}

void deletion()
{
	node *t1,*t2;
	cout<<"enter the number you want to delete: ";
	int x;cin>>x;
	t1=start;
	t2=start->next;
	if(t1->data==x)
	{
		t2->pre=start;
		start=t2;
	}
	else{
		while(t1!=NULL)
		{
			if(t2->data==x)
			{
				if(t2->next==NULL)
				{
					t1->next=NULL;
					t2->pre=NULL;
					break;
				}
				else{
				t2->next->pre=t1;
				t1->next=t2->next;
				break;
			}
			}
			else{
				t1=t1->next;
				t2=t2->next;
			}
		}
	}
}

void display()
{
	node *t;
	if(start==NULL)
	{
		cout<<"the list is empty\n";
	}
	else{
		t=start;
		cout<<"the list is: ";
		while(t!=NULL)
		{
			cout<<t->data<<"   ";
			t=t->next;
		}
		cout<<endl;
	}
}


int main()
{
	int n;
	cout<<"enter n: ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		insert_node_at_big();
		display();
	}
	//insert();
	for(int i=0;i<3;i++){
	deletion();
	display();
	}
}
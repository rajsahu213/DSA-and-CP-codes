#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *pre;
	node *next;
};

node *start=NULL;

void insert_node_at_beg()
{
	node *temp;
	temp=(node*)new(node);
	cout<<"enter a number: ";
	cin>>temp->data;
	temp->pre=NULL;
	temp->next=start;
	start=temp;

}

void display()
{
	node *t;
	if(start==NULL)
	{
		cout<<"list is empty\n";
	}
	else {
		t=start;
		cout<<"the list is\n";
		while(t!=NULL)
		{
			cout<<t->data<<endl;
			t=t->next;
		}
		cout<<endl;
	}
}

int main()
{
	cout<<"enter n: ";
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		insert_node_at_beg();
	}
	cout<<start->data<<endl;
	display();
	return 0;
}
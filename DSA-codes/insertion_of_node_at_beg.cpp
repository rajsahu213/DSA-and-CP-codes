#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node *next;
};

node *start=NULL;

node *creatnode()
{
	node *n;
	n=(node*)new(node);
	return n;
}

void insertnode()
{
	node *temp;
	temp=creatnode();
	cout<<"enter a number: ";
	cin>>temp->data;
	if(start==NULL)
	{
		start=temp;
		temp->next=NULL;
	}
	else
	{
		temp->next=start;
		start=temp;
	}
}

void display()
{
	node *t;
	if(start==NULL)
	{
		cout<<"list is empty\n";
	}
	else
	{
		t=start;
		cout<<"the list is: ";
		while(t!=NULL)
		{
			cout<<t->data<<"    ";
			t=t->next;
		}
		cout<<endl;
	}
}

int main()
{
 	cout<<"enter n: ";
 	int n;cin>>n;
 	for(int i=0;i<n;i++)
 	{
 		insertnode();
 		display();
 	}
 	return 0;
}
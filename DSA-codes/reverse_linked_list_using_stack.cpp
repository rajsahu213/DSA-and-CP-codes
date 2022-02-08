
#include<iostream>
#include<stack>
using namespace std;

struct node{
	int data;
	node *next;
};

node *start=NULL;

void insert()
{
	node *temp;
	temp=(node*)new(node);
	cout<<"enter a number: ";
	cin>>temp->data;
	temp->next=start;
	start=temp;
}

void reverse()
{
	stack<node*> s;
	node *t;
	t=start;
	while(t!=NULL)
	{
		s.push(t);
		t=t->next;
	}
	start=s.top();
	node *t1;
	t1=s.top();
	while(!s.empty())
	{
		s.pop();
		if(s.empty())
		{
			t1->next=NULL;
		}
		else{
			t1->next=s.top();
			t1=t1->next;
		}
	}

}

void display()
{
	node *t;
	t=start;
	cout<<"the list is: ";
	while(t!=NULL)
	{
		cout<<t->data<<"   ";
		t=t->next;
	}
	cout<<endl;
}

int main()
{
	cout<<"enter n: ";
	int n;cin>>n;
	for(int i=0;i<n;i++)
	{
		insert();
	}
	display();
	reverse();
	display();
}
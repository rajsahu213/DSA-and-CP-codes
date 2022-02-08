#include<iostream>
using namespace std;

struct node{
	int data;
	node *next;
};

node *start=NULL;

void enqueue(int data)
{
	node *temp;
	temp=(node*)new(node);
	temp->data=data;
	temp->next=start;
	start=temp;
}

void dequeue()
{
	if(start==NULL)
	{
		cout<<"the queue is empty\n";
	}
	else{
		node *t1,*t2;
		t1=start;
		t2=start->next;
		while(t2->next!=NULL)
		{
			t1=t1->next;
			t2=t2->next;
		}
		cout<<"the deleted number is: "<<t2->data<<endl;
		t1->next=NULL;
		free(t2);
	}
}

int peek()
{
	if(start==NULL)
	{
		cout<<"the queue is empty\n";
	}
	else{
		node *t;
		t=start;
		while(t->next!=NULL)
		{
			t=t->next;
		}
		return t->data;
	}
}

void display()
{
	if(start==NULL)
	{
		cout<<"the queue is empty\n";
	}
	else{
		cout<<"the queue is: ";
		node *t;
		t=start;
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
	int c,d1,d3;
	do{
	cout<<"1: ENQUEUE\n";
	cout<<"2: DEQUEUE\n";
	cout<<"3: FRONT\n";
	cout<<"4: DISPLAY\n";
	cout<<"5: EXIT\n";
	cout<<"enter the choice: ";
	cin>>c;
	switch(c)
	{
		case 1:cout<<"enter a number: ";
				cin>>d1;
				enqueue(d1);
				break;
		case 2: dequeue();
				break;
		case 3: d3=peek();
				cout<<"the front of the queue is: "<<d3<<endl;
				break;
		case 4: display();
				break;
		case 5: break;					 		

	}

	}while(c!=5);
	cout<<"THANK YOU\n";
	return 0;
}

#include<iostream>
using namespace std;

 struct lnode{
 	int data;
 	lnode *next;
 };

 typedef struct lnode* lptr;

 void push(lptr &l,int n)
 {
 	lptr t;
 	t= new (lnode);
 	t->data=n;
 	t->next=l;
 	l=t;
 }

 int pop(lptr &l)
 {
 	if(l==NULL)
 	{
 		cout<<"the stack is empty\n";
 	}
 	else{
 		lptr t;
 		t=l;
 		int n=t->data;
 		l=t->next;
 		free(t);
 		return n;
 	}
 }

int peek(lptr &l)
{
	if(l==NULL)
	{
		cout<<"the stack is empty\n";
	}
	else{
		return l->data;
	}
}

void reverse(lptr &l)
{
	static lptr t=l;
	if(l->next!=NULL)
	{
		reverse(l->next);
	}
	else if(t!=l)
	{
	int temp=l->data;
	l->data=t->data;
	t->data=temp;
	t=t->next;}
}

void display_reverse(lptr &l)
{
	if(l->next!=NULL)
	{
		display_reverse(l->next);
	}
	cout<<l->data<<" ";
}

 int main()
{
	lptr l=NULL;
	int choice;
	do
	{
		cout<<"1: push\n";
		cout<<"2: pop\n";
		cout<<"3: peek\n";
		cout<<"4: display\n";
		cout<<"5: reverse\n";
		cout<<"enter your choice\n";
		cin>>choice;
		switch(choice)
		{
			case 1: cout<<"enter a number: ";
					int n;cin>>n;
					push(l,n);
					break;
			case 2: cout<<"the poped out element is: "<<pop(l)<<endl;
					break;
			case 3: cout<<"the top of the stack is: "<<peek(l)<<endl;
					break;		
			case 4: display_reverse(l);
					cout<<endl;
					break;
			case 5: reverse(l);
					break;				
		}

	}while(choice!=6);
}

#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node *prev;
	node *next;
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
		temp->prev=start;
		start=temp;
	}
	else{
		t=start;
		while(t->next!=NULL)
		{
			t=t->next;
		}
		temp->prev=t;
		t->next=temp;
	}
}

void insert_node_at_big()
{
	node *temp;
	temp=(node*)new(node);
	cout<<"enter a number: ";
	cin>>temp->data;
	temp->next=start;
	temp->prev=start;
	start=temp;
}

void insert()
{
	node *temp,*t;
	temp=(node*)new(node);
	cout<<"enter a number: ";
	cin>>temp->data;
	cout<<"enter element: ";
	int x;cin>>x;
	t=start;
	while(t!=NULL)
	{
		if(t->data==x)
		{
			if(t->next==NULL)
			{
				temp->next=NULL;
				temp->prev=t;
				t->next=temp;
				break;
			}
			else{
			t->next->prev=temp;
			temp->next=t->next;
			temp->prev=t;
			t->next=temp;
			break;}
		}
		else{
			t=t->next;
		}
	}
}

void deletion()
{
	node *t1,*t2;
	cout<<"enter the you want to delete: ";
	int x;cin>>x;
	t1=start;
	t2=start->next;
	if(t1->data==x)
	{
		t2->prev=start;
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
					free(t2);
					break;
				}
				else{
					t2->next->prev=t1;
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

void reverse()
{
	node *prev,*curr,*next;
	prev=NULL;
	curr=start;
	while(curr!=NULL)
	{
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
	start=prev;
}

void sorting()
{
	node *t1,*t2;
	t1=start;
	int min,temp;
	while(t1!=NULL)
	{
		min=t1->data;
		t2=t1->next;
		while(t2!=NULL)
		{
			if(t2->data<min){min=t2->data;temp=t1->data;t1->data=t2->data;t2->data=temp;}
			t2=t2->next;
		}
		t1=t1->next;
	}
}

void update()
{
	node *t;
	cout<<"enter the element you want to update: ";
	int x;cin>>x;
	cout<<"enter a new number: ";
	int n;cin>>n;
	t=start;
	while(t!=NULL)
	{
		if(t->data==x)
		{
			t->data=n;
			break;
		}
		else{
			t=t->next;
		}
	}
	cout<<"after updation ";
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
	int c;
	do{
	cout<<"### select the operation ###\n";
	cout<<"1: insert_node_at_end\n";
	cout<<"2: insert_node_at_biggning\n";
	cout<<"3: insert_node_after_an_element\n";
	cout<<"4: delete_a_node\n";
	cout<<"5: update_a_node\n";
	cout<<"6: reverse_the_linked_list\n";
	cout<<"7: sort_the_linked_list\n";
	cout<<"8: display_the_linked_list\n";
	cout<<"9: exit\n";
	cout<<"enter your choice: ";
	cin>>c;
	switch(c)
	{
		case 1: cout<<"enter number nodes you want to insert at end: ";
				int n1;cin>>n1;
				for(int i=0;i<n1;i++)
				{
					insert_node_at_end();
					display();
				}
				cout<<"\n\n\n";
				break;
		case 2: cout<<"enter number nodes you want to insert at bigning: ";
				int n2;cin>>n2;
				for(int i=0;i<n2;i++)
				{
					insert_node_at_big();
					display();
				}
				cout<<"\n\n\n";
				break;	
		case 3: insert();
				display();
				cout<<"\n\n\n";
				break;
		case 4: deletion();
				display();
				cout<<"\n\n\n";
				break;
		case 5: update();
				display();
				cout<<"\n\n\n";	
				break;
		case 6: cout<<"after reversing ";
				reverse();
				display();
				cout<<"\n\n\n";
				break;
		case 7: cout<<"after sorting ";
				sorting();
				display();
				cout<<"\n\n\n";
				break;
		case 8: display();
				cout<<"\n\n\n";
				break;
		case 9: break;

		default: cout<<"wrong choice..!!!\n";
				 cout<<"try again\n";
				 cout<<endl;
				 break;													

	}

	}while(c!=9);
}


#include<bits/stdc++.h>
using namespace std;

struct node {
	int data;
	node *next;
	
};

node *start=NULL;

void insertnode()
{
	node *temp,*t;
	temp=(node*)new(node);
	cout<<"enter a number: ";
	cin>>temp->data;
	temp->next=NULL;
	if(start==NULL)
	{
		start=temp;
	}
	else{
		t=start;
		while(t->next!=NULL)
		{
			t=t->next;
		}
		t->next=temp;
	}
}

void display()
{
	node *t;
	if(start==NULL)
	{
		cout<<"the list is empty\n";
	}
	else
	{
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

void insertnode_at_beg()
{
	node *temp;
	temp=(node*)new(node);
	cout<<"enter a number: ";
	cin>>temp->data;
	temp->next=NULL;
	if(start==NULL)
	{
		start=temp;	
	}
	else{
		temp->next=start;
		start=temp;
	}
}

node *reverse(node *curr)
{
	static node *prev=NULL;
	node *next;
	if(curr==NULL)
	{
		return prev;
	}
	else{
		next=curr->next;
		curr->next=prev;
		prev=curr;
	}
	return reverse(next);
}

void insert()
{
   cout<<"enter the number you want to insert\n";
   int value;cin>>value;
   cout<<"enter element: ";
   int x;cin>>x;
   node *temp;
   temp=(node*)new(node);
   temp->data=value;
   node *t;
   t=start;
   while(t!=NULL)
   {
   	if(t->data==x)
   	{
   		temp->next=t->next;
   		t->next=temp;
   		break;
   	}
   	else{
   		t=t->next;
   	}
   }
}

void deletion()
{
	cout<<"enter the number: ";
	int x;cin>>x;
	node *t1,*t2;
	t1=start;
	t2=start->next;
	while(t1!=NULL)
	{
		if(t2->data==x)
		{
			t1->next=t2->next;
			break;
		}
		else{
			t1=t1->next;
			t2=t2->next;
		}
	}
}

void update()
{
	cout<<"enter a number you want to update\n";
	int x;cin>>x;
	cout<<"enter new number: ";
	int n;cin>>n;
	node *t;
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
}

void length()
{
	node *t;
	int count=0;
	t=start;
	while(t!=NULL)
	{
		count++;
		t=t->next;
	}
	cout<<"the lenght of the list is "<<count<<endl;
}

// void sort()
// {
// 	int min,temp;
// 	node *t1,*t2,t3;
// 	t1=start;
// 	t2=start->next;
// 	while(t1!=NULL)
// 	{
// 		min=t1->data;
// 		while(t2!=NULL)
// 		{
// 			if(t2->data<min){t3->d=t2->data;}
// 			t2=t2->next;
// 		}
// 		temp=t1->data;t1->data=min;
// 	}
// }

int main()
{
	cout<<"enter n: ";
	int n;cin>>n;
	for(int i=0;i<n;i++)
	{
		insertnode();
	}
	display();
	int choice;
	do{
		
		cout<<"enter the choice\n";
		cout<<"1: insert a node at the biggining\n";
		cout<<"2: insert a node at the end\n";
		cout<<"3: insert a node after an element\n";
		cout<<"4: delete a node\n";
		cout<<"5: update an element\n";
		cout<<"6: get the length of the list\n";
		cout<<"7: sort the list\n";
		cout<<"8: reverse the list\n";
		cout<<"9: exit\n";
		cin>>choice;

		switch(choice)
		{
			case 1:insertnode_at_beg();
					display();
					break;
			case 2: insertnode();
				    display();
				    break;
			case 3:insert();
					display();
					break;
			case 4: deletion();
					display();
					break;
			case 5:update();
					display();
					break;
			case 6:length();
					break;
			case 7://sort();
					break;	
			case 8: start=reverse(start);	
					display();			
			case 9: break;		
			default: cout<<"wrong choice try once again\n";			 				 	    		
		}

	}while(choice!=9);
	cout<<"THANK YOU\n";
	return 0;
}
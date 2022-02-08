#include<bits/stdc++.h>
using namespace std;

struct  node1
{
	int data;
	node1* next;
};

struct node2
{
	int data;
	node2* next;
};

struct node3
{
	int data;
	node3 *next;
};

node1 *start1=NULL;
node2 *start2=NULL;
node3 *start3=NULL;

void insert1()
{
	node1 *temp1,*t1;

	temp1=(node1*)new(node1);

	cout<<"enter number: ";
	cin>>temp1->data;
	temp1->next=NULL;

	t1=start1;

	if(t1==NULL){start1=temp1;}
	else
	{
		while(t1->next!=NULL)
		{
			t1=t1->next;
		}
		t1->next=temp1;
	}
}

void insert2()
{
	node2 *temp2,*t2;
	temp2=(node2*)new(node2);
	cout<<"enter number: ";
	cin>>temp2->data;
	temp2->next=NULL;
	t2=start2;
	if(t2==NULL){start2=temp2;}
	else
	{
		while(t2->next!=NULL)
		{
			t2=t2->next;
		}
		t2->next=temp2;
	}
}

void sorting()
{
	node3 *t1,*t2;
	t1=start3;
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

void cop()
{
	node1 *t1;
	t1=start1;
	do{
		node3 *temp3,*t3;
		temp3=(node3*)new(node3);
		temp3->data=t1->data;
		temp3->next=NULL;
		t3=start3;
		if(t3==NULL){start3=temp3;}
		else{
			while(t3->next!=NULL)
			{
				t3=t3->next;
			}
			t3->next=temp3;
		}
		t1=t1->next;
	}while(t1!=NULL);
	node2 *t2;
	t2=start2;
	do{
		node3 *temp3,*t3;
		temp3=(node3*)new(node3);
		temp3->data=t2->data;
		temp3->next=NULL;
		t3=start3;
		if(t3==NULL){start3=temp3;}
		else{
			while(t3->next!=NULL)
			{
				t3=t3->next;
			}
			t3->next=temp3;
		}
		t2=t2->next;
	}while(t2!=NULL);
}

void display()
{
    node3 *t3;
	t3=start3;
	cout<<"the merged list is\n";
	while(t3!=NULL)
	{
		cout<<t3->data<<endl;
		t3=t3->next;
	}
}

int main()
{
    cout<<"enter the number of numbers to be entered in 1 ll\n";
    int n1;cin>>n1;
    cout<<"enter the numbers of 1 ll\n";
    for(int i=0;i<n1;i++)
    {
    	insert1();
    }
    cout<<"enter the number of numbers to be entered in 2 ll\n";
    int n2;cin>>n2;
    cout<<"enter the numbers of 2 ll\n";
    for(int i=0;i<n2;i++)
    {
    	insert2();
    }
    cop();
    sorting();
    display();
}


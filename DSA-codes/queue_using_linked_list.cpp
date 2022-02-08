#include<iostream>
using namespace std;

struct lnode{
	int data;
	lnode *next;
};

typedef struct lnode* lptr;

void enqueue(lptr &f,lptr &r,int n)
{
	lptr t;
	t= new(lnode);
	t->data=n;
	t->next=NULL;
	if(f==NULL)
	{
		f=t;
		r=t;
	}
	else{
		r->next=t;
		r=r->next;
	}
}		

int dequeue(lptr &f,lptr &r)
{

	if(f==NULL)
	{
		cout<<"the queue is empty\n";
		return -1;
	}
	else{
		int n=f->data;
		lptr t;
		t=f;
		f=f->next;
		free(t);
		return n;
	}
}

int front(lptr &f,lptr &r)
{

	if(f==NULL)
	{
		cout<<"the queue is empty\n";
		return -1;
	}
	else{
		return f->data;
	}
}

int main()
{
	lptr f=NULL;
    lptr r=NULL;
	int c;
	do{
		cout<<"1: ENQUEUE\n";
		cout<<"2: DEQUEUE\n";
		cout<<"3: FRONT\n";
		cout<<"4: EXIT\n";
		cout<<"enter the choice: ";
		cin>>c;
		switch(c)
		{
			case 1:	{
						cout<<"enter a number: ";
						int n;cin>>n;
						enqueue(f,r,n);
						break;
					}
			case 2: {
						int t=dequeue(f,r);
						if(t!=-1){
							cout<<"the dequeued element is: "<<t<<endl;
						}
						break;
					}
			case 3: {
						int t=front(f,r);
						if(t!=-1){
							cout<<"the front of the queue: "<<t<<endl;	
						}
						break;
					}				 		
			default: break;	

		}
	}while(c!=4);

	return 0;
}
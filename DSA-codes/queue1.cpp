#include<iostream>
using namespace std;

class queue{
	int front=-1;
	int rear=-1;
	int *array;
	int c;
public: 
	void enqueue(int data);
	int dequeue();
	int empty();
	int peek();
	void cap();
	int full();
	void display();
};

void queue::cap()
{
	cout<<"enter the capacity of the queue: ";
	cin>>c;
	array=(int*)malloc(sizeof(int)*(c));
}

int queue::full()
{
	if((rear+1)%c==front) return 1;
	else return 0;
}

int queue::peek()
{
	if(empty())
	{
		cout<<"the queue is empty\n";
	}
	else return array[front];
}

int queue::empty()
{
	if(front==-1&&rear==-1)
	{
		return 1;
	}
	else return 0;
}

void queue::enqueue(int data)
{
	if(full())
	{
		cout<<"the queue is full\n";
	}
	else{
		if(empty())
		{
			front=0;
			rear=0;
		}
		else
		{
			rear++;
		}
		array[rear]=data;
	}
}

int queue::dequeue()
{
	if(empty())
	{
		cout<<"the queue is empty\n";
	}
	else
	{
		if(front==rear)
		{
			front=rear=-1;
			return array[0];
		}
		else
		{
			front=front +1;
			return array[front-1];
		}
	}
}

void queue::display()
{
	if(empty())
	{
		cout<<"the queue is empty\n";
	}
	else
	{
		cout<<"the queue is: ";
		for(int i=front;i<=rear;i++)
		{
			cout<<array[i]<<"   ";
		}
		cout<<endl;
	}
}

int main()
{
	int d1,d2,d3,c;
	class queue q;
	q.cap();
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
				q.enqueue(d1);
				break;
		case 2: d2=q.dequeue();
				cout<<"the deleted number is: "<<d2<<endl;
				break;
		case 3: d3=q.peek();
				cout<<"the front of the queue is: "<<d3<<endl;
				break;
		case 4: q.display();
				break;
		case 5: break;					 		

	}

	}while(c!=5);
	cout<<"THANK YOU\n";
	return 0;
}
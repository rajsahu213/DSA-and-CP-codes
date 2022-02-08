#include<iostream>
using namespace std;
#define max 101

class queue{
	int front;
	int rear;
	int array[max];
public: 
	queue();
	void enqueue(int data);
	void dequeue();
	int empty();
	int full();
	void display();
	int Front();
};

queue::queue()
{
	front=-1;
	rear=-1;
}

int queue::empty()
{
	return (front==-1&&rear==-1);
}

int queue::full()
{
	return ((rear+1)%max==front);
}

int queue::Front()
{
	if(empty()){cout<<"the queue is empty\n";}
	else return array[front];
}

void queue::enqueue(int data)
{
	cout<<"enqueuing: "<<data<<endl;
	if(full())
	{
		cout<<"the queue is full\n";
	}
	else if(empty())
	{
		front=rear=0;
		array[rear]=data;
	}
	else{
		rear=(rear+1)%max;
		array[rear]=data;
	}
}

void queue::dequeue()
{
	cout<<"dequeuing: "<<array[front]<<endl;
	if(empty())
	{
		cout<<"the queue is empty\n";
	}
	else if(front==rear)
	{
		rear=front=-1;
	}
	else{
		front=(front+1)&max;
	}
}

void queue::display()
{
	int count=(rear+max-front)%max+1;
	cout<<"the queue is: ";
	for(int i=0;i<count;i++)
	{
		int index=(front+i)%max;
		cout<<array[index]<<"   ";
	}
	cout<<"\n\n";
}

int main()
{
	int c,d1,d3;
	queue q;
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
		case 2: q.dequeue();
				break;
		case 3: d3=q.Front();
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

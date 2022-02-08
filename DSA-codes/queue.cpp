#include<bits/stdc++.h>
using namespace std;

struct arrayqueue
{
	int front,rare;
	int capacity;
	int *array;
};

arrayqueue *creatqueue(int cap)
{
  arrayqueue *q;
  q=(arrayqueue*)new(arrayqueue);
  if(!q){return NULL;}
  else{
  	q->capacity=cap;
  	q->front=q->rare=-1;
  	q->array=(int*)malloc(q->capacity*sizeof(int));
  	if(!q->array){return NULL;}
  	else{return q;}
  }
}

int isemptyqueue(arrayqueue *q)
{
	return q->front==-1;
}

int isfullqueue(arrayqueue *q)
{
	return (q->rare+1)%q->capacity==q->front;
}

int queuesize(arrayqueue *q)
{
	return (q->capacity-q->front+q->rare+1)%q->capacity;
}

void enqueue(arrayqueue *q,int data)
{
	if(isfullqueue(q)){cout<<"queue overflow\n";}
	else{
		q->rare=(q->rare+1)%q->capacity;
		q->array[q->rare]=data;
		if(q->front==-1)
		{
			q->front=q->rare;
		}
	}
}

int dequeue(arrayqueue *q)
{
	int data=-1;
	if(isemptyqueue(q))
	{
		cout<<"queue is empty\n";
		return -1;
	}
	else{
		data=q->array[q->front];
		if(q->front==q->rare)
		{
			q->front=q->rare=-1;
		}
		else{
			q->front=(q->front+1)%q->capacity;
		}
		return data;
	}
}


int main()
{
	int c,data;
	cout<<"enter the capacity of the queue: ";
	int cap;
	cin>>cap;
	arrayqueue *q;
	q=creatqueue(cap);
	do{
	cout<<"1: enter an element\n";
	cout<<"2: delete an element\n";
	cout<<"3: size of the queue\n";
	cout<<"4: display\n";
	cout<<"5: exit\n";
	cout<<"enter the choice: ";
	cin>>c;
	switch(c)
	{
		case 1:cout<<"enter a number: ";
				cin>>data;
				enqueue(q,data);
				break;
		case 2: data=dequeue(q);
				cout<<"the deleted number is: "<<data<<endl;
				break;
		case 3: data=queuesize(q);
				cout<<"the size of queue is: "<<data<<endl;
				break;
		case 4: display();
				break;
		case 5: break;					 		

	}

	}while(c!=5);

}
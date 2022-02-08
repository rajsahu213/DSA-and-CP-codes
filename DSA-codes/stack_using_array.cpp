#include<iostream>
using namespace std;

class stack{
	int top=-1;
	int *array;
	int capa;
public: 
	void push();
	void pop();
	void display();
	void cap();
};

void stack::cap()
{
	cout<<"enter the capacity of the stack: ";
	cin>>capa;
	array=(int*)malloc(sizeof(int)*capa);
}

void stack::push()
{
	if(top==capa-1)
	{
		cout<<"error: stack overflow\n";
	}
	else{
	cout<<"enter a number: ";
	int n;cin>>n;
	top=top+1;
	array[top]=n;}
}

void stack::pop()
{
	if(top==-1)
	{
		cout<<"the stack is empty\n";
	}
	else{
		cout<<"the number poped out is: "<<array[top]<<endl;
		top=top-1;
	}
}

void stack::display()
{
	if(top==-1)
	{
		cout<<"the stack is empty\n";
	}
	else{
		cout<<"the stack is: ";
		for(int i=0;i<=top;i++)
		{
			cout<<array[i]<<"   ";
		}
		cout<<endl;
	}
}

int main()
{
	class stack ob;
	ob.cap();
	int choice;
	do
	{
		cout<<"   ####STACK####    \n";
		cout<<"1: push\n";
		cout<<"2: pop\n";
		cout<<"3: display\n";
		cout<<"4: exit\n";
		cout<<"enter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1: ob.push();
					break;
			case 2: ob.pop();
					break;
			case 3: ob.display();
					break;
			case 4: break;
			default: cout<<"wrong choice try again\n";				
		}

	}while(choice!=4);
	cout<<"THANK YOU\n";
	return 0;
}

#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

struct stack
{
    int top;
    char element[50];
    int size;
};

void push(stack &s,char a)
{
    if(s.top==s.size-1)
    {
        cout<<"the stack is full\n";
    }
    else{
        s.top+=1;
        s.element[s.top]=a;
    }
}

char pop(stack &s)
{
    if(s.top==-1)
    {
        return 'e';
    }
    else{
        return s.element[s.top--];
    }
}

char peek(stack &s)
{
    if(s.top==-1)
    {
        return 'e';
    }
    else{
        return s.element[s.top];
    }
}

int empty(stack &s)
{
	if(s.top==-1)
	{
		return 1;
	}
	else return 0;
}

int check2(char a,char b)
{
	if(a=='['&&b==']')return 1;
	else if(a=='{'&&b=='}')return 1;
	else if(a=='('&&b==')')return 1;
	else return 0;
}

int check(stack &s,char a[])
{
	int l=strlen(a);
	for(int i=0;i<l;i++)
	{
		if(a[i]=='['||a[i]=='('||a[i]=='{')
		{
			push(s,a[i]);
		}
		else if(a[i]=='}'||a[i]==')'||a[i]==']')
		{
			if(empty(s)||!check2(peek(s),a[i]))
			{
				return 0;
			}
			else{
				pop(s);
			}
		}
	}
	if(empty(s))return 1;
	else return 0;
}

int main()
{
	struct stack s;
	s.top=-1;
	s.size=40;
	cout<<"enter a string: ";
	char a[100];
	cin.getline(a,100);
	int flag=check(s,a);
	if(flag==0){cout<<"not balanced\n";}
	else{
		cout<<"balanced\n";
	}
}
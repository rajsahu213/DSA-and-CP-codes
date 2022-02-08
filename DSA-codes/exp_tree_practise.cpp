#include<bits/stdc++.h>
using namespace std;

struct btnode
{
	string data;
	btnode* lchild;
	btnode* rchild;
};

typedef struct btnode* btptr;

btptr creatnode(string a)
{
	btptr temp;
	temp=new btnode;
	temp->data=a;
	temp->lchild=temp->rchild=NULL;
	return temp;
}

void creat_exp(btptr &t,string s[],int &i,int n)
{
	if(i==n)return;
	if(s[i]!="+"&&s[i]!="-"&&s[i]!="*"&&s[i]!="/")
	{
		t=creatnode(s[i]);
		return;
	}
	else
	{
		t=creatnode(s[i]);
		creat_exp(t->lchild,s,++i,n);
		creat_exp(t->rchild,s,++i,n);
	}
}

void level_order(btptr &t)
{
    queue<btptr> q;
    q.push(t);
    q.push(NULL);
    while(!q.empty())
    {
        if(q.front()==NULL)
        {
            cout<<endl;
            q.pop();
            if(q.empty())break;
            q.push(NULL);
        }
        btptr t1=q.front();
        cout<<t1->data<<" ";
        q.pop();
        if(t1->lchild!=NULL)q.push(t1->lchild);
        if(t1->rchild!=NULL)q.push(t1->rchild);
    }
}

int oper(int a,char c,int b)
{
	switch(c)
	{
		case '+':return a+b;
		case '-':return a-b;
		case '*':return a*b;
		case '/':return a/b;
	}
}

int eval(btptr &t)
{
	if(t->lchild==NULL&&t->rchild==NULL)
	{
		return stoi(t->data);
	}
	else return oper(eval(t->lchild),t->data[0],eval(t->rchild));
}

int main()
{
	string s[20];
	cout<<"enter the expression: ";
	int i=0;
	while(1)
	{
		cin>>s[i];
		if(s[i]=="$")break;
		i++;
	}
	btptr t=NULL;
	int j=0;
	creat_exp(t,s,j,i);
	level_order(t);
	cout<<"the ans of the expression tree is: "<<eval(t)<<endl;
}
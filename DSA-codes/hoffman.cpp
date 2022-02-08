#include<bits/stdc++.h>
using namespace std;

struct hnode
{
	int f;
	char ch;
	hnode* lchild;
	hnode* rchild;
};

typedef struct hnode* hptr;

void insert_heap(hptr h[],int &n,hptr x)
{
	int i=n;
	h[n]=x;
	while((i-1)/2>=0)
	{
		if(h[(i-1)/2]->f>h[i]->f){hptr temp=h[i];h[i]=h[(i-1)/2];h[(i-1)/2]=temp;i=(i-1)/2;}
		else break;
	}
	n++;
}

void convert_into_min_heap(hptr h[],int n)
{
	for(int i=0;i<n;i++)
	{
		insert_heap(h,i,h[i]);
	}
}

void delete_num(hptr h[],int &n)
{
	int i=0;
	h[i]=h[n-1];n=n-1;
	hptr temp;
	while(n>=(2*i+1))
	{
		if(n==(2*i+1))
		{
			if(h[2*i+1]->f<h[i]->f){temp=h[i];h[i]=h[2*i+1];h[2*i+1]=temp;break;}
			else break;
		}
		else if(h[2*i+1]->f<h[i]->f&&h[2*i+2]->f>h[i]->f)
		{
			temp=h[i];h[i]=h[2*i+1];h[2*i+1]=temp;i=2*i+1;
		}
		else if(h[2*i+1]->f>h[i]->f&&h[2*i+2]->f<h[i]->f)
		{
			temp=h[i];h[i]=h[2*i+2];h[2*i+2]=temp;i=2*i+2;
		}		
		else if(h[2*i+1]->f<h[i]->f&&h[2*i+2]->f<h[i]->f)
		{
			if(h[2*i+1]->f<h[2*i+2]->f){temp=h[i];h[i]=h[2*i+1];h[2*i+1]=temp;i=2*i+1;}
			else {temp=h[i];h[i]=h[2*i+2];h[2*i+2]=temp;i=2*i+2;}
		}		
		else break;
	}
}

void level_order(hptr &t)
{
    queue<hptr> q;
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
        hptr t1=q.front();
        cout<<t1->ch<<t1->f<<" ";
        q.pop();
        if(t1->lchild!=NULL)q.push(t1->lchild);
        if(t1->rchild!=NULL)q.push(t1->rchild);
    }
}

hptr creatnode(char c,int fr)
{
	hptr temp;
	temp=new hnode;
	temp->f=fr;
	temp->ch=c;
	temp->lchild=temp->rchild=NULL;
	return temp;
}

hptr creat_node(hptr data1,hptr data2)
{
	hptr temp;
	temp=new hnode;
	temp->f=data1->f+data2->f;
	temp->ch='#';
	temp->lchild=data1;
	temp->rchild=data2;
	return temp;
}

int search(hptr &t,int x)
{
    if(t==NULL)return 0;
    if(t->f==x)return 1;
    else return search(t->lchild,x)+search(t->rchild,x);
}

void encode(hptr &t,int fr)
{
	if(t==NULL||t->f==fr)return;
	if(search(t->lchild,fr))
	{
		cout<<"0";
		encode(t->lchild,fr);
	}
	else
	{
		cout<<"1";
		encode(t->rchild,fr);
	}
}

void decode(hptr &t,string s,int &i)
{
	static int flag=0;
	if(t!=NULL)
	{
		if(s[i]=='0')decode(t->lchild,s,++i);
		else decode(t->rchild,s,++i);
	}
	if(flag==0&&t!=NULL){cout<<t->ch<<endl;flag=1;}
}

int main()
{
	cout<<"enter the number of input of hoffman code\n";
	int n;cin>>n;
	cout<<"character  frequency \n";
	hptr h[n];
	for(int i=0;i<n;i++)
	{
		char c;
		int fr;
		cin>>c>>fr;
		h[i]=creatnode(c,fr);
	}
	//convert_into_min_heap(a,n);
	hptr a[n];
	int size=0;
	for(int i=0;i<n;i++)
	{
		insert_heap(a,size,h[i]);
	}
	hptr t;
	while(n>1)
	{
		hptr temp1=a[0];
		delete_num(a,n);
		hptr temp2=a[0];
		delete_num(a,n);
		t=creat_node(temp1,temp2);
		insert_heap(a,n,t);
	}
	level_order(a[0]);
	cout<<"enter the character and its frequency\n";
	char ch;
	int freq;
	cin>>ch>>freq;
	cout<<"its hoffman code is: ";
	hptr te=a[0];
	encode(te,freq);
	cout<<endl;
	cout<<"enter the encoded string: ";
	string s;cin>>s;
	int k=0;
	decode(t,s,k);
}
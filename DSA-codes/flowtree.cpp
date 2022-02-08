#include<bits/stdc++.h>
using namespace std;

struct gtnode
{
	char data;
	int cnt;
    int maxiter;
	gtnode* cptr[50]; 
};

typedef struct gtnode* gtptr;

gtptr creatnode(char a)
{
	if(a==')')return NULL;
	gtptr temp;
	temp=new gtnode;
	temp->data=a;
	temp->cnt=0;
	for(int i=0;i<50;i++){temp->cptr[i]=NULL;}
	return temp;
}

gtptr creat(gtptr &t,int &i,string s)
{
	t=creatnode(s[i]);
	if(t==NULL||i>=s.length())return t;
	for(int j=0;j<30;j++)
	{
		t->cptr[j]=creat(t->cptr[j],++i,s);
		if(t->cptr[j]==NULL)break;
	}
	return t;
}

void level_order(gtptr &t,int &ht)
{
    queue<gtptr> q;
    q.push(t);
    q.push(NULL);
    while(!q.empty())
    {
        if(q.front()==NULL)
        {
        	ht++;
            cout<<endl;
            q.pop();
            if(q.empty())break;
            q.push(NULL);
        }
        gtptr t1=q.front();
        cout<<t1->data<<" ";
        q.pop();
        for(int i=0;i<30;i++)
        {
        	if(t1->cptr[i]!=NULL)
        	{
        		t1->cnt++;
        		q.push(t1->cptr[i]);
        	}
        }
    }
}

void preorder(gtptr &t)
{
    if(t!=NULL)
    {
        cout<<t->maxiter<<" ";
        for(int i=0;i<=t->cnt;i++)
        {
            preorder(t->cptr[i]);
        }
    }
}
int max_iter(gtptr &t);
int maxi(gtptr &t)
{
    int a[t->cnt];
    for(int i=0;i<t->cnt;i++)
    {
        a[i]=max_iter(t->cptr[i]);
    }
    sort(a,a+t->cnt);
    for(int i=0;i<t->cnt;i++)
    {
        a[i]=a[i]+t->cnt-i;
    }
    return *max_element(a,a+t->cnt);
}

int max_iter(gtptr &t)
{
    if(t->cnt==0)
    {
        t->maxiter=0;
        return t->maxiter;
    }
    else
    {
        t->maxiter=maxi(t);
        return t->maxiter;
    }
}
int index(gtptr &t)
{
    int max=INT_MIN,temp;
    for(int i=0;i<t->cnt;i++)
    {
        if(t->cptr[i]->cnt>max){max=t->cptr[i]->cnt;temp=i;}
    }
    return temp;
}
// void print(gtptr &t,int m)
// {
//     queue<gtptr> q;
//     q.push(t);
//     int i=1;
//     while(m--)
//     {
//         int te=q.size();
//         cout<<"at "<<i<<" iteration\n";i++;

//     }
// }

int main()
{
    cout<<"enter a string : ";//abf)g)z)y))ci)j)k))dhk)l)m))s)p))en)k)))
    string s;
    cin>>s;
    gtptr t=NULL;
    int i=0;
    creat(t,i,s);
    cout<<"the breadth first traversal is  \n";
    int ht=0;
    level_order(t,ht);
    int maxit=max_iter(t);
    cout<<"the maximum iterations are: "<<maxit<<endl;
    // print(t,maxit);
    // cout<<endl;
}
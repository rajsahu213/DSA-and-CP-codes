#include<bits/stdc++.h>
using namespace std;

struct lnode{
    int data;
    lnode *next;
};

struct lnode *l;

typedef struct lnode* lptr;

void insert_at_big(lptr &l,int x)
{
    lptr t;
    t= new(lnode);
    t->data=x;
    t->next=l;
    l=t;
}

void deletion(lptr &l,int x)
{
    lptr t1,t2;
    t1=l;
    t2=l->next;
    if(l->data==x)
    {
        l=t2;
        free(t1);
    }
    else{
        while(t1->next!=NULL)
        {
            if(t2->data==x)
            {
                t1->next=t2->next;
                free(t2);
                break;
            }
            else{
                t1=t1->next;
                t2=t2->next;
            }
        }
    }
}

void display(lptr &l)
{
    if(l==NULL)
    {
        cout<<"the list is empty\n";
    }
    else{
        lptr t;
        t=l;
        cout<<"list is: ";
        while(t!=NULL)
        {
            cout<<t->data<<" ";
            t=t->next;
        }
        cout<<endl;
    }
}

void rmv_dup(lptr &l)
{
	lptr t1=l,t2;
	while(t1!=NULL)
	{
		t2=t1->next;
		while(t2!=NULL)
		{
			if(t2->data==t1->data)
			{
				deletion(l,t2->data);
			}
			t2=t2->next;
		}
		t1=t1->next;
	}
}

int main()
{
    lptr l=NULL;
    cout<<"enter the elements in the list(or enter -1 to stop)\n";
    while(1)
    {
        cout<<"enter a number: ";
        int data;cin>>data;
        if(data==-1)break;
        insert_at_big(l,data);
    }
    rmv_dup(l);
    cout<<"the corrected ";
    display(l);
}
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

int count1(lptr l)
{
    static int i=0;
    if(l==NULL)
    {
        return i;
    }
    else{
        i++;
        count1(l->next);
    }
}

bool find(lptr l,int x)
{
    if(l==NULL)
    {
        return false;
    }
    else{
        if(l->data==x)
        {
            return true;
        }
        else{
            find(l->next,x);
        }
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
    cout<<"enter the number you want to find: ";
    int x;cin>>x;
    int count=count1(l);
    bool flag=find(l,x);
    if(flag)cout<<"found\n";
    else cout<<"not found\n";
    cout<<"there are "<<count<<" nodes in the list\n";
    return 0;
}
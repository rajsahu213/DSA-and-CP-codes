#include<bits/stdc++.h>
using namespace std;

struct lnode{
    char data;
    lnode *next;
};

struct lnode *l;

typedef struct lnode* lptr;

lptr creatnode(char x)
{
    lptr temp;
    temp=new(lnode);
    temp->data=x;
    temp->next=NULL;
    return temp;
}

lptr insert_at_end(lptr &l,char x)
{
    if(l==NULL)
    {
        l=creatnode(x);
    }
    else
    {
        l->next=insert_at_end(l->next,x);
    }
    return l;
}

void display(lptr l)
{
    if(l!=NULL)
    {
        cout<<l->data;
        display(l->next);
    }
}

int main()
{
    lptr l=NULL;
    cout<<"enter the string: ";
    char a[100];
    cin.getline(a,100);
    int le=strlen(a);
    for(int i=0;i<le;i++)
    {
        l=insert_at_end(l,a[i]);
    }
    cout<<"the list is: ";
    display(l);
    cout<<endl;
}
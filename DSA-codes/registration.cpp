#include<iostream>
using namespace std;
struct rnode;

union u
{
    int rll;
    char ch;
    struct rnode *ptr;
};

struct rnode
{
    int flag;
    union u opt;
    struct rnode *next;
};

typedef struct rnode* rptr;

void insert_stud(rptr &s,int no)
{
    rptr t;
    t= new(rnode);
    t->next=NULL;
    t->opt.rll=no;
    t->flag=0;
    s=t;
}

void insert_course(rptr &c,char ch)
{
    rptr t;
    t= new(rnode);
    t->next=NULL;
    t->opt.ch=ch;
    t->flag=1;
    c=t;
}

void insert_at_end(rptr &l,rptr &x)
{
    rptr t;
    t= new (rnode);
    t->flag=2;
    t->opt.ptr=NULL;
    t->next=NULL;
    if(l->next==NULL)
    {
        l->next=t;
    }
    else{
        rptr t1;
        t1=l->next;
        while(t1->opt.ptr!=NULL)
        {
            t1=t1->opt.ptr;
        }
        t1->opt.ptr=t;
    }    
    if(x->next==NULL)
    {
        x->next=t;
    }
    else{
        rptr t2;
        t2=x->next;
        while(t2->next!=NULL)
        {
            t2=t2->next;
        }
        t2->next=t;
    }    
}

void creat(rptr s[],rptr c[],int s1,int c1)
{
    int a[c1+10];
    for(int i=0;i<s1;i++)
    {
        int j=0;
        cout<<"enter the cources opted by s"<<i+1<<" (or * to stop)\n";
        while(1)
        {
            char data;cin>>data;
            if(data=='*')break;
            a[j++]=data-'a';
        }
        for(int k=0;k<j;k++)
        {
            insert_at_end(s[i],c[a[k]]);
        }
    }
    for(int i=0;i<s1;i++)
    {
        rptr t=s[i]->next;
        while(t->opt.ptr!=NULL)
        {
            t=t->opt.ptr;
        }
        t->opt.ptr=s[i];
    }
    for(int j=0;j<c1;j++)
    {
        rptr t1=c[j]->next;
        while(t1->next!=NULL)
        {
            t1=t1->next;
        }
        t1->next=c[j];
    }
    int choice;
    do{
        cout<<"1: cources enrolled by a particular student\n";
        cout<<"2: students enrolled in a particular cource\n";
        cout<<"3: exit\n";
        cout<<"enter the choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1: {cout<<"enter the students roll no: ";
                    int no;cin>>no;
                    rptr t=s[no-1]->next;
                    while(t->flag==2)
                    {
                        rptr t1=t->opt.ptr;
                        while(t->flag==2)
                        {
                            t=t->next;
                        }
                        cout<<t->opt.ch<<" ";
                        t=t1;
                    }
                    cout<<endl;
                    break;
                    }

            case 2: {cout<<"enter the cource: ";
                    char o;cin>>o;
                    int no=o-'a';
                    rptr t=c[no]->next;
                    while(t->flag==2)
                    {
                        rptr t1=t->next;
                        while(t->flag==2)
                        {
                            t=t->opt.ptr;
                        }
                        cout<<t->opt.rll<<" ";
                        t=t1;
                    }
                    cout<<endl;
                    break;
                    }       
            case 3: break;        
        }

    }while(choice!=3);
}

int main()
{
    cout<<"enter the number of students: ";
    int s1;cin>>s1;
    rptr s[s1];
    for(int i=0;i<s1;i++)
    {
        insert_stud(s[i],i+1);
    }
    cout<<"enter the number of cources: ";
    int c1;cin>>c1;
    rptr c[c1];
    char temp='a';
    for(int i=0;i<c1;i++)
    {
        insert_course(c[i],temp);
        temp=temp+1;
    }
    creat(s,c,s1,c1);
}
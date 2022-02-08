#include<bits/stdc++.h>

using namespace std;

struct lnode{
    int data;
    lnode* next;
    lnode(int d){
        data=d;
        next=NULL;
    }
};

typedef struct lnode* lptr;

lptr insert_at_end(lptr l,int data)
{
    if(l==NULL)l=new lnode(data);
    else l->next=insert_at_end(l->next,data);
    return l;
}

void insert_at_end_iter(lptr &l,int data)
{
    if(l==NULL){
        l=new lnode(data);
        return;
    }else{
        lptr t=l;
        while(t->next!=NULL){
            t=t->next;
        }
        t->next=new lnode(data);
        return;
    }
}

void insert_at_begin(lptr &l,int data)
{
    lptr temp=new lnode(data);
    temp->next=l;
    l=temp;
}

void insert_after(lptr &l,int x,int data)
{
    if(l==NULL)return;
    else if(l->data==x){
        lptr temp=new lnode(data);
        temp->next=l->next;
        l->next=temp;
        return;
    }
    else insert_after(l->next,x,data);
}

void insert_after_iter(lptr &l,int x,int data)
{
    if(l==NULL){
        return;
    }else{
        lptr t=l;
        while(t!=NULL && t->data!=x){
            t=t->next;
        }
        if(t==NULL)return;
        else{
            lptr temp=new lnode(data);
            temp->next=t->next;
            t->next=temp;
            return;
        }
    }
}

void insert_before(lptr &l,lptr &prev,int x,int data)
{
    if(l==NULL)return;
    else if(l->data==x){
        if(prev==NULL){
            insert_at_begin(l,data);
        }else{
            lptr temp=new lnode(data);
            temp->next=prev->next;
            prev->next=temp;
        }
        return ;
    }
    else insert_before(l->next,l,x,data);
}

void insert_before_iter(lptr &l,int x,int data)
{
    if(l==NULL)return;
    else if(l->data==x){
        insert_at_begin(l,data);
    }else{
        lptr t1=l->next,t2=l;
        while(t1!=NULL && t1->data!=x){
            t1=t1->next;
            t2=t2->next;
        }
        if(t1==NULL){
            return;
        }else{
            lptr temp=new lnode(data);
            temp->next=t2->next;
            t2->next=temp;
            return;
        }
    }
}

lptr deletion(lptr &l,int x)
{
    if(l==NULL)return NULL;
    else if(l->data==x){
        return l->next;
    }else{
        l->next=deletion(l->next,x);
        return l;
    }
}

lptr delete_after(lptr &l,int x)
{
    if(l==NULL)return NULL;
    else if(l->data==x){
        if(l->next!=NULL){
            l->next=l->next->next;
        }
    }else{
        l->next=delete_after(l->next,x);
    }
    return l;
}

lptr delete_before(lptr &l,int x)
{
    if(l==NULL)return NULL;
    else if(l->next==NULL)return l;
    else if(l->next->data==x){
        return l->next;
    }else{
        l->next=delete_before(l->next,x);
        return l;
    }
}

void display(lptr &l){
    if(l==NULL)return;
    else{
        cout<<l->data<<" ";
        display(l->next);
    }
}

bool search(lptr &l,int x)
{
    if(l==NULL)return false;
    else if(l->data==x)return true;
    else return search(l->next,x);
}

int count(lptr &l,int x)
{
    if(l==NULL)return 0;
    else if(l->data==x)return 1+count(l->next,x);
    else return count(l->next,x);
}

void selection_sort(lptr &l)
{
    int n=0;
    lptr t=l;
    while(t!=NULL){
        n++;
        t=t->next;
    }
    lptr t1=l;
    while(t1->next!=NULL){
        int min=t1->data;
        lptr t2=t1->next;
        lptr minptr=t1;
        while(t2!=NULL){
            if(t2->data<min){min=t2->data;minptr=t2;}
            t2=t2->next;
        }
        swap(t1->data,minptr->data);
        t1=t1->next;
    }
}

lptr reverse(lptr l){
    lptr curr=l,prev=NULL,next;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

void rever(lptr &curr,lptr &prev,lptr &head){
    if(curr==NULL)return;
    rever(curr->next,curr,head);
    if(curr->next==NULL){
        head=curr;
    }
    curr->next=prev;
}


void bubble_sort(lptr &l){
    int n=0;
    lptr t1=l;
    while(t1!=NULL){
        n++;
        t1=t1->next;
    }
    lptr t=l;
    for(int i=0;i<n;i++){
        int last=n-i-1;
        lptr t2=l;
        for(int j=0;j<last;j++){
            if(t2->next->data<t2->data){
                int temp=t2->next->data;t2->next->data=t2->data;
                t2->data=temp;
            }
            t2=t2->next;
        }
        t=t->next;
    }
}

int main()
{
    lptr l=NULL;
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int data;cin>>data;
        l=insert_at_end(l,data);
    }
    display(l);cout<<endl;
    // sort(l);
    bubble_sort(l);
    // lptr t1=NULL,t2=l;
    // rever(t2,t1,l);
    display(l);cout<<endl;
    // while(l!=NULL){
    //     int data;cin>>data;
    //     l=delete_before(l,data);
    //     display(l);cout<<endl;
    // }
    // int x;cin>>x;
    // cout<<search(l,x)<<endl;
    // cout<<count(l,x)<<endl;
}

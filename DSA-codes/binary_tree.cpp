#include<bits/stdc++.h>
using namespace std;

struct btnode{
    char data;
    btnode* lchild;
    btnode* rchild;
};

typedef struct btnode* btptr;

btptr creatnode(char a)
{
    if(a=='.')return NULL;
    btptr temp;
    temp=new(btnode);
    temp->data=a;
    temp->lchild=temp->rchild=NULL;
    return temp;
}

btptr creat(btptr &t,string s,int n,int &i)
{
    t=creatnode(s[i]);
    if(t==NULL||i==n)return t;
    t->lchild=creat(t->lchild,s,n,++i);
    t->rchild=creat(t->rchild,s,n,++i);
    return t;
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

int count_leaf(btptr &t)
{
    if(t==NULL)return 0;
    if(t->lchild==NULL&&t->rchild==NULL)return 1;
    else return count_leaf(t->lchild)+count_leaf(t->rchild);
}

int count_nonleaf(btptr &t)
{
    if(t!=NULL)
    {
        if(t->lchild!=NULL||t->rchild!=NULL)
        return count_nonleaf(t->lchild)+count_nonleaf(t->rchild)+1;
    }
}

void preorder(btptr &t)
{
    if(t!=NULL)
    {
        cout<<t->data<<" ";
        preorder(t->lchild);
        preorder(t->rchild);
    }
}

void inorder(btptr &t)
{
    if(t!=NULL)
    {
        inorder(t->lchild);
        cout<<t->data<<" ";
        inorder(t->rchild);
    }
}

void postorder(btptr &t)
{
    if(t!=NULL)
    {
        postorder(t->lchild);
        postorder(t->rchild);
        cout<<t->data<<" ";
    }
}

void preorder_serial(btptr &t)
{
    if(t==NULL)cout<<".";
    if(t!=NULL)
    {
        cout<<t->data;
        preorder_serial(t->lchild);
        preorder_serial(t->rchild);
    }
}

void print_1d_left(btptr &t,int &max,int l)
{
    if(t!=NULL)
    {
        if(l>max)
        {
            cout<<t->data<<" ";
            max=l;
        }
        print_1d_left(t->lchild,max,l+1);
        print_1d_left(t->rchild,max,l+1);
    }
}

void print_1d_right(btptr &t,int &max,int l)
{
    if(t!=NULL)
    {
        if(l>max)
        {
            cout<<t->data<<" ";
            max=l;
        }
        print_1d_right(t->rchild,max,l+1);
        print_1d_right(t->lchild,max,l+1);
    }
}

int max(int a,int b)
{
    if(a>b)return a;
    else return b;
}

int find_h(btptr &t)
{
    if(t==NULL)return -1;
    else return max(find_h(t->lchild),find_h(t->rchild))+1;
}

bool search(btptr &t,char x)
{
    if(t==NULL)return false;
    if(t->data==x)return true;
    else return search(t->lchild,x)||search(t->rchild,x);
}

btptr creat_iter(btptr &t)
{
    stack<btptr> s; 
    btptr t1;
    cout<<"enter the element: ";
    char data,ch;cin>>data;
    t=creatnode(data);  
    s.push(t);
    t1=t;
    while(!s.empty())
    {      
        while(1)
        {  
            cout<<"do this node have a left child?(y/n): ";
            cin>>ch;
            if(ch=='y')
            {
                s.push(t1);
                cout<<"enter the element(left): ";
                cin>>data;
                t1->lchild=creatnode(data);
                t1=t1->lchild;
            }
            else break;
        }
        while(!s.empty())
        {
            cout<<"do this node have a right child? (y/n): ";
            cin>>ch;
            if(ch=='y')
            {
                cout<<"enter the element(right): ";
                cin>>data;
                t1->rchild=creatnode(data);
                t1=t1->rchild;
                break;
            }
            else
            {
                t1=s.top();
                s.pop();
            }
        }
    }
    return t;
}

int eval(btptr &t)
{
    if(t->lchild==NULL&&t->rchild==NULL)
    {
        return t->data-'0';
    }
    else
    {
        switch(t->data)
        {
            case '+':return eval(t->lchild)+eval(t->rchild);
            case '-':return eval(t->lchild)-eval(t->rchild);
            case '*':return eval(t->lchild)*eval(t->rchild);
            case '/':return eval(t->lchild)/eval(t->rchild);
        }
    }
}


void creat_level(btptr &t)
{
    cout<<"enter the root: ";
    char data;cin>>data;
    t=creatnode(data);
    queue<btptr> q;
    q.push(t);
    while(!q.empty())
    {
        btptr t1=q.front();q.pop();
        cout<<"do left?: ";
        char chl;cin>>chl;
        if(chl=='y')
        {
            cout<<"enter the data(left): ";
            char data;cin>>data;
            t1->lchild=creatnode(data);
            q.push(t1->lchild);
        }
        cout<<"do right?: ";
        char chr;cin>>chr;
        if(chr=='y')
        {
            cout<<"enter the data(right): ";
            char data;cin>>data;
            t1->rchild=creatnode(data);
            q.push(t1->rchild);
        }
    }
}

int max(int a,int b,int c,int d)
{
    int max=a;
    if(b>max)max=b;
    if(c>max)max=c;
    if(d>max)max=d;
    return max;
}
int max1(int a,int b)
{
    if(a>b)return a;
    else return b;
}

int mid_lev(btptr &t)
{
    if(t==NULL)
    {
        return -1;
    }
    else if(t->lchild==NULL&&t->rchild==NULL)
    {
        return 0;
    }
    else
    {
        if(t->lchild==NULL)
        {
            return max1(mid_lev(t->rchild->rchild),mid_lev(t->rchild->lchild))+1;
        }
        else if(t->rchild==NULL)
        {
            return max1(mid_lev(t->lchild->lchild),mid_lev(t->lchild->rchild))+1;
        }
    else return max(mid_lev(t->lchild->lchild),mid_lev(t->rchild->rchild),mid_lev(t->lchild->rchild),mid_lev(t->rchild->lchild))+1;
    }
}

void covered_uncovered(btptr &t,int &sumc,int &sumuc)
{
    vector<int> v;
    queue<btptr> q;
    q.push(t);
    q.push(NULL);
    while(!q.empty())
    {
        if(q.front()==NULL)
        {
            q.pop();
            sumuc+=v[0];
            if(v.size()>1)sumuc+=v[v.size()-1];
            for(int i=1;i<v.size()-1;i++)
            {
                sumc+=v[i];
            }
            v.erase(v.begin(),v.end());
            if(q.empty())break;
            q.push(NULL);
        }
        btptr t1=q.front();
        v.push_back(t1->data-'0');
        q.pop();
        if(t1->lchild!=NULL)q.push(t1->lchild);
        if(t1->rchild!=NULL)q.push(t1->rchild);
    }
}

int main()
{
    btptr t=NULL;
    cout<<" >> ";
    string a;
    cin>>a;
    int i=0,n=a.length();
    t=creat(t,a,n,i); 
    // creat_level(t);
    //t=creat_iter(t); 
    level_order(t);
    // cout<<"no of leaf nodes are: "<<count_leaf(t)<<endl;
    // cout<<"no of non leaf nodes are: "<<count_nonleaf(t)<<endl;
    // preorder_serial(t);
    // cout<<endl;
    // int max=0,l=1;
    // print_1d_left(t,max,l);
    // cout<<endl;
    // max=0,l=1;
    // print_1d_right(t,max,l);
    // cout<<endl;
    // cout<<"the height of the tree is: "<<find_h(t)<<endl;
    // preorder(t); 
    // cout<<endl;
    // inorder(t); 
    // cout<<endl;
    // postorder(t); 
    // cout<<endl;       
    // cout<<"the ans is: "<<eval(t)<<endl;
    // cout<<"enter the element: ";
    // char x;cin>>x;
    // cout<<search(t,x)<<endl; 
    // cout<<max_path(t)<<endl;
    // cout<<"the middle level is: "<<mid_lev(t)<<endl;
    int sumc=0,sumuc=0;
    covered_uncovered(t,sumc,sumuc);
    cout<<sumc<<" "<<sumuc<<endl;
}
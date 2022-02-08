#include<bits/stdc++.h>
using namespace std;

union u 
{
	int num;
	char ch;
};

struct kdnode
{
	int flag[10];
	union u data[10];
	kdnode* lchild;
	kdnode* rchild;
};

typedef struct kdnode* kdptr;

kdptr creatnode(int d,string s[])
{
	kdptr temp;
	temp=new kdnode;
	int b;
	for(int i=0;i<d;i++)
	{
		b=s[i][0];
		if(b>=97&&b<=122||b<=90&&b>=65)
		{
			temp->data[i].ch=s[i][0];
			temp->flag[i]=0;
		}
		else 
		{
			temp->data[i].num=stoi(s[i]);
			temp->flag[i]=1;
		}
	}
	temp->lchild=temp->rchild=NULL;
	return temp;
}

void insert(kdptr &t,int d,string k[],int &i)
{
	if(t==NULL)
	{
		t=creatnode(d,k);
	}
	else
	{
		if(t->flag[i]==0)
		{
			int b1=k[i][0],b2=t->data[i].ch;
			if(b1<b2)
			{
				i=(i+1)%d;
				insert(t->lchild,d,k,i);
			}
			else
			{
				i=(i+1)%d;
				insert(t->rchild,d,k,i);
			}
		}
		else
		{
			if(stoi(k[i])<t->data[i].num)
			{
				i=(i+1)%d;
				insert(t->lchild,d,k,i);
			}
			else
			{
				i=(i+1)%d;
				insert(t->rchild,d,k,i);
			}
		}

	}
}

void preorder(kdptr &t,int d)
{
    if(t!=NULL)
    {
        for(int i=0;i<d;i++)
        {
        	if(t->flag[i]==0)
        	{
        		cout<<t->data[i].ch<<" ";
        	}
        	else
        	{
        		cout<<t->data[i].num<<" ";
        	}
        }
        preorder(t->lchild,d);
        preorder(t->rchild,d);
    }
}

bool compare(kdptr &t,string s[],int d)
{
	for(int i=0;i<d;i++)
	{
		if(t->flag[i]==0)
		{
			if(t->data[i].ch!=s[i][0])
			{
				return false;
			}
		}
		else
		{
			if(t->data[i].num!=stoi(s[i]))
			{
				return false;
			}
		}
	}
	return true;
}

int search(kdptr &t,int d,string k[])
{
	static int i=0;
	if(t==NULL)return 0;
	if(t->flag[i]==0)
	{
		if(t->data[i].ch==k[i][0])
		{
			if(compare(t,k,d))return 1;
		}
		else
		{
			int b1=t->data[i].ch,b2=k[i][0];
			if(b2<b1)
			{
				i=(i+1)%d;
				search(t->lchild,d,k);
			}
			else 
			{
				i=(i+1)%d;
				search(t->rchild,d,k);
			}
		}
	}
	else
	{
		if(t->data[i].num==stoi(k[i]))
		{
			if(compare(t,k,d))return 1;
		}
		else
		{
			if(stoi(k[i])<t->data[i].num)
			{
				i=(i+1)%d;
				search(t->lchild,d,k);
			}
			else
			{
				i=(i+1)%d;
				search(t->rchild,d,k);
			}
		}
	}
}

int main()
{
	cout<<"enter d: ";
	int d;cin>>d;
	cout<<"enter n: ";
	int n;cin>>n;
	string s[d];
	cout<<"enter the numbers or characters\n";
	kdptr t=NULL;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<d;j++)
		{
			cin>>s[j];
		}
		int h=0;
		insert(t,d,s,h);
	}
	preorder(t,d);
	cout<<endl;
	cout<<"enter the node you want to search\n";
	for(int i=0;i<d;i++)
	{
		cin>>s[i];
	}
	cout<<search(t,d,s)<<endl;
} 

//ANOTHER IMPLEMENTATION OF SAME ABOVE CODE

#include<bits/stdc++.h>
using namespace std;
#define d 10

union u{
    char ch;
    int val;
};

struct node{
    union u data[d];
    bool flag[d];
    node* lchild;
    node* rchild;
    node(string s[]){
        for(int i=0;i<d;i++){
            if((s[i][0]-'0')>=0 && (s[i][0]-'0')<=9){
                flag[i]=true;data[i].val=stoi(s[i]);
            }else{
                flag[i]=false;data[i].ch=s[i][0];
            }
        }
        lchild=rchild=NULL;
    }
};

typedef node* kdptr;

kdptr insert_node(kdptr &t,string data[],int &i){
    if(t==NULL){
        return new node(data);
    }else{
        int temp=(i+1)%d;
        if(t->flag[i]){
            if(stoi(data[i])<t->data[i].val){
                t->lchild=insert_node(t->lchild,data,temp);
            }else{
                t->rchild=insert_node(t->rchild,data,temp);
            }
        }else{
            if(data[i][0]<t->data[i].ch){
                t->lchild=insert_node(t->lchild,data,temp);
            }else{
                t->rchild=insert_node(t->rchild,data,temp);
            }
        }
    }
    return t;
}

void preorder(kdptr &t){
    if(t!=NULL){
        for(int i=0;i<d;i++){
            if(t->flag[i])cout<<t->data[i].val<<" ";
            else cout<<t->data[i].ch<<" ";
        }
        cout<<"\t";
        preorder(t->lchild);
        preorder(t->rchild);
    }
}

bool compare(kdptr &t,string s[]){
    for(int i=0;i<d;i++){
        if(t->flag[i]){
            if(t->data[i].val!=stoi(s[i]))return false;
        }else{
            if(t->data[i].ch!=s[i][0])return false;
        }
    }
    return true;
}

bool search(kdptr t,string s[]){
    int i=0;
    while(t!=NULL){
        if(t->flag[i]){
            if(stoi(s[i])<t->data[i].val){
                t=t->lchild;
            }else if(stoi(s[i])>t->data[i].val){
                t=t->rchild;
            }else{
                if(compare(t,s))return true;
                else t=t->rchild;
            }
        }else{
            if(s[i][0]<t->data[i].ch){
                t=t->lchild;
            }else if(s[i][0]>t->data[i].ch){
                t=t->rchild;
            }else{
                if(compare(t,s))return true;
                else t=t->rchild;
            }
        } 
        i=(i+1)%d;   
    }
    return false;
}

int main()
{
    int n;cin>>n;
    string s[d];
    kdptr t=NULL;
    for(int i=0;i<n;i++){
        for(int j=0;j<d;j++){
            cin>>s[j];
        }
        int h=0;
        t=insert_node(t,s,h);
    }
    preorder(t);
    cout<<endl;
    for(int i=0;i<d;i++)
    {
        cin>>s[i];
    }
    cout<<search(t,s)<<endl;
}

#include<bits/stdc++.h>
using namespace std;

struct bstnode{
	int data;
	bstnode* lchild;
	bstnode* rchild;
	bstnode(int val){
		data=val;lchild=NULL;rchild=NULL;
	}
};

typedef bstnode* bstptr;

bstptr create(bstptr &t,int data){
	if(t==NULL){
		t=new bstnode(data);
	}else if(data<t->data){
		t->lchild=create(t->lchild,data);
	}else{
		t->rchild=create(t->rchild,data);
	}
	return t;
}

void preorder(bstptr &t){
	if(t!=NULL){
		cout<<t->data<<" ";
		preorder(t->lchild);
		preorder(t->rchild);
	}
}

void inorder(bstptr &t){
	if(t!=NULL){
		inorder(t->lchild);
		cout<<t->data<<" ";
		inorder(t->rchild);
	}
}

void postorder(bstptr &t){
	if(t!=NULL){
		postorder(t->lchild);
		postorder(t->rchild);
		cout<<t->data<<" ";
	}
}

void level_order(bstptr &t){
	if(t==NULL)return;
	queue<bstptr> q;
	q.push(t);q.push(NULL);
	while(!q.empty()){
		if(q,front()==NULL){
			cout<<endl;
			q.pop();
			if(q.empty())break;
			q.push(NULL);
		}
		bstptr temp=q.front();q.pop();
		cout<<temp->data<<" ";
		if(temp->lchild)q.push(temp->lchild);
		if(temp->rchild)q.push(temp->rchild);
	}
}

void recc_level_order(queue<bstptr> q){
	if(!q.empty()){
		queue<bstptr> util;
		while(!q.empty()){
			bstptr temp=q.front();q.pop();
			cout<<temp->data<<" ";
			if(temp->lchild)util.push(temp->lchild);
			if(temp->rchild)util.push(temp->rchild);
		}
		cout<<endl;
		recc_level_order(util);
	}
}

int min_value(bstptr &t){
	if(t->lchild==NULL)return t->data;
	else return min_value(t->lchild);
}

int max_value(bstptr &t){
	if(t->rchild==NULL)return t->data;
	else return max_value(t->rchild);
}

void preorder_iter(bstptr &t){
	if(t==NULL)return;
	stack<bstptr> s;
	s.push(t);
	while(!s.empty()){
		bstptr temp=s.top();s.pop();
		while(temp!=NULL){
			cout<<temp->data<<" ";
			if(temp->rchild)s.push(temp->rchild);
			temp=temp->lchild;
		}
	}
	cout<<endl;
}

void inorder_iter(bstptr &t){
	if(t==NULL)return;
	stack<bstptr> s;
	bstptr temp=t;
	while(temp!=NULL){
		s.push(temp);
		temp=temp->lchild;
	}
	while(!s.empty()){
		bstptr temp=s.top();s.pop();
		cout<<temp->data<<" ";
		if(temp->rchild!=NULL){
			bstptr t1=temp->rchild;
			while(t1!=NULL){
				s.push(t1);
				t1=t1->lchild;
			}
		}
	}
	cout<<endl;
}

void pathPrint(bstptr &t,vector<int> path){
	if(t==NULL)return;
	else if(t->lchild==NULL && t->rchild==NULL){
		for(int &data:path){
			cout<<data<<" ";
		}cout<<t->data<<endl;
		return;
	}else{
		path.push_back(t->data);
		pathPrint(t->lchild,path);
		pathPrint(t->rchild,path);
	}
}

void range(bstptr &t,int min,int max,int k){
	if(t==NULL)return;
	else if(t->data==k){
		if(t->lchild==NULL && t->rchild==NULL){
			cout<<((min==INT_MIN)?"-inf":to_string(min))<<" to "<<((max==INT_MAX)?"inf":to_string(max))<<endl;
		}else if(t->lchild==NULL){
			cout<<((min==INT_MIN)?"-inf":to_string(min))<<" to "<<min_value(t->rchild)<<endl;
		}else if(t->rchild==NULL){
			cout<<max_value(t->lchild)<<" to "<<((max==INT_MAX)?"inf":to_string(max))<<endl;
		}else{
			cout<<max_value(t->lchild)<<" to "<<min_value(t->rchild)<<endl;
		}
	}else if(k<data){
		range(t->lchild,min,t->data,k);
	}else{
		range(t->rchild,t->data,max,k);
	}
}

bool check_level_order(vector<int> &a){
	if(a.size()<=1)return true;
	queue<pair<int,pair<int,int>>> q;
	q.push({a[0],{INT_MIN,INT_MAX}});int i=1;
	while(!q.empty() && i<a.size()){	
		pair<int,pair<int,int>> temp=q.front();q.pop();
		if(a[i]>temp.second.first && a[i]<temp.first){
			q.push({a[i],{temp.second.first,temp.first}});
			i++;
		}
		if(i==a.size())break;
		if(a[i]>temp.first && a[i]<temp.second.second){
			q.push({a[i],{temp.first,temp.second.second}});
		}
	}
	if(i==a.size())return true;
	else return false;
}

void greater_sum_tree(bstptr &t){
	static int sum=0;
	if(t!=NULL){
		greater_sum_tree(t->rchild);
		if(sum==0){
			sum+=t->data;
			t->data=0;
		}else{
			sum+=t->data;
			t->data=sum;
		}
		greater_sum_tree(t->lchild);
	}
}

bool is_dead(bstptr &t,int min,int max){
	if(t==NULL)return false;
	else if(min==max)return true;
	else return is_dead(t->lchild,min,t->data)||is_dead(t->rchild,t->data,max);
}

void postorder_iter(bstptr &t){
	if(t==NULL)return;
	stack<int> value;
	stack<bstptr> s;
	s.push(t);
	while(!s.empty()){
		bstptr temp=s.top();s.pop();
		value.push(temp->data);
		if(temp->lchild)s.push(temp->lchild);
		if(temp->rchild)s.push(temp->rchild);
	}
	while(!value.empty()){
		cout<<value.top()<<" ";
		value.pop();
	}
}

void zig_zag(bstptr &t){
	if(t==NULL)return;
	stack<bstptr> curr,util;
	curr.push(t);
	bool evenlevel=true;
	while(!curr.empty())
	{
		bstptr temp=curr.top();curr.pop();
		cout<<temp->data<<" ";
		if(evenlevel){
			util.push(temp->lchild);
			util.push(temp->rchild);
		}else{
			util.push(temp->rchild);
			util.push(temp->lchild);
		}
		if(curr.empty()){
			cout<<endl;
			evenlevel=!evenlevel;
			curr=util;while(!util.empty())util.pop();
		}

	}
}

#include<bits/stdc++.h>

using namespace std;

struct bstnode{
    int data;
    bstnode* lchild;
    bstnode* rchild;
    bstnode(int val){
        data=val;
        lchild=NULL;
        rchild=NULL;
    }
};

typedef bstnode* bstptr;
    
bstptr creat(bstptr &t,int data){
    if(t==NULL){
        t=new bstnode(data);
    }else if(data<t->data){
        t->lchild=creat(t->lchild,data);
    }else{
        t->rchild=creat(t->rchild,data);
    }
    return t;
}

void preorder(bstptr &t){
    if(t!=NULL){
        cout<<t->data<<" ";
        preorder(t->lchild);
        preorder(t->rchild);
    }
}

void inorder(bstptr &t){
    if(t!=NULL){
        inorder(t->lchild);
        cout<<t->data<<" ";
        inorder(t->rchild);
    }
}

void postorder(bstptr &t){
    if(t!=NULL){
        postorder(t->lchild);
        postorder(t->rchild);
        cout<<t->data<<" ";
    }
}

void level_order(bstptr &t){
    if(t==NULL)return;
    queue<bstptr> q;
    q.push(t);
    q.push(NULL);
    while(!q.empty()){
        if(q.front()==NULL){
            cout<<endl;
            q.pop();
            if(q.empty())break;
            q.push(NULL);
        }
        bstptr temp=q.front();q.pop();
        cout<<temp->data<<" ";
        if(temp->lchild!=NULL)q.push(temp->lchild);
        if(temp->rchild!=NULL)q.push(temp->rchild);
    }
}

void rec_level_order(queue<bstptr> q){
    if(!q.empty()){
        queue<bstptr> util;
        while(!q.empty()){
            bstptr temp=q.front();q.pop();
            cout<<temp->data<<" ";
            if(temp->lchild)util.push(temp->lchild);
            if(temp->rchild)util.push(temp->rchild);
        }
        cout<<endl;
        rec_level_order(util);
    }
}

int min_value(bstptr &t){
    if(t->lchild==NULL)return t->data;
    else return min_value(t->lchild);
}

int max_value(bstptr &t){
    if(t->rchild==NULL)return t->data;
    else return max_value(t->rchild);
}

void preorder_iter(bstptr t){
    stack<bstptr> s;
    s.push(t);
    while(!s.empty()){
        bstptr temp=s.top();
        s.pop();
        while(temp!=NULL){
            cout<<temp->data<<" ";
            if(temp->rchild!=NULL){
                s.push(temp->rchild);
            }
            temp=temp->lchild;
        }
    }
}

void inorder_iter(bstptr t){
    stack<bstptr> s;
    bstptr t1=t;
    while(t1!=NULL){
        s.push(t1);
        t1=t1->lchild;
    }
    while(!s.empty()){
        bstptr temp=s.top();s.pop();
        cout<<temp->data<<" ";
        if(temp->rchild!=NULL){
            bstptr t1=temp->rchild;
            while(t1!=NULL){
                s.push(t1);
                t1=t1->lchild;
            }
        }
    }
}

void pathPrint(bstptr &t,vector<int> path){
    if(t==NULL)return;
    if(t->lchild==NULL && t->rchild==NULL){
        for(auto &data:path){
            cout<<data<<" ";
        }cout<<t->data<<endl;
        return;
    }else{
        path.push_back(t->data);
        pathPrint(t->lchild,path);
        pathPrint(t->rchild,path);
    }
}

void range(bstptr &t,int min,int max,int k){
    if(t==NULL)return;
    else if(t->data==k){
        if(t->lchild==NULL && t->rchild==NULL){
            cout<<((min==INT_MIN)?"-inf":to_string(min))<<" to "<<((max==INT_MAX)?"+inf":to_string(max))<<endl;
        }else if(t->lchild==NULL){
            cout<<((min==INT_MIN)?"-inf":to_string(min))<<" to "<<min_value(t->rchild)<<endl;
        }else if(t->rchild==NULL){
            cout<<max_value(t->lchild)<<" to "<<((max==INT_MAX)?"+inf":to_string(max))<<endl;
        }else{
            cout<<max_value(t->lchild)<<" to "<<min_value(t->rchild)<<endl;
        }
    }else if(k<t->data){
        range(t->lchild,min,t->data,k);
    }else{
        range(t->rchild,t->data,max,k);
    }
}
struct values{
    int val;int min;int max;
    values(int data,int mi,int ma){
        val=data;min=mi;max=ma;
    }
};

bool check_level(vector<int> &a){
    if(a.size()<=1)return true;
    queue<values> q;
    values temp(a[0],INT_MIN,INT_MAX);int i=1;
    q.push(temp);
    while(!q.empty() && i<a.size()){
        values temp=q.front();q.pop();
        if(a[i]>temp.min && a[i]<temp.val){
            values temp1(a[i],temp.min,temp.val);
            q.push(temp1);
            i++;
        }
        if(i==a.size())break;
        if(a[i]<temp.max && a[i]>temp.val){
            values temp1(a[i],temp.val,temp.max);
            q.push(temp1);
            i++;
        }
    }
    if(i==a.size())return true;
    else return false;
}

void zig_zag_print(bstptr &t){
    if(t==NULL)return;
    stack<bstptr> curr,util;
    curr.push(t);
    bool even_level=true;
    while(!curr.empty()){
        bstptr temp=curr.top();
        cout<<temp->data<<" ";
        curr.pop();
        if(even_level){
            if(temp->lchild)util.push(temp->lchild);
            if(temp->rchild)util.push(temp->rchild);
        }else{
            if(temp->rchild)util.push(temp->rchild);
            if(temp->lchild)util.push(temp->lchild);
        }
        if(curr.empty()){
            cout<<endl;
            curr=util;while(!util.empty())util.pop();
            even_level=!even_level;
        }
    }
}

bool is_dead(bstptr &t,int min,int max){
    if(t==NULL)return false;
    else if(min==max)return true;
    else return is_dead(t->lchild,min,t->data-1)||is_dead(t->rchild,t->data+1,max);
}

void morris_traversal(bstptr &t){
    bstptr curr,pre;
    curr=t;
    //make curr as the root of the tree
    while(curr!=NULL){  // while curr is not null
        if(curr->lchild==NULL){   // if we dont have any node in the left side print the curr node and go to the right
            cout<<curr->data<<" ";
            curr=curr->rchild;
        }else{ // otherwise
            pre=curr->lchild;   // find the inorder predessor i.e the node which 
                                //comes just before the curr node in inorder traversal
            while(pre->rchild!=NULL && pre->rchild!=curr){
                pre=pre->rchild;
            }
            // if the right child is null means we have to process that
            if(pre->rchild==NULL){
                pre->rchild=curr;
                curr=curr->lchild;
            }else{// otherwise if means the we have processed all left nodes now revert changes print curr node 
                // and go to the right side
                pre->rchild=NULL;
                cout<<curr->data<<" ";
                curr=curr->rchild;
            }
        }
    }  
    cout<<endl;  
}

int main()
{
    bstptr t=NULL;
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int data;cin>>data;
        t=creat(t,data);
    }
    // preorder(t);cout<<endl;
    // inorder(t);cout<<endl;
    // postorder(t);cout<<endl;
    morris_traversal(t);
    level_order(t);
    // queue<bstptr> pal;pal.push(t);
    // rec_level_order(pal);
    // vector<int> temp;
    // pathPrint(t,temp);
    // // while(true){
    // //     int data;cin>>data;
    // //     range(t,INT_MIN,INT_MAX,data);
    // // }
    // vector<int> a(n);
    // for(int i=0;i<n;i++)cin>>a[i];
    // cout<<check_level(a)<<endl;
    // zig_zag_print(t);cout<<endl;
}


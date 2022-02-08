#include<iostream>
#include<climits>
#include<queue>
using namespace std;

struct bstnode{
	int data;
	bstnode *left;
	bstnode *right;
};

bstnode *creatnode(int data)
{
	bstnode *temp;
	temp=(bstnode*)new(bstnode);
	temp->data=data;
	temp->left=temp->right=NULL;
	return temp;
}

bstnode *insert(bstnode *root,int data)
{
	if(root==NULL)root=creatnode(data);
	else if(data<=root->data)root->left=insert(root->left,data);
	else root->right=insert(root->right,data);
	return root;
}

void levelorder_display(bstnode *root)
{
	if(root!=NULL)
	{
		queue<bstnode*> q;
		q.push(root);
		bstnode *curr;
		while(!q.empty())
		{
			curr=q.front();
			cout<<curr->data<<"   ";
			if(curr->left!=NULL)q.push(curr->left);
			if(curr->right!=NULL)q.push(curr->right);
			q.pop();
		}
	}
}


bstnode *findmin(bstnode *root)
{
	if(root->left==NULL)return root;
	else return findmin(root->left);
}

bstnode *delet(bstnode *root,int data)
{
	if(root==NULL)return root;
	else if(data<root->data)root->left=delet(root->left,data);
	else if(data>root->data)root->right=delet(root->right,data);
	else{
		//case 1:

		//case 2:
		if(root->left==NULL)
		{
			bstnode *temp=root->right;
			free(root);
			return temp;
		}
		else if(root->right==NULL)
		{
			bstnode *temp=root->left;
			free(root);
			return temp;
		}	
		//case 3: 	
		else{
			bstnode *temp;
			temp=findmin(root->right);
			root->data=temp->data;
			root->right=delet(root->right,temp->data);
		}
	}
	return root;
}

bool checkbst(bstnode *root,int low,int high)
{
	if(root==NULL)return true;
	if(root->data>low&&root->data<high)
	{
		if(checkbst(root->left,low,root->data)&&checkbst(root->right,root->data,high))
		{
			return true;
		}
	}
	else return false;
}

int main()
{
	bstnode *root=NULL;
	cout<<"enter n: ";
	int n;cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"enter a number: ";
		int data;cin>>data;
		root=insert(root,data);
	}
	cout<<"the level order display of the tree is: ";
	levelorder_display(root);
	cout<<endl;
	cout<<"enter the number you want to delete: ";
	int num;cin>>num;
	root=delet(root,num);
	cout<<"the resulting tree is: ";
	levelorder_display(root);
	cout<<endl;
	if(checkbst(root,INT_MIN,INT_MAX))cout<<"the tree is a binary search tree\n";
	else cout<<"the tree is not a binary search tree\n";
}
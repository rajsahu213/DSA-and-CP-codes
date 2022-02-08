#include<bits/stdc++.h>
using namespace std;

struct bstnode{
	int data;
	bstnode *left;
	bstnode *right;
};

bstnode *root=NULL;

void insert()
{
	bstnode *temp,*curr,*par;
	temp=(bstnode*)new(bstnode);
	cout<<"enter a number: ";
	cin>>temp->data;
	temp->right=NULL;
	temp->left=NULL;
	if(root==NULL)
	{
		root=temp;
	}
	else{
		curr=root;
		par=NULL;
		while(1)
		{
			par=curr;
			if(temp->data<par->data)
			{
				curr=curr->left;
				if(curr==NULL)
				{
					par->left=temp;
					return;
				}
			}
			else{
				curr=curr->right;
				if(curr==NULL)
				{
					par->right=temp;
					return;
				}
			}
		}
	}
}

bstnode *findmin(bstnode *root1)
{
	if(root1->left==NULL){return root1;}
	else return findmin(root1->left);
}

bstnode *delet(bstnode *root,int data)
{
	if(root==NULL)
	{
		return root;
	}
	else if(data<root->data)
	{
		root->left=delet(root->left,data);
	}
	else if(data>root->data)
	{
		root->right=delet(root->right,data);
	}
	else{
		if(root->left==NULL&&root->right==NULL)
		{
			delete root;
			root=NULL;
			return root;
		}
		else{
			if(root->left==NULL)
			{
				bstnode *temp;
				temp=root;
				root=root->right;
				delete temp;
				return root;
			}
			else if(root->right==NULL)
			{
				bstnode *temp;
				temp=root;
				root=root->left;
				delete root;
				return root;
			}
			else{
				bstnode *temp=findmin(root->right);
				root->data=temp->data;
			}
		}
	}
}

void preorder(bstnode *root)
{
	if(root!=NULL)
	{
		cout<<root->data<<"  ";
		preorder(root->left);
		preorder(root->right);
	}
}

int main()
{
	cout<<"enter n: ";
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		insert();
	}
	preorder(root);
	cout<<"enter the number: ";
	int data;cin>>data;
	delet(root,data);
	preorder(root);
}
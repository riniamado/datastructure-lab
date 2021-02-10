#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *right;
struct node *left;
}*root;

	struct node* search(struct node *root,int x)
		{
		if(root==NULL || root->data==x)
		return root;
		
		else if(root->data<x)
		return search(root->right,x);
		else
		return search(root->left,x);
		}
	struct node* new_node(int x)
		{
		struct node *p;
		p=(struct node*)malloc(sizeof(struct node));
		if(p==NULL)
		{	
		printf("Unable to allocate memory");
		exit(0);
		}
		p->data=x;
		p->left=NULL;
		p->right=NULL;
		return p;
		}
	struct node* insert(struct node *root,int x)
	{
	if(root==NULL)
	return new_node(x);
	else if(root->data>x)
	root->left=insert(root->left,x);
	else
	root->right=insert(root->right,x);
	return root;
	}
struct node* find_minimum(struct node *root)
	{
	if(root==NULL)
        return NULL;
	if(root->left==NULL)
	return root;
	return find_minimum(root->left);

	}
	struct node* delete(struct node *root,int x)
	{
		if(root==NULL)
		return NULL;
		if(root->data>x)
		root->left=delete(root->left,x);
		else if(root->data<x)
		root->right=delete(root->right,x);
		else
		{
		if(root->left==NULL && root->right==NULL)//no child
		{
		free(root);
		return NULL;
		}
		else if(root->left==NULL || root->right==NULL)            //one child
		{
		struct node *tmp;
		if(root->left==NULL)
		tmp=root->right;
		if(root->right==NULL)
		tmp=root->left;
		free(root);
		return tmp;

		}
		else                                                      //two children
		{struct node *tmp;
		tmp=find_minimum(root->right);
		root->data=tmp->data;
		root->right=delete(root->right,tmp->data);

		}
		}
		return root;
		}
int main()
	{
	int choice,x;
	
	printf("Menu\n1.Insert\n2.Delete\n3.Search\n4.Exit\n");
	do
	{
		printf("Enter your choice ");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:
			printf("Enter data to be inserted");
			scanf("%d",&x);
			if(root==NULL)
			root=new_node(x);
			else
			insert(root,x);
			break;
		case 2:
			printf("Enter data to be deleted");
			scanf("%d",&x);
			root=delete(root,x);
			break;
		case 3:
			printf("Enter data to be searched");
			scanf("%d",&x);
			if(search(root,x)==NULL)
			printf("Not Found");
			else
			printf("Found");
			break;
		case 4:
			exit(0);
		default: 
			printf("Wrong choice\n");
			break;
	}
	}
	while(1);
	return 0;
	};
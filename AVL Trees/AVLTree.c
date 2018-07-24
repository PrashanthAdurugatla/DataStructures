#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<malloc.h>


typedef struct Node
{
	int i;
	struct Node *left;
	struct Node *right;
}node;



node *newNode(int key)
{
    node *a =  ( node *)malloc(sizeof(node));
    a->i = key;
    a->left = a->right = NULL;
    return a;
}


int height(node *root)
{
	int LH, RH;
	if(!root)
		return 0;
	
	LH=height(root->left);
	RH=height(root->right);
	
	if(LH>RH)
		return 1+LH;
		
return 1+RH;

}
int difference(node *root)
{
	int d;

	if(!root)
		return 0;
	
	else
		d = height(root->left)-height(root->right);
		return d;
}

node* rotateRight(node *root)	
{
	node *p;
	p = root->left;
	root->left = p->right;
	p->right = root;
	root = p;
	
}


node* rotateLeft(node *root)	
{
	node *p;
	p = root->right;
	root->right = p->left;
	p->left = root;
	root = p;
	
}

node* rotateLeftRight(node *root)
{
	rotateLeft(root->right);
	rotateRight(root);
	return root;
}

node* rotateRightLeft(node *root)
{
	rotateRight(root->right);
	rotateLeft(root);
	return root;
}

node* balance(node *root)	
{
	if(difference(root)==2)
	{
		if(difference(root->left)==1)
			return rotateRight(root);	
		
		else 
			return rotateLeftRight(root);
	
	}
	
	else if (difference(root)==-2)
	{
		if(difference(root->right)==-1)
			return rotateLeft(root);
		else
			return rotateRightLeft(root);

	}

return root;
}














node * insert(node *root, int key);
node *removee(node *root, int key);
bool search(node *root, int key);
void print(node *root);
void clear(node *root);


void menu()
{
	
	printf("\n1. To Insert a Node");
	printf("\t2. To Remove a Node");
	printf("\t3. To Search a Node");
	printf("\n4. To Print all Nodes");
	printf("\t5. To Clear the Tree");
	printf("\t-1. To Exit" );
	
}


int main()
{
	node *root=NULL;
	int value, key;
	menu();
	
	while(1)
	{
		printf("\n\nEnter a value to perform Operation: ");
		scanf("%d",&value);
		
		if(value==-1)
			break;
			
			
		switch(value)
		{
			case 0:
				printf("\tError");
				break;
				
			case 1:
				printf("\tEnter a key to Insert: ");
				scanf("%d",&key);
				root=insert(root, key);
				break;
				
			case 2:
				printf("\tEnter a key to Remove: ");
				scanf("%d",&key);
				root=removee(root, key);
				break;
			
			case 3:
				printf("\tEnter a key to Search: ");
				scanf("%d",&key);
				printf("\tSearching for a node: ");
				search(root, key);
				break;
				
			case 4:
				printf("\tInorder method is used to Print : ");
				print(root);
				break;
				
			case 5:
				printf("\tClearing all nodes in the Tree: ");
				clear(root);
				break;
		}
	}
}




node * insert(node *root, int key)
{

	if(!root)
	{
		 node *a =  ( node *)malloc(sizeof(node));
	    a->i = key;
	    a->left = a->right = NULL;
	    return a;
	}
		
	else if(key<root->i)
		root->left=insert(root->left, key);	
			
	else
		root->right=insert(root->right, key);	
			
	return balance(root);
	

}

node *removee(node *root, int key)
{
	if(!root)
		printf("\nTree is Empty ");
	
	else if(key<root->i)
		removee(root->left, key);
	
	else if(key>root->i)
		removee(root->right, key);
		
	else
	{
		if(!root->left&&!root->right)	
			free(root);
		
		else if(root->left&&!root->right)
		{
			node *a = root;
			root=root->left;
			free(a);
		}
		
		else if(root->left&&!root->right)
		{
			node *a = root;
			root=root->right;
			free(a);
		}
		
		else
		{
			node *a = root->right;
			while(a->left)
				a=a->left;
			
			a->left=root->left;
			a=root;
			root=root->right;
			free(a);
		}
	}	
		
	return balance(root);	
		
}

bool search(node *root, int key)
{
	if(!root)		
		return 0;
	
	
	if(key==root->i)
		return 1;
	
		
	else if(key<root->i)	
		return(search(root->left, key));
		
		
	else if(key>root->i)
		return(search(root->right, key));
	
	
}

void print(node *root)
{
	
	if(!root)
		printf("Tree is Empty");

	else
	{
		if(root->left)
			print(root->left);
		printf("%d==>", root->i);
		if(root->right)
			print(root->right);
	}
	
}

void clear(node *root)
{
	if(root)
	{
		if(root->left)
			clear(root->left);
		if(root->right)
			clear(root->right);
		free (root);
	}
	
	else
		printf("Tree is Empty");

}




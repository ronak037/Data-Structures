#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
}node;

node* root=NULL;
node* extra=NULL;

void insertnode(int data)								//function for creating binary search tree
{
	node* par;
	node* newnode=(node*)malloc(sizeof(node));
	newnode->data=data;
	newnode->left=NULL;
	newnode->right=NULL;
	
	if(root==NULL)
		root=newnode;
	else
	{
		par=root;
		while(par!=NULL)
		{
			if(par->data>data)
			{	
				if(par->left==NULL)
				{
					par->left=newnode;
				}
				par=par->left;
			}
			else if(par->data<data)
			{
				if(par->right==NULL)
				{
					par->right=newnode;
				}
				par=par->right;
			}
			else
			{
				par=NULL;
			}
		}//end of while
	}//end of else
}//end of insertnode function

void inorder(node* root)										//function for inorder traversing
{
	if(root==NULL)
		return;
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
}

node* max(node* root)											//function to find max node
{
	while(root->right!=NULL)
	{
		root=root->right;
	}
	return root;
}

node* deletenode(node* root,int data)
{
	node* temp;
	if(root==NULL)
	{
		printf("Elements not exist!!\n");
		return NULL;
	}
	if(root->data>data)
	{
		root->left=deletenode(root->left,data);
	}
	else if(root->data<data)
	{
		root->right=deletenode(root->right,data);
	}
	else														//it implements when element founds
	{
		if(root->left && root->right)							//for both children
		{
			temp=max(root->left);
			root->data=temp->data;
			root->left=deletenode(root->left,root->data);
		}
		else 															// one or no child
		{
			temp=root;
			if(root->left==NULL)
			{
				root=root->right;
			}
			else if(root->right==NULL)
			{
				root=root->left;
			}
			free (temp);
		}
	}			//end of else
	return root;
}				//end of function

int main()
{
	int n;
	printf("Enter number how many elements you want to enter: ");
	scanf("%d",&n);
	int data;
	printf("Now enter elements: ");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&data);
		insertnode(data);
	}
	inorder(root);
	
	extra=root;
	printf("\n");
	printf("Now enter element you want to delete: ");
	scanf("%d",&data);
	deletenode(extra,data);
	printf("\nNow the binary search tree look like this: ");
	inorder(root);
	printf("\n");
	return 0;
}

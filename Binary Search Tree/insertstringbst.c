#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct course
{
    char courseid[15];
    char coursename[20];
}course;

typedef struct node
{
	course data;
	struct node *left;
	struct node *right;
}node;

node* insertnode(node* root)								//function for creating binary search tree
{
	node* temp;
	node* newnode=(node*)malloc(sizeof(node));
	newnode->left=NULL;
	newnode->right=NULL;

	printf("Enter course id: ");
	scanf("%s",newnode->data.courseid);
	printf("Enter course name: ");
	scanf("%s",newnode->data.coursename);
	
	if(root==NULL)
		root=newnode;
	else
	{
		temp=root;
		int cmp;
		while(temp!=NULL)
		{
			cmp=strcmp(temp->data.courseid,newnode->data.courseid);			//compare which string is large according to dictionary
			if(cmp>0)		//return cmp>0 when next string is short than first
			{	
				if(temp->left==NULL)
				{
					temp->left=newnode;
				}
				temp=temp->left;
			}
			else if(cmp<0)		//return cmp>0 when next string is longer than first
			{
				if(temp->right==NULL)
				{
					temp->right=newnode;
				}
				temp=temp->right;
			}
			else
			{
				temp=NULL;
			}
		}//end of while
	}//end of else
	return root;
}//end of insertnode function

void inorder(node* root)										//function for inorder traversing
{
	if(root==NULL)
		return;
	inorder(root->left);
	printf("\n%s\t%s\n ",root->data.courseid,root->data.coursename);
	inorder(root->right);
}

int main()
{
	int n;
	printf("Enter number how many elements you want to enter: ");
	scanf("%d",&n);
	node* root=NULL;
	for(int i=0;i<n;i++)
	{
		root=insertnode(root);
	}
	printf("\nNow the binary search tree look like this: ");
	inorder(root);
	printf("\n");
	return 0;
}

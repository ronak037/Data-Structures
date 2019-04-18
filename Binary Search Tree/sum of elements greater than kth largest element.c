#include<stdio.h>
#include<stdlib.h>

//This is the code to find the sum of all elements greater than kth largest element

				/* THE MAIN IDEA OF THIS CODE*/
/*
We will go to the right end node of the tree as this will give us the maximum value of that tree
then we will traverse the 2nd largest element and so on and then we will update the sum to that number then
we also increase the value of extra variable as we will add these numbers till which the user tells
us to calculate the sum.
*/

typedef struct bstnode                                 //defining structure for binary search tree
{
	int data;
	struct bstnode* left;
	struct bstnode* right;
}bstnode;

void insertnode(bstnode** root,int data)				//function to create binary search tree
{
	bstnode* temp;
	bstnode* newnode=(bstnode*)malloc(sizeof(bstnode));//creating newnode
	newnode->data=data;
	newnode->left=NULL;
	newnode->right=NULL;
	if(*root==NULL)										//return data if root is null
	{
		*root=newnode;
	}
	else
	{
		temp=*root;
		while(temp!=NULL)
		{
			if(temp->data>data)							//compare data with root data and then insert that data at its right place
			{
				if(temp->left==NULL)
				{
					temp->left=newnode;
				}
				temp=temp->left;
			}
			else if(temp->data<data)
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
}//end of function

int sum,value=0;

void findsum(bstnode* root,int k)									//function to calculate sum by traversing tree from right end and updating the sum according
{																	//to the value of k inserted by the user 
	if(root==NULL)
	{
		return;
	}
	
	findsum(root->right,k);
	
	value++;
	if(value<=k-1)
	{
		sum=sum+root->data;
	}
	
	findsum(root->left,k);
}//end of function

int main()
{
	int num;
	printf("Enter how many num you want to insert:");				//taking how many elements you want to enter
	scanf("%d",&num);
	printf("Now enter elements:");
	int data;
	bstnode* root=NULL;
	for(int i=0;i<num;i++)
	{
		scanf("%d",&data);												//taking elements and create tree
		insertnode(&root,data);
	}
	
	int k;
	printf("Enter the value of k:");
	scanf("%d",&k);
	findsum(root,k);												//calling function to calculate sum
	printf("The sum is %d\n",sum);
	return 0;
}

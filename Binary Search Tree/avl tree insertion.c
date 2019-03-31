#include <stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
    int height;
}node;

//creating newnode
node* newnode(node* root,int data)
{
    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    newnode->height=1;
    return newnode;
}

//function for finding the height of node
int getheight(node* node)
{
    if(node==NULL)
    {
        return 0;
    }
    return node->height;
}

//function to find max 
int max(int x,int y)
{
    if(x>y)
    {
        return x;
    }
    else
    {
        return y;
    }
}

//function to find the value of balance factor
int balancefactor(node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    return getheight(root->left) - getheight(root->right);
}

//function for right rotation
struct node* rightrotation(node* root)
{
    node* extranode = root->left;
    node* garbage = extranode->right;

    //rotation occurs
    extranode->right=root;
    root->left=garbage;

    //returning new node
    return extranode;
}

//function for left rotation
struct node* leftrotation(node* root)
{
    node* extranode = root->right;
    node* garbage = extranode->left;

    //rotation occurs
    extranode->left=root;
    root->right=garbage;

    //returning new node
    return extranode;
}


struct node* insertnode(node* root,int data)
{
    if(root==NULL)
    {
        return newnode(root,data);
    }
    else if(data<root->data)
    {
        root->left=insertnode(root->left,data);
    }
    else if(data>root->data)
    {
        root->right=insertnode(root->right,data);
    }
    else
    {
        return NULL;
    }

    //getting height of node
    root->height=1+(max(getheight(root->left),getheight(root->right)));

    //checking balance factor here
    int balance;
    balance=balancefactor(root);

    //LL rotation case;
    if(balance>1 && data < root->left->data)
    {
        return rightrotation(root);
    }
    //RR rotation case
    else if(balance<-1 && data > root->right->data)
    {
        return leftrotation(root);
    }
    //LR rotation case
    else if(balance>1 && data > root->left->data)
    {
        root->left = leftrotation(root->left);
        return rightrotation(root);
    }
    //RL rotation case
    else if(balance<-1 && data < root->right->data)
    {
        root->right = rightrotation(root->right);
        return leftrotation(root);
    }

    return root;
}

void inorder(node* root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d  ",root->data);
    inorder(root->right);
}

int main()
{
    node* root=NULL;

    //inserting element
    int num,data;
    printf("Enter how many elements you want to enter: ");
    scanf("%d",&num);
    printf("Enter elements:");
    for(int i=0;i<num;i++)
    {
        scanf("%d",&data);
        root=insertnode(root,data);
    }

    printf("Now inorder arrangement of this binary search tree is:");
    inorder(root);
    printf("\n");
    return 0;
}
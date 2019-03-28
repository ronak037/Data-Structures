#include<iostream>
using namespace std;

typedef struct bstnode
{
    int data;
    struct bstnode *left;
    struct bstnode *right;
}bstnode;

void insertnode(bstnode **root,int data)
{
    bstnode* temp;
    bstnode* newnode=(bstnode*)malloc(sizeof(bstnode));
    newnode->left=NULL;
    newnode->data=data;
    newnode->right=NULL;

    if(*root==NULL)
    {
        *root=newnode;
    }
    else
    {
        temp=*root;
        while(temp!=NULL)
        {
            if(temp->data>data)
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
            
        }
    }
    
}

void inorder(bstnode* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void find(bstnode* root,int data)                               //function to find element in bst
{
    if(root==NULL)
    {
        cout<<"Element not found!!\n";
    }
    if(root->data>data)
    {
        if(root->left==NULL)
        {
            cout<<"Element not found\n";
            return;
        }
        find(root->left,data);
    }
    else if(root->data<data)
    {
        if(root->right==NULL)
        {
            cout<<"Element not found\n";
            return;
        }
        find(root->right,data);
    }
    else
    {
        cout<<"Element found!!\n";
    }
    
}

bstnode *root=NULL;
int main()
{
    int n;
    cout<<"Enter how many elements you want to enter: ";
    cin>>n;
    int data;
    printf("Now enter elements: ");
    for(int i=0;i<n;i++)
    {
        cin>>data;
        insertnode(&root,data);
    }    
    inorder(root);

    cout<<"\nEnter which number you want to search in this: ";
    cin>>data;
    find(root,data);
    return 0;
}
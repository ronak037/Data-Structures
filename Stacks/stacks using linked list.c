#include<stdio.h>
#include<stdlib.h>

typedef struct stack
{
    int data;
    struct stack *next;
}stack;

void print(stack *head)
{
    while(head!=NULL)
    {
        printf("%d\n",head->data);
        head = head->next;
    }
}

void push(stack **head,int ele)
{
    stack *newnode = (stack*)malloc(sizeof(stack));
    newnode->data=ele;
    newnode->next = *head;
    *head=newnode;
    print(*head);
}

void pop(stack **head)
{
    if(*head == NULL)
	{
		printf("Stack is already empty!!\n");
	}
	else
	{
		*head=(*head)->next;
		print(*head);
	}
}

int main()
{
    stack *head = (stack*)malloc(sizeof(stack));
    head=NULL;
    int opt = 0;
	while(opt!=3)
	{
		printf("1. for push\n2. for pop\n3. exit\n");
		printf("Enter your option:");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1: printf("Enter element:");
					int ele;
					scanf("%d",&ele);
					push(&head,ele);
					printf("\n");
					break;
			case 2: pop(&head);
					printf("\n");
					break;
			case 3: exit(0);
					printf("\n");
					break;
		}
	}
}
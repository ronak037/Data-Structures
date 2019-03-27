#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXLIMIT 100

typedef struct stack
{
    int top;
    int arr[MAXLIMIT];
}stack;

void print(stack *start)
{
    int temp;
    temp = start->top;
    while(temp!=-1)
    {

        printf("%d\n",start->arr[temp--]);
    }
}

void push(stack *start,int ele)
{
    if(start->top==(MAXLIMIT-1))
    {
        printf("stack is full\n");
        return;
    }
    start->top++;
    start->arr[start->top]=ele;
    print(start);
}

void pop(stack *start)
{
    if(start->top == -1)
    {
        printf("stack is empty\n");
        return;
    }
    start->arr[--start->top];
    print(start);
}

void top(stack *start)
{
    printf("%d\n",start->arr[start->top]);
}

void isempty(stack *start)
{
    if(start->top==-1)
    {
        printf("stack is empty\n");
    }
    else
        printf("stack is non-empty\n");
}

int main()
{
    stack *start = (stack*)malloc(sizeof(stack));
    start->top=-1;
    int opt = 0;
	while(opt!=5)
	{
		printf("1. for push\n2. for pop\n3. for access to top element\n4. for check empty\n5. exit\n");
		printf("Enter your option:");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1: printf("Enter element:");
					int ele;
					scanf("%d",&ele);
					push(start,ele);
					printf("\n");
					break;
			case 2: pop(start);
					printf("\n");
					break;
			case 3: top(start);
					printf("\n");
					break;
			case 4: isempty(start);
					printf("\n");
					break;
			case 5: exit(0);
					printf("\n");
					break;
            default:exit(0);
		}
	}
    return 0;
}

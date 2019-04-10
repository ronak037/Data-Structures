//Hashing code to find the required sum
#include<stdio.h>
#include<stdlib.h>

//to return tdata into the form of index
int hash(int data,int n)
{
	int rem;
	rem=data%n;
	if(data>=0)
	{
		return rem;
	}
	else
	{
		return (-1)*rem;
	}
}


int main()
{
	int n1,n2;
	printf("Enter how many number you want to enter in 1st and 2nd array:");
	scanf("%d%d",&n1,&n2);
	int a[n1],b[n2];
	printf("Now enter elements of first array:");
	for(int i=0;i<n1;i++)
	{
		a[i]=0;
		b[i]=0;
	}
	for(int i=0;i<n1;i++)
	{
		int data,x;
		scanf("%d",&data);
		x=hash(data,n1);
		if(a[x]==0)
		{
			a[x]=data;											//if place is empty then fill value here
		}
		else													//otherwise check which place is empty and put the data there
		{
			for(int j=x+1;;)
			{
				j=j%n1;
				if(a[j]==0)
				{
					a[j]=data;	
					break;
				}
				j++;
			}
		}
	}
	printf("Now enter elements of second array:");
	for(int i=0;i<n2;i++)
	{
		int data,x;
		scanf("%d",&data);
		x=hash(data,n2);
		if(b[x]==0)
		{
			b[x]=data;
		}
		else
		{
			for(int j=x+1;;)
			{
				j=j%n2;
				if(b[j]==0)
				{
					b[j]=data;
					break;
				}
				j++;
			}
		}
	}
	
	int x;
	printf("Enter the number you want to get as a sum:");
	scanf("%d",&x);
	
	
	int sub,r,extra;
	for(int i=0;i<n2;i++)													//print the sum by taking element from second array then find its corresponding number which makes the sum  by checking the different positions of other array
	{
		sub=x-b[i];
		r=sub%n1;
		if(a[r]==sub)
		{
			printf("(%d,%d)\n",a[r%n1],b[i]);
		}
		else
		{
			for(int j=r+1;;)
			{
				extra=r;
				
				j=j%n1;
				if(a[j]==sub)
				{
					printf("(%d,%d)\n",a[j],b[i]);
					break;
				}
				j++;
				if(j==extra)
				{
					break;
				}
			}
		}
	}
}

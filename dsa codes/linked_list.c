#include <stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *next;
	} *start=NULL;

//create linked list
void create(int x)
{
	struct node *ptr,*temp;
	ptr=(struct node *)malloc(sizeof(struct node));
	ptr->data=x;
	ptr->next=NULL;
	if (start ==NULL)
	{
		start=ptr;
	}
	else
	{
		temp=start;
		while(temp->next != NULL)
		{
			temp=temp->next;
		}
		temp->next=ptr;
	}
}

//dispaly linked list
void traverse ()
{
	struct node *temp=start;
	while (temp != NULL)
	{
		printf("%d\n",temp->data);
		temp=temp->next;
	}
}
int main(){
	int n;
	printf("enter no of elements :");
	scanf("%d",&n);
	printf("enter elements :");
	for (int i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		create(x);
	}
	printf("The linked list is :\n");
	traverse();
	return 0;
}

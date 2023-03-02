#include <stdio.h>
#include <stdlib.h>
struct node{
	int coeff;
	int exp;
	struct node *next;
}*start=NULL;

void create(int c,int e)
{
	struct node *ptr;
	ptr=(struct node *)malloc(sizeof(struct node));
	ptr->coeff = c;
	ptr->exp = e;
	ptr->next = NULL;
	if (start == NULL)
		start = ptr;
	else
	{
		struct node *temp;
		temp = start;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = ptr;
	}
}

void traverse()
{
	struct node *temp = start;
        while (temp != NULL)
        {
                printf("%dx^%d  ",temp->coeff,temp->exp);
                temp = temp->next;
        }
}

int main(){
	int n,c,e;
	printf("enter no of element:");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("enter coeff and exp");
		scanf("%d",&c);
		scanf("%d",&e);
		create(c,e);
	}
	traverse();
}

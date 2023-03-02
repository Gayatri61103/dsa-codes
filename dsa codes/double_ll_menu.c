#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node*next;
	struct node *prev;
	}*start=NULL,*last=NULL;
//create a node in ll
void create(int x)
{
	struct node *ptr;
	ptr=(struct node *)malloc(sizeof(struct node));
	ptr->data=x;
	ptr->next=ptr->prev=NULL;
	if (start==NULL)
	{
		start=ptr;
		last=ptr;
	}
	else
	{
		last->next=ptr;
		ptr->prev=last;
		last=ptr;
	}
}
//traverse
void traverse()
{
	struct node *temp;
	temp=start;
	while(temp !=NULL)
	{
		printf("%d  ",temp->data);
		temp=temp->next;
	}
}
//insert at the beginning
void ins_beg(int x)
{
	struct node *ptr;
        ptr=(struct node *)malloc(sizeof(struct node));
        ptr->data=x;
        ptr->next=ptr->prev=NULL;
        if (start==NULL)
        {
                start=ptr;
                last=ptr;
        }
	else
	{
		ptr->next=start;
		start->prev=ptr;
		start=ptr;
	}
	printf("\nThe linked list is :\n");
        traverse();
}
//insert at the end
void ins_end(int x)
{
	struct node *ptr;
        ptr=(struct node *)malloc(sizeof(struct node));
        ptr->data=x;
        ptr->next=ptr->prev=NULL;
        if (start==NULL)
        {
                start=ptr;
                last=ptr;
        }
        else
        {
                last->next=ptr;
                ptr->prev=last;
                last=ptr;
        }
	printf("\nThe linked list is :\n");
        traverse();
}
//insert spec loc
void ins_loc(int x)
{
        printf("\ninsertion at the specific location");
        struct node *ptr,*temp;
        ptr=(struct node *)malloc(sizeof(struct node));
        ptr->data=x;
        ptr->next=ptr->prev=NULL;
        int loc;
        printf("\nenter a location to insert the element :");
        scanf("%d",&loc);
        if (start==NULL)
                printf("linked list is empty");
        else{
                temp=start;
                for (int i=0;i<loc-1;i++)
                        temp=temp->next;
                if (temp !=NULL){
                        ptr->next=temp->next;
			(temp->next)->prev=ptr;
                        temp->next=ptr;
			ptr->prev=temp;
                }
                else
                        printf("location not found");
        }
	printf("\nThe linked list is :\n");
        traverse();
}
//deletion from beg
void del_beg()
{
	struct node *temp;
	if (start == NULL)
	{
		printf("ll is empty");
	}
	else
	{
		temp = start;
		start = start->next;
		start->prev = NULL;
		free (temp);
	}
	printf("\nThe linked list is :\n");
        traverse();
}
//deletion from end
void del_end()
{
	struct node *temp;
	if (start == NULL)
		printf("ll empty");
	else
	{
		temp = last;
		last = last -> prev;
		last -> next = NULL;
		free (temp);
	}
	printf("\nThe linked list is :\n");
        traverse();
}
//deletion from spec location
void del_loc()
{
	printf("\ndeletion at a particular location");
        struct node *temp,*prev1;
        printf("\nenter a location which u want to delete:");
        int loc;
        scanf("%d",&loc);
        if (start ==NULL)
                printf("list is empty\n");
        else
        {
                temp=start;
                for(int i=0;i<loc;i++){
                	prev1=temp;
                        temp=temp->next;
                }
                if (temp != NULL)
                {
                        prev1->next=temp->next;
			(temp->next)->prev= prev1;
                        free (temp);
                }
	}
        printf("\nThe linked list is :\n");
        traverse();
}

int main()
{
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
	x:
        printf("\nmenu:\n");
        printf("1.insertion at the beginning\n2.insertion at the end\n3.insertion at the specific location\n");
        printf("4.delete at the beginning\n5.delete at the end\n6.delete at a location\n7.exit\n");
        printf("\nenter your choice :");
        int ch,t;
        scanf("%d",&ch);
        switch(ch-1)
        {
                case 0:
                        printf("\nelement which u want to insert :");
                        scanf("%d",&t);
                        ins_beg(t);
                        break;
                case 1:
                        printf("\nelement which u want to insert :");
                        scanf("%d",&t);
                        ins_end(t);
                        break;
                case 2:
                        printf("\nelement which u want to insert :");
                        scanf("%d",&t);
                        ins_loc(t);
                        break;
                case 3:
                        del_beg();
                        break;
                case 4:
                        del_end();
                        break;
                case 5:
                        del_loc();
                        break;
		case 6:
			break;
	}
	if (ch <7){
                printf("\ndo you want to continue ??\n y=1 or n=0 :");
                int c;
                scanf("%d",&c);
                if (c==1)
                        goto x;
        }
        return 0;
}

#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node *next;
	}*start=NULL;
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
//inserting node in the beginning
void insn_beg(int x){
	struct node *ptr;
	ptr=(struct node *)malloc(sizeof(struct node));
	ptr->data=x;
	ptr->next=NULL;
	if (start==NULL)
		start=ptr;
	else{
		ptr->next=start;
		start=ptr;
	}
}
//display
void traverse ()
{
        struct node *temp=start;
        while (temp != NULL)
        {
                printf("%d  ",temp->data);
                temp=temp->next;
        }
}
int main(){
        int n,t;
        printf("enter no of elements :");
        scanf("%d",&n);
        printf("enter elements :");
        for (int i=0;i<n;i++)
        {
                int x;
                scanf("%d",&x);
                create(x);
        }
	printf("enter element to be inserted :");
	scanf("%d",&t);
	insn_beg(t);
	printf("insering %d in the beginning of the l.l\n",t);
        printf("The linked list is :\n");
        traverse();
        return 0;
}

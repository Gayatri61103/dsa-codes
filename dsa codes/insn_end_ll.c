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
//inseting ea node at the end
void insn_end(int x){
        struct node *ptr,*temp;
        ptr=(struct node *)malloc(sizeof(struct node));
        ptr->data=x;
        ptr->next=NULL;
        if (start==NULL)
                start=ptr;
        else{
                temp=start;
                while (temp->next !=NULL)
			temp=temp->next;
		temp->next=ptr;
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
        insn_end(t);
        printf("insering %d in the end of the l.l\n",t);
        printf("The linked list is :\n");
        traverse();
        return 0;
}

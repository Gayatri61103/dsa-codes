#include <stdio.h>
#include <stdlib.h>
struct node {
	int priority;
        int data;
        struct node *next;
}*front = NULL,*rear = NULL;

//insertion
void insertion ()
{
        int x,p;
        printf("enter ele to insert and its priority :");
        scanf("%d %d",&x,&p);
        struct node *ptr;
        ptr = (struct node* )malloc(sizeof(struct node ));
        ptr->data = x;
	ptr->priority = p;
        ptr->next = NULL;
        if (front == NULL && rear == NULL)
        {
                front = ptr;
                rear = ptr;
        }
        if(front->priority > ptr->priority){
                ptr->next = front;
                front = ptr;
        }
	//else
	//{
		struct node *temp,*prev;
		temp=front;
		while (temp->priority < ptr->priority)
		{
			prev=temp;
			temp= temp->next;
		}
		ptr->next= temp;
		prev->next = ptr;
	//}
}

//deletion
void deletion()
{
        struct node *temp;
        if(front == NULL && rear == NULL)
        {
                printf (" queue is empty ");
        }
        else if (front == rear)
        {
                free (front);
                front = rear = NULL;
        }
        else
        {
                temp = front;
                front = temp->next;
                free (temp);
        }
}

//display
void display()
{
        struct node *temp;
        temp = front;
        while (temp!=NULL)
        {
                printf("%d %d | ", temp->data,temp->priority);
                temp = temp->next;
        }
}

int main(){
        x:
        printf("menu:\n1.insert in queue\n2.delete from queue\n3.display\n");
        printf("enter your choice..");
        int ch,t;
        scanf("%d",&ch);
        switch(ch-1)
        {
                case 0:
                        insertion();
                        break;
                case 1:
                        deletion();
                        break;
                case 2:
                        display();
        }
        if (ch <3){
                printf("\ndo you want to continue ??\n y=1 or n=0 :");
                int c;
                scanf("%d",&c);
                if (c==1)
                        goto x;
        }
        return 0;
}

#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int ex;
    int co;
    struct node* next;
}Node;
Node* insert_poly_node(Node *start , int co, int ex)
{
    Node *ptr, *temp;
    temp = malloc(sizeof(Node));
    temp->co = co;
    temp->ex = ex;
    temp->next = NULL;
    
    if(start==NULL)
    {
        start =  temp;
    }
    else
    {
        ptr = start;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next = temp;
    }
    return (start);
}
Node* create_poly(Node *start)
{
    int i,n,ex,co;
    printf("How many terms do you want to enter: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the exponent: ");
        scanf("%d",&ex);
        printf("Enter the coefficient: ");
        scanf("%d",&co);
        start = insert_poly_node(start,co,ex);
    }
    return start;
}
Node* add_poly(Node *p1, Node *p2)
{
    Node *p3 = NULL;
    if(p1 == NULL && p2==NULL)
    {
        return p3;
    }
    while(p1!=NULL && p2!=NULL)
    {
        if(p1->ex >p2->ex)
        {
            p3 = insert_poly_node(p3,p1->co,p1->ex);
            p1 = p1->next;
        }
        else if(p2->ex > p1->ex)
        {
            p3 = insert_poly_node(p3,p2->co,p3->ex);
            p2 = p2->next;
        }
        else
        {
            p3 = insert_poly_node(p3,(p1->co+p2->co), p1->ex);
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    while(p1!=NULL)
    {
        p3 = insert_poly_node(p3,p1->co,p1->ex);
        p1 = p1->next;
    }
    while(p2!=NULL)
    {
        p3 = insert_poly_node(p3,p2->co,p2->ex);
        p2 = p2->next;
    }
    return p3;
}
void show_poly(Node *poly)
{
    if(poly==NULL)
    {
        printf("Empty\n");
        return;
    }
    while(poly->next!=NULL)
    {
        printf("(%dx^%d)+",poly->co,poly->ex);
        poly = poly->next;
    }
    printf("(%dx^%d)",poly->co,poly->ex);
    printf("\n");
}

int main()
{
    int choice;
    Node *poly_1=NULL,*poly_2=NULL,*poly_3=NULL;
    printf("Create first expression\n");
    poly_1=create_poly(poly_1);
    printf("the first expression is :\n");
    show_poly(poly_1);
    printf("Create second expression\n");
    poly_2 =  create_poly(poly_2);
    printf("the second expression is :\n");
    show_poly(poly_2);
    poly_3 = add_poly(poly_1,poly_2);
    printf("\nthe added polynomial is :\n");
    show_poly(poly_3);
    return 0;
}



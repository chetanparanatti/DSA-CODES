//CSLL
#include<stdlib.h>
#include<stdio.h>
typedef struct NODE
{
    int data;
    struct NODE *next;
}*node;

node insert_rear(node head);
node getnode();
node delete_front(node head);
node insert_front(node head);
node delete_rear(node head);
node delete_pos(node head);


node getnode()
{
    node temp;
    printf("Enter the data\n");
    scanf("%d",&temp->data);
    temp->next=NULL;
}

main()
{
    node head=NULL;
    int choice;
    printf("Enter choice\t1.INSERT NODE\n2.INSERT REAR\n3.DISPLAY\n4.DELETE FRONT\n5.DELETE REAR\n6.DELETE POS\n7.INSERT POS\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 2:printf("\nEnter the data\n");
          head=insert_rear(head);
          break;

        case 1:printf("Insert front:\n");
          head=insert_front(head);
          break;

        case 3:printf("\nDisplay list inserted\n");
          display_list(head);
          break;

        case 4:printf("Delete front element:\n");
          head=delete_front(head);
          break;

        case 5:printf("Delete last element:\n");
          head=delete_rear(head);
          break;

        case 6:printf("DELETE POSITION\n");
          head=delete_rear(head);
          break;

        defaultprintf("Invalid user choice\n");
            exit(0);
            break;
    }
}
node insert_front(node head)
{
    node temp,cur;
    temp= getnode();

    if(head == NULL)
    {
       head=temp;
       head->next=head;
    }
    else
    {   cur= head;
    while(cur->next != head)
    cur=cur->next;
    cur->next=temp;
    temp->next=head;
    head= temp;  // if INSERT at end..just remove this statement
    }
    return head;
}
node insert_rear(node head)
{
    node temp,cur;
    temp= getnode();

    if(head == NULL)
    {
       head=temp;
       head->next=head;
    }
    else
    {   cur= head;
    while(cur->next != head)
    cur=cur->next;
    cur->next=temp;
    temp->next=head;
    }
    return head;
}
void display(node head)
{
     node cur;
     if (head == NULL)
     printf("Empty\n");
     else if (head->next == head)
     printf("%d",head->data);
     else
     {
        cur=head;
        while (cur->next !=head)
        {
           printf("%d\t",cur->data);
           cur= cur->next;
        }
        printf("%d",cur->data);
    }
}
node delete_front(node head)
{
    node cur;
    if( head == NULL)
    {
        printf("Empty\n");
        return NULL;
    }
    else if (head->next == head)
    {
        printf("Deleted :%d",head->data);
        free(head);
        return NULL;
    }
    else
    {cur=head;
    while(cur->next != head)
    {
        cur=cur->next;
    }
    cur->next=head->next;
    printf("Deleted:%d",head->data);
    free(head);
    head=head->next;
    return head;
}
node delete_rear(node head)
{
    node cur,prev;
     if( head == NULL)
    {
        printf("Empty\n");
        return NULL;
    }
    else if (head->next == head)
    {
        printf("Deleted :%d",head->data);
        free(head);
        return NULL;
    }
    else
    {   cur=head;
        prev=NULL;

    while(cur->next != head)
    {
        prev=cur;
        cur=cur->next;

    }
    prev->next=head;
    printf("Deleted:%d",cur->data);
    free(cur);
    return head;
    }
}
node delete_pos(node head)
{
    int pos,c;
    node cur,prev,ptr;
    if (head==NULL)
    printf("Empty");

    else
    {
        printf("Enter position\n");
        scanf("%d",&pos);
        if(pos==1 && head->next==head)
        {
            printf("Deleted:%d",head->data);
            free(head);
            head=NULL;
        }
        else if(pos==1)
        {
            ptr=head;
            printf("Deleted:%d",ptr->data);
            cur=head;
            while(cur->next != head)
            {
                cur=cur->next;
            }
            head=head->next;
            cur->next=head;
            free(ptr);

        }
        else
        {
            c=1;
            prev=cur=head;
            while(c!=pos && cur->next!=head)
            {
                c++;
                prev=cur;
                cur=cur->next;
            }
            if (pos>c)
            {
                printf("Position greater than pos\n ");
            }
        }

}


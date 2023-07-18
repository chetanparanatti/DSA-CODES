#include<stdio.h>
#include<stdlib.h>

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
node insert_pos(node head,int pos);  //insert a node based on the given position
node delete_pos(node head,int pos);
void display_list(node head);

main()
{
  node head=NULL;
  int choice,pos;
  for(;;)
  {
      printf("1-INSERT REAR\n 2-DISPLAY\n 3-DELETE FRONT\n 4-DELETE LAST\n 5-INSERT FRONT:\n 6-INSERT NODE\n 7-DELTE NODE\n");
      scanf("%d",&choice);
      switch(choice)
      {
          case 1:printf("\nEnter the values for the data field:\n");
          head=insert_rear(head);
          break;

          case 2:printf("\nDisplay list inserted\n");
          display_list(head);
          break;

          case 3:printf("Delete front element:\n");
          head=delete_front(head);
          break;

          case 4:printf("Delete last element:\n");
          head=delete_rear(head);
          break;

          case 5: printf("Insert front:\n");
          head=insert_front(head);
          break;

          case 6:printf("Enter the position where you want to insert a node");
          scanf("%d",&pos);
          head=insert_pos(head,pos);
          break;

          case 7: printf("Enter the position where u want to delete a node");
          scanf("%d",&pos);
          head=delete_pos(head,pos);
          break;

          default:printf("Invalid user choice\n");
            exit(0);
            break;
      }
  }
}
node getnode()
{
    node new;
    new=(node)malloc(sizeof(struct NODE));
    if(new == NULL)
    {
        printf("NOT CREATED\n");
        exit(0);
    }
    printf("Enter the data:\n");
    scanf("%d",&new->data);
    new->next=NULL;
    return new;
}
node insert_rear(node head)
{
    node new,cur;
    new=getnode();
    new->next=NULL;
    if(head==NULL)
     return new;
  cur=head;
  while(cur->next!=NULL)
  {
      cur=cur->next;
  }
  cur->next=new;
  return head;
}
void display_list(node head)
{
    node cur;
    if(head==NULL)
    {
        printf("Empty list\n");
        return;

    }
    printf("Elements are:\n");
    cur=head;
    while(cur!=NULL)
    {
        printf("%d\n",cur->data);
        cur=cur->next;  //increment to the next node
    }
}
node delete_front(node head)
{
    node cur;
    if(head==NULL)
    {
        printf("list empty\n");
        return head;
    }
    if(head->next==NULL)
    {
        printf("deleted:%d\n",head->data);
        free(head);
        return NULL;
    }
    cur=head;
    head=head->next;
    printf("Deleted:%d\n",cur->data);
    free(cur);
    return head;
}
node delete_rear(node head)
{
    node cur,prev;
    if(head==NULL)
    {
        printf("list empty\n");
        return head;
    }
    if(head->next==NULL)
    {
        printf("deleted:%d\n",head->data);
        free(head);
        return NULL;
    }
    prev=NULL;
    cur=head;
    while(cur->next!=NULL)  //to traverse the list to read all the element in the list
    {
        prev=cur;
        cur=cur->next;
    }
    printf("Deleted=%d\n",cur->data);
    free(cur);
    prev->next=NULL;
    return head;
}
node insert_pos(node head,int pos)
{
    node new,prev,cur;
    new=getnode();
    int count;
    new->next=NULL;
    if(head==NULL && pos==1)
        return new;
    if(head==NULL)
    {
        printf("INVALID POSITION\n");
        return head;
    }
    if(pos==1)
    {
        new->next=head;
        return new;
    }
    count=1;  //used to keep track of the nodes
    prev=NULL;
    cur=head;
    while(cur!=NULL && count!=pos)
    {
        prev=cur;
        cur=cur->next;
        count++;
    }
    if(count==pos)
    {
        prev->next=new;
        new->next=cur;
        return head;
    }
    else
        printf("Invalid position\n");
    return head;

}
node insert_front(node head)
{
    node new;
    new = getnode();

    if(head == NULL)
    {
        return new;
    }
    new->next = head;
    head = new;
    return new;
}
node delete_pos  (node head, int pos)
{
    node cur,prev,count;
    if (head==NULL)//lists not existing
    {
        printf("List empty\n");
        return NULL;
    }
    if (pos==1)
    {
        cur=head;
        head=cur->next;
        printf("Deleted data=%d\n",cur->data);
        free(cur);
        return head;
    }
    prev=NULL;
    cur=head;
    count=1;
    while(cur!=NULL && count!=pos)
    {
        prev=cur;
        cur=cur->next;
        count++;
    }
    if (cur==NULL )
    {
        printf("Invalid position\n");
        return head;
    }
    prev->next=cur->next;
    printf("Deleted:%d\n",cur->data);
    free(cur);
    return head;
}

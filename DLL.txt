#include<stdio.h>
#include<stdlib.h>

typedef struct NODE
{
    int data;
    struct NODE *llink;
    struct NODE *rlink;

}*node;
node insert_rear(node head);
node getnode();
node delete_front(node head);
node insert_front(node head);
node delete_rear(node head);
//node insert_pos(node head,int pos);  //insert a node based on the given position
//node delete_pos(node head,int pos);
void display_forward(node head);
void display_backward(node head);
main()
{
  node head=NULL;
  int choice,pos;
  for(;;)
  {
      printf("1-INSERT REAR\n 2-DISPLAY FORWARD\n 3-DELETE FRONT\n 4-DELETE LAST\n 5-INSERT FRONT:\n 6-INSERT NODE\n 7-DELTE NODE\n 8-DISPLAY BACKWARD\n");
      scanf("%d",&choice);
      switch(choice)
      {
          case 1:printf("\nEnter the values for the data field:\n");
          head=insert_rear(head);
          break;

          case 2:printf("\nDisplay list inserted\n");
          display_forward(head);
          break;

          case 8:printf("\nDisplay list inserted\n");
          display_backward(head);
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

         /* case 6:printf("Enter the position where you want to insert a node");
          scanf("%d",&pos);
          head=insert_pos(head,pos);
          break;

          case 7: printf("Enter the position where u want to delete a node");
          scanf("%d",&pos);
          head=delete_pos(head,pos);*/
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
    new->llink=NULL;
    new->rlink=NULL;
    return new;
}
node insert_front(node head)
{
    node new;
    new=getnode();
    if(head==NULL)
      return new;
      head->llink=new;
      new->rlink=head;
      return new;

}
node insert_rear(node head)
{
   node new,cur;
   new=getnode();
   if(head==NULL)
   return new;
   if(head->rlink==NULL)
   {
      head->rlink=new;
      new->llink=head;
      return head;
   }
   cur=head;
   while(cur->rlink!=NULL)
   {cur=cur->rlink;}
   cur->rlink=new;
   new->llink=cur;
   return head;
}
void display_forward(node head)
{
   node cur;
   if(head==NULL)
   { printf("Enter the list is empty\n");
      exit(0);}
      if(head->rlink==NULL)
      printf("%d",head->data);
      cur=head;
      printf("Elemts are\n ");
      while(cur != NULL)
      {
          printf("%d\t",cur->data);
          cur=cur->rlink;
       }printf("\n");
   }
void display_backward(node head)
{
   node cur,p;
   if(head==NULL)
   { printf("Enter the list is empty\n");
      exit(0);}
      if(head->rlink==NULL)
      printf("%d",head->data);
      cur=head;
      printf("Elemts are\n ");
      while(cur->rlink != NULL)
      {
          cur=cur->rlink;
       }
       p=cur;
       while(p!=NULL)
       {
         printf("%d\t",p->data);
         p=p->llink;
       }printf("\n");
   }
node delete_front(node head)
{

    node cur;
    if(head==NULL)
        {printf("Empty list\n");
          return head;}
    if(head->rlink==NULL && head->llink==NULL)
    {
        printf("Element to be deleted:%d\n",head->data);
        free(head);
        return NULL;
    }
    cur=head;
    head=cur->rlink;
    head->llink=NULL;
    printf("Element to be deleted :%d\n",cur->data);
    free(cur);
    return head;

}
node delete_rear(node head)
{

    node cur,prev;
    if(head==NULL)
        printf("Empty list\n");
    if(head->rlink==NULL && head->llink==NULL)
    {
        printf("Element to be deleted:%d\n",head->data);
        free(head);
        return NULL;
    }
    cur=head;
    while(cur->rlink != NULL)
    {
        cur=cur->rlink;
    }
    prev=cur->llink;
    cur->llink=NULL;
    prev->rlink=NULL;
    printf("Element to be deleted :%d\n",cur->data);
    free(cur);
    return head;

}

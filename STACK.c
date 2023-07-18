#include<stdio.h>
#include<stdlib.h>
#define MAX 5
struct stack
{
    int data[MAX];
    int top;

};
typedef struct stack stack;
int empty(stack s)
{
    if(s.top==-1)
        return(1);
    else
        return(0);
}

int full(stack s)
{

    if(s.top==MAX-1)
        return(1);
    else
        return(0);

}
void push(stack *ps,int num)
{
    if(full(*ps))
    {
        printf("\nstack overflow");
        return;
    }
    ps->top=ps->top+1;
    ps->data[ps->top]=num;
}
int pop(stack *ps)
{
    if(empty(*ps))
    {
        printf("\nstack underflow");
         return;
    }
    int num=ps->data[ps->top];
    ps->top=ps->top-1;
    return num;
}
void display(stack ps)
{
    int i;
    if(empty(ps))
        printf("\nunderflow");
    else{
    for(i=0;i<=ps.top; i++)
        printf("%d\t",ps.data[i]);
    }
}
int main()
{

    stack s;
    s.top=-1;
    int num,ch,x;
    while(1)
    {
        printf("\nenter choice");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("\nenter number:");
            scanf("%d",&num);
            push(&s,num);
            break;
        case 2:

            x=pop(&s);
            break;
        case 3:
            display(s);
            break;

        }

    }
}

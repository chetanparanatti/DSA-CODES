#include<stdio.h>
main()
{
    int n,i;
    printf("Enter the Number");
    scanf("%d",&n);
    for(i=0;i<11;i++)
    {
        printf("%dX%d=%d\n",n,i,n*i);
    }
}

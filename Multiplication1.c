#include<stdio.h>
#include<time.h>
main()
{
    int n,i;
    printf("Enter the Number");
    scanf("%d",&n);
     clock_t start=clock();
    for(i=1;i<11;i++)
    {
        printf("%dX%d=%d\n",n,i,n*i);
    }
    clock_t stop=clock();
    time_t tt=stop-start;
    printf("Time measured:-%0.9d seconds\n",tt);
}

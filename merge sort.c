#include<stdio.h>
#include<time.h>
main()
{
    clock_t t;
    int b[10000],n=0;
    FILE *fp;
    t=clock();
    fp=fopen("input.txt","r");
    while(!feof(fp))
{
    fscanf(fp,"%d\n",&b[n]);
    n++;
}
fclose(fp);
merge_sort1(b,0,n-1);
fp=fopen("output.txt","a");
fprintf(fp,"MERGE SORT:\n");
for(int i=0;i<n;i++)
{
    fprintf(fp,"%d\t",b[i]);
}
fprintf(fp,"\n");
fclose(fp);
t=clock()-t;
double time=((double)t)/CLOCKS_PER_SEC;
printf("This took %f seconds to execute \n",time);
fp=fopen("logs.txt","a");
fprintf(fp,"MERGE SORT : %f\t",time);
fprintf(fp,"\n");
fclose(fp);
}
void merge1(int b[10000],int f,int m,int r)
{
    int n1,n2,i,j,k;
    n1=m-f+1;
    n2=r-m;
    int L[n1],R[n2];
    for(i=0;i<n1;i++)
    {
        L[i]=b[f+i];
    }
    for(j=0;j<n2;j++)
    {
        R[j]=b[m+1+j];
    }
    i=0;
    j=0;
    k=f;
    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {
            b[k]=L[i];
            i++;
            k++;
        }
else
        {
            b[k]=R[j];
            j++;
             k++;
        }

    }
    while(i<n1)
    {
        b[k]=L[i];
            i++;
            k++;
    }
    while(j<n2)
    {
         b[k]=R[j];
            j++;
            k++;
    }
}
void merge_sort1(int b[10000],int f,int r)
{
    int m;
    if(f<r)
    {
        m=(f+r)/2;
        merge_sort1(b,f,m);
        merge_sort1(b,m+1,r);
        merge1(b,f,m,r);
    }
}

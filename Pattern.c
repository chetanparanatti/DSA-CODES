#include<stdio.h>
void put(int n,char str[n][100]);
void read(int n, FILE *fp);
int count(int n,char s[n][100],int i);
void main()
{
   int n,i;
   char str[n][100];
   printf("Enter the no.of lines\n");
   scanf("%d",&n);
   printf("Enter lines\n");
   for(i=0;i<=n;i++)
   {
     gets(str[i]);
    }
    put(n,str);

}
void put(int n,char str[n][100])
{
    FILE *fp;
    int i;
    fp=fopen("paragraph.txt","w");
    for(i=0;i<=n;i++)
    {
    fprintf(fp,"%s\n",str[i]);
    }
    fclose(fp);
    read(n,fp);
}
void read(int n,FILE *fp)
{
    int i,max=0,l,m;
    char s[n][100];
    fp=fopen("paragraph.txt","r");
    i=0;
     while(!feof(fp))
    {
        fgets(s[i],100,fp);
        i++;
    }
    fclose(fp);
    for(i=0;i<=n;i++)
    {
    m=count(n,s,i);
    if(m>max)
    {
        max=m;
        l=i;
    }
    }
printf("The longest line is %d\n",l);
puts(s[l]);
}
int count(int n,char s[n][100],int i)
{
    int j,c=0;
 for(j=0;s[i][j]!='\0';j++)
 {
     c++;
 }
 return c;
}

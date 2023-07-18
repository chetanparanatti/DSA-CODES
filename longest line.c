#include<stdio.h>
void largest(int n,str[n][100]);
void main()
{
 int n,i;
 char s[n][100];
 printf("Enter the no. of lines\n");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 { gets(s[i]);
}
  largest(n,s);
}
void largest(int n,char s[n][100]);
{
 {
    int j,i,c=0,max=0,m;
    for(i=0;i<=n;i++)
    {

       for(j=0;s[i][j]!='\0';j++)
          {
               c++;
          }
          if(c>max)
            {
               max=c;
               m=i;
            }
              c=0;
    }
printf("The longest line is %d\n",m);
puts(s[m]);
}
 }

#include<stdio.h>
int main()
{
    int num,i,temp,r,sum=0;
    printf("Enter any number:");
    scanf("%d",&num);
    temp=num;
   while(temp!=0)
    {
        r=temp%10;
       int fact=1;
       for(i=1;i<=r;i++)
    {
        fact=fact*i;
    }
    sum=sum+fact;
    temp=temp/10;
    }


    if(num==sum)
        printf("strong number \n");
    else
        printf("NOt strong number\n");


}





#include<stdio.h>
int main()
{
    int num,count=0,i,k;

    printf("Enter any number:");
    scanf("%d",&num);
    for(i=2; i<num/2; i++)
    {
        if(num%i==0)
        {
            count++;
            break;
        }
    }
    if(count==0)
        printf("Prime number\n");
    else
        printf("Not prime number\n");
}

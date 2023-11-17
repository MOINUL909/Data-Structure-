#include<stdio.h>
int main()
{
    int num,i;
    while(1)
    {
        printf("Enter number you want to see Multiplication table:\n");
        scanf("%d",&num);
        for(i=1; i<=10; i++)
        {
            printf("%d X %d = %d\n",i,num,num*i);
        }
    }
}

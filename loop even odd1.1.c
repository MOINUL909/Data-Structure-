#include<stdio.h>
int main()
{
    int i,f,l;
    printf("Enter first &last number:\n");
    scanf("%d%d",&f,&l);
    printf("EVEN Numbers are:\n");
    for(i=f;i<=l;i++)
    {
        if(i%2==0)
        {
            printf("%d\n",i);
        }
    }
    printf("\n\n");
    printf("ODD Numbers are:\n");
    for(i=f;i<=l;i++)
    {
        if(i%2!=0)
        {
            printf("%d\n",i);
        }
    }

}

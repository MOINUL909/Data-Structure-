#include<stdio.h>
int main()
{
    int i,f,l;
    printf("Enter first & last number:");
    scanf("%d%d",&f,&l);
      printf("Even numbers are:");
  /*  for(i=f;i<=l;i=i+2)
    {

        printf("%d\t",i);
    }*/
     for(i=f;i<=l;i=i+1)
     {
         if(i%2==0)
        // continue;
            printf("%d\t",i);
     }

}


#include<stdio.h>
#define N 5
int stack[N];
int top=-1;
void push()
{
    int x;
    printf("Enter Data: ");
    scanf("%d",&x);
    if(top==N-1)
    {
        printf("Over Flow");
    }
    else
    {
        top++;
        stack[top]=x;
    }
}
void pop()
{
    int item;
    if(top==-1)
    {
        printf("Underflow");
    }
    else
    {
        item=stack[top];
        top--;
        printf(" Pop item is %d \n",item);
    }
}
void peek()
{
    if(top==-1)
    {
        printf("No elements availabe here");
    }
    else{
        printf(" peek value is %d \n",stack[top]);
    }
}
void display()
{
    int i;
   /* for (i=top;i>=0;i--)
    {
        printf("%d ",stack[i]);
    } */
    printf("\n\n\n");
     for (i=0;i<=top;i++)
    {
        printf("%d ",stack[i]);
    }
}
int main()
{
    push();
    push();
    push();
    push();
    pop();
    peek();
    display();


}

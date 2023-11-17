#include<stdio.h>
#define N 5
int queue[N];
int front=-1;
int rear=-1;
void enqueue(int x)
{
 if(rear==N-1)
 {
     printf("Overflow\n");
 }
 else if(front==-1 && rear==-1)
 {
     front=rear=0;
     queue[rear]=x;

 }
 else
 {
     rear++;
     queue[rear]=x;
 }
}
void dequeue()
{
   if(front==-1 && rear==-1)
   {
       printf("Underflow\n");
   }
   else if (front==rear)
   {
       front=rear=-1;
   }
   else
   {
       printf("Dequeue Value is: %d\n",queue[front]);
       front++;
   }
}
void display()
{
    int i;
    if(front==-1 && rear==-1)
    {
        printf("Queue Is Empty!\n");
    }
    else
    {
        for(i=front;i<rear+1;i++)
        {
            printf("%d\n",queue[i]);
        }
    }
}
void peek()
{
    if(front==-1 && rear==-1 )
    {
        printf("Queue id Empty! \n");
    }
    else
    {
        printf("Peek Value is: %d\n",queue[front]);
    }
}
int main()
{
    enqueue(2);
    enqueue(5);
    enqueue(6);
    enqueue(-2);
    display();
    dequeue();
    peek();
}


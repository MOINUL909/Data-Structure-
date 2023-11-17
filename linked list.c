#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
};
int main()
{
   char null;
    struct node*head = null;
    struct node*second = null;
    struct node*third = null;
    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));
    head->data =1;
    head->next = third;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = null;
}

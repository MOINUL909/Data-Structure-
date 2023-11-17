#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
typedef struct Node *tree;
void insert(tree **t, int val)
{
    tree *temp=NULL;
 if(!(*t))
 {
 temp=(tree*)malloc(sizeof(tree));
 temp->left=temp->right=NULL;
 temp->data=val;
 *t=temp;
 return;
 }
 if(val<(*t)->data)
 {
 insert(&(*t)->left,val);
 }
 else if(val>(*t)->data)
 {
 insert(&(*t)->right,val);
 }
}
}
int main()
{
    bst *tree=NULL;
    tree=(bst*)malloc(sizeof(bst));
    tree->left=tree->right=NULL;
    insert(tree,4);
     insert(tree,5);
      insert(tree,3);
}

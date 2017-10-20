
#ifndef BST_H
#define BST_H
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data ;
    struct Node *parent;
    struct Node *lchild;
    struct Node *rchild;
};

struct Tree
{
    struct Node *root;
};

void Print(struct Node *t);
struct Node* Insert(int value , struct Node *t) ;
void insertNode(int value,struct Node *t) ;
struct Node *Search(int value , struct Node *t) ;
void del(struct Node *t);
#endif /* BST_h */

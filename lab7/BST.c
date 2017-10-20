#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

int main()
{
    int element ;
    struct Tree *tree=malloc(sizeof(struct Tree));
    tree->root=NULL;
    FILE *fp;
     fp = fopen("1.txt","r");
    while(fscanf(fp,"%d",&element)!= EOF)
    {
            struct Node *temp = Insert(element,tree->root);
            //printf("=======\n");
            if(temp!=NULL)
            {
                tree->root=temp;
                //tree->root=root;
            }

    }
    fclose(fp);
    printf("build tree finished\n");
    Print(tree->root);


    printf("\nPlease input the data to be searched:\n put in -1 to stop\n");
    int num ;
            while(scanf("%d",&num))
            {
                if(Search(num , tree->root))
            {
                struct Node *R = Search(num , tree->root);
                printf("success\n");
                printf("value:%d\n",R->data);
                if(R->parent==NULL)
                    printf("this is tree->root no parent\n");
                else
                    printf("parent:%d\n",R->parent->data);
                if(R->lchild==NULL)
                    printf("no lchild\n");
                else
                    printf("lchild:%d\n",R->lchild->data);
                if(R->rchild==NULL)
                    printf("no rchild\n");
                else
                    printf("rchild:%d\n",R->rchild->data);
                printf("Please input the data to be searched:\n (put in -1 to stop)\n");
            }
            else 
            printf("Failed!\n") ;
             if(num==-1)
                break;
            }

            del(tree->root);
            free(tree);
    return 0;
}


void insertNode(int value,struct Node *t)
{
    struct Node *P=malloc(sizeof(struct Node));
    P->data=value ;
    P->lchild=NULL;
    P->rchild=NULL;
    P->parent=t;
    if(value > t->data)
        t->rchild=P;
    else
        t->lchild=P;
}

struct Node *Insert(int value , struct Node *t)
{
    struct Node *temp;
    
    if(t == NULL )
            {
                printf("Insert value:%d\n", value);
                t =malloc(sizeof(struct Node));
                t -> parent = NULL;
                t -> data = value ;
                t -> lchild = NULL ;
                t -> rchild = NULL ;
                return t;
            }

            else
            {
                while(t){
                        if(value==t->data)
                        {
                            printf("cannot insert duplicate values:%d\n",value);
                            return NULL;
                        }
                    if(value > t->data){
                            temp=t;
                            t=t->rchild;
                            }
                else{
                        temp=t;
                        t=t->lchild;
                    }
                }
                    //if(value!=t->data)
                    printf("Insert value:%d\n", value);
                    insertNode(value,temp);
                    return NULL;
            }
            
    
}

struct Node *Search(int value , struct Node *t)
{
    if(t ==NULL)
        return NULL ;
    else if(value == t->data)
        return t ;
    else if(value <t->data)
    {
        return Search(value , t->lchild ) ;
        
    }
    else if(value > t->data)
    {
        return Search(value , t->rchild) ;
    }
    return NULL;
}

void Print(struct Node *t)
{
    if(t !=  NULL)
    {
        Print(t -> lchild) ;
        printf("%d ",t->data );
        Print(t -> rchild) ;
    }
}
void del(struct Node *t)
{
    if(t !=  NULL)
    {
        if(t->lchild!=NULL)
        del(t -> lchild) ;
        //printf("%d ",t->data );
    if(t->rchild!=NULL)
        del(t -> rchild) ;
    free(t);
    }
}
